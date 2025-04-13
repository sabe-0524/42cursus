/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:49:13 by abesouichir       #+#    #+#             */
/*   Updated: 2025/04/09 18:46:43 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_int(char *str)
{
	int			i;
	long int	num;
	int			flag;

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

int	check_error(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (j == 0 && argv[i][j] != '+' && argv[i][j] != '-'
				&& (argv[i][j] < '0' || argv[i][j] > '9'))
				return (1);
			if (j != 0 && (argv[i][j] < '0' || argv[i][j] > '9'))
				return (1);
			j++;
		}
		if (check_int(argv[i]))
			return (1);
	}
	return (0);
}

void	check_duplicated(t_stack *stack)
{
	t_node	*node_a;
	t_node	*node_b;

	node_a = stack->top;
	while (node_a != stack->top->prev)
	{
		node_b = node_a->next;
		while (node_b != stack->top)
		{
			if (node_a->content == node_b->content)
			{
				write(2, "Error\n", 6);
				all_free(stack);
				exit(1);
			}
			node_b = node_b->next;
		}
		node_a = node_a->next;
	}
}

void	alert_error(int argc, char **argv)
{
	if (check_error(argc, argv))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}
