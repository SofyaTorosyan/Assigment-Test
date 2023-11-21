#pragma once

#include <iostream>

class OptionBase 
{
public:
    explicit OptionBase(std::string desc, std::string name) noexcept;
    virtual ~OptionBase() = default;

    virtual bool parse(const std::string& value) = 0;
    virtual const bool isValRequired() const noexcept = 0;
    const std::string& getOptName() const noexcept;
    const std::string& getDescription() const noexcept;
protected:
    std::string m_description;
    std::string m_optName;
};
