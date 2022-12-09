/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 09:58:44 by nlouro            #+#    #+#             */
/*   Updated: 2022/12/09 19:40:50 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm( std::string name, size_t grade_4sign, size_t grade_4exec ) : _name(name), _grade_4sign(grade_4sign), _grade_4exec(grade_4exec), _signed(false)
{
	std::cout << this->_name << " (AForm) created with grade for sign " << this->_grade_4sign << " and grade for exec " << this->_grade_4exec << std::endl;
}

AForm::~AForm( void )
{
	std::cout << this->_name << " (AForm) destructor called." << std::endl;
}

AForm::AForm( const AForm &src ) : _name(src._name), _grade_4sign(src._grade_4sign), _grade_4exec(src._grade_4exec)
{
	std::cout << this->_name << " (AForm) copied." << std::endl;
}

AForm & AForm::operator=( const AForm &src )
{
	//this->_name = src.getName();
	//this->_grade_4sign = src._grade_4sign;
	this->_signed = src._signed;
	std::cout << "AForm class partially assigned. const name and grades can't be re-assigned\n";
	return *this;
}

std::string	AForm::getName( void ) const
{
	return (this->_name);
}

size_t	AForm::getGrade4Sign( void ) const
{
	return this->_grade_4sign;
}

std::string	AForm::getGrade4SignAsString( void ) const
{
	return std::to_string( this->getGrade4Sign() );
}

bool	AForm::beSigned( Bureaucrat &b )
{
	if ( this->_grade_4sign > b.getGrade() )
		return true;
	else
		//return false;
		throw AForm::GradeTooHighException();
}

size_t	AForm::getGrade4Exec( void ) const
{
	return this->_grade_4exec;
}

std::string	AForm::getGrade4ExecAsString( void ) const
{
	return std::to_string( this->getGrade4Exec() );
}

std::ostream & operator<<( std::ostream &ostream, AForm const &f)
{
	return ostream << f.getName() << " requires grade for sign >" << f.getGrade4SignAsString() << " for signature";
}

const char* AForm::GradeTooHighException::what( void ) const throw()
{
	return "AForm grade too high";
}

const char* AForm::GradeTooLowException::what( void ) const throw()
{
	return "AForm grade too low";
}
