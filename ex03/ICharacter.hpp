/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:50:17 by pgouasmi          #+#    #+#             */
/*   Updated: 2024/01/18 18:18:49 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once


#include "./AMateria.hpp"
#include <string>
#include "Floor.hpp"

class ICharacter
{
public:
	virtual ~ICharacter() {};
	virtual std::string const & getName() const = 0;
	virtual void equip(AMateria *a) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter& target) = 0;
};

