/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 17:51:57 by sabe              #+#    #+#             */
/*   Updated: 2025/06/08 18:50:42 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
	private:
		std::string name;
	public:
		void announce(void) const;
		Zombie();
		Zombie(std::string name);
		~Zombie(void);
		void setName(std::string name);
};

Zombie* zombieHorde(int N, std::string name);

#endif
