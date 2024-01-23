/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 22:03:19 by pgouasmi          #+#    #+#             */
/*   Updated: 2024/01/18 22:03:19 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (size_t i = 0; i < 4; i++)
		this->_source[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &obj)
{
	*this = obj;
}

MateriaSource& MateriaSource::operator=(const MateriaSource &obj)
{
	for (size_t i = 0; i < 4; i++)
		this->_source[i] = obj._source[i];
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (size_t i = 0; i < 4; i++)
		delete this->_source[i];
}

void	MateriaSource::learnMateria(AMateria *m)
{
	size_t i = 0;

	while (i < 4 && this->_source[i])
		i++;
	if (i == 3 && this->_source[i])
		std::cout << "Materia Source is already full" << std::endl;
	else
		this->_source[i] = m;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	size_t	i = 0;

	while (i < 4 && this->_source[i] && this->_source[i]->getType() != type)
		i++;
	if ((i == 3 && this->_source[i] && this->_source[i]->getType() != type) || !this->_source[i])
	{
		std::cout << "Unknown type `" << type << "\'" << std::endl;
		return NULL;
	}
	return this->_source[i]->clone();
}
