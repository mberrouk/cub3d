/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberrouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 20:30:43 by mberrouk          #+#    #+#             */
/*   Updated: 2023/09/30 23:41:53 by mberrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsfile/parsing.h"

int	main(int ac, char *av[])
{
	t_data	data;

	if (init_pars(ac, av, &data) == ERROR)
		return (1);
	clean_parsing_data(&data);
	return (0);
}
