/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:39:40 by pgouasmi          #+#    #+#             */
/*   Updated: 2024/01/18 19:54:47 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(const std::string &name)
{
	this->_name = name;
}

Character::Character(Character const &obj)
{
	*this = obj;
}

Character &Character::operator=(const Character &obj)
{
	this->_name = obj.getName();
	return *this;
}

Character::~Character()
{

}

void Character::equip(AMateria *m)
{

}

void Character::unequip(int idx)
{

}

void Character::use(int idx, ICharacter &target)
{

}

std::string const &Character::getName() const
{
	return this->_name;
}

