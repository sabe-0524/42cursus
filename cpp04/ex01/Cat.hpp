/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 13:01:52 by sabe              #+#    #+#             */
/*   Updated: 2025/06/15 14:30:32 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain *brain;
	public:
		Cat(void);
		~Cat(void);
		Cat(const Cat &other);
		Cat& operator=(const Cat &other);
		virtual void makeSound(void) const;
		std::string getIdea(int nbr) const;
		void setIdea(int nbr, std::string idea);
};

#endif
