set(FLUI_COMPONENTS
    Forward/Module/MessageItem.qml
    Forward/Module/MessageContainer.qml
    Forward/Module/WindowsTitleBar.qml
    Forward/Module/ChatTitleBar.qml
)
set(FLUI_SOURCE 
    Forward/Source/MessageContainerLogic.cpp
    Forward/Source/MessageContainerLogic.hpp
)

qt6_add_qml_module(Forward.UI
URI Forward.UI
VERSION 0.1
RESOURCE_PREFIX "/forward/ui"
QML_FILES 
    ${FLUI_COMPONENTS}
SOURCES 
    ${FLUI_SOURCE}
RESOURCES
    "Resources/qrc/module.qrc"
NO_PLUGIN
)