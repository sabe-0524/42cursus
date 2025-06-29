/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 16:07:45 by sabe              #+#    #+#             */
/*   Updated: 2025/06/29 22:38:33 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

// int main() {
//     {
//         std::cout << "===== DiamondTrap Default Construction =====\n";
//         DiamondTrap dt1;                   // default constructor
//         dt1.attack("Target");              // ScavTrap::attack
//         dt1.takeDamage(20);                // ClapTrap::takeDamage
//         dt1.beRepaired(10);                // ClapTrap::beRepaired
//         dt1.guardGate();                   // ScavTrap::guardGate
//         dt1.highFivesGuys();               // FragTrap::highFivesGuys
//         dt1.whoAmI();                      // DiamondTrap::whoAmI
//     }
//     std::cout << "===== End of scope A (destructors: DiamondTrap → FragTrap → ScavTrap → ClapTrap) =====\n\n";

//     {
//         std::cout << "===== DiamondTrap Named Construction =====\n";
//         DiamondTrap dt2("Dia");            // name constructor

//         std::cout << "\n-- Copy Construction --\n";
//         DiamondTrap dt3 = dt2;             // copy constructor
//         dt3.whoAmI();

//         std::cout << "\n-- Assignment Operator --\n";
//         DiamondTrap dt4("Dummy");          // name constructor
//         dt4 = dt2;                         // copy assignment
//         dt4.attack("Bandit");

//         std::cout << "\n-- whoAmI() on assigned object --\n";
//         dt4.whoAmI();
//     }
//     std::cout << "===== End of scope B (destructors again) =====\n";

//     return 0;
// }

int main() {
    std::cout << "─── DiamondTrap の生成 ───\n";
    DiamondTrap dt("Diamond");

    std::cout << "\n─── whoAmI() の呼び出し ───\n";
    dt.whoAmI();

    std::cout << "\n─── attack() （ScavTrap 由来）の呼び出し ───\n";
    dt.attack("EnemyTarget");

    std::cout << "\n─── guardGate() （ScavTrap 由来）の呼び出し ───\n";
    dt.guardGate();

    std::cout << "\n─── highFivesGuys() （FragTrap 由来）の呼び出し ───\n";
    dt.highFivesGuys();

    std::cout << "\n─── takeDamage() と beRepaired() の呼び出し ───\n";
    dt.takeDamage(5);
    dt.beRepaired(3);

    std::cout << "\n─── 再度 whoAmI() で名前を確認 ───\n";
    dt.whoAmI();

    std::cout << "\nプログラム終了\n";
    return 0;
}
