/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 21:28:08 by nlouro            #+#    #+#             */
/*   Updated: 2022/12/10 21:18:55 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

class	PresidentialPardonForm: public AForm
{
	private:
		std::string	const	_target;
	public:
		PresidentialPardonForm( std::string target );
		PresidentialPardonForm( PresidentialPardonForm const &src );
		PresidentialPardonForm &operator=( PresidentialPardonForm const &src );
		~PresidentialPardonForm( void );
		void	execute(Bureaucrat const &executor) const;

};
