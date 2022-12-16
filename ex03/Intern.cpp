/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 09:58:44 by nlouro            #+#    #+#             */
/*   Updated: 2022/12/16 11:48:16 by nlouro           ###   ########.fr       */
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

ssize_t	get_form_id( std::string form_name )
{
	std::string	form_names[] = [ "shrubbery creation", "robotomy request", "presidential pardon" ];

	for ( int i = 0; i < 3; i++ )
	{
		if ( form_name.compare( form_names[i] ))
			return i ;
	}
	return -1 ;
}

AForm	*Intern::makeForm( std::string name, std::string target )
{
	AForm	*new_form;
	size_t	form_id;

	form_id = get_form_id( name );
	switch ( form_id )
	{
		case 0:
			new_form = new ShrubberyCreationForm( target );
			std::cout << "Intern creates form for " << name << " with target " << target << std::endl;
			break;
		case 1:
			new_form = new RobotomyRequestForm( target );
			std::cout << "Intern creates form for " << name << " with target " << target << std::endl;
			break;
		case 2:
			new_form = new PresidentialPardonForm( target );
			std::cout << "Intern creates form for " << name << " with target " << target << std::endl;
			break;
		default:
			new_form = NULL;
			std::cout << "ERROR: Intern can not create form " << name << std::endl;
	}
	return new_form ;
}

std::ostream & operator<<( std::ostream &ostream, Intern const &b)
{
	return ostream << "Intern has no name nor grade\n";
}

