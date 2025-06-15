/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 12:28:36 by sabe              #+#    #+#             */
/*   Updated: 2025/06/15 13:11:36 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    std::cout << "=== Polymorphism Tests ===\n";

    // 基底クラスと派生クラスを new して動的ポリモーフィズムをチェック
    const Animal* meta = new Animal();
    const Animal* dog  = new Dog();
    const Animal* cat  = new Cat();

    std::cout << "\nTypes:\n";
    std::cout << "dog->getType(): "  << dog->getType()  << "\n";  // Dog
    std::cout << "cat->getType(): "  << cat->getType()  << "\n";  // Cat

    std::cout << "\nSounds:\n";
    cat->makeSound();   // Cat の音
    dog->makeSound();   // Dog の音
    meta->makeSound();  // Animal の音

    delete meta;  // デストラクタの呼び出し順にも注目
    delete dog;
    delete cat;


    std::cout << "\n=== Copy & Assignment Tests ===\n";

    // Dog のコピー／代入
    Dog originalDog;
    Dog copyDog(originalDog);    // copy constructor
    Dog assignedDog;
    assignedDog = originalDog;   // copy assignment

    // Cat のコピー／代入
    Cat originalCat;
    Cat copyCat(originalCat);
    Cat assignedCat;
    assignedCat = originalCat;


    std::cout << "\n=== WrongAnimal Polymorphism Tests ===\n";

    // WrongAnimal 系では virtual でないので WrongCat でも WrongAnimal の makeSound が呼ばれる
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat  = new WrongCat();

    std::cout << "\nTypes:\n";
    std::cout << "wrongCat->getType(): " << wrongCat->getType() << "\n";  // WrongCat

    std::cout << "\nSounds:\n";
    wrongCat->makeSound();   // WrongAnimal::makeSound()
    wrongMeta->makeSound();  // WrongAnimal::makeSound()

    delete wrongCat;
    delete wrongMeta;


    std::cout << "\n=== Wrong Copy & Assignment Tests ===\n";

    // WrongCat のコピー／代入
    WrongCat originalWrongCat;
    WrongCat copyWrongCat(originalWrongCat);
    WrongCat assignedWrongCat;
    assignedWrongCat = originalWrongCat;

    return 0;
}
