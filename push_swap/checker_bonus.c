/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesouichirou <abesouichirou@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 21:03:41 by abesouichir       #+#    #+#             */
/*   Updated: 2025/03/03 21:14:49 by abesouichir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;
    
    alert_error(argc, argv);
    stack_a = create_stack(argc, argv);
    if (!stack_a)
        exit(1);
    stack_b = create_stack(0, NULL);
    if (!stack_b)
    {
        all_free(stack_a);
        exit(1);
    }
    
    all_free(stack_a);
    free(stack_b);
    return (0);
}