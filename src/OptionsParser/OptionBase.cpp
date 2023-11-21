#include "OptionBase.h"
 
OptionBase::OptionBase(std::string desc, std::string name) noexcept 
:   m_description(std::move(desc)), 
    m_optName(std::move(name)) 
{

}

const std::string& OptionBase::getOptName() const noexcept 
{ 
    return m_optName; 
}

 const std::string& 
 OptionBase::getDescription() const noexcept
 {
    return m_description;
 }
