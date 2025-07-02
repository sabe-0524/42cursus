/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 20:43:39 by sabe              #+#    #+#             */
/*   Updated: 2025/07/02 22:00:50 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <string>

class Weapon
{
	private:
		std::string type;
	public:
		void setType(std::string type);
		const std::string getType(void);
		Weapon(std::string type);
};

#endif
