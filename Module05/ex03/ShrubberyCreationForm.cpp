/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 20:07:44 by mregrag           #+#    #+#             */
/*   Updated: 2025/01/07 21:43:17 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreation", 145, 137), target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreation", 145, 137), target(target)
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

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    // First, check if execution is allowed by calling the parent class method
    // This will throw an exception if:
    // 1. The form is not signed
    // 2. The executor's grade is too low
    checkExecutability(executor);
    
    // If we get past checkExecutionRequirements, we can proceed with the actual execution
    std::string filename = target + "_shrubbery";
    std::ofstream outFile(filename.c_str());
    
    if (!outFile.is_open()) {
        throw std::runtime_error("Cannot create output file");
    }

    // Draw ASCII tree
    outFile << "          &&& &&  & && " << std::endl;
    outFile << "      && &\\/&\\|& ()|/ @, &&" << std::endl;
    outFile << "      &\\/(/&/&||/& /_/)_&/_&" << std::endl;
    outFile << "   &() &\\/&|()|/&\\/ '%\" & ()" << std::endl;
    outFile << "  &_\\_&&_\\ |& |&&/&__%_/_& &&" << std::endl;
    outFile << "&&   && & &| &| /& & % ()& /&&" << std::endl;
    outFile << " ()&_---()&\\&\\|&&-&&--%---()~" << std::endl;
    outFile << "     &&     \\|||" << std::endl;
    outFile << "             |||" << std::endl;
    outFile << "             |||" << std::endl;
    outFile << "             |||" << std::endl;
    outFile << "       , -=-~  .-^- _" << std::endl;

    outFile.close();
}

