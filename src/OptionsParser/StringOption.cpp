#include "StringOption.h"

StringOption::StringOption(std::string desc, std::string optName, std::string defaultVal) noexcept
:   OptionBase(std::move(desc), std::move(optName)), 
    m_defaultValue(std::move(defaultVal)) 
{

} 

bool 
StringOption::parse(const std::string& val) noexcept
{
    try
    {
        m_value = val;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }
    return true;
}

const bool 
StringOption::isValRequired() const noexcept
{
  return true;
}

const std::string& 
StringOption::getValue() const noexcept 
{ 
    return m_value; 
}
