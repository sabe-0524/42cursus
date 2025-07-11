/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 12:28:39 by sabe              #+#    #+#             */
/*   Updated: 2025/06/15 13:16:52 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected:
		std::string type;
	public:
		Animal(void);
		virtual ~Animal(void);
		Animal(const Animal &other);
		Animal &operator=(const Animal &other);
		virtual void makeSound(void) const;
		std::string getType(void) const;
};

#endif
