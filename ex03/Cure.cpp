/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:05:19 by pgouasmi          #+#    #+#             */
/*   Updated: 2024/01/18 19:07:29 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Cure.hpp"
#include "ICharacter.hpp"

cure::cure(std::string const &type) : AMateria(type)
{
	this->_type = type;
}

cure::cure(const cure &obj) : AMateria(obj)
{
	*this = obj;
}

cure &cure::operator=(const cure &obj)
{
	this->_type = obj.getType();
	return *this;
}

cure::~cure()
{

}

AMateria *cure::clone() const
{
	cure *res = new cure("Cure");
	*res = *this;
	return res;
}

void cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}


