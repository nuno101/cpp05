/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:39:20 by nlouro            #+#    #+#             */
/*   Updated: 2022/12/16 10:12:39 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include "AForm.hpp" 

class	AForm;

class	Intern
{
	public:
		Intern();
		Intern( const Intern &src );
		Intern &operator=( const Intern &src );
		~Intern();
		AForm	*makeForm( std::string form_name, std::string form_target );
};

/*
 * overload of the « operator 
 */
std::ostream & operator<<( std::ostream &ostream, Intern const &b);

#endif
