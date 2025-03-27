/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 20:07:44 by mregrag           #+#    #+#             */
/*   Updated: 2025/01/19 17:20:38 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery_Form", 145, 137), target("Default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("Shrubbery_Form", 145, 137), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& rhs) : AForm(rhs), target(rhs.target)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
    if (this != &rhs)
    {
        AForm::operator=(rhs);
        this->target = rhs.target;
    }
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() 
{
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
    this->checkExecutability(executor);
    std::string filename = target + "_shrubbery";
    std::ofstream outFile(filename.c_str());
    
    if (!outFile.is_open())
        throw std::runtime_error("Cannot create output file");

    outFile << "       *" << std::endl;
    outFile << "      ***" << std::endl;
    outFile << "     *****" << std::endl;
    outFile << "    *******" << std::endl;
    outFile << "   *********" << std::endl;
    outFile << "  ***********" << std::endl;
    outFile << " *************" << std::endl;
    outFile << "      |||" << std::endl;
    outFile << "      |||" << std::endl;
    outFile << "      |||" << std::endl;
    outFile << "      |||" << std::endl;
    outFile << "    ~~~~~~~" << std::endl;

    outFile.close();
}
