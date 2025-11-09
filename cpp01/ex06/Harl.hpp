/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 14:36:36 by sabe              #+#    #+#             */
/*   Updated: 2025/07/20 14:04:08 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

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
		static const std::string levels[4];
	public:
		void exec(std::string level);
		Harl(void);
};

#endif
