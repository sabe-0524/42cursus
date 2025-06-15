/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 19:25:21 by sabe              #+#    #+#             */
/*   Updated: 2025/06/15 22:14:36 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
	private:
		std::string name;
		AMateria* inventory[4];
		AMateria*     floor[4];
		int           floorCount;
	public:
		Character(const std::string &name);
		virtual ~Character (void);
		Character(const Character &other);
		Character& operator=(const Character& other);
		virtual std::string const &getName(void) const;
		virtual void equip(AMateria *m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter &target);
};

#endif
