cmake_minimum_required(VERSION 3.24 FATAL_ERROR)

qt6_add_library(ForwardUILib STATIC)

message(STATUS "Building Forward.UI.Lib")

set_target_properties(ForwardUILib PROPERTIES AUTOMOC ON)
target_link_libraries(ForwardUILib PUBLIC Qt6::Widgets Qt6::Gui Qt6::Qml Qt6::Quick)
target_include_directories(ForwardUILib
    PUBLIC 
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/forward/source>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/forward/source>
)

set(FLUI_QML_SOURCE
    forward/components/ChatList.qml
    forward/components/ChatListItem.qml
    forward/components/MessageList.qml
    forward/components/MessageItem.qml
    
    forward/components/windows/TitleBar.qml
    forward/components/windows/TrayMenu.qml
)

set(FLUI_SOURCE 
    forward/source/CursorPosition.hpp
    forward/source/SystemTray.cpp
    forward/source/SystemTray.hpp
    forward/source/TrayMenuItem.cpp
    forward/source/TrayMenuItem.hpp
    forward/source/TrayMenuWrapper.cpp
    forward/source/TrayMenuWrapper.hpp
)

qt6_add_qml_module(ForwardUILib
    URI forward.ui
    RESOURCE_PREFIX /imports
    SOURCES
        ${FLUI_SOURCE}
    QML_FILES
        ${FLUI_QML_SOURCE}
)