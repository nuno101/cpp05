/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 21:27:39 by nlouro            #+#    #+#             */
/*   Updated: 2022/12/16 12:47:27 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( std::string target ) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm constructor called with target " << this->_target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const &src ) :  AForm("RobotomyRequestForm", 72, 45), _target(src._target) 
{
	std::cout << this->getName() << " copied." << std::endl;
	*this = src;
}

RobotomyRequestForm & RobotomyRequestForm::operator=( RobotomyRequestForm const &src )
{
	//this->_target = src._target;
	( void ) src;
	std::cout << "RobotomyRequestForm class assigned called but nothing to assign. const attributes can't be re-assigned\n";
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	static int i = 0;
	if ( !this->isSigned() )
		throw FormNotSignedException();
	else if ( executor.getGrade() >= this->getGrade4Exec() )
		throw GradeTooHighException();
	else
	{
		std::cout << "Some drilling noises..." << std::endl;
		if ( i % 2 )
			std::cout << this->_target << " has been robotomized successfully." << std::endl;
		else
			std::cout << this->_target << " robotomy failed." << std::endl;
		i++;
	}
}
