/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_point.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 01:52:06 by maparmar          #+#    #+#             */
/*   Updated: 2019/03/12 02:10:31 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */ 
#ifndef T_POINT_FLOOD_FILL
# define T_POINT_FLOOD_FILL

typedef struct 	s_point {
    int 		x;				// x : Width  | x-axis
    int 		y;				// y : Height | y-axis
} 				t_point;

void  flood_fill(char **tab, t_point size, t_point begin);
#endif
