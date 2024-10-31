/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplace.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 21:03:16 by mregrag           #+#    #+#             */
/*   Updated: 2024/10/30 12:31:35 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILEREPLACE_HPP
#define FILEREPLACE_HPP

#include <string>

class FileReplace
{

	private:
		std::string filename;
		std::string swapstr(std::string &line, const std::string &s1, const std::string &s2);
	public:
		FileReplace(const std::string &filename);
		bool replacestr(const std::string &s1, const std::string &s2);
};

#endif

