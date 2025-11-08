/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesouichirou <abesouichirou@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 15:00:00 by abesouichir       #+#    #+#             */
/*   Updated: 2025/08/22 15:00:00 by abesouichir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color3 vec3_random_range(double min, double max) {
    return (t_color3){
        rand_double(min, max),
        rand_double(min, max),
        rand_double(min, max)
    };
}

void create_random_scene(t_hittable_lst *lst) {
    // Ground material (lambertian)
    t_material *ground_material = lambertian_new((t_color3){0.5, 0.5, 0.5});
    sphere_create(lst, (t_vec3){0, -1000, 0}, 1000, *ground_material);

    // Generate random spheres
    for (int a = -11; a < 11; a++) {
        for (int b = -11; b < 11; b++) {
            double choose_mat = rand_double(0.0, 1.0);
            t_point3 center = (t_point3){
                a + 0.9 * rand_double(0.0, 1.0),
                0.2,
                b + 0.9 * rand_double(0.0, 1.0)
            };
            
            // Check distance from reference point (4, 0.2, 0)
            t_vec3 ref_point = (t_vec3){4, 0.2, 0};
            if (vec3_length(vec3_sub(center, ref_point)) > 0.9) {
                t_material *sphere_material;
                
                if (choose_mat < 0.8) {
                    // Diffuse (lambertian)
                    t_color3 albedo1 = vec3_random_range(0.0, 1.0);
                    t_color3 albedo2 = vec3_random_range(0.0, 1.0);
                    t_color3 albedo = vec3_mul_v(albedo1, albedo2);
                    sphere_material = lambertian_new(albedo);
                    sphere_create(lst, center, 0.2, *sphere_material);
                } else if (choose_mat < 0.95) {
                    // Metal
                    t_color3 albedo = vec3_random_range(0.5, 1.0);
                    double fuzz = rand_double(0.0, 0.5);
                    sphere_material = metal_new(albedo, fuzz);
                    sphere_create(lst, center, 0.2, *sphere_material);
                } else {
                    // Glass (dielectric)
                    sphere_material = dielectric_new((t_color3){1.0, 1.0, 1.0}, 1.5);
                    sphere_create(lst, center, 0.2, *sphere_material);
                }
            }
        }
    }

    // Three large spheres
    t_material *material1 = dielectric_new((t_color3){1.0, 1.0, 1.0}, 1.5);
    sphere_create(lst, (t_point3){0, 1, 0}, 1.0, *material1);

    t_material *material2 = lambertian_new((t_color3){0.4, 0.2, 0.1});
    sphere_create(lst, (t_point3){-4, 1, 0}, 1.0, *material2);

    t_material *material3 = metal_new((t_color3){0.7, 0.6, 0.5}, 0.0);
    sphere_create(lst, (t_point3){4, 1, 0}, 1.0, *material3);
}
