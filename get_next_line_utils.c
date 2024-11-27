/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimendon <dimendon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:11:26 by dimendon          #+#    #+#             */
/*   Updated: 2024/11/27 20:05:51 by dimendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *input)
{
	size_t	len;

	len = 0;
	while (input[len] != '\0')
		len++;
	return (len);
}

char	*ft_strdup(char *src, short flag)
{
	char	*dupe;
	int		size;
	int		i;

	if (src == NULL)
		return (NULL);
	else
		size = ft_strlen(src);
	dupe = malloc(size + 1);
	if (!dupe)
		return (NULL);
		
	i = 0;
	while (i < size)
	{
		dupe[i] = src[i];
		i++;
	}
	dupe[i] = '\0';
	if (flag == 1)
		free(src);
	return (dupe);
}

char	*ft_new_strlcat(char *alldata, const char *grabdata)
{
	size_t	src_len;
	size_t	dest_len;
	size_t	i;
	char	*newdata;

	src_len = 0;
	dest_len = 0;
	if (alldata != NULL)
		dest_len = ft_strlen(alldata);
	if (grabdata != NULL)
		src_len = ft_strlen(grabdata);
	newdata = malloc(dest_len + src_len + +1);
	if (!newdata)
		return (NULL);
	i = 0;
	while (i < dest_len)
	{
		newdata[i] = alldata[i];
		i++;
	}
	i = 0;
	while (i < src_len)
	{
		newdata[dest_len + i] = grabdata[i];
		i++;
	}
	newdata[dest_len + src_len] = '\0';
	free(alldata);
	return (newdata);
}

char	*putstr_nlpos(char *s, char **remains)
{
	char	*ret;
	int		i;
	int		size;

	ret = NULL;
	size = 0;
	i = 0;
	while (s[size])
	{
		if (s[size] == '\n')
		{
			size++;
			break;
		}
		size++;
	}

	if (s[size-1] == '\n')
    {
		ret = malloc(size + 1);
		if (!ret)
			return (NULL);

		while (i < size)
		{
			ret[i] = s[i];
			i++;
		}
		ret[i] = '\0';

		*remains = ft_strdup(s + size, 0);
	    free(s);
    }
	else if (s[size] == '\0')
	{
		ret = ft_strdup(s, 0);
		*remains = ft_strdup("", 0);
		free(s);
	}

	return (ret);
}
