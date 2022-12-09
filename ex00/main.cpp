/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:52:53 by nlouro            #+#    #+#             */
/*   Updated: 2022/12/09 15:06:50 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main( void )
{
	Bureaucrat bob("Bob", 3);
	std::cout << bob << std::endl;
	// Object copy 
	Bureaucrat bob2( bob );
	std::cout << bob2 << std::endl;
	// Assignment operator - initialise with dummy values
	Bureaucrat c("dummy", 1);
	c = bob;
	std::cout << c << std::endl;
	c.decrementGrade();
	return 0;
}
