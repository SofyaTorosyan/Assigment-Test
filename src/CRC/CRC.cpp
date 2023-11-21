#include "CRC.h"

CRC::CRC(std::string name) noexcept
: m_fileName(std::move(name))
{

}

uint32_t 
CRC::calculateCRC32(const char* buffer, size_t size) const {
    uint32_t crc = 0xFFFFFFFF;  // Initialize with all bits set

    for (size_t i = 0; i < size; ++i) {
        crc ^= static_cast<uint32_t>(buffer[i]);  // XOR with the next byte

        for (int j = 0; j < 8; ++j) {
            crc = (crc >> 1) ^ ((crc & 1) ? CRC32_POLYNOMIAL : 0);
        }
    }

    return crc ^ 0xFFFFFFFF;  // Final XOR with all bits set
}

uint32_t 
CRC::calculateFileCRC32() const {
    std::ifstream file(m_fileName, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file: " << m_fileName << std::endl;
        exit(EXIT_FAILURE);
    }

    const size_t buffer_size = 1024;
    char buffer[buffer_size];

    uint32_t crc = 0xFFFFFFFF;  // Initialize with all bits set

    while (file.read(buffer, buffer_size)) {
        crc = calculateCRC32(buffer, buffer_size);
    }

    // Handle the last part of the file if it's not a multiple of buffer size
    if (file.gcount() > 0) {
        crc = calculateCRC32(buffer, file.gcount());
    }

    file.close();

    return crc;
}
