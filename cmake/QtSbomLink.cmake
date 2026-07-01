# QtSbomLink.cmake — link a cmake-sbom document to Qt's pre-shipped SBOMs.
#
# Qt (6.8+) ships pre-generated SPDX SBOMs next to its install
# (<qt_prefix>/sbom/*.spdx). This helper wires the current cmake-sbom
# document to those, so listing Qt module names is all a project needs.
#
#   qt_sbom_link(Core Gui Widgets Network ...)
#
# For each module it locates the Qt SBOM document that declares the module's
# package (searching every *.spdx under <qt_prefix>/sbom), then calls
# cmake-sbom's sbom_add(EXTERNAL ...) which emits an ExternalDocumentRef
# (namespace + SHA1 auto-extracted from the file) and a DEPENDS_ON from this
# project's root package. The Qt SBOM path and the module package SPDXID
# (which carries a build-specific hash) are resolved dynamically, so the link
# survives Qt reinstalls/updates.
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

    foreach(_mod IN LISTS ARGV)
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
                sbom_add(EXTERNAL "${_pkg_id}"
                    FILENAME "${_doc}"
                    RENAME   "${_doc_name}"
                    SPDXID   "DocumentRef-${_ref_suffix}")
                set(_linked TRUE)
                break()
            endif()
        endforeach()
        if(NOT _linked)
            message(WARNING "qt_sbom_link: Qt module '${_mod}' not found in any SBOM under ${_dir}")
        endif()
    endforeach()
endfunction()
