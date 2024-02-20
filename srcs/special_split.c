/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:24:28 by mrusu             #+#    #+#             */
/*   Updated: 2024/02/15 14:32:35 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	count_words(char const *s, char c)
{
	int	word_c;
	int	is_word;

	word_c = 0;
	is_word = 0;
	while (*s)
	{
		if (*s != c && is_word == 0)
		{
			is_word = 1;
			word_c++;
		}
		else if (*s == c)
			is_word = 0;
		s++;
	}
	return (word_c);
}

static void	free_mem(char **str_tab, int i_t)
{
	int	i;

	i = 0;
	while (i < i_t)
	{
		free(str_tab[i]);
		i++;
	}
}

static int	words_alloc(int i_t, int w_l, char **str_tab, const char *start)
{
	str_tab[i_t] = (char *)malloc((w_l + 1) * sizeof(char));
	if (!str_tab[i_t])
	{
		free_mem(str_tab, i_t);
		return (0);
	}
	ft_memcpy(str_tab[i_t], start, w_l);
	str_tab[i_t][w_l] = '\0';
	return (1);
}

static void	*mem_string(char const *s, char **str_tab, char c)
{
	int			i_t;
	int			w_l;
	const char	*start;

	i_t = 0;
	while (*s)
	{
		w_l = 0;
		while (*s == c && *s != '\0')
			s++;
		start = s;
		while (*s != c && *s != '\0')
		{
			w_l++;
			s++;
		}
		if (w_l != 0)
		{
			if (words_alloc(i_t, w_l, str_tab, start) == 0)
				return (NULL);
			i_t++;
		}
	}
	str_tab[i_t] = NULL;
	return (str_tab);
}

char	**ft_split2(char const *s, char c)
{
	int		word_count;
	char	**str_tab;

	if (!s || !*s)
	{
		str_tab = (char **)malloc(sizeof(char *));
		if (!str_tab)
			return (NULL);
		str_tab[0] = NULL;
		return (str_tab);
	}
	word_count = count_words(s, c);
	str_tab = (char **)malloc((word_count + 1) * sizeof(char *));
	if (!str_tab)
		return (NULL);
	if (!mem_string(s, str_tab, c))
	{
		free(str_tab);
		return (NULL);
	}
	return (str_tab);
}
