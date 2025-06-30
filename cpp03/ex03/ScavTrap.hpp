/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 16:12:10 by sabe              #+#    #+#             */
/*   Updated: 2025/06/30 18:06:27 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap(void);
		ScavTrap(const std::string name);
		ScavTrap(const ScavTrap &other);
		ScavTrap &operator=(const ScavTrap &other);
		virtual ~ScavTrap(void);

		void guardGate(void);
		void attack(const std::string& target);
};

#endif
