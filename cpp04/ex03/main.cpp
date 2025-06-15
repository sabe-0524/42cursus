/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 21:38:29 by sabe              #+#    #+#             */
/*   Updated: 2025/06/15 22:10:17 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int main() {
    std::cout << "=== Exercise 03: Interface & Recap Tests ===\n\n";

    // 1) MateriaSource learning & creation
    std::cout << "[1] Learning up to 4 Materias (5th ignored)\n";
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Ice());  // should be ignored

    std::cout << "\n[2] Creating known and unknown Materias\n";
    AMateria* m1 = src->createMateria("ice");
    AMateria* m2 = src->createMateria("cure");
    AMateria* m3 = src->createMateria("ice");
    AMateria* m4 = src->createMateria("cure");
    AMateria* mx = src->createMateria("fire");  // unknown

    std::cout << " m1 type: " << (m1 ? m1->getType() : "NULL") << "\n";
    std::cout << " m2 type: " << (m2 ? m2->getType() : "NULL") << "\n";
    std::cout << " m3 type: " << (m3 ? m3->getType() : "NULL") << "\n";
    std::cout << " m4 type: " << (m4 ? m4->getType() : "NULL") << "\n";
    std::cout << " mx type: " << (mx ? mx->getType() : "NULL") << " (expected NULL)\n";

    // 2) Character equip/use/unequip
    std::cout << "\n[3] Character equip/use/unequip tests\n";
    ICharacter* alice = new Character("Alice");
    alice->equip(m1);
    alice->equip(m2);
    alice->equip(m3);
    alice->equip(m4);
    // 5th equip should do nothing
    AMateria* extra = src->createMateria("ice");
    alice->equip(extra);

    ICharacter* bob = new Character("Bob");
    std::cout << "\n-- Using slots 0–4 on Bob --\n";
    for (int i = 0; i < 5; ++i)
        alice->use(i, *bob);

    std::cout << "\n-- Unequip slot 1 and use again --\n";
    alice->unequip(1);
    alice->use(1, *bob);

    delete bob;
    delete alice;

    // 3) Deep copy Character
    std::cout << "\n[4] Deep-copy Character tests\n";
    Character* c1 = new Character("C1");
    AMateria* iceX = src->createMateria("ice");
    AMateria* cureX = src->createMateria("cure");
    c1->equip(iceX);
    c1->equip(cureX);

    Character c2(*c1);            // copy constructor
    std::cout << " c2 uses slot 0 on Bob:\n";
    bob = new Character("Bob2");
    c2.use(0, *bob);
    delete bob;

    Character c3("Temp");
    c3 = c2;                      // copy assignment
    std::cout << " c3 uses slot 1 on Bob:\n";
    bob = new Character("Bob3");
    c3.use(1, *bob);
    delete bob;

    delete c1;

    // 4) Deep copy MateriaSource
    std::cout << "\n[5] Deep-copy MateriaSource tests\n";
    MateriaSource* src2 = new MateriaSource(*static_cast<MateriaSource*>(src));
    AMateria* mnew = src2->createMateria("cure");
    std::cout << " created from src2: "
              << (mnew ? mnew->getType() : "NULL") << "\n";
    delete mnew;
    delete src2;

    std::cout << "\n[Cleanup] Deleting original source...\n";
    delete src;
    return 0;
}
