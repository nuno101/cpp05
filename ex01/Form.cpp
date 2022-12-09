/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 09:58:44 by nlouro            #+#    #+#             */
/*   Updated: 2022/12/09 19:17:43 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form( std::string name, size_t grade_4sign ) : _name(name), _grade_4sign(grade_4sign), _signed(false)
{
	std::cout << this->_name << " (Form) created with grade " << this->_grade_4sign << std::endl;
}

Form::~Form( void )
{
	std::cout << this->_name << " (Form) destructor called." << std::endl;
}

Form::Form( const Form &src ) : _name(src._name), _grade_4sign(src._grade_4sign)
{
	std::cout << this->_name << " (Form) copied." << std::endl;
}

Form & Form::operator=( const Form &src )
{
	//this->_name = src.getName();
	//this->_grade_4sign = src._grade_4sign;
	this->_signed = src._signed;
	std::cout << "Form class partially assigned. const name and grade can't be re-assigned\n";
	return *this;
}

std::string	Form::getName( void ) const
{
	return (this->_name);
}

size_t	Form::getGrade4Sign( void ) const
{
	return this->_grade_4sign;
}

std::string	Form::getGrade4SignAsString( void ) const
{
	return std::to_string( this->getGrade4Sign() );
}

bool	Form::beSigned( Bureaucrat &b )
{
	if ( this->_grade_4sign > b.getGrade() )
		return true;
	else
		//return false;
		throw Form::GradeTooHighException();
}


std::ostream & operator<<( std::ostream &ostream, Form const &f)
{
	return ostream << f.getName() << " requires grade >" << f.getGrade4SignAsString() << " for signature";
}

const char* Form::GradeTooHighException::what( void ) const throw()
{
	return "Form grade too high";
}

const char* Form::GradeTooLowException::what( void ) const throw()
{
	return "Form grade too low";
}
