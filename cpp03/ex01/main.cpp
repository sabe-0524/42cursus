/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 16:07:45 by sabe              #+#    #+#             */
/*   Updated: 2025/06/14 17:18:56 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    {
        std::cout << "===== ScavTrap Default Construction =====\n";
        ScavTrap a;                   // default ctor
        a.attack("Bandit");           // inherited attack()
        a.takeDamage(30);             // inherited takeDamage()
        a.beRepaired(20);             // inherited beRepaired()
        a.guardGate();                // ScavTrap の固有機能
    }
    std::cout << "===== End of scope A (destructors should fire: ScavTrap → ClapTrap) =====\n\n";

    {
        std::cout << "===== ScavTrap Named Construction =====\n";
        ScavTrap b("Bobby");          // name ctor

        std::cout << "\n-- Copy Construction --\n";
        ScavTrap c = b;               // copy ctor
        c.guardGate();

        std::cout << "\n-- Assignment Operator --\n";
        ScavTrap d("Dummy");          // name ctor
        d = b;                        // copy assignment
        d.attack("Enemy");
    }
    std::cout << "===== End of scope B (destructors again) =====\n";

    return 0;
}
