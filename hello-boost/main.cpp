#include <boost/regex.hpp>
#include <iostream>
#include <string>

int main()
{
    std::string line;
    boost::regex pat( "^hello: *(\\d*)" );
    boost::regex exit_pattern("exit");

    while (std::cin)
    {
        std::getline(std::cin, line);
        boost::smatch matches;
        if (boost::regex_match(line, matches, pat)) {
            std::cout << matches[1].str() << std::endl;
        }

        if (boost::regex_match(line, exit_pattern)) {
            break;
        }
    }
}
