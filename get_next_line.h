/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimendon <dimendon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:11:21 by dimendon          #+#    #+#             */
/*   Updated: 2024/11/27 20:07:43 by dimendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>


char    *get_next_line(int fd);
size_t	ft_strlen(const char *input);
char	*ft_strdup(char *src, short flag);
char	*ft_new_strlcat(char *alldata, const char *grabdata);
char	*putstr_nlpos(char *s, char **remains);

#endif
