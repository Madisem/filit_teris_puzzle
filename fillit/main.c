/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maseidua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 16:17:34 by maseidua          #+#    #+#             */
/*   Updated: 2018/12/01 13:44:14 by maseidua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_create(char **str, int idx)
{
	char	*pattern;

	str[idx] = "END\n";
	pattern = create_field(idx);
	while (!(fill_field(str, pattern, idx, 0)))
	{
		free(pattern);
		pattern = create_field(++idx);
	}
	ft_putstr(pattern);
}

int		checkpattern(const int fd, int idx)
{
	char	buff[BUFF_SIZE];
	int		n;
	char	*str[26];

	if (fd < 0 || BUFF_SIZE < 0)
		return (0);
	while ((n = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[n] = '\0';
		str[idx] = ft_strdup(buff);
		idx++;
	}
	if (n == 0 && (str[0] == NULL || str[0][0] == '\0'))
		ft_putstr("error\n");
	else if (str[idx - 1][20] == '\n')
		ft_putstr("error\n");
	else if (chd(idx, str) && chl(idx, str) && chsh(idx, str)
			&& count(idx, str) && idx < 26)
		ft_create(str, idx);
	else
		ft_putstr("error\n");
	return (1);
}

int		main(int ac, char **av)
{
	int fd;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		checkpattern(fd, 0);
		close(fd);
	}
	else
		ft_putstr("usage: ./fillit input_file");
	return (0);
}
