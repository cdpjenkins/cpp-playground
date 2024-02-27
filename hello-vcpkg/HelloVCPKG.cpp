#include <fmt/core.h>
#include <boost/algorithm/string.hpp>
#include <boost/regex.hpp>


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
#include <string>
#include <vector>

int main()
{
    fmt::print("Hello World!\n");


    std::string string_to_split{"comma,separated,values,and,shizzle"};

    std::vector<std::string> toks;

    boost::algorithm::split(toks, string_to_split, boost::is_any_of(","));

    for (auto&& tok : toks) {
        std::cout << tok << std::endl;
    }

    std::cout << "Time for some regex fun!" << std::endl;
    std::string input{"first second"};
    boost::regex re{"^([a-z]+) ([a-z]+)$"};
    boost::smatch matches;
    if (boost::regex_match(input, matches, re, boost::match_extra)) {
        for (int i = 0; i < matches.size(); i++) {
            std::cout << matches[i] << std::endl;
        }
    } else {
        std::cout << "sucks to be you... no match" << std::endl;
    }

    return 0;
}

