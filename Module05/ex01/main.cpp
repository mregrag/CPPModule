/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:23:56 by mregrag           #+#    #+#             */
/*   Updated: 2024/12/29 19:45:03 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    try 
    {
        Bureaucrat bob("Bob", 50);
        Form taxForm("Tax Form", 75, 50);
        
        std::cout << bob << std::endl;
        std::cout << taxForm << std::endl;

        bob.signForm(taxForm);
        std::cout << taxForm << std::endl;

        Form invalidForm("Invalid Form", 0, 151);
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    /*try*/
    /*{*/
    /*    // Test signing with insufficient grade*/
    /*    Bureaucrat lowRankBob("Low Bob", 100);*/
    /*    Form restrictedForm("Restricted Form", 50, 25);*/
    /**/
    /*    lowRankBob.signForm(restrictedForm);*/
    /*}*/
    /*catch (std::exception& e)*/
    /*{*/
    /*    std::cerr << "Exception caught: " << e.what() << std::endl;*/
    /*}*/
    /**/
    return (0);
}
