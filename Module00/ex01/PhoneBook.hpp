/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 22:05:58 by mregrag           #+#    #+#             */
/*   Updated: 2024/10/05 22:45:15 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// PhoneBook.hpp
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
	private:
		Contact contacts[8];
		int count;
		int oldestIndex;

	public:
		PhoneBook();
		void addContact(const Contact& contact);
		void addNewContact();
		void searchContact() const;
		void displayAllContacts() const;
};

#endif
