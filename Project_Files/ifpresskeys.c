/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifpresskeys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gotunc <gotunc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:44:17 by gotunc            #+#    #+#             */
/*   Updated: 2024/02/19 01:48:25 by gotunc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ifpresskeyleft(t_data *data)
{
	if (data->charvisionangle == 354)
		data->charvisionangle = 0;
	else
		data->charvisionangle += 6;
	printf("new angle: %d\n", data->charvisionangle);
	// kafayı kafayı sola çevirir
}

void	ifpresskeyright(t_data *data)
{
	if (data->charvisionangle == 0)
		data->charvisionangle = 354;
	else
		data->charvisionangle -= 6;
	printf("new angle: %d\n", data->charvisionangle);
	// kafayı sağa çevirir
}
