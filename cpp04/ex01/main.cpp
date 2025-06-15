/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 12:28:36 by sabe              #+#    #+#             */
/*   Updated: 2025/06/15 14:39:08 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main() {
    std::cout << "=== Dynamic Array of Animals Test ===\n";
    const int N = 6;
    const Animal* animals[N];

    // Fill half with Dogs, half with Cats
    for (int i = 0; i < N/2; ++i) {
        animals[i] = new Dog();
    }
    for (int i = N/2; i < N; ++i) {
        animals[i] = new Cat();
    }

    std::cout << "\nTypes and Sounds:\n";
    for (int i = 0; i < N; ++i) {
        std::cout << animals[i]->getType() << ": ";
        animals[i]->makeSound();
    }

    // Delete all via base‐class pointer
    std::cout << "\nDeleting all animals:\n";
    for (int i = 0; i < N; ++i) {
        delete animals[i];
    }


    std::cout << "\n=== Deep Copy Test for Dog ===\n";
    Dog* d1 = new Dog();
    d1->setIdea(0, "Chase the mailman");
    std::cout << "d1 idea[0]: " << d1->getIdea(0) << "\n";

    Dog d2(*d1);  // copy ctor
    std::cout << "d2 idea[0] after copy: " << d2.getIdea(0) << "\n";

    d2.setIdea(0, "Guard the yard");
    std::cout << "d1 idea[0] after modifying d2: " << d1->getIdea(0) << "\n";
    std::cout << "d2 idea[0] after modifying d2: " << d2.getIdea(0) << "\n";

    delete d1;  // should call Dog & Brain destructors


    std::cout << "\n=== Deep Copy Test for Cat ===\n";
    Cat c1;
    c1.setIdea(1, "Nap in the sun");
    std::cout << "c1 idea[1]: " << c1.getIdea(1) << "\n";

    Cat c2;
    c2 = c1;     // copy assignment
    std::cout << "c2 idea[1] after assignment: " << c2.getIdea(1) << "\n";

    c2.setIdea(1, "Knock things off the table");
    std::cout << "c1 idea[1] after modifying c2: " << c1.getIdea(1) << "\n";
    std::cout << "c2 idea[1] after modifying c2: " << c2.getIdea(1) << "\n";


    std::cout << "\n=== End of Tests ===\n";
    return 0;
}
