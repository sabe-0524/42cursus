/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 15:22:46 by sabe              #+#    #+#             */
/*   Updated: 2025/06/14 17:21:14 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
	protected:
		virtual const char* getClassName() const { return "ClapTrap"; }
	private:
		std::string name;
		unsigned int hitPoints;
		unsigned int energyPoints;
		unsigned int attackDamage;
	public:
		ClapTrap(void);
		ClapTrap(const std::string &name);
		ClapTrap(const std::string &name, const unsigned int &hitPoints, const unsigned int &energyPoints, const unsigned int &attackDamage);
		ClapTrap(const ClapTrap &other);
		ClapTrap &operator=(const ClapTrap &other);
		virtual ~ClapTrap(void);
		void setName(const std::string &name);
		void setHitPoints(const unsigned int &hitPoints);
		void setEnergyPoints(const unsigned int &energyPoints);
		void setAttackDamage(const unsigned int &attackDamage);

		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif
