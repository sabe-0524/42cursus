/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 14:36:36 by sabe              #+#    #+#             */
/*   Updated: 2025/06/09 14:59:23 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
#define HARL_H

#include <iostream>
#include <string>
#include <map>

typedef enum e_level
{
	DEBUG,
	INFO,
	WARNING,
	ERROR
} t_level;

class Harl
{
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
		std::map<std::string,int> level_map;
	public:
		void exec(std::string level);
		Harl(void);
};

#endif
