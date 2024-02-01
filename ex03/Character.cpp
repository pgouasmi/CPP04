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
#include <sstream>

Character::Character(const std::string &name)
{
	this->_name = name;
	for (size_t i = 0; i < 4; i++)
		this->_inventory[i] = NULL;

}

Character::Character(Character const &obj)
{
	for (size_t i = 0; i < 4; i++)
		delete (this->_inventory[i]);

	*this = obj;
}

Character &Character::operator=(const Character &obj)
{
	this->_name = obj.getName();
	for (size_t i = 0; i < 4; i++)
		this->_inventory[0] = obj._inventory[0];
	return *this;
}

Character::~Character()
{
	for (size_t i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
}

void Character::equip(AMateria *m)
{
	size_t i = 0;

	if (!m)
	{
		std::cout << "No materia to equip. Did the createMateria() go well?\n" << std::endl;
		return ;
	}

	while (i < 3 && this->_inventory[i])
	{
		if (this->_inventory[i] == m)
		{
			std::cerr << "This materia " << m->getType() << " " << m <<" is already equipped\n" << std::endl;
			return ;
		}
		i++;
	}
	if (i == 3 && this->_inventory[i] != NULL)
	{
		std::cout << "Materia inventory is full. " << this->getName() << " " << "can not learn the materia " << m->getType() << " " << m <<  std::endl;
		delete m;
	}
	else
	{
		this->_inventory[i] = m;
		std::cout << "Character " << this->getName() << " equipped Materia " << m->getType() << " " << m << " at slot " << i << "\n" << std::endl;
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3 || !this->_inventory[idx])
	{
		std::cout << "No materia to unequip at index " << idx << "\n" << std::endl;
		return ;
	}
	std::cout << "Character " << this->getName() << " unequipped the " << this->_inventory[idx]->getType() << " Materia " << this->_inventory[idx] << "\n" << std::endl;
	this->_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx <= 3 && this->_inventory[idx])
		this->_inventory[idx]->use(target);
	else
		std::cout << "Wrong index" << std::endl;
}

std::string const &Character::getName() const
{
	return this->_name;
}

