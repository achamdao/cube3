/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achamdao <achamdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:11:16 by achamdao          #+#    #+#             */
/*   Updated: 2025/07/29 14:57:09 by achamdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

char    is_player_char(char c)
{
    return (c == 'W' || c == 'N' || c == 'S' || c == 'E');
}

char    is_char_map(char c)
{
    return (is_whitespace(c) || c == '1' || c == '0');
}

char    check_correct_char(int i, int index, t_info_cub *info_cub)
{
    if (!is_char_map(info_cub->line[i]) && !is_player_char(info_cub->line[i]))
        return (1);
    if (is_player_char(info_cub->line[i]))
    {
        info_cub->x = i;
        info_cub->y = index;
        info_cub->count_player++;
        info_cub->player_direction = info_cub->line[i];
    }
    return (0);
}

char    base_parsing_map(int index, t_info_cub *info_cub)
{
    int i;

    i = 0;
    if (count_char(info_cub->line, '\n') > 1 || !ft_strcmp(info_cub->line, "\n"))
        return (1);
    if (check_whitespace(info_cub->line))
        return (0);
    while (info_cub->line[i])
    {
        if (check_with_hiegth_map(info_cub->line, index, info_cub->length_map, i))
            return (1);
        if (check_correct_char(i, index, info_cub))
            return (1);
        if (check_empty_space_map(index, info_cub, i))
            return (1);
        i++;
    }
    return (0);
}