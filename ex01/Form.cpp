/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 09:58:44 by nlouro            #+#    #+#             */
/*   Updated: 2022/12/09 17:35:35 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form( std::string name, size_t grade ) : _name(name), _grade(grade), _signed(false)
{
	std::cout << this->_name << " (Form) created with grade " << this->_grade << std::endl;
}

Form::~Form( void )
{
	std::cout << this->_name << " (Form) destructor called." << std::endl;
}

Form::Form( const Form &src ) : _name(src._name), _grade(src._grade)
{
	std::cout << this->_name << " (Form) copied." << std::endl;
}

Form & Form::operator=( const Form &src )
{
	//this->_name = src.getName();
	//this->_grade = src._grade;
	this->_signed = src._signed;
	std::cout << "Form class partially assigned. const name and grade can't be re-assigned\n";
	return *this;
}

std::string	Form::getName( void ) const
{
	return (this->_name);
}

size_t	Form::getGrade( void ) const
{
	return this->_grade;
}

std::string	Form::getGradeAsString( void ) const
{
	return std::to_string( this->getGrade() );
}


std::ostream & operator<<( std::ostream &ostream, Form const &b)
{
	return ostream << b.getName() << " bureaucrat grade " << b.getGradeAsString() << "\n";
}

const char* Form::GradeTooHighException::what( void ) const throw()
{
	return "Grade too high";
}

const char* Form::GradeTooLowException::what( void ) const throw()
{
	return "Grade too low";
}
