/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplace.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 21:17:44 by mregrag           #+#    #+#             */
/*   Updated: 2024/12/06 16:45:49 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileReplace.hpp"
#include <iostream>
#include <fstream>

FileReplace::FileReplace(const std::string &filename) : filename(filename)
{
}


std::string FileReplace::swapstr(std::string &line, const std::string &s1, const std::string &s2)
{
	size_t pos = 0;

	while ((pos = line.find(s1, pos)) != std::string::npos)
	{
		line.erase(pos, s1.length());
		line.insert(pos, s2);
		pos += s2.length();
	}
	return (line);
}


bool FileReplace::replacestr(const std::string &s1, const std::string &s2)
{
	if (s1.empty())
	{
		 std::cout << "Error: string (s1) cannot be empty." << std::endl;
		return (false);
	}

	std::ifstream in_file(filename.c_str());

	if (!in_file.is_open())
	{
		std::cout<< "Error: Could not open file " << filename << std::endl;
		return (false);
	}

	std::string out_file = filename + ".replace";
	std::ofstream output_file(out_file.c_str());

	if (!output_file.is_open())
	{
		std::cout << "Error: Could not create output file " << out_file << std::endl;
		in_file.close();
		return (false);
	}

	std::string line;
	while (std::getline(in_file, line))
	{
		output_file << swapstr(line, s1, s2);
		if (!in_file.eof())
			output_file << '\n';
	}
	in_file.close();
	output_file.close();
	return (true);
}
