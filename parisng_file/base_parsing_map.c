/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_parsing_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achamdao <achamdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 12:14:54 by achamdao          #+#    #+#             */
/*   Updated: 2025/07/29 15:24:13 by achamdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void get_start_end(int *end, int *start, char *line)
{
    int start_pos;
    int end_pos;

    start_pos = 0;
    end_pos = ft_strlen(line) - 1;
    while (line[start_pos] && is_whitespace(line[start_pos]))
        start_pos++;
    if (!end_pos || end_pos == start_pos)
    {
         *end = end_pos;
        *start = start_pos;
        return ;
    }
    while (line[end_pos] && is_whitespace(line[end_pos]))
        end_pos--;
    *end = end_pos;
    *start = start_pos;
}

char    check_with_hiegth_map(char *line, int index, int length_map, int i)
{
    int end;
    int start;
    if (index == 0 || (length_map - 1) == index)
    {
       if (!(is_whitespace(line[i]) || line[i] == '1'))
            return (1);
    }
    get_start_end(&end, &start, line);
    if (!((line[end] == '1' && line[start] == '1')))
        return (1);
    return (0);
}

char    check_empty_space_map_up(char *line, char **map, int index, size_t i)
{
    if (index - 1 >= 0)
    {
        if (i > ft_strlen(map[index - 1]) - 1)
            return (1);
        else
            if (is_whitespace(map[index - 1][i]))
                return (1);
    }
    if (i > 0)
        if (is_whitespace(line[i - 1]))
            return (1);
    return (0);
}

char    check_empty_space_map(int index, t_info_cub *info_cub, size_t i)
{
    if (info_cub->line[i] == '0' || is_player_char(info_cub->line[i]))
    {
        if (index + 1 <= info_cub->length_map - 1)
        {
            if (i > ft_strlen(info_cub->temp_map[index + 1]) - 1)
                return (1);
            else
                if (is_whitespace(info_cub->temp_map[index + 1][i]))
                    return (1);
        }
        if (i + 1 <= (ft_strlen(info_cub->line) - 1))
            if (is_whitespace(info_cub->line[i + 1]))
                return (1);
        if (check_empty_space_map_up(info_cub->line, info_cub->temp_map, index, i))
            return (1);
    }
    return (0);
}
