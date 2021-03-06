/*
** VMParser.cpp for  in /home/vaga/Projects/tek2/abstractVM
** 
** Made by fabien casters
** Login   <fabien.casters@epitech.eu>
** 
** Started on  Fri Feb 15 12:48:38 2013 fabien casters
** Last update Wed Feb 27 11:48:32 2013 maxime ginters
*/

#include "VMParser.h"

VMParser::VMParser()
    : _lines(), _path()
{
}

VMParser::~VMParser()
{
}

char VMParser::_cleanLine(char c)
{
    if (c == '\t' || c == '(' || c == ')')
    {
        return ' ';
    }
    return c;
}

void VMParser::addLine(const std::string &line)
{
    std::string str = line;
    size_t pos;

    std::transform(str.begin(), str.end(), str.begin(), (int (*)(int))VMParser::_cleanLine);
    pos = str.find(";");
    if (pos != std::string::npos)
        str.erase(pos);
    _lines.push_back(str);
}

void VMParser::addLinesFromFile(std::string const& path)
{
    std::ifstream file(path.c_str());
    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line))
            addLine(line);
    }
    else
        throw Exception::ExceptFileNotFound();
}

void VMParser::addLinesFromIO()
{
    std::string line;

    while (std::getline(std::cin, line))
    {
        if (line.find(";;") != std::string::npos)
            return;
        std::cout << "test" << std::endl;
        addLine(line);
    }
}

void VMParser::setPath(std::string const& path)
{
    _path = path;
}

std::vector<std::string> const &VMParser::getLines()
{
    return _lines;
}

void VMParser::exec()
{
    if (_path.empty())
        addLinesFromIO();
    else
        addLinesFromFile(_path);
}
