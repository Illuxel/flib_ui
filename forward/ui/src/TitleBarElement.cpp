#include "TitleBarElement.hpp"

TitleBarElement::TitleBarElement() 
{
    
}

void TitleBarElement::SetTitleBarName(std::string titlebar_name)
{
    titlebar_name_ = titlebar_name;
}
std::string TitleBarElement::GetTitleBarName() const
{
    return titlebar_name_;
}