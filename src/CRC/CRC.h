#pragma once

#include <iostream>
#include <fstream>

// CRC32 polynomial (normal form)
#define CRC32_POLYNOMIAL 0xEDB88320 

class CRC
{
public:
    explicit CRC(std::string name) noexcept;

    uint32_t calculateCRC32(const char* buffer, size_t size) const;
    uint32_t calculateFileCRC32() const;
private:
    std::string m_fileName; 
};
