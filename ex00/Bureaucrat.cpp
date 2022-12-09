/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 09:58:44 by nlouro            #+#    #+#             */
/*   Updated: 2022/12/09 16:13:24 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( std::string name, size_t grade ) : _name(name), _grade(grade)
{
	std::cout << this->_name << " (Bureaucrat) created with grade " << this->_grade << std::endl;
}

Bureaucrat::~Bureaucrat( void )
{
	std::cout << this->_name << " (Bureaucrat) destructor called." << std::endl;
	//std::cout << " (Bureaucrat) destructor called." << std::endl;
}

Bureaucrat::Bureaucrat( const Bureaucrat &src ) : _name(src._name), _grade(src._grade)
{
	std::cout << this->_name << " (Bureaucrat) copied." << std::endl;
}

Bureaucrat & Bureaucrat::operator=( const Bureaucrat &src )
{
	//this->_name = src.getName();
	//this->_grade = src._grade;
	( void ) src;
	std::cout << "Bureaucrat class const values can't be re-assigned\n";
	return *this;
}

std::string	Bureaucrat::getName( void ) const
{
	return (this->_name);
}

size_t	Bureaucrat::incrementGrade( void )
{
	this->_grade--;
	return this->_grade;
}

size_t	Bureaucrat::decrementGrade( void )
{
	//std::cout << this << std::endl;
	this->_grade++;
	return this->_grade;
}

size_t	Bureaucrat::getGrade( void ) const
{
	return this->_grade;
}

std::string	Bureaucrat::getGradeAsString( void ) const
{
	return std::to_string(this->getGrade());
}


std::ostream & operator<<( std::ostream &ostream, Bureaucrat const &b)
{
	return ostream << b.getName() << " bureaucrat grade " << b.getGradeAsString() << ".\n";
}

const char* Bureaucrat::GradeTooHighException::what( void ) const throw()
{
	return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what( void ) const throw()
{
	return "Grade too low";
}
