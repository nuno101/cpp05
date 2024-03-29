/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 21:28:08 by nlouro            #+#    #+#             */
/*   Updated: 2022/12/16 10:17:20 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

class	RobotomyRequestForm: public AForm
{
	private:
		std::string	const	_target;
	public:
		RobotomyRequestForm( std::string target );
		RobotomyRequestForm( RobotomyRequestForm const &src );
		RobotomyRequestForm &operator=( RobotomyRequestForm const &src );
		~RobotomyRequestForm( void );
		void	execute(Bureaucrat const &executor) const;

};
