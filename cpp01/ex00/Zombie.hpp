/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 17:51:57 by sabe              #+#    #+#             */
/*   Updated: 2025/06/08 18:45:55 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>
#include <iostream>

class Zombie
{
	private:
		std::string name;
	public:
		void announce(void);
		Zombie(std::string name);
		~Zombie(void);
};


Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif
