/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 20:47:14 by sabe              #+#    #+#             */
/*   Updated: 2025/06/08 21:44:16 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanA
{
	private:
		std::string name;
		Weapon &weapon;
	public:
		void attack(void);
		HumanA(const std::string& name, Weapon &weapon);
};

#endif
