/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:10:29 by nlouro            #+#    #+#             */
/*   Updated: 2022/12/09 18:58:42 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class	Bureaucrat;
class	AForm
{
	private:
		std::string	const	_name;
		size_t	const 		_grade;
		bool				_signed;
	public:
		AForm( std::string name, size_t grade );
		AForm( const AForm &src );
		AForm &operator=( const AForm &src );
		~AForm();
		std::string	getName( void ) const;
		size_t		getGrade( void ) const;
		std::string	getGradeAsString( void ) const;
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
std::ostream & operator<<( std::ostream &ostream, AForm const &f);

#endif
