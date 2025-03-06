/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesouichirou <abesouichirou@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:35:07 by abesouichir       #+#    #+#             */
/*   Updated: 2025/03/06 22:29:23 by abesouichir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv)
{
    int outfile;

    outfile = open(argv[argc - 1], O_WRONLY);

    if (outfile < 0)
        return(1); //エラー処理追加
    handle_command(argc, argv, outfile);
    close(outfile);
}