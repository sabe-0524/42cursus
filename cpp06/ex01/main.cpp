/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesouichirou <abesouichirou@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 00:00:00 by sabe              #+#    #+#             */
/*   Updated: 2026/01/30 01:20:04 by abesouichir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

int main(void)
{
	Data data;
	data.id = 42;
	data.name = "example";

	Data* originalPtr = &data;
	uintptr_t raw = Serializer::serialize(originalPtr);
	Data* restoredPtr = Serializer::deserialize(raw);

	std::cout << "Original ptr: " << originalPtr << std::endl;
	std::cout << "Restored ptr: " << restoredPtr << std::endl;

	if (restoredPtr == originalPtr)
		std::cout << "OK: pointers match" << std::endl;
	else
		std::cout << "Error: pointers do not match" << std::endl;

	std::cout << "Data.id: " << restoredPtr->id << std::endl;
	std::cout << "Data.name: " << restoredPtr->name << std::endl;
	return 0;
}
