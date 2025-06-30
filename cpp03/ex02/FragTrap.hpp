/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 18:56:51 by sabe              #+#    #+#             */
/*   Updated: 2025/06/30 18:06:21 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGTRAP_HPP
#define FLAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(const std::string name);
		FragTrap(const FragTrap &other);
		FragTrap &operator=(const FragTrap &other);
		virtual ~FragTrap(void);

		void highFivesGuys(void);
};

#endif
