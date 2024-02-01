/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 09:36:48 by ekuchel           #+#    #+#             */
/*   Updated: 2023/03/11 15:39:07 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*# include <stdarg.h> is library for variadic arguments function*/
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_format(va_list args, char format);
int		ft_printfc(char c);
int		ft_printfs(char *s);
int		ft_printfd(int n);
int		ft_printfu(unsigned int n);
int		ft_printfx(unsigned long n, char c);
int		ft_printfp(unsigned long int n);
int		ft_printf(const char *str, ...);
char	ft_check(char value);
#endif
