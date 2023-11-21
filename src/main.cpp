#include <iostream>
#include <vector>
#include "Application/Application.h"

using namespace std; 

int main(int argc, char* argv[])
{
    const std::string& description = "Creating parser with allowed options";
    Application app;
    if (!app.run(description, argc, argv))
    {
        std::cout << "ERROR: There was an error, while running command line argument parser and test application. \n"; 
        return 1;
    }
    return 0;
}
