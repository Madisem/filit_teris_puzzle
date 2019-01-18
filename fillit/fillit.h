/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeliu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 20:24:32 by jeliu             #+#    #+#             */
/*   Updated: 2018/12/01 13:48:43 by maseidua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUFF_SIZE 21
# include "./libft/libft.h"
# include <fcntl.h>
# include <unistd.h>

int		ft_simsqrt(int a);
void	clean_field(char *field, int *param, int k);
int		vert_int(char *str);
int		hor_int(char *str);
char	*create_field(int idx);
int		*save_param(char *str, int fw);
int		does_fit(char *field, int *param, int k);
int		fill_field(char **str, char *field, int idx, int i);
int		chd(int idx, char **str);
int		chl(const int idx, char **str);
int		chsh(int idx, char **str);
int		checktouch(int x[4], int y[4]);
int		count(int idx, char **str);
int		checkpattern(const int fd, int idx);

#endif
