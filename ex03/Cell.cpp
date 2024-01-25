/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cell.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:19:00 by pgouasmi          #+#    #+#             */
/*   Updated: 2024/01/24 18:59:34 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cell.hpp"

Cell::Cell(AMateria *m) : _m(m), _prev(NULL), _next(NULL)
{
}

Cell::Cell(const Cell &obj)
{
	(void)obj;
	this->_m = NULL;
	this->_next = NULL;
	this->_prev = NULL;
}

Cell &Cell::operator=(const Cell &obj)
{
	(void) obj;
	return *this;
}

Cell::~Cell()
{

}
AMateria *Cell::getMateria()
{
	return this->_m;
}

Cell	*Cell::getPrev()
{
	return this->_prev;
}

Cell	*Cell::getNext()
{
	return this->_next;
}

void	Cell::setNext(Cell *obj)
{
	this->_next = obj;
}

void	Cell::setPrev(Cell *obj)
{
	this->_prev = obj;
}

void	Cell::destroyMateria()
{
	if (this->_m)
		delete this->_m;
}
