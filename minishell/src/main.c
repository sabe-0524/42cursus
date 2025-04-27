/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 17:03:00 by sabe              #+#    #+#             */
/*   Updated: 2025/04/27 17:19:33 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int main(void) {
    char *line;
    while ((line = readline("minishell$ ")) != NULL) {
        if (*line)  // 空でなければ履歴に追加
            add_history(line);
        printf("You entered: %s\n", line);
        free(line);
    }
    return 0;
}
