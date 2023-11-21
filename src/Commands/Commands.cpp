#include <filesystem>

#include "Commands.h"

const char* searchPattern = "mother";
const std::string initHelpDescription(const std::vector<std::string>& optionDesctriptions)
{
    std::string help = "The program is a console application to parse command line arguments and execute commands. \n"; 
    for (const auto& description : optionDesctriptions)
    {
        help = help + description + "\n";
    }
    
    return help;
}

void printHelp(const std::string& helpDescription)
{
    std::cout << helpDescription;
}

bool fileExists(const std::string& fileName) {
    return std::filesystem::exists(fileName);
}

int printChecksum(const std::string& fileName)
{
    CRC crc32(fileName);
    return crc32.calculateFileCRC32();
}

// As in task it's not specified whether Mother, Mother's is calculated. The algorithm searches only " mother " in the text.
void printWordCount(const std::string& fileName)
{
    std::fstream file(fileName);
    int numWords = 0;
    std::string line;
    while(getline(file, line))
    {
        std::istringstream iss(line);
        numWords += std::count(std::istream_iterator<std::string>{iss},  std::istream_iterator<std::string>{}, searchPattern); 
    }
    // "mother" --> change
    std::cout << "Number of word < " << searchPattern << " > in file " << fileName << " is " << numWords << std::endl;
}
