/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 09:58:44 by nlouro            #+#    #+#             */
/*   Updated: 2022/12/10 08:52:01 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form( std::string name, size_t grade_4sign, size_t grade_4exec ) : _name(name), _grade_4sign(grade_4sign), _grade_4exec(grade_4exec), _signed(false)
{
	std::cout << this->_name << " (Form) created with grade for sign " << this->_grade_4sign << " and grade for exec " << this->_grade_4exec << std::endl;
}

Form::~Form( void )
{
	std::cout << this->_name << " (Form) destructor called." << std::endl;
}

Form::Form( const Form &src ) : _name(src._name), _grade_4sign(src._grade_4sign), _grade_4exec(src._grade_4exec)
{
	std::cout << this->_name << " (Form) copied." << std::endl;
}

Form & Form::operator=( const Form &src )
{
	//this->_name = src.getName();
	//this->_grade_4sign = src._grade_4sign;
	this->_signed = src._signed;
	std::cout << "Form class partially assigned. const name and grades can't be re-assigned\n";
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
	{
		this->_signed = true;
		return true;
	}
	else
		//return false;
		throw Form::GradeTooHighException();
}

size_t	Form::getGrade4Exec( void ) const
{
	return this->_grade_4exec;
}

std::string	Form::getGrade4ExecAsString( void ) const
{
	return std::to_string( this->getGrade4Exec() );
}

std::ostream & operator<<( std::ostream &ostream, Form const &f)
{
	return ostream << f.getName() << " requires grade for sign >" << f.getGrade4SignAsString() << " for signature";
}

const char* Form::GradeTooHighException::what( void ) const throw()
{
	return "Form grade too high";
}

const char* Form::GradeTooLowException::what( void ) const throw()
{
	return "Form grade too low";
}
