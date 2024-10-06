/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 22:05:29 by mregrag           #+#    #+#             */
/*   Updated: 2024/10/05 22:43:18 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// PhoneBook.cpp
#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : count(0), oldestIndex(0) {}

void PhoneBook::addContact(const Contact& contact) {
    if (count < 8) {
        contacts[count] = contact;
        count++;
    } else {
        contacts[oldestIndex] = contact;
        oldestIndex = (oldestIndex + 1) % 8;
    }
}

void PhoneBook::addNewContact() {
    std::string fname, lname, nname, phone, secret;

    std::cout << "Enter First Name: ";
    std::cin >> fname;
    std::cout << "Enter Last Name: ";
    std::cin >> lname;
    std::cout << "Enter Nickname: ";
    std::cin >> nname;
    std::cout << "Enter Phone Number: ";
    std::cin >> phone;
    std::cout << "Enter Darkest Secret: ";
    std::cin >> secret;

    // Check if any field is empty
    if (fname.empty() || lname.empty() || nname.empty() || phone.empty() || secret.empty()) {
        std::cout << "Error: All fields must be filled. Contact not added." << std::endl;
        return;
    }

    Contact newContact;
    newContact.setContact(fname, lname, nname, phone, secret);
    addContact(newContact);

    std::cout << "Contact added successfully." << std::endl;
}

void PhoneBook::searchContact() const {
    displayAllContacts();
    
    int index;
    std::cout << "Enter the index of the contact to display: ";
    std::cin >> index;
    
    if (std::cin.fail() || index < 0 || index >= count) {
        std::cout << "Invalid index." << std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        return;
    }
    
    contacts[index].displayContact();
}

std::string truncate(const std::string& str) {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void PhoneBook::displayAllContacts() const {
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;
    
    for (int i = 0; i < count; i++) {
        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << truncate(contacts[i].getFirstName()) << "|"
                  << std::setw(10) << truncate(contacts[i].getLastName()) << "|"
                  << std::setw(10) << truncate(contacts[i].getNickname()) << std::endl;
    }
}
