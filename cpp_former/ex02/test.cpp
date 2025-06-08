/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 16:12:46 by sabe              #+#    #+#             */
/*   Updated: 2025/06/08 16:17:59 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <time.h>
#include <iostream>

int main(void)
{
	struct tm when;
	char buf[16];

	time_t tme = time(NULL);
	when = *localtime(&tme);
	strftime(buf, 16, "%Y%m%d_%H%M%S", &when);
	std::cout << "[" << buf << "]" << " ";
}
