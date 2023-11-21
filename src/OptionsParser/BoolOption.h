#pragma once 

#include "OptionBase.h"

class BoolOption : public OptionBase
{
public:
    BoolOption(std::string desc, std::string optName) noexcept;

    bool parse(const std::string& val) noexcept;
    const bool isValRequired() const noexcept;
    bool getHelp() const noexcept;
private:
    bool m_help;
};

