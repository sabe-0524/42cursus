/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 12:40:39 by sabe              #+#    #+#             */
/*   Updated: 2025/06/15 14:36:16 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain *brain;
	public:
		Dog(void);
		~Dog(void);
		Dog(const Dog &other);
		Dog& operator=(const Dog &other);
		virtual void makeSound(void) const;
		std::string getIdea(int nbr) const;
		void setIdea(int nbr, std::string idea);
};

#endif
