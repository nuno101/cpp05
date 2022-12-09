/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 09:58:44 by nlouro            #+#    #+#             */
/*   Updated: 2022/12/09 18:56:30 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm( std::string name, size_t grade ) : _name(name), _grade(grade), _signed(false)
{
	std::cout << this->_name << " (AForm) created with grade " << this->_grade << std::endl;
}

AForm::~AForm( void )
{
	std::cout << this->_name << " (AForm) destructor called." << std::endl;
}

AForm::AForm( const AForm &src ) : _name(src._name), _grade(src._grade)
{
	std::cout << this->_name << " (AForm) copied." << std::endl;
}

AForm & AForm::operator=( const AForm &src )
{
	//this->_name = src.getName();
	//this->_grade = src._grade;
	this->_signed = src._signed;
	std::cout << "AForm class partially assigned. const name and grade can't be re-assigned\n";
	return *this;
}

std::string	AForm::getName( void ) const
{
	return (this->_name);
}

size_t	AForm::getGrade( void ) const
{
	return this->_grade;
}

std::string	AForm::getGradeAsString( void ) const
{
	return std::to_string( this->getGrade() );
}

bool	AForm::beSigned( Bureaucrat &b )
{
	if ( this->_grade > b.getGrade() )
		return true;
	else
		//return false;
		throw AForm::GradeTooHighException();
}


std::ostream & operator<<( std::ostream &ostream, AForm const &f)
{
	return ostream << f.getName() << " requires grade >" << f.getGradeAsString() << " for signature";
}

const char* AForm::GradeTooHighException::what( void ) const throw()
{
	return "AForm grade too high";
}

const char* AForm::GradeTooLowException::what( void ) const throw()
{
	return "AForm grade too low";
}
