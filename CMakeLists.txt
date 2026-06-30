cmake_minimum_required(VERSION 3.16)

project(WinSelector VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets LinguistTools)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets LinguistTools)

set(TS_FILES resources/WinSelector_ja_JP.ts)

set(PROJECT_SOURCES
        src/main.cpp
        src/mainwindow.cpp
        src/mainwindow.h
        src/mainwindow.ui
        src/windowscanner.cpp
        src/windowscanner.h
        src/windowtile.cpp
        src/windowtile.h
        src/flowlayout.cpp
        src/flowlayout.h
        src/win32utils.cpp
        src/win32utils.h
        src/config.h
        src/settings.cpp
        src/settings.h
        resources/resources.qrc
        ${TS_FILES}
)

if(WIN32)
    set(PROJECT_SOURCES ${PROJECT_SOURCES} resources/WinSelector.rc)
endif()

qt_add_executable(WinSelector
    MANUAL_FINALIZATION
    ${PROJECT_SOURCES}
)

qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})

target_link_libraries(WinSelector PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

if(WIN32)
    target_link_libraries(WinSelector PRIVATE user32 gdi32 psapi shell32)
endif()

set_target_properties(WinSelector PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    WIN32_EXECUTABLE TRUE
)

# MACOSX_BUNDLE should only be enabled on Apple platforms. Setting it
# unconditionally makes Qt's SBOM helper build a bogus
# "<name>.app/Contents/MacOS/<name>.exe" path on Windows.
if(APPLE)
    set_target_properties(WinSelector PROPERTIES MACOSX_BUNDLE TRUE)
endif()

include(GNUInstallDirs)
install(TARGETS WinSelector
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Find windeployqt executable
if(WIN32)
    find_program(WINDEPLOYQT_EXECUTABLE windeployqt)

    if(WINDEPLOYQT_EXECUTABLE)
        # Deploy Qt dependencies after install
        install(CODE "
            execute_process(
                COMMAND \"${WINDEPLOYQT_EXECUTABLE}\" \"\${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_BINDIR}/WinSelector.exe\" --no-translations --no-opengl-sw --no-system-dxc-compiler --no-compiler-runtime --no-network --no-svg --no-system-d3d-compiler
                RESULT_VARIABLE deploy_result
            )
            if(NOT deploy_result EQUAL 0)
                message(WARNING \"windeployqt failed with result: \${deploy_result}\")
            else()
                message(STATUS \"Successfully deployed Qt dependencies\")
            endif()
        ")
    else()
        message(WARNING "windeployqt not found. Qt DLLs will not be automatically deployed.")
    endif()
endif()

qt_finalize_executable(WinSelector)

# ---- SBOM 生成 ----
_qt_internal_setup_sbom()

_qt_internal_sbom_begin_project(
    SUPPLIER           "endo5501"
    SUPPLIER_URL       "https://github.com/endo5501"
    DOCUMENT_NAMESPACE "https://github.com/endo5501/WinSelector"
    VERSION            "1.0.0"
    LICENSE_EXPRESSION "MIT"
)

_qt_internal_add_sbom(WinSelector
    SBOM_ENTITY_TYPE   EXECUTABLE
    PACKAGE_VERSION    "${PROJECT_VERSION}"
    RUNTIME_PATH       "${CMAKE_INSTALL_BINDIR}"
    LICENSE_EXPRESSION "MIT"
    COPYRIGHTS         "Copyright (C) 2026 endo5501"
)

_qt_internal_sbom_end_project()