/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 21:27:39 by nlouro            #+#    #+#             */
/*   Updated: 2022/12/10 21:17:23 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( std::string target ) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm constructor called with target " << this->_target << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const &src ) :  AForm("PresidentialPardonForm", 25, 5), _target(src._target) 
{
	std::cout << this->getName() << " copied." << std::endl;
	*this = src;
}

PresidentialPardonForm & PresidentialPardonForm::operator=( PresidentialPardonForm const &src )
{
	//this->_target = src._target;
	( void ) src;
	std::cout << "PresidentialPardonForm class assigned called but nothing to assign. const attributes can't be re-assigned\n";
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if ( !this->isSigned() )
		throw FormNotSignedException();
	else if ( executor.getGrade() >= this->getGrade4Exec() )
		throw GradeTooHighException();
	else
		std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
