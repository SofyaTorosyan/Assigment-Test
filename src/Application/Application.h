#pragma once

#include "StringOption.h"
#include "BoolOption.h"
#include "Commands.h"
#include "OptionParser.h"

class Application
{
public:
    const std::unique_ptr<OptionParser> createParser(const std::string& description);
    void checkHelpOption() const;
    bool checkFileNameOption() const;
    bool checkChecksumOption() const;
    bool run(const std::string& description, const int argc, char* argv[]);
private:
    std::shared_ptr<StringOption> fileNameOpt;
    std::shared_ptr<StringOption> checksumOpt;
    std::shared_ptr<StringOption> searchPatternOpt;
    std::shared_ptr<BoolOption> helpOpt;
};
