/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_parts_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achamdao <achamdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 18:51:17 by achamdao          #+#    #+#             */
/*   Updated: 2025/07/29 15:22:25 by achamdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

char    is_whitespace(char c)
{
    return (c == ' ' || c == '\n');
}

char check_whitespace(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (!is_whitespace(str[i]))
            return (0);
        i++;
    }
    return (1);
}

int get_length_map(char **matrex, short skeep)
{
    int i;
    int count;

    i = 0;
    count = 0;
    if (!matrex)
        return (0);
    while (matrex[i])
    {
        if (!check_whitespace(matrex[i]) && skeep)
            skeep--;
        if (!skeep)
            count++;
        i++;
    }
    return (count);
}

char    get_clean_map(t_info_cub *info_cub, int skeep, int size)
{
    int     i;
    int     count;

    i = skeep;
    count = 0;
    while (check_whitespace(info_cub->file[i]))
        i++;
    info_cub->temp_map = &info_cub->file[i];
    i = 0;
    while (info_cub->temp_map[i])
    {
        info_cub->line = info_cub->temp_map[i];
        if (base_parsing_map(i, info_cub))
            return (1);
        info_cub->map[i] = ft_strdup(info_cub->temp_map[i]);
        if (!info_cub->map[i])
            return(free_matrex(&info_cub->map), -1);
        i++;
    }
    info_cub->map[size] = NULL;
    if (i != size)
        return (1);
    if (info_cub->count_player != 1)
        return (1);
    return (0);
}

char get_path_color(t_info_cub *info_cub, int *skeep, int size)
{
    int i;
    int count;

    i = *skeep;
    count = 0;
    while (info_cub->file[i])
    {
        if (!check_whitespace(info_cub->file[i]) && count < size)
        {
            info_cub->line = info_cub->file[i];
            if (choice_what_stored(info_cub, size))
                return (1);
            count++;
        }
        i++;
        if (count == size)
            break ;
    }
    if (count != size)
        return (1);
    *skeep = i;
    return (0);
}
