/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:52:53 by nlouro            #+#    #+#             */
/*   Updated: 2022/12/10 00:27:39 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main( void )
{
	if ( VERBOSE )
	{
		Bureaucrat bob("Bob", 2);
		std::cout << bob;
		// Object copy 
		Bureaucrat bob2( bob );
		std::cout << bob2;
		// Assignment operator - initialise with dummy values
		Bureaucrat c("dummy", 1);
		c = bob;
		std::cout << c;
		// call increment on bob2 twice and raise an exception in the second call
		try
		{
			bob2.incrementGrade();
			bob2.incrementGrade();
		}
		catch ( Bureaucrat::GradeTooHighException & e )
		{
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
		// check grade still within boundaries
		std::cout << bob2;
	}
	// AForm can't be instantiated as it's now an abstract class
	//AForm form("D-form", 100, 88);
    ShrubberyCreationForm s_form = ShrubberyCreationForm( "home" );
	std::cout << s_form << std::endl;
	Bureaucrat bill("Bill", 145);
	std::cout << bill;
	// try to execute form w/o it being signed
	try
	{
		s_form.execute( bill );
	}
	catch ( AForm::FormNotSignedException & e )
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	bill.signForm( s_form );
	bill.incrementGrade();
	std::cout << bill;
	bill.signForm( s_form );
	// execute form now that it is signed
	try
	{
		s_form.execute( bill );
	}
	catch ( AForm::FormNotSignedException & e )
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}
