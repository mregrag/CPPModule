/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 22:06:15 by mregrag           #+#    #+#             */
/*   Updated: 2024/10/05 22:42:45 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Contact.hpp
#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

public:
    Contact();
    void setContact(const std::string& fname, const std::string& lname, 
                    const std::string& nname, const std::string& phone, 
                    const std::string& secret);
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;
    void displayContact() const;
};

#endif
