#include "Replace.hpp"
#include <stdexcept>
#include <fstream>
#include <iostream>





void Replace::fileReplace(const std::string& file, const std::string& target, const std::string&replace)
{
    std::ifstream in;
    std::ofstream out;
    std::string line;
    std::string outfile =  file + ".replace";
    in.open(file.c_str());
    out.open(outfile.c_str());
    if (!in || !out)
        return;
    while (std::getline(in, line))
    {
        strReplace(line, target, replace);
        out << line;
        if (!in.eof())
        out << "\n";
    }
}

void Replace::strReplace(std::string&str, const std::string& target, const std::string& replace)
{
    size_t idx;
    size_t pos;

    if (!target.length())
        return ;
    idx = 0;
    do
    {
        pos = str.find(target, idx);
        if (pos != std::string::npos)
        {
            str.erase(pos, target.length());
            str.insert(pos, replace);
            idx = pos + replace.length();
        }
    }while(pos != std::string::npos);
}
