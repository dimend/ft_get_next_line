/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimendon <dimendon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:11:21 by dimendon          #+#    #+#             */
/*   Updated: 2024/12/04 14:21:41 by dimendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# elif BUFFER_SIZE < 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 42
# elif BUFFER_SIZE > 9999
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 5000
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char *input, const char delimiter);
char	*ft_strdup(char *src, const char delimiter, short flag);
char	*ft_new_strlcat(char *alldata, const char *grabdata);
char	*putstr_nlpos(char *s, char **remains);

#endif
