/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:23:12 by sabe              #+#    #+#             */
/*   Updated: 2025/06/17 14:25:21 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "../libft/libft.h"
# include <stdbool.h>
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
int					my_setenv(t_env *env, char *str);
void				my_unset(t_env *env, char *key);
void				free_item(t_item *item);
void				free_env(t_env *env);
char				**catenv(t_env *env);
char				*catenv_i(t_item *item);
void				my_setenv_row(t_env *env, char *key, char *data);
void				all_free_env(t_env *env);
char				*ft_strjoin_free(char *s1, char *s2);
int					handle_assignment(t_env *env, char *str, char *equal);
int					handle_no_assignment(char *str);
bool				is_available_env(char *s);
void				insert_env(t_env *env, t_item *item, bool is_add);

#endif
