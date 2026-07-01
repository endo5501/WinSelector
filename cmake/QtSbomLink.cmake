# QtSbomLink.cmake — link a cmake-sbom document to Qt's pre-shipped SBOMs.
#
# Qt (6.8+) ships pre-generated SPDX SBOMs next to its install
# (<qt_prefix>/sbom/*.spdx). This helper wires the current cmake-sbom
# document to those, so listing Qt module names is all a project needs.
#
#   qt_sbom_link([FROM <spdxid>] <Module> [<Module> ...])
#
# For each module it locates the Qt SBOM document that declares the module's
# package (searching every *.spdx under <qt_prefix>/sbom), then calls
# cmake-sbom's sbom_add(EXTERNAL ...) which emits an ExternalDocumentRef
# (namespace + SHA1 auto-extracted from the file) and a DEPENDS_ON edge. The Qt
# SBOM path and the module package SPDXID (which carries a build-specific hash)
# are resolved dynamically, so the link survives Qt reinstalls/updates.
#
#   FROM <spdxid>  Source element of the DEPENDS_ON edge, i.e. depend at target
#                  granularity. Pass a target's file SPDXID captured from
#                  ${SBOM_LAST_SPDXID} right after sbom_add(TARGET ...):
#                      sbom_add(TARGET B LICENSE MIT)          # B.exe
#                      qt_sbom_link(FROM "${SBOM_LAST_SPDXID}" Widgets Xml Network)
#                  When omitted, the edge originates from the project's ROOT
#                  package (cmake-sbom's default) = project-level granularity.
#                  Caveat: for a Windows SHARED library, sbom_add(TARGET) adds
#                  the .dll then the .lib, so ${SBOM_LAST_SPDXID} is the import
#                  .lib. That still conveys "library A uses <module>"; if you
#                  must anchor on the .dll specifically, add it via
#                  sbom_add(FILENAME .../A.dll SPDXID <id> ...) and pass FROM <id>.
#
# Prerequisites (caller side):
#   find_package(Qt6 ...)      # provides Qt6_DIR
#   include(sbom)              # demcon/cmake-sbom
#   sbom_generate(...)         # must be called before qt_sbom_link()
#
# Missing pieces degrade gracefully to a warning (never a hard error), so a
# machine without Qt's shipped SBOM still configures.

if(COMMAND qt_sbom_link)
    return()
endif()

function(qt_sbom_link)
    cmake_parse_arguments(_qsl "" "FROM" "" ${ARGV})
    set(_modules "${_qsl_UNPARSED_ARGUMENTS}")
    if(NOT _modules)
        message(WARNING "qt_sbom_link: no Qt module names given; nothing to do")
        return()
    endif()

    if(NOT DEFINED Qt6_DIR)
        message(WARNING "qt_sbom_link: Qt6_DIR is not set (call find_package(Qt6) first); skipped")
        return()
    endif()

    # Qt6_DIR is <qt_prefix>/lib/cmake/Qt6 -> go up three levels for <qt_prefix>.
    get_filename_component(_qt_prefix "${Qt6_DIR}/../../.." ABSOLUTE)
    set(_dir "${_qt_prefix}/sbom")
    if(NOT IS_DIRECTORY "${_dir}")
        message(WARNING "qt_sbom_link: Qt SBOM directory not found at ${_dir}; skipped")
        return()
    endif()

    file(GLOB _docs "${_dir}/*.spdx")
    if(NOT _docs)
        message(WARNING "qt_sbom_link: no *.spdx documents under ${_dir}; skipped")
        return()
    endif()

    foreach(_mod IN LISTS _modules)
        set(_linked FALSE)
        foreach(_doc IN LISTS _docs)
            file(READ "${_doc}" _content)
            # Anchor on the "SPDXID:" declaration line so we hit the document
            # that DEFINES the module package (qtbase), not one that merely
            # references it in a Relationship (e.g. qqeffectmaker depends on Core).
            # e.g.  SPDXID: SPDXRef-Package-qtbase-qt-module-Widgets-14f2e7e421b1
            if(_content MATCHES "SPDXID: *(SPDXRef-Package-[A-Za-z0-9]+-qt-module-${_mod}-[0-9a-f]+)")
                set(_pkg_id "${CMAKE_MATCH_1}")
                get_filename_component(_doc_name "${_doc}" NAME)
                get_filename_component(_doc_stem "${_doc}" NAME_WLE)
                # DocumentRef id must match ^DocumentRef-[-a-zA-Z0-9]+$ (no dots):
                # sanitize the version dots etc. Unique per (document, module).
                string(REGEX REPLACE "[^A-Za-z0-9]" "-" _ref_suffix "${_doc_stem}-${_mod}")

                # With FROM, override the edge source (target-level). Without it,
                # cmake-sbom's default originates the edge from the root package.
                set(_rel "")
                if(_qsl_FROM)
                    set(_rel RELATIONSHIP
                        "${_qsl_FROM} DEPENDS_ON DocumentRef-${_ref_suffix}:${_pkg_id}")
                endif()

                sbom_add(EXTERNAL "${_pkg_id}"
                    FILENAME "${_doc}"
                    RENAME   "${_doc_name}"
                    SPDXID   "DocumentRef-${_ref_suffix}"
                    ${_rel})
                set(_linked TRUE)
                break()
            endif()
        endforeach()
        if(NOT _linked)
            message(WARNING "qt_sbom_link: Qt module '${_mod}' not found in any SBOM under ${_dir}")
        endif()
    endforeach()
endfunction()
