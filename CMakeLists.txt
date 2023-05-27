qt6_add_library(ForwardUILib STATIC)

message(STATUS "Building ForwardUILib")

set_target_properties(ForwardUILib PROPERTIES AUTOMOC ON)
target_link_libraries(ForwardUILib PUBLIC Qt6::Gui Qt6::Qml Qt6::Quick)
target_include_directories(ForwardUILib
    PUBLIC 
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/forward/ui>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/forward/ui>
)

set(FLUI_QML_FILES "")
set(FLUI_QML_SOURCE
    forward/ui/module/TrayMenu.qml
)

remove_path_from_list(FLUI_QML_SOURCE "forward/ui/module" FLUI_QML_FILES)

foreach(dir_file file_name IN ZIP_LISTS FLUI_QML_SOURCE FLUI_QML_FILES)
    set_source_files_properties(${dir_file} PROPERTIES QT_RESOURCE_ALIAS ${file_name})
endforeach()

set(FLUI_SOURCE 
    forward/ui/AppStyle.cpp
    forward/ui/AppStyle.hpp
    forward/ui/CursorPosition.hpp
    forward/ui/SystemTray.cpp
    forward/ui/SystemTray.hpp
    forward/ui/TrayMenuItem.cpp
    forward/ui/TrayMenuItem.hpp
    forward/ui/TrayMenuWrapper.cpp
    forward/ui/TrayMenuWrapper.hpp
)

qt6_add_qml_module(ForwardUILib
    URI forward.ui
    RESOURCE_PREFIX /imports
    SOURCES
        ${FLUI_SOURCE}
    QML_FILES
        ${FLUI_QML_SOURCE}
)