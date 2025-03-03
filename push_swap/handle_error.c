/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesouichirou <abesouichirou@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:49:13 by abesouichir       #+#    #+#             */
/*   Updated: 2025/03/03 20:29:32 by abesouichir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_int(char *str)
{
    int i;
    long int num;
    int flag;

    i = 0;
    flag = 1;
    num = 0;
    if (str[0] == '+' || str[0] == '-')
    {
        i++;
        if (str[0] == '-')
            flag = -1;
    }
    if (str[i] == '\0')
        return (1);
    while (str[i] != '\0')
    {
        num = num * 10 + str[i] - '0';
        if (num * flag < INT_MIN || num * flag > INT_MAX)
            return (1);
        i++;
    }
    return (0);
}

int check_error(int argc, char **argv)
{
    int i;
    int j;

    i = 0;
    while (++i < argc)
    {
        j = 0;
        while (argv[i][j] != '\0')
        {
            if (argv[i][j] != '+' && argv[i][j] != '-' && (argv[i][j] < '0' || argv[i][j] > '9'))
                return (1);
            j++;
        }
        if (check_int(argv[i]))
            return(1);
    }
    return (0);
}

int check_duplicated(int argc, char **argv)
{
    int i;
    int j;

    i = 0;
    while (++i < argc - 1)
    {
        j = i + 1;
        while (j < argc)
        {
            if (!ft_strncmp(argv[i], argv[j], (size_t)ft_max((int)ft_strlen(argv[i]), (int)ft_strlen(argv[j]))))
            {
                return (1);
            }
            j++;
        }
    }
    return (0);
}

void alert_error(int argc, char **argv)
{
    if (check_error(argc, argv) || check_duplicated(argc, argv))
    {
        write(1, "Error\n", 6);
        exit(1);
    }
}
