/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 21:27:39 by nlouro            #+#    #+#             */
/*   Updated: 2022/12/10 08:36:14 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : AForm("ShrubberyCreationForm", 145, 45), _target(target)
{
	std::cout << "ShrubberyCreationForm constructor called with target " << this->_target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const &src ) :  AForm("ShrubberyCreationForm", 145, 45), _target(src._target) 
{
	std::cout << this->getName() << " copied." << std::endl;
	*this = src;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=( ShrubberyCreationForm const &src )
{
	//this->_target = src._target;
	( void ) src;
	std::cout << "ShrubberyCreationForm class assigned called but nothing to assign. const attributes can't be re-assigned\n";
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if ( !this->isSigned() )
		throw FormNotSignedException();
	else if ( executor.getGrade() >= this->getGrade4Exec() )
		throw GradeTooHighException();
	else
		std::cout << "ASCII trees... " << std::endl;
}
