#include "WindowsTitleBar.hpp"

WindowsTitleBar::WindowsTitleBar() 
{
    
}

void WindowsTitleBar::SetTitleBarName(std::string titlebar_name)
{
    titlebar_name_ = titlebar_name;
}
std::string WindowsTitleBar::GetTitleBarName() const
{
    return titlebar_name_;
}