/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 00:00:00 by sabe              #+#    #+#             */
/*   Updated: 2026/02/27 20:30:14 by sabe             ###   ########.fr       */
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
	std::cout "raw: " << raw << std::endl;
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
