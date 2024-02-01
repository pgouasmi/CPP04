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

	AMateria* tmp0;
	AMateria* tmp1;
	AMateria* tmp2;
	AMateria* tmp3;
	AMateria* tmp4;
	AMateria* tmp5;

	tmp0 = src->createMateria("ice");
	me->equip(tmp0);
	me->equip(tmp0);
	tmp1 = src->createMateria("cure");
	me->equip(tmp1);

	floor->addback(tmp1);
	me->unequip(1);
	floor->addback(tmp0);
	me->unequip(0);

	tmp2 = src->createMateria("ice");
	me->equip(tmp2);
	tmp3 = src->createMateria("ice");
	me->equip(tmp3);
	tmp4 = src->createMateria("cure");
	me->equip(tmp4);
	tmp5 = src->createMateria("fire");
	me->equip(tmp5);

	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
	delete floor;

	return 0;

}
