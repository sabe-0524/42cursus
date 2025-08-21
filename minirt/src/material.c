/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesouichirou <abesouichirou@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 12:44:29 by abesouichir       #+#    #+#             */
/*   Updated: 2025/08/21 22:05:39 by abesouichir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_material *material_new(const void *object, const t_material_vtable *vtable)
{
    t_material *mat = ft_calloc(1, sizeof(t_material));
    if (!mat)
        return (NULL);
    mat->object = object;
    mat->vtable = vtable;
    return (mat);
}

// t_material_vtable *lambertian_vtable(void)
// {
//     static t_material_vtable vtable = {
//         .scatter = lambertian_scatter,
//     };
//     return (&vtable);
// }