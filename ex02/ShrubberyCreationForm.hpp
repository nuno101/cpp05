/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 21:28:08 by nlouro            #+#    #+#             */
/*   Updated: 2022/12/10 09:02:08 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

class	ShrubberyCreationForm: public AForm
{
	private:
		std::string	const	_target;
		void _print_to( std::string const filename ) const;
	public:
		ShrubberyCreationForm( std::string target );
		ShrubberyCreationForm( ShrubberyCreationForm const &src );
		ShrubberyCreationForm &operator=( ShrubberyCreationForm const &src );
		~ShrubberyCreationForm( void );
		void	execute(Bureaucrat const &executor) const;

};
