/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 16:07:45 by sabe              #+#    #+#             */
/*   Updated: 2025/06/14 19:10:56 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    {
        std::cout << "===== FragTrap Default Construction =====\n";
        FragTrap f1;                    // default constructor
        f1.attack("Bandit");            // inherited attack()
        f1.takeDamage(30);              // inherited takeDamage()
        f1.beRepaired(20);              // inherited beRepaired()
        f1.highFivesGuys();             // FragTrap の固有機能
    }
    std::cout << "===== End of scope A (destructors should fire: FragTrap → ClapTrap) =====\n\n";

    {
        std::cout << "===== FragTrap Named Construction =====\n";
        FragTrap f2("Freddie");         // name constructor

        std::cout << "\n-- Copy Construction --\n";
        FragTrap f3 = f2;               // copy constructor
        f3.highFivesGuys();

        std::cout << "\n-- Assignment Operator --\n";
        FragTrap f4("Dummy");           // name constructor
        f4 = f2;                        // copy assignment
        f4.attack("Enemy");
    }
    std::cout << "===== End of scope B (destructors again) =====\n";

    return 0;
}
