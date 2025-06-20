/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 19:28:22 by sabe              #+#    #+#             */
/*   Updated: 2025/06/14 20:37:01 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap
  : virtual public ScavTrap
  , virtual public FragTrap
{
protected:
	virtual const char* getClassName() const { return "DiamondTrap"; }
private:
    std::string name;

public:
    DiamondTrap();
    DiamondTrap(const std::string& n);
    DiamondTrap(const DiamondTrap& o);
    DiamondTrap& operator=(const DiamondTrap& o);
    ~DiamondTrap();

    using ScavTrap::attack;

    void whoAmI();
};

#endif
