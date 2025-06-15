/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 20:16:13 by sabe              #+#    #+#             */
/*   Updated: 2025/06/15 22:12:49 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	std::cout << "MateriaSource constructor called." << std::endl;
	for (int i = 0; i < 4; i++)
	{
		this->sources[i] = NULL;
	}
}

MateriaSource::~MateriaSource(void)
{
	std::cout << "MateriaSource destructor called." << std::endl;
	for (int i = 0; i < 4; i++)
	{
		delete this->sources[i];
	}
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	std::cout << "MateraSource copy constructor called." << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (other.sources[i])
			this->sources[i] = other.sources[i]->clone();
		else
			this->sources[i] = NULL;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource &other)
{
	std::cout << "MateriaSource copy assigned operator called." << std::endl;
	for (int i = 0; i < 4; i++)
	{
		delete this->sources[i];
	}
	for (int i = 0; i < 4; i++)
	{
        if (other.sources[i])
            sources[i] = other.sources[i]->clone();
        else
            sources[i] = NULL;
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!sources[i])
		{
			sources[i] = m;
			return;
		}
	}
	delete m;
}

AMateria *MateriaSource::createMateria(const std::string &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (sources[i] && sources[i]->getType() == type)
			return (sources[i]->clone());
	}
	return (NULL);
}
