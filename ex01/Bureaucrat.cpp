/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 09:58:44 by nlouro            #+#    #+#             */
/*   Updated: 2022/12/16 12:04:20 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( std::string name, size_t grade ) : _name(name), _grade(grade)
{
	if ( _grade > 150 )
		throw GradeTooLowException();
	else if ( _grade < 1 )
		throw GradeTooHighException();
	std::cout << this->_name << " (Bureaucrat) created with grade " << this->_grade << std::endl;
}

Bureaucrat::~Bureaucrat( void )
{
	std::cout << this->_name << " (Bureaucrat) destructor called." << std::endl;
}

Bureaucrat::Bureaucrat( const Bureaucrat &src ) : _name(src._name), _grade(src._grade)
{
	std::cout << this->_name << " (Bureaucrat) copied." << std::endl;
}

Bureaucrat & Bureaucrat::operator=( const Bureaucrat &src )
{
	//this->_name = src.getName();
	this->_grade = src._grade;
	std::cout << "Bureaucrat class partially assigned. const name can't be re-assigned\n";
	return *this;
}

std::string	Bureaucrat::getName( void ) const
{
	return (this->_name);
}

size_t	Bureaucrat::incrementGrade( void )
{
	std::cout << "incrementGrade() called on: " << *this ;
	if ( this->_grade - 1 > 0 )
		this->_grade--;
	else
		throw GradeTooHighException(); 
	return this->_grade;
}

size_t	Bureaucrat::decrementGrade( void )
{
	std::cout << "decrementGrade() called on: " << *this << std::endl;
	if ( this->_grade + 1 < 150 )
		this->_grade++;
	else
		throw GradeTooLowException(); 
	return this->_grade;
}

size_t	Bureaucrat::getGrade( void ) const
{
	return this->_grade;
}

bool	Bureaucrat::signForm( Form &f )
{
	std::cout << this->getName() << " to sign " << f << std::endl;
	try
	{
		f.beSigned( *this );
		std::cout << this->getName() << " signed " << f.getName() << std::endl;
		return true;
	}
	catch ( Form::GradeTooHighException & e )
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
		std::cout << this->getName() << " couldn't sign " << f.getName() << " because his grade is not suficient to sign the form!\n";
	}
	return false;
}

std::string	Bureaucrat::getGradeAsString( void ) const
{
	return std::to_string( this->getGrade() );
}


std::ostream & operator<<( std::ostream &ostream, Bureaucrat const &b)
{
	return ostream << b.getName() << " bureaucrat grade " << b.getGradeAsString() << "\n";
}

const char* Bureaucrat::GradeTooHighException::what( void ) const throw()
{
	return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what( void ) const throw()
{
	return "Grade too low";
}
