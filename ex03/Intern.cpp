/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 09:58:44 by nlouro            #+#    #+#             */
/*   Updated: 2022/12/16 11:25:51 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern created" << std::endl;
}

Intern::~Intern( void )
{
	std::cout << "Intern destructor called." << std::endl;
}

Intern::Intern( const Intern &src )
{
	std::cout << "Intern copied." << std::endl;
}

Intern & Intern::operator=( const Intern &src )
{
	std::cout << "Intern assigned.\n";
	return *this;
}

std::string	Intern::getName( void ) const
{
	return "" ;
}

std::string	Intern::getGradeAsString( void ) const
{
	return "" ;
}

AForm	*Intern::makeForm( std::string name, std::string target )
{
	std::string	form_names[] = [ "ShrubberyCreation", "RobotomyRequest", "PresidentialPardon" ];
	for ( int i = 0; i < 3; i++ )
	{
		if ( form == form_names[i] )
		{
			std::cout << "Intern creates form " << name << " with target " << target << std::endl;
			//TODO
			//return 
		}
	}
	std::cout << "ERROR: Intern can not create form " << name << std::endl;
	return NULL;
}

std::ostream & operator<<( std::ostream &ostream, Intern const &b)
{
	return ostream << "Intern has no name nor grade\n";
}

