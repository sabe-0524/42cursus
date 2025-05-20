/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesouichirou <abesouichirou@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:23:12 by sabe              #+#    #+#             */
/*   Updated: 2025/05/20 15:01:56 by abesouichir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "../libft/libft.h"
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_item
{
	char			*key;
	char			*data;
	struct s_item	*next;
	struct s_item	*prev;
}					t_item;

typedef struct s_env
{
	t_item			*head;
}					t_env;

char				*my_getenv(char *key, t_env *env);
t_env				*init_env(char **envp);
void				my_setenv(t_env *env, char *str);
void				my_unset(t_env *env, char *key);
void				free_item(t_item *item);
void				free_env(t_env *env);
char				**catenv(t_env *env);
char				*catenv_i(t_item *item);
void				my_setenv_row(t_env *env, char *key, char *data);
void all_free_env(t_env *env);

#endif
