/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maseidua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 16:17:34 by maseidua          #+#    #+#             */
/*   Updated: 2018/12/01 13:44:06 by maseidua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*create_field(int idx)
{
	int		n;
	int		fw;
	char	*field;

	fw = ft_simsqrt(idx * 4);
	field = ft_strnew((fw + 1) * fw);
	n = 0;
	while (n < (fw + 1) * fw)
	{
		field[n] = '.';
		if ((n + 1) % (fw + 1) == 0)
			field[n] = '\n';
		n++;
	}
	return (field);
}

int		*save_param(char *str, int fw)
{
	int j;
	int fi;
	int	*param;

	fi = 0;
	j = 0;
	param = ft_memalloc(4);
	while (str[j])
	{
		if (str[j] == '#')
			param[fi++] = (j % 5 - vert_int(str))
				+ ((j / 5 - hor_int(str)) * fw);
		j++;
	}
	return (param);
}

int		does_fit(char *field, int *param, int k)
{
	int j;

	j = 0;
	while (j < 4)
	{
		if (field[param[j] + k] != '.')
			return (-1);
		j++;
	}
	return (1);
}

int		fill_field(char **str, char *field, int idx, int i)
{
	int k;
	int fw;
	int	*param;
	int j;

	if (ft_strcmp(str[i], "END\n") == 0)
		return (1);
	k = 0;
	fw = ft_simsqrt(idx * 4) + 1;
	param = save_param(str[i], fw);
	while (k < (int)ft_strlen(field))
	{
		j = 0;
		if ((does_fit(field, param, k)) >= 0)
		{
			while (j < 4)
				field[param[j++] + k] = i + 65;
			if (fill_field(str, field, idx, i + 1))
				return (1);
			clean_field(field, param, k);
		}
		k++;
	}
	return (0);
}
