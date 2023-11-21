#include "BoolOption.h"

BoolOption::BoolOption(std::string desc, std::string optName) noexcept
: OptionBase(std::move(desc), std::move(optName)),
  m_help(false)
{

} 

bool 
BoolOption::parse(const std::string& val) noexcept
{
  m_help = true;
  return true;
}

bool 
BoolOption::getHelp() const noexcept
{
  return m_help;
}

const bool 
BoolOption::isValRequired() const noexcept
{
  return false;
}

