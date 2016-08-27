#ifndef ARGUMENTS_HPP
#define ARGUMENTS_HPP

#include <getopt.h>
#include <iostream>

void parseArguments(int argc, char** argv)
{
    int c;
    bool used = false;
    while((c = getopt(argc, argv, "h::")) != -1)
    {
        used = true;
        switch (c)
        {
            case 'h':
                std::cout << "-h \t show help \n";
                break;
            case '?':
                std::cout << "Unknown argument\n-h \t show help \n";
                break;
            default:
                break; ///Not handled yet
        }
    }
    if(!used)
        std::cout << "No arguments \n";
}

#endif
