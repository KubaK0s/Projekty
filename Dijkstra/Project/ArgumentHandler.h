#pragma once
#include <iostream>
#include <string>

struct Files
{
    string input;
    string output;
    string centralOffice;

    bool end = false;
};

/// Handles passed arguments
struct ArgumentHandler
{
    void showArguments(int argc, char* argv[])
    {
        for (int i = 0; i < argc; i++)
            std::cout << argv[i] << '\n';
    }


    Files process(int argc, char* argv[])
    {
        Files f;

        if (argc > 1 && std::string(argv[1]) == "-h")
        {
            std::cout << "Help:\n\t-i <input file>\n\t-c <central office>\n\t-o <output file>\n\n";
        }
        if (argc > 7)
        {
            std::cout << "Too many arguments.\n";
            f.end = true;
        }
        if (argc < 7)
        {
            std::cout << "Too few arguments.\n";
            f.end = true;
        }

        for (int i = 1; i < argc; i++)
        {
            if (std::string(argv[i]) == "-i")
                f.input = std::string(argv[++i]);
            else if (std::string(argv[i]) == "-c")
                f.centralOffice = std::string(argv[++i]);
            else if (std::string(argv[i]) == "-o")
                f.output = std::string(argv[++i]);
        }

        return f;
    }
};