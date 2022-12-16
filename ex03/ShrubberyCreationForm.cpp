/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 21:27:39 by nlouro            #+#    #+#             */
/*   Updated: 2022/12/16 12:42:56 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : AForm("ShrubberyCreationForm", 145, 45), _target(target)
{
	std::cout << "ShrubberyCreationForm constructor called with target " << this->_target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const &src ) :  AForm("ShrubberyCreationForm", 145, 45), _target(src._target) 
{
	std::cout << this->getName() << " copied." << std::endl;
	*this = src;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=( ShrubberyCreationForm const &src )
{
	//this->_target = src._target;
	( void ) src;
	std::cout << "ShrubberyCreationForm class assigned called but nothing to assign. const attributes can't be re-assigned\n";
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if ( !this->isSigned() )
		throw FormNotSignedException();
	else if ( executor.getGrade() >= this->getGrade4Exec() )
		throw GradeTooHighException();
	else
		this->_print_to( _target );
}

void    ShrubberyCreationForm::_print_to( std::string const filename ) const
{
	std::ofstream	out_file;
	out_file.open ( filename + "_shrubbery", std::ios::out );
	//out_file << 'ASCII trees... ' << std::endl;
	// ASCII art from https://www.asciiart.eu/holiday-and-events/christmas/trees
	std::string ascii_tree =
"         |\n"
"        -+-\n"
"         A\n"
"        /=\\               /\\  /\\    ___  _ __  _ __ __    __ \n"
"      i/ O \\i            /  \\/  \\  / _ \\| '__|| '__|\\ \\  / /\n"
"      /=====\\           / /\\  /\\ \\|  __/| |   | |    \\ \\/ /\n"
"      /  i  \\           \\ \\ \\/ / / \\___/|_|   |_|     \\  /\n"
"    i/ O * O \\i                                       / /\n"
"    /=========\\        __  __                        /_/    _\n"
"    /  *   *  \\        \\ \\/ /        /\\  /\\    __ _  ____  | |\n"
"  i/ O   i   O \\i       \\  /   __   /  \\/  \\  / _` |/ ___\\ |_|\n"
"  /=============\\       /  \\  |__| / /\\  /\\ \\| (_| |\\___ \\  _\n"
"  /  O   i   O  \\      /_/\\_\\      \\ \\ \\/ / / \\__,_|\\____/ |_|\n"
"i/ *   O   O   * \\i\n"
"/=================\\\n"
"       |___|\n";
	out_file << ascii_tree;
	out_file.close();
}
