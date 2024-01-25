/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:56:30 by pgouasmi          #+#    #+#             */
/*   Updated: 2024/01/18 17:19:14 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Character.hpp"
#include "./Cure.hpp"
#include "./Ice.hpp"
#include "MateriaSource.hpp"
#include "Floor.hpp"

int main()
{
	Floor *floor = new Floor();
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	floor->addback(me->getMateria(1));
	me->unequip(1);
	floor->addback(me->getMateria(0));
	me->unequip(0);

	if (me->reequip(*floor) != 0)
	{
		std::cout << "\nEOF detected. Exiting the program" << std::endl;
		delete me;
		delete floor;
		delete src;
		return 1;
	}

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("fire");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
	delete floor;

	return 0;

}
