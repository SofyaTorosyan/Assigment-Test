#pragma once

#include <iostream>
#include <exception>
#include <map>
#include "OptionBase.h"

class OptionParser
{
public: 
    explicit OptionParser(const std::string& description) noexcept;
    bool parse(const int argc, char* argv[]) const;
    void addOption(std::shared_ptr<OptionBase> opt);
    int getSize() { return m_optNameToVal.size(); }
private:
    std::string m_optionName;
    std::multimap<std::string, std::shared_ptr<OptionBase>> m_optNameToVal;
};
