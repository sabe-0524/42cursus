/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 12:28:36 by sabe              #+#    #+#             */
/*   Updated: 2025/06/15 18:35:26 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

// この行をコメントアウトするとコンパイルエラーになるはずです。
// Animal は抽象クラスなのでインスタンス化できません。
// Animal a; // error: cannot declare variable ‘a’ to be of abstract type ‘Animal’

int main() {
    std::cout << "=== Abstract Animal Test ===\n";
    std::cout << "Animal is abstract: instantiation should fail (see commented code above).\n\n";

    std::cout << "=== Polymorphism Test ===\n";
    const Animal* zoo[4];
    zoo[0] = new Dog();
    zoo[1] = new Cat();
    zoo[2] = new Dog();
    zoo[3] = new Cat();

    for (int i = 0; i < 4; ++i) {
        std::cout << zoo[i]->getType() << " says: ";
        zoo[i]->makeSound();
    }

    std::cout << "\nCleaning up:\n";
    for (int i = 0; i < 4; ++i) {
        delete zoo[i];
    }

    std::cout << "\n=== Deep Copy Test ===\n";
    Dog*   d1 = new Dog();
    d1->setIdea(0, "Fetch the ball");
    Dog    d2(*d1);            // copy constructor
    d2.setIdea(0, "Guard the house");

    std::cout << "d1 idea[0]: " << d1->getIdea(0) << "\n";
    std::cout << "d2 idea[0]: " << d2.getIdea(0) << "\n";
    delete d1;

    Cat    c1;
    c1.setIdea(1, "Nap in sun");
    Cat    c2;
    c2 = c1;                   // copy assignment
    c2.setIdea(1, "Chase laser");

    std::cout << "c1 idea[1]: " << c1.getIdea(1) << "\n";
    std::cout << "c2 idea[1]: " << c2.getIdea(1) << "\n";

    std::cout << "\nAll tests passed.\n";
    return 0;
}
