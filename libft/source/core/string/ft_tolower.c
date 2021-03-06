/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 02:20:13 by viwade            #+#    #+#             */
/*   Updated: 2019/06/11 00:24:46 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>

int		ft_tolower(int c)
{
	return (c | (('A' <= c && c <= 'Z') << 5));
}
