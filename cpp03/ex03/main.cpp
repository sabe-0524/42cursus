/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 16:07:45 by sabe              #+#    #+#             */
/*   Updated: 2025/06/14 20:32:44 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main() {
    {
        std::cout << "===== DiamondTrap Default Construction =====\n";
        DiamondTrap dt1;                   // default constructor
        dt1.attack("Target");              // ScavTrap::attack
        dt1.takeDamage(20);                // ClapTrap::takeDamage
        dt1.beRepaired(10);                // ClapTrap::beRepaired
        dt1.guardGate();                   // ScavTrap::guardGate
        dt1.highFivesGuys();               // FragTrap::highFivesGuys
        dt1.whoAmI();                      // DiamondTrap::whoAmI
    }
    std::cout << "===== End of scope A (destructors: DiamondTrap → FragTrap → ScavTrap → ClapTrap) =====\n\n";

    {
        std::cout << "===== DiamondTrap Named Construction =====\n";
        DiamondTrap dt2("Dia");            // name constructor

        std::cout << "\n-- Copy Construction --\n";
        DiamondTrap dt3 = dt2;             // copy constructor
        dt3.whoAmI();

        std::cout << "\n-- Assignment Operator --\n";
        DiamondTrap dt4("Dummy");          // name constructor
        dt4 = dt2;                         // copy assignment
        dt4.attack("Bandit");

        std::cout << "\n-- whoAmI() on assigned object --\n";
        dt4.whoAmI();
    }
    std::cout << "===== End of scope B (destructors again) =====\n";

    return 0;
}
