/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:54:54 by pgouasmi          #+#    #+#             */
/*   Updated: 2024/01/18 19:14:07 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CURE_HPP
# define CURE_HPP

#include "./AMateria.hpp"

class cure : public AMateria
{
private:
	/* data */
public:
	cure(std::string const &type);
	cure(const cure &obj);
	cure &operator=(const cure &obj);
	virtual ~cure();

	AMateria *clone() const;
	void	use(ICharacter &target);
};

# endif
