/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifpresskeys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gotunc <gotunc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:44:17 by gotunc            #+#    #+#             */
/*   Updated: 2024/02/28 21:31:01 by gotunc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ifpresskeyleft(t_data *data)
{
	if (data->charvisionangle == 358)
		data->charvisionangle = 0;
	else
		data->charvisionangle += 2;
	rayat(data);
	printf("new angle: %d\n", data->charvisionangle);
	// kafayı kafayı sola çevirir
}

void	ifpresskeyright(t_data *data)
{
	if (data->charvisionangle == 0)
		data->charvisionangle = 358;
	else
		data->charvisionangle -= 2;
	rayat(data);
	printf("new angle: %d\n", data->charvisionangle);
	// kafayı sağa çevirir
}
