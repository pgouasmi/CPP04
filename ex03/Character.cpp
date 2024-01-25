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

AMateria *Character::getMateria(int idx) const
{
	return this->_inventory[idx];
}

int	Character::reequip(Floor &obj)
{
	Cell *temp = obj.getList();
	size_t		size = obj.lstsize();

	if (!temp)
	{
		std::cout << "No Materia on the floor for you to reequip\n" << std::endl;
		return 1;
	}


	std::cout << "Materias on the floor :" << std::endl;
	for (size_t i = 0; i < size; i++)
	{

		std::cout << i << ": " << temp->getMateria()->getType() << " " << temp->getMateria() << std::endl;
		temp = temp->getNext();
	}
	std::cout << std::endl;
	std::cout << "Type the index of the Materia you want to reequip :" << std::endl;


	std::string Line;
	size_t		nb;

	while (1)
	{
		std::getline(std::cin, Line);
		if (std::cin.eof())
			return 1;
		else if (Line.find_first_not_of("0123456789") != std::string::npos || Line.empty())
			std::cout << "Wrong input, please type digits only.\n" << std::endl;
		else
			break ;
	}
	std::stringstream sstream(Line);
	sstream >> nb;
	if (nb >= size)
	{
		std::cout << "No materia at index " << nb << ". Reequip cancelled\n" << std::endl;
		return 0;
	}
	temp = obj.getList();
	for (size_t i = 0; i < nb; i++)
		temp = temp->getNext();
	this->equip((AMateria *)temp->getMateria());
	obj.deletesingle(temp->getMateria());
	return 0;
}

