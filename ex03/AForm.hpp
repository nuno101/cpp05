/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:10:29 by nlouro            #+#    #+#             */
/*   Updated: 2022/12/16 13:19:17 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class	Bureaucrat;
class	AForm
{
	private:
		std::string	const	_name;
		size_t	const 		_grade_4sign;
		size_t	const 		_grade_4exec;
		bool				_signed;
	public:
		AForm( std::string name, size_t grade_4sign, size_t grade_4exec);
		AForm( const AForm &src );
		AForm &operator=( const AForm &src );
		virtual	~AForm();
		std::string	getName( void ) const;
		size_t		getGrade4Sign( void ) const;
		size_t		getGrade4Exec( void ) const;
		std::string	getGrade4SignAsString( void ) const;
		std::string	getGrade4ExecAsString( void ) const;
		bool		isSigned( void  ) const;
		bool		beSigned( Bureaucrat &b );
		virtual		void execute(Bureaucrat const &executor) const = 0;
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
		class   FormNotSignedException : public std::exception
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
