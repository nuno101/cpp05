/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:10:29 by nlouro            #+#    #+#             */
/*   Updated: 2022/12/09 19:16:49 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class	Bureaucrat;
class	Form
{
	private:
		std::string	const	_name;
		size_t	const 		_grade_4sign;
		bool				_signed;
	public:
		Form( std::string name, size_t grade );
		Form( const Form &src );
		Form &operator=( const Form &src );
		~Form();
		std::string	getName( void ) const;
		size_t		getGrade4Sign( void ) const;
		std::string	getGrade4SignAsString( void ) const;
		size_t		incrementGrade ( void );
		size_t		decrementGrade ( void );
		bool		beSigned( Bureaucrat &b );
		// Class Exceptions
		class   GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class   GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

};

/*
 * overload of the « operator
 */
std::ostream & operator<<( std::ostream &ostream, Form const &f);

#endif
