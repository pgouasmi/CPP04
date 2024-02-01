/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:49:19 by pgouasmi          #+#    #+#             */
/*   Updated: 2024/01/25 12:11:52 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOOR_H
#define FLOOR_H

#pragma once

#include "AMateria.hpp"
#include "Cell.hpp"

class Floor
{
public:
    Floor();
    Floor(const Floor &obj);
    Floor   &operator=(const Floor &obj);
    ~Floor();

    void    addback(const AMateria *m);
    void    free();
    Cell    *getList();
    size_t  lstsize();
    void    deletesingle(const AMateria *m);
	int		reequip(ICharacter *obj);
	AMateria	*getMateria(ICharacter *obj);

private:
    Cell  *_lst;
};

#endif
