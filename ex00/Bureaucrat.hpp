/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:39:20 by nlouro            #+#    #+#             */
/*   Updated: 2022/12/04 16:54:11 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat : _name(name), _grade(grade)
{
	private:
		std::string	const _name;
		size_t	_grade;
	public:
		std::string	getName( void ) const;
		size_t	getGrade( void );
		size_t	incrementGrade ( void );
		size_t	decrementGrade ( void );
		
};

//TODO
//Bureaucrat::GradeTooHighException
//Bureaucrat::GradeTooLowException

#endif
