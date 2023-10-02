/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberrouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 23:36:33 by mberrouk          #+#    #+#             */
/*   Updated: 2023/09/30 23:36:36 by mberrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	valid_form(char *arg, int j, int comma)
{
	return (comma > 2 || (arg[j] != ',' && ((arg[j] < '0' || arg[j] > '9') \
						&& (!WHITESPACE(arg[j])))) || (arg[j] == ','\
						&& (!arg[j + 1] || arg[j + 1] == ','\
						|| arg[j + 1] == '\n')));
}

int	convert_rgb(char *arg, int conver)
{
	int	i;
	int	value;

	i = 0;
	while (WHITESPACE(arg[i]))
		i++;
	value = ft_atoi(&arg[i]);
	if (!arg[i] || value < 0 || value > 255)
		return (-1);
	return (value << conver);
}

int	floor_ceiling_value(char *arg, int comma, int conver, int i)
{
	int	j;
	int	result;

	j = i;
	result = 0;
	while (arg[j])
	{
		if (valid_form(arg, j, comma))
			return (-1);
		j++;
		if (arg[j] == ',' || !arg[j])
		{
			if (arg[j])
			{
				arg[j] = '\0';
				comma++;
				j++;
			}
			result += convert_rgb(&arg[i], conver);
			conver -= 8;
			i = j;
		}
	}
	if (comma != 2)
		return (-1);
	return (result);
}

int	get_floor_ceiling(t_data *data, char *arg, int flag)
{
	int	i;
	int	value;

	i = 0;
	while (WHITESPACE(arg[i]))
		i++;
	value = floor_ceiling_value(&arg[i], 0, 16, i);
	if (value == -1)
		return (-1);
	if (flag == F)
		data->F = value;
	else
		data->C = value;
	return (1);
}

int	check_arg(t_data *data, char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (WHITESPACE(line[i]))
		i++;
	if (!line[i])
		return (0);
	while (line[i + j] && !WHITESPACE(line[i + j]))
		j++;
	line[i + j++] = '\0';
	if (!ft_strcmp(&line[i], "NO") && !data->fd[NO])
		return (get_data(data, &line[i + j], NO));
	if (!ft_strcmp(&line[i], "SO") && !data->fd[SO])
		return (get_data(data, &line[i + j], SO));
	if (!ft_strcmp(&line[i], "WE") && !data->fd[WE])
		return (get_data(data, &line[i + j], WE));
	if (!ft_strcmp(&line[i], "EA") && !data->fd[EA])
		return (get_data(data, &line[i + j], EA));
	if (!ft_strcmp(&line[i], "F") && data->F == -1)
		return (get_floor_ceiling(data, &line[i + j], F));
	if (!ft_strcmp(&line[i], "C") && data->C == -1)
		return (get_floor_ceiling(data, &line[i + j], C));
	return (-1);
}
