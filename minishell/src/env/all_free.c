/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesouichirou <abesouichirou@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:58:52 by abesouichir       #+#    #+#             */
/*   Updated: 2025/05/20 15:01:46 by abesouichir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <env.h>

void all_free_env(t_env *env)
{
    t_item *tmp;

    if (!env)
        return;
    while (env->head)
    {
        tmp = env->head->next;
        free(env->head->key);
        free(env->head->data);
        free(env->head);
        env->head = tmp;
    }
    free(env);
}