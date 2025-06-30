/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 19:35:03 by sabe              #+#    #+#             */
/*   Updated: 2025/06/30 22:17:03 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(const std::string &name)
: name(name), floorCount(0)
{
    std::cout << "Character constructor called." << std::endl;
    for (int i = 0; i < 4; ++i) {
        inventory[i] = NULL;
        floor[i]     = NULL;
    }
}

Character::Character(const Character &other)
: name(other.getName()), floorCount(0)
{
    std::cout << "Character copy constructor called." << std::endl;
    for (int i = 0; i < 4; ++i) {
        if (other.inventory[i])
            inventory[i] = other.inventory[i]->clone();
        else
            inventory[i] = NULL;
        floor[i] = NULL;
    }
    floorCount = 0;
}

Character& Character::operator=(const Character &other)
{
    std::cout << "Character copy assignment operator called." << std::endl;
    if (this != &other) {
        for (int i = 0; i < 4; ++i) {
            delete inventory[i];
            inventory[i] = NULL;
            delete floor[i];
            floor[i] = NULL;
        }
        name = other.getName();
        for (int i = 0; i < 4; ++i) {
            if (other.inventory[i])
                inventory[i] = other.inventory[i]->clone();
            else
                inventory[i] = NULL;
            floor[i] = NULL;
        }
        floorCount = 0;
    }
    return *this;
}

Character::~Character(void)
{
    std::cout << "Character destructor called." << std::endl;
    for (int i = 0; i < 4; ++i)
        delete inventory[i];
    for (int i = 0; i < floorCount; ++i)
        delete floor[i];
}

std::string const &Character::getName(void) const
{
    return name;
}

void Character::equip(AMateria *m)
{
    if (!m) return;
    for (int i = 0; i < 4; ++i) {
        if (inventory[i] == NULL) {
            inventory[i] = m;
            return;
        }
    }
	delete m;
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4) return;
    if (inventory[idx]) {
        if (floorCount >= 4) {
            delete floor[0];
            for (int i = 0; i < 3; ++i) {
                floor[i] = floor[i+1];
            }
            floor[3] = NULL;
            floorCount--;
        }
        floor[floorCount++] = inventory[idx];
        inventory[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter &target)
{
    if (idx < 0 || idx >= 4) return;
    if (inventory[idx]) {
        inventory[idx]->use(target);
    }
}
