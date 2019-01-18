/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maseidua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 16:17:34 by maseidua          #+#    #+#             */
/*   Updated: 2018/11/30 14:06:35 by maseidua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_simsqrt(int a)
{
	int	x;

	x = 2;
	while (x * x < a)
		x++;
	return (x);
}

void	clean_field(char *field, int *param, int k)
{
	int j;

	j = 0;
	while (j < 4)
		field[param[j++] + k] = '.';
}

int		hor_int(char *str)
{
	int count;
	int a;
	int j;

	j = 0;
	a = 0;
	while (j < 20 && str[j] != '#')
	{
		count = 0;
		while (str[j] != '\n' && str[j] != '\0')
		{
			if (str[j] == '.')
				count++;
			j++;
		}
		if (count == 4)
			a++;
		j++;
	}
	return (a);
}

int		vert_int(char *str)
{
	int m;
	int count;
	int b;
	int j;

	b = 0;
	m = 0;
	while (m < 4)
	{
		j = m;
		count = 0;
		if (str[j] == '#')
			break ;
		while (str[j] && str[j] == '.')
		{
			count++;
			j += 5;
		}
		if (count == 4)
			b++;
		m++;
	}
	return (b);
}
