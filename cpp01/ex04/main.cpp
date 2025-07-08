/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 16:14:56 by sabe              #+#    #+#             */
/*   Updated: 2025/07/08 16:15:01 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

bool validateArgs(int argc);
bool openInputFile(const std::string& filename, std::ifstream& infile);
bool openOutputFile(const std::string& filename, std::ofstream& outfile);
std::string replaceAll(const std::string& line, const std::string& s1, const std::string& s2);
void processFile(std::ifstream& infile, std::ofstream& outfile, const std::string& s1, const std::string& s2);

int main(int argc, char **argv)
{
    if (!validateArgs(argc))
        return 1;

    std::string inputFilename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    std::ifstream infile;
    if (!openInputFile(inputFilename, infile))
    {
        std::cout << "File Error" << std::endl;
        return 1;
    }

    std::string outputFilename = inputFilename + ".replace";
    std::ofstream outfile;
    if (!openOutputFile(outputFilename, outfile))
    {
        std::cout << "File Error" << std::endl;
        return 1;
    }

    processFile(infile, outfile, s1, s2);

    infile.close();
    outfile.close();
    return 0;
}

bool validateArgs(int argc)
{
    if (argc != 4)
    {
        std::cout << "Invalid Input" << std::endl;
        return false;
    }
    return true;
}

bool openInputFile(const std::string &filename, std::ifstream &infile)
{
    infile.open(filename.c_str());
    return infile.is_open();
}

bool openOutputFile(const std::string &filename, std::ofstream &outfile)
{
    outfile.open(filename.c_str());
    return outfile.is_open();
}

std::string replaceAll(const std::string &line, const std::string &s1, const std::string &s2)
{
    std::string result = line;
    std::string::size_type pos = 0;
    while ((pos = result.find(s1, pos)) != std::string::npos)
    {
        result.erase(pos, s1.length());
        result.insert(pos, s2);
        pos += s2.length();
    }
    return result;
}

void processFile(std::ifstream &infile, std::ofstream &outfile, const std::string &s1, const std::string &s2)
{
    std::string text;
    while (std::getline(infile, text))
    {
        outfile << replaceAll(text, s1, s2) << std::endl;
    }
}
