/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scope.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 01:14:49 by mregrag           #+#    #+#             */
/*   Updated: 2024/10/22 01:51:44 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int x = 10;  // Global variable

void display()
{
	int x = 5;  // Local variable
	std::cout << "Local x: " << x << std::endl;          // Outputs 5
	std::cout << "Global x: " << ::x << std::endl;      // Outputs 10
}

namespace MyNamespac{

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

	class string
	{
		public:
			void	displayinfo()
			{
				std::cout << "my string" << std::endl;
			}
	};

}
class my_class
{
	public:
		std::cout << "my string" << std::endl;
};

int main(void)
{
	int	x = 3;
	MyNamespac::Student s1("name", 25);
	std::string s2("hello");
	/*display();*/
	std::cout << ::x << std::endl;
	std::cout << x << std::endl;

	return 0;
}

