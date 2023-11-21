#include "Application.h"

constexpr char* checksumValue = "checksum";
constexpr char* wordValue = "word";

bool Application::run(const std::string& description, const int argc, char* argv[]) 
{
    std::unique_ptr<OptionParser> optParser = createParser(description);
    if(!optParser->parse(argc, argv))
    {
        std::cout << "ERROR: parser failed to finish.\n";
        return false;
    }
    checkHelpOption();
    if (!checkFileNameOption() || !checkChecksumOption())
    {    
        return false;
    }
    return true;
}

const std::unique_ptr<OptionParser>
Application::createParser(const std::string& description)
{
    std::unique_ptr<OptionParser> optParser = std::make_unique<OptionParser>(description);
    fileNameOpt = std::make_shared<StringOption>("-f <fileName> : Gets file name, on which commands will execute.",  "-f", "");
    checksumOpt = std::make_shared<StringOption>("-m checksum/word : Calcultaes 32-bit checksum with words/Searhes word pattern occuracies in file.",  "-m",  "");
    searchPatternOpt = std::make_shared<StringOption>("-v <SearchPattern> : Searches pattern occuracies in file.",  "-v", "");
    helpOpt = std::make_shared<BoolOption>("-h : Prints help description for about the application.",  "-h");

    optParser->addOption(fileNameOpt);
    optParser->addOption(searchPatternOpt);
    optParser->addOption(helpOpt);
    optParser->addOption(checksumOpt);

    return optParser;
}

void
Application::checkHelpOption() const
{
    const bool help = helpOpt->getHelp();

    std::vector<std::string> optionDesctriptions;
    optionDesctriptions.push_back(fileNameOpt->getDescription());
    optionDesctriptions.push_back(checksumOpt->getDescription());
    optionDesctriptions.push_back(searchPatternOpt->getDescription());
    optionDesctriptions.push_back(helpOpt->getDescription());

    const std::string helpDescription = initHelpDescription(optionDesctriptions);
    if(help)
    {
        printHelp(helpDescription);
    }
}

bool
Application::checkFileNameOption() const
{
    const std::string& fName = fileNameOpt->getValue();
    if(!fName.empty() && !fileExists(fName))
    {
        std::cout << "ERROR: " << "File with name " + fName + " doesn't exist\n";
        return false;
    }
    return true;
}

bool
Application::checkChecksumOption() const
{
    const std::string& checksum = checksumOpt->getValue();
    if(checksum == checksumValue)
    {
        if (searchPatternOpt->getValue().empty())
        {
            std::cout << "Checksum: " << printChecksum(fileNameOpt->getValue()) << std::endl;
        }
        return true;
    }

    if(checksum == wordValue)
    {
        const std::string& searchPattern = searchPatternOpt->getValue();
        if(searchPattern.empty())
        {
            std::cout << "ERROR: Wrong arguments to the command. Search pattern isn't given\n";
            return false;
        }
        printWordCount(fileNameOpt->getValue());
        return true;
    }
    std::cout << "Wrong value for the option < " << checksumOpt->getOptName() << " > . \n";
    return false;
}
