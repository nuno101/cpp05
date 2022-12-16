/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:52:53 by nlouro            #+#    #+#             */
/*   Updated: 2022/12/16 10:09:22 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


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
	// ShrubberyCreationForm tests
	if ( VERBOSE )
	{
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
		catch ( AForm::GradeTooHighException & e )
		{
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
		for(int i = 144; i > 44; i--) 
		{
			bill.incrementGrade();
		}
		std::cout << bill;
		// two ways to execute the form as required
		// form can be executed multiple times
		s_form.execute( bill );
		bill.executeForm( s_form );
	}
	// RobotomyRequestForm test
	if ( VERBOSE )
	{
		RobotomyRequestForm s_form = RobotomyRequestForm( "home" );
		std::cout << s_form << std::endl;
		Bureaucrat bill("Bill", 72);
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
		catch ( AForm::GradeTooHighException & e )
		{
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
		for(int i = 71; i > 44; i--) 
		{
			bill.incrementGrade();
		}
		std::cout << bill;
		bill.executeForm( s_form );
	}
	// PresidentialPardonForm tests
	if ( true )
	{
		PresidentialPardonForm s_form = PresidentialPardonForm( "home" );
		std::cout << s_form << std::endl;
		Bureaucrat bill("Bill", 25);
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
		catch ( AForm::GradeTooHighException & e )
		{
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
		for(int i = 24; i > 5; i--) 
		{
			bill.incrementGrade();
		}
		std::cout << bill;
		bill.executeForm( s_form );
	}
	return 0;
}
