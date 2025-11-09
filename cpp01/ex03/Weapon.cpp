/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 20:45:27 by sabe              #+#    #+#             */
/*   Updated: 2025/07/08 16:02:09 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string& type)
{
	setType(type);
}

void Weapon::setType(const std::string& type)
{
	this->type = type;
}

const std::string &Weapon::getType(void) const
{
	return (this->type);
}
