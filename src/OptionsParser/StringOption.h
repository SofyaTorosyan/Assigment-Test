#pragma once 

#include "OptionBase.h"

class StringOption : public OptionBase
{
public:
    StringOption(std::string desc, std::string optName, std::string defaultVal) noexcept;

    bool parse(const std::string& val) noexcept;
    const bool isValRequired() const noexcept;
    const std::string& getValue() const noexcept;
private:
    std::string m_value;
    std::string m_defaultValue;
};
