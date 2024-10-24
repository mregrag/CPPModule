/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 22:06:50 by mregrag           #+#    #+#             */
/*   Updated: 2024/10/24 01:21:28 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Contact.hpp
#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
	private:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string darkestSecret;
	public:
		Contact();
		~Contact();

		void	setFirstName(const std::string& fname);
		void	setLastName(const std::string& fname);
		void	setNickname(const std::string& nname);
		void	setPhoneNumber(const std::string& phone);
		void	setDarkestSecret(const std::string& secret);

		std::string getFirstName(void) const;
		std::string getLastName(void) const;
		std::string getNickname(void) const;
		void displayContact(void) const;
};

#endif
