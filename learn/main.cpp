/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 22:14:42 by mregrag           #+#    #+#             */
/*   Updated: 2024/10/22 01:05:57 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Student
{
	private:
		std::string name;
		int age;
		static int totalStudents;
	public:
		Student(const std::string& name, int age);
		~Student();

		//static member function 
		static int getToatalStudends();

		//static member function 
		static void schoolName();

		//regular member function
		void displayInfo();
};

int Student::totalStudents = 0;

Student::Student(const std::string& name, int age): name(name), age(age)
{
	totalStudents++;
}

Student::~Student()
{
}

int	Student::getToatalStudends(void)
{
	return (Student::totalStudents);
}


void	Student::schoolName(void)
{
	std::cout << "1337" << std::endl;
}

void	Student::displayInfo(void)
{
	std::cout << "Name : " << this->name << std::endl;
	std::cout << "Age : " << this->age << std::endl;
}

int main (void)
{
	Student s1("mohamed", 25);
	Student s2("amal", 24);
	Student s3("regrag", 23);
	Student s4("azib", 22);


	std::cout << "Total Students : " <<  Student::getToatalStudends() << std::endl;
	std::cout << "School : ";
	Student::schoolName();
	
	return (0);
}
