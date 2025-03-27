/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 23:55:50 by mregrag           #+#    #+#             */
/*   Updated: 2025/02/13 17:51:09 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include "Array.hpp"

class Person
{
    private:
	std::string name;
	int age;

    public:
	Person() : name("Unknown"), age(0) {}

	Person(const std::string& name, int age) : name(name), age(age) {}

	Person(const Person& rhs) : name(rhs.name), age(rhs.age) {}

	Person& operator=(const Person& rhs)
	{
	    if (this != &rhs)
	    {
		name = rhs.name;
		age = rhs.age;
	    }
	    return (*this);
	}
	~Person() {}
	std::string getName() const { return name; }
	int getAge() const { return age; }

};

std::ostream& operator<<(std::ostream& lhs, const Person& person)
{
    lhs << "Person(Name: " << person.getName() << ", Age: " << person.getAge() << ")";
    return (lhs);
}

int main(void)
{
    try
    {
	Array<int> intArray(3);
	intArray[0] = 10;
	intArray[1] = 20;
	intArray[2] = 30;

	std::cout << "intArray: ";
	for (unsigned int i = 0; i < intArray.size(); ++i)
	    std::cout << intArray[i] << " ";
	std::cout << std::endl;

	Array<Person> personArray(2);
	std::cout << personArray[0] << std::endl;
	std::cout << personArray[1] << std::endl;
	personArray[0] = Person("mohamed", 25);
	personArray[1] = Person("yasin", 28);

	std::cout << "personArray: ";
	for (unsigned int i = 0; i < personArray.size(); ++i)
	    std::cout << personArray[i] << " ";
	std::cout << std::endl;

	Array<Person> copiedPersonArray(personArray);
	std::cout << "copiedPersonArray: ";
	for (unsigned int i = 0; i < copiedPersonArray.size(); ++i)
	    std::cout << copiedPersonArray[i] << " ";
	std::cout << std::endl;

	Array<Person> assignedPersonArray;
	assignedPersonArray = personArray;
	std::cout << "assignedPersonArray: ";
	for (unsigned int i = 0; i < assignedPersonArray.size(); ++i)
	    std::cout << assignedPersonArray[i] << " ";
	std::cout << std::endl;

    }
    catch (const std::exception& e)
    {
	std::cout << e.what() << std::endl;
    }

    return (0);
}
