set(FLUI_COMPONENTS
)
set(FLUI_SOURCE 
    forward/ui/src/AppStyle.cpp
    forward/ui/src/AppStyle.hpp
    forward/ui/src/TitleBarElement.cpp
    forward/ui/src/TitleBarElement.hpp
)
set(FLUI_RESOURCES
    qrc/module.qrc
)

qt_add_library(Forward.UI STATIC
    ${FLUI_RESOURCES}
)
qt_add_qml_module(Forward.UI 
URI Forward.UI 
VERSION 1.0
RESOURCE_PREFIX
    "/forward/ui"
SOURCES
    ${FLUI_SOURCE}
NO_PLUGIN
)

target_include_directories(Forward.UI 
PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/forward/ui/src>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/forward/ui/src>
)
target_link_libraries(Forward.UI 
PUBLIC 
    Qt6::Core
    Qt6::Quick
    Qt6::Qml
    Qt6::QuickControls2
)