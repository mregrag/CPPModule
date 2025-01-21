/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:49:47 by mregrag           #+#    #+#             */
/*   Updated: 2025/01/18 20:10:13 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <new>
#include <stdexcept>
#include <string>
#include <exception>
#include <strstream>

/*class A*/
/*{*/
/*    private:*/
/*	std::string name;*/
/*    public:*/
/*	A(const std::string& name) : name(name){*/
/*	    std::cout << " Constructor A : " << name << std::endl;*/
/*	}*/
/*	~A(){*/
/*	    std::cout << "Destructor A " << std::endl;*/
/*	}*/
/**/
/*};*/
/**/
/*void fun2()*/
/*{*/
/*    A ob2("ob2");*/
/**/
/*    throw std::runtime_error("Exception in func2");*/
/*}*/
/**/
/*void fun1()*/
/*{*/
/*    A ob1("ob1");*/
/*    fun2();*/
/*}*/
/**/
/**/
/*int main(void)*/
/*{*/
/*    try*/
/*    {*/
/*	fun1();*/
/*    }*/
/*    catch(const std::runtime_error& e)*/
/*    {*/
/*	std::cout << "Caought eception: " << e.what() << std::endl;*/
/*    }*/
/*    return (0);*/
/*}*/



void allocator(int size)
{
    int *p = new int[size];
}

int main(void)
{

    std::cout << "Hello world " << std::endl;
    try
    {
	allocator(-1);
    }
    catch(std::bad_alloc& e)
    {
	std::cout << "Error bad : " << e.what() << std::endl;
    }
    catch(std::runtime_error& e)
    {
	std::cout << "Error exception : " << e.what() << std::endl;
    }
    catch(std::exception& e)
    {
	std::cout << "Error exception : " << e.what() << std::endl;
    }
    std::cout.operator<<(1);
    return (0);
}
