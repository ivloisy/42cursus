/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 18:01:29 by ivloisy           #+#    #+#             */
/*   Updated: 2020/04/09 18:01:39 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>

size_t				ft_strlen(const char *s);
int					ft_isdigit(int c);
int					ft_toupper(int c);
char				*ft_strchr(const char *s, int c);
char				*ft_strdup(const char *s1);

char				*ft_itoa(int n);

char				*ft_strcpy(char *dest, char *src);
char				*ft_itoa_base(int n, int base);

#endif
