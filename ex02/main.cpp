/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:52:53 by nlouro            #+#    #+#             */
/*   Updated: 2022/12/09 18:54:54 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

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
	AForm form("D-form", 100);
	std::cout << form << std::endl;
	Bureaucrat bill("Bill", 100);
	std::cout << bill;
	bill.signForm( form );
	bill.incrementGrade();
	std::cout << bill;
	bill.signForm( form );

	return 0;
}
