/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:30:07 by mregrag           #+#    #+#             */
/*   Updated: 2024/10/14 05:41:56 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"
#include <iostream>
#include <fstream>

Replace::Replace(const std::string& filename, const std::string& s1, const std::string& s2) : filename(filename), s1(s1), s2(s2) {}

std::string Replace::replaceLine(const std::string& line) const
{
		std::string result = line;
		size_t pos = 0;
		while ((pos = result.find(s1, pos)) != std::string::npos)
		{
			result = result.substr(0, pos) + this->s2 + result.substr(pos + this->s1.length());
			pos += this->s2.length();
		}
		return (result);
	}

void Replace::execute() const 
{
	if (this->s1.empty())
	{
		std::cerr << "Error: s1 cannot be an empty string." << std::endl;
		return;
	}
	std::ifstream inFile(this->filename);
	if (!inFile)
	{
		std::cerr << "Error: Unable to open input file." << std::endl;
		return;
	}

	std::string outFilename = this->filename + ".replace";
	std::ofstream outFile(outFilename);
	if (!outFile)
	{
		std::cerr << "Error: Unable to create output file." << std::endl;
		return;
	}
	std::string line;
	while (std::getline(inFile, line))
		outFile << replaceLine(line) << std::endl;
	inFile.close();
	outFile.close();
	std::cout << "Replacement complete. Output written to " << outFilename << std::endl;
}
