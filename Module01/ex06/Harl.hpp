/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 06:25:22 by mregrag           #+#    #+#             */
/*   Updated: 2024/10/14 06:32:24 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <string>
#include <iostream>

class Harl 
{
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
		int  getLevelIndex(const std::string &level);
	public:
		void complain(const std::string& level);
};

#endif
