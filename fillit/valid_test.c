/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeliu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 20:20:00 by jeliu             #+#    #+#             */
/*   Updated: 2018/12/01 13:20:52 by jeliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int	chd(int idx, char **str)
{
	int i;
	int j;
	int len;

	i = 0;
	while (i < idx)
	{
		len = ft_strlen(str[i]);
		j = 0;
		while (j < len)
		{
			if (str[i][j] != '\n' && str[i][j] != '.' && str[i][j] != '#')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	chl(const int idx, char **str)
{
	int i;
	int j;
	int len;

	i = 0;
	while (i < idx)
	{
		len = ft_strlen(str[i]);
		j = 4;
		while (j < len)
		{
			if (str[i][j] == '\n')
				j += 5;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int	checktouch(int x[4], int y[4])
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (x[i] + 1 == x[j] && y[i] == y[j])
				count++;
			if (y[i] + 1 == y[j] && x[i] == x[j])
				count++;
			j++;
		}
		i++;
	}
	if (count < 3)
		return (0);
	return (1);
}

int	count(int idx, char **str)
{
	int j;
	int len;
	int count;
	int hashcount;

	while (idx--)
	{
		len = ft_strlen(str[idx]);
		j = 0;
		count = 0;
		hashcount = 0;
		while (j <= len)
		{
			if (str[idx][j] == '#')
				count++;
			if (str[idx][j] == '.')
				hashcount++;
			j++;
		}
		if (count != 4 || hashcount != 12)
			return (0);
	}
	return (1);
}

int	chsh(int idx, char **str)
{
	int j;
	int len;
	int count;
	int x[4];
	int y[4];

	while (idx--)
	{
		len = ft_strlen(str[idx]);
		j = 0;
		count = 0;
		while (j <= len)
		{
			if (str[idx][j] == '#' && count < 4)
			{
				x[count] = j / 5;
				y[count] = j % 5;
				count++;
			}
			j++;
		}
		if (!checktouch(x, y))
			return (0);
	}
	return (1);
}
