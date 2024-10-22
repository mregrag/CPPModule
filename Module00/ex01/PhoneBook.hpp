/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 22:05:58 by mregrag           #+#    #+#             */
/*   Updated: 2024/10/21 06:20:14 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>

class PhoneBook
{
	private:
		Contact contacts[8];
		std::string getInfo(const std::string& prompt, int info) const;
		std::string Truncate(const std::string& str) const;
		bool isDigitsOnly(const std::string& str) const;
		int count;
		int index;

	public:
		PhoneBook();
		~PhoneBook();
		void addContact();
		void searchContact() const;
		void displayAllContacts() const;
};

#endif
