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

qt6_add_qml_module(Forward.UI URI Forward.UI VERSION 0.1
RESOURCE_PREFIX 
    "/forward/ui"
QML_FILES 
    ${FLUI_COMPONENTS}
SOURCES 
    ${FLUI_SOURCE}
RESOURCES 
    "Resources/qrc/module.qrc"
STATIC
NO_PLUGIN
)

target_include_directories(Forward.UI 
PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Forward/Source>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/Forward/Source>
)