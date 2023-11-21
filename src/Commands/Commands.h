#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "CRC.h"

const std::string initHelpDescription(const std::vector<std::string>& optionDesctriptions);
void printHelp(const std::string& helpDescription);
bool fileExists(const std::string& fileName);
int printChecksum(const std::string& fileName);
void printWordCount(const std::string& fileName);
