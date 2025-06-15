/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 14:08:09 by sabe              #+#    #+#             */
/*   Updated: 2025/06/15 14:43:30 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain default constructor called." << std::endl;
	for (int i = 0; i < 100; i++)
	{
		std::ostringstream oss;
		oss << "Idea " << i;
		this->ideas[i] = oss.str();
	}
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called." << std::endl;
}

Brain::Brain(const Brain &other)
{
	std::cout << "Brain copy constructor called." << std::endl;
	for (int i = 0; i < 100; ++i)
	{
		ideas[i] = other.ideas[i];
	}
}

Brain& Brain::operator=(const Brain &other)
{
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
		{
			this->ideas[i] = other.ideas[i];
		}
	}
	return (*this);
}

std::string *Brain::getIdeas(void)
{
	return (this->ideas);
}

void Brain::setIdea(int nbr, std::string idea)
{
	this->ideas[nbr] = idea;
}
