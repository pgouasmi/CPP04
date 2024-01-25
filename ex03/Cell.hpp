/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cell.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:19:03 by pgouasmi          #+#    #+#             */
/*   Updated: 2024/01/24 17:56:07 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CELL_H
#define CELL_H

#pragma once

#include "AMateria.hpp"

class Cell
{
public:
    Cell(AMateria *m);
    Cell(const Cell &obj);
    Cell &operator=(const Cell &obj);
    ~Cell();

    AMateria *getMateria();
    Cell*   getPrev();
    Cell*   getNext();
    void    setNext(Cell *obj);
    void    setPrev(Cell *obj);
    void    destroyMateria();

private:
    AMateria *_m;
    Cell    *_prev;
    Cell    *_next;
};

#endif
