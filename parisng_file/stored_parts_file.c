/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stored_parts_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achamdao <achamdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 18:55:18 by achamdao          #+#    #+#             */
/*   Updated: 2025/07/29 15:43:57 by achamdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

char    choice_what_stored(t_info_cub *info_cub, int size)
{
    if (size == 4)
    {
       if (parse_paths(info_cub))
            return (1);
    }
    else
        if (parse_colors(info_cub))
            return (1);
    return (0);
}

char    stored_part_map(t_info_cub *info_cub, int skeep)
{
    info_cub->length_map = get_length_map(info_cub->file, 7);
    if (!info_cub->length_map)
        return (-1);
    info_cub->map = ft_calloc((info_cub->length_map + 1) , sizeof(char *));
    if (!info_cub->map)
        return (-1);
    if (get_clean_map(info_cub, skeep, info_cub->length_map))
        return (-1);
    return (0);
}

char    storted_parts(t_info_cub *info_cub)
{
    int error;
    int skeep;

    skeep = 0;
    if (!info_cub->file)
        return (ft_putendl_fd("Error\nEmpty file!!", 2), -1);                                                                                                               
    error = get_path_color(info_cub, &skeep, 4);
    if (error)
        return (ft_putendl_fd("Error\nInvalid path !!", 2), -1);
     error = get_path_color(info_cub, &skeep, 2);
    if (error)
        return (ft_putendl_fd("Error\nInvalid color !!", 2),-1);
    error = stored_part_map(info_cub, skeep);
    if (error)
        return (ft_putendl_fd("Error\nInvalid map!!", 2), -1);
    return (0);
}
