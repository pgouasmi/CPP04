/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:49:16 by pgouasmi          #+#    #+#             */
/*   Updated: 2024/01/25 12:53:16 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Floor.hpp"

Floor::Floor()
{
	this->_lst = NULL;
}

Floor::Floor(const Floor &obj)
{
	*this = obj;
}

Floor &Floor::operator=(const Floor &obj)
{
	Cell *temp = obj._lst;

	while (temp)
	{
		this->addback(temp->getMateria());
		temp = temp->getNext();
	}
	return *this;
}

Floor::~Floor()
{
	this->free();
}

void	Floor::addback(const AMateria *m)
{
	Cell *obj = new Cell((AMateria *)m);

	Cell *temp = this->_lst;
	if (!temp)
		this->_lst = obj;
	else
	{
		while (temp->getNext())
			temp = temp->getNext();
		temp->setNext(obj);
		obj->setPrev(temp);
	}
}

void	Floor::free()
{
	Cell *temp = this->_lst;
	Cell *next;
	while (temp)
	{
		if (temp == NULL)
			break ;
		next = temp->getNext();
		if (temp->getMateria())
			temp->destroyMateria();
		if (temp->getPrev())
			temp->getPrev()->setNext(temp->getNext());
		if (temp->getNext())
			temp->getNext()->setPrev(temp->getPrev());
		delete temp;
		temp = next;
		if (!temp)
			break ;
	}
}

Cell *Floor::getList()
{
	return this->_lst;
}

size_t	Floor::lstsize()
{
	Cell *temp = this->_lst;
	size_t i = 0;

	while (temp)
	{
		i++;
		temp = temp->getNext();
	}
	return i;
}

void	Floor::deletesingle(const AMateria *m)
{
	Cell *temp = this->_lst;
	size_t		size = this->lstsize();
	Cell *newhead = NULL;


	if (!temp)
		return ;
	while (temp && temp->getMateria() != m)
		temp = temp->getNext();
	if (temp == this->_lst)
		newhead = temp->getNext();
	if (temp->getPrev())
		temp->getPrev()->setNext(temp->getNext());
	if (temp->getNext())
		temp->getNext()->setPrev(temp->getPrev());
	std::cout << "Materia " << temp->getMateria()->getType() << " " << temp->getMateria() << " deleted from Floor\n" << std::endl;
	delete temp;
	if (size == 1)
		this->_lst = NULL;
	else
	{
		if (newhead != NULL)
			this->_lst = newhead;
	}
}


