include(cmake/path-cat.cmake)

set(FLUI_COMPONENTS
    Forward/Module/WindowsTitleBar.qml
    Forward/Module/ChatTitleBar.qml
    Forward/Module/MessageItem.qml
    Forward/Module/MessageContainer.qml
)
set(FLUI_SOURCE 
    Forward/Source/MessageContainerLogic.cpp
    Forward/Source/MessageContainerLogic.hpp
    Forward/Source/WindowsTitleBar.cpp
    Forward/Source/WindowsTitleBar.hpp
)

concat_path_to_list(${CMAKE_CURRENT_SOURCE_DIR} ${FLUI_SOURCE} FLUI_DIR_SOURCE)

qt6_add_qml_module(Forward.UI
URI Forward.UI
VERSION 0.1
    RESOURCE_PREFIX "/forward/ui"
QML_FILES 
    ${FLUI_COMPONENTS}
SOURCES 
    ${FLUI_DIR_SOURCE}
RESOURCES
    "Resources/qrc/module.qrc"
STATIC
)