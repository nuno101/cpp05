/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:39:20 by nlouro            #+#    #+#             */
/*   Updated: 2022/12/16 12:02:56 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
	private:
		std::string	const	_name;
		size_t				_grade;
	public:
		Bureaucrat( std::string name, size_t grade );
		Bureaucrat( const Bureaucrat &src );
		Bureaucrat &operator=( const Bureaucrat &src );
		~Bureaucrat();
		std::string	getName( void ) const;
		size_t		getGrade( void ) const;
		std::string	getGradeAsString( void ) const;
		size_t		incrementGrade ( void );
		size_t		decrementGrade ( void );

		// Class Exceptions
		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class	GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

/*
 * overload of the « operator to show the Bureaucrat details
 */
std::ostream & operator<<( std::ostream &ostream, Bureaucrat const &b);

#endif
