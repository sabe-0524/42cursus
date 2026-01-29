/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesouichirou <abesouichirou@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 00:00:00 by sabe              #+#    #+#             */
/*   Updated: 2026/01/30 01:20:04 by abesouichir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>
#include "Data.hpp"

class Serializer
{
	private:
		Serializer(void);
		Serializer(const Serializer &other);
		Serializer &operator=(const Serializer &other);
		~Serializer(void);

	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};

#endif
