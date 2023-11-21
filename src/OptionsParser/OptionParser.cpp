#include "OptionParser.h"

OptionParser::OptionParser(const std::string& description) noexcept
{
    std::cout << description << "\n";
}

/*
bool OptionParser::parse(const int argc, char* argv[]) const
{
    if (argc < 2)
    {
        std::cout << "ERROR: Invalid number of cmd line arguments given.\n";
        return false;
    }

    int optionIndex = 0;
    for (int i = 1; i < argc; )
    {
        std::cout << "i: " << i << "\n";
        //std::cout << "i: " << i << std::endl;
        std::string arg = argv[i];
        auto opt = m_optNameToVal.begin();
        if(arg.find("-") != std::string::npos)
        {
            optionIndex = i;
            opt = m_optNameToVal.find(arg);
            if (opt == m_optNameToVal.end())
            {
                std::cout << "ERROR: Unsupported option name: " << arg << ".\n";
                return false;
            }
            ++i;
        }
        else{
            if (!opt->second->isValRequired())
            {
                opt->second->parse("true");
                // After boolian no argument should be specified.
                if (++i < argc) 
                {
                    std::cout << "ERROR: After boolian option < " << arg << " > nothing should be given. \n";  
                    return false;
                }
            }
            else 
            {
                opt->second->parse(argv[i]);
                if (i >= argc) 
                {
                    std::cout << "ERROR: Value for option  " << opt->first << " isn't given. \n";
                    return false; 
                }
                // check which option was initial arg("-f", "-m", "-m", "-v")
                if (std::string(argv[optionIndex]) == "-f")
                {
                    if (++i >= argc)
                    {
                        std::cout << "ERROR: After file name no option was given. \n";
                        return false;    
                    }
                }
                else if(std::string(argv[optionIndex]) == "checksum")
                {
                    if (++i < argc)
                    {
                        std::cout << "ERROR: After checksum no option should be given. \n";
                        return false;    
                    }
                }
                else if(std::string(argv[optionIndex]) == "word")
                {
                    if (++i >= argc)
                    {
                        std::cout << "ERROR: After word no option should be given. \n";
                        return false;    
                    }
                    if(std::string(argv[i]) != "-v")
                    {
                        std::cout << "ERROR: Wrong option after <-m>. \n";
                        return false;   
                    }
                }
            }
        }    
    }
    return true;
}
*/

bool OptionParser::parse(const int argc, char* argv[]) const
{
    if (argc < 2)
    {
        std::cout << "ERROR: Invalid number of arguments.\n";
        return false;
    }
    auto opt = m_optNameToVal.begin();
    for (int i = 1; i < argc; ++i)
    {
        std::string arg = argv[i];
        // option
        if (arg.find("-") != std::string::npos)
        {
            opt = m_optNameToVal.find(arg);
            if (opt == m_optNameToVal.end())
            {
                std::cout << "ERROR: No such option can be given < "  << arg << " >. \n";
                return false;
            }
        }
        // opt is value, check is bool or is string 
        if (!opt->second->isValRequired())
        {
            opt->second->parse("true");
            if ((i+1) < argc)
            {
                std::cout << "ERROR: After boolian option nothing should be specified. \n"; 
                return false;
            }
        }
        else 
        {
            if ((i+1) >= argc)
            {
                std::cout << "ERROR: String option value isn't given. \n"; 
                return false;
            }
            opt->second->parse(argv[++i]);
            if(opt->second->getOptName() == "-f" && (i+1) >= argc)
            {
                std::cout << "ERROR: After file name one more option should be given. \n"; 
                return false;
            }
        }
    }
    return true;
}

void OptionParser::addOption(std::shared_ptr<OptionBase> opt)
{
    m_optNameToVal.insert(std::make_pair(opt->getOptName(), opt));
}

