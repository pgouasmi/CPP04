/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:52:13 by pgouasmi          #+#    #+#             */
/*   Updated: 2024/01/18 19:07:26 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Ice.hpp"
#include "ICharacter.hpp"

ice::ice(std::string const &type) : AMateria(type)
{
	this->_type = type;
}

ice::ice(const ice &obj) : AMateria(obj)
{
	*this = obj;
}

ice &ice::operator=(const ice &obj)
{
	this->_type = obj.getType();
	return *this;
}

ice::~ice()
{

}

AMateria *ice::clone() const
{
	ice *res = new ice("ice");
	*res = *this;
	return res;
}

void ice::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
