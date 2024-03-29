/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:25:33 by pgouasmi          #+#    #+#             */
/*   Updated: 2024/01/18 19:32:21 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./AMateria.hpp"

AMateria::AMateria()
{
	
}

AMateria::AMateria(std::string const &type)
{
	this->_type = type;
}

AMateria::AMateria(const AMateria &obj)
{
	// std::cout << "AMateria copy constructor called" << std::endl;
	*this = obj;
}

AMateria &AMateria::operator=(const AMateria &obj)
{
	this->_type = obj.getType();
	return *this;
}

AMateria::~AMateria()
{
	// std::cout << "AMateria Default destructor called" << std::endl;
}

std::string const & AMateria::getType() const
{
	return this->_type;
}

void	AMateria::use(ICharacter &target)
{
	(void) target;
}
