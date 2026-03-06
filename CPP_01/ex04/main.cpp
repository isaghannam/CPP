/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 16:11:34 by ighannam          #+#    #+#             */
/*   Updated: 2026/03/05 17:35:55 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Wrong number of args.\nUsage: ./replace <filename> <string1> <string2>\n";
        return (1);
    }
    std::ifstream fd_file_input(argv[1]);
    if (!fd_file_input)
    {
        std::cout << "Error opening input file.\n";
        return (1);
    }
    std::string new_file = std::string(argv[1]) + ".replace";
    std::ofstream replaced_file(new_file.c_str());
    if (!replaced_file.is_open())
    {
        std::cout << "Error creating or opening output file.\n";
        return (1);
    }
    std::string line;
    std::string str1 = argv[2];
    std::string str2 = argv[3];
    size_t pos;
    while (getline(fd_file_input, line))
    {
        pos = 0;
        while ((pos = line.find(str1, pos)) != std::string::npos)
        {
            if (str1.empty())
            {
                replaced_file << line << "\n";
                break;
            }
            line.erase(pos, str1.length());
            line.insert(pos, str2);
            pos = pos + str2.length();
        }
        if (!str1.empty())
            replaced_file << line << "\n";
    }
    return (0);
}
