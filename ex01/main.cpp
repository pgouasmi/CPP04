/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:18:12 by pgouasmi          #+#    #+#             */
/*   Updated: 2024/01/18 14:34:22 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Animal.hpp"
#include "./Dog.hpp"
#include "./Cat.hpp"

int main()
{
	{
		Animal *arr[10];

		std::string s = "LOL";
		for (size_t i = 0; i < 5; i++)
		{
			arr[i] = new Dog();
		}
		for (size_t j = 5; j < 10; j++)
		{
			arr[j] = new Cat();
		}
		for (size_t k = 0; k < 10; k++)
		{
			delete arr[k];
		}
	}

//	std::cout << std::endl;
	{
	Animal* j = new Dog();
	Cat* i = new Cat();
	Cat* test = new Cat();

	*test = *i;
	i->setCatIdea("BRUH", 1);
	std::cout << i->getCatIdea(1) << std::endl;
	i->setCatIdea("TEST", 1);
	std::cout << i->getCatIdea(1) << std::endl;
	std::cout << i->getCatIdea(21) << std::endl;
	delete i;
	delete test;
//	std::cout << test->_brain->getIdea(0);

	delete j;//should not create a leak
//	delete i;
	}

}
