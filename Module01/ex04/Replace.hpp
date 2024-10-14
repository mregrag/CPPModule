/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:23:01 by mregrag           #+#    #+#             */
/*   Updated: 2024/10/10 18:23:26 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
# define REPLACE_HPP

#include <string>

class Replace
{
	private:
		std::string filename;
		std::string s1;
		std::string s2;

		std::string replaceLine(const std::string& line) const;

	public:
		Replace(const std::string& filename, const std::string& s1, const std::string& s2);
		void execute() const;
};

#endif
