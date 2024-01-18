/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:52:34 by pgouasmi          #+#    #+#             */
/*   Updated: 2024/01/18 19:14:00 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ICE_HPP
# define ICE_HPP

#include "./AMateria.hpp"

class ice : public AMateria
{
private:
	/* data */
public:
	ice(std::string const &type);
	ice(const ice &obj);
	ice &operator=(const ice &obj);
	virtual ~ice();

	AMateria *clone() const;
	void	use(ICharacter &target);
};

# endif
