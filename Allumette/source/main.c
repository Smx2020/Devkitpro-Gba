/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@doussaud.org>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 17:45:54 by olivier           #+#    #+#             */
/*   Updated: 2018/09/01 18:04:14 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int main(int argc, char const *argv[])
{
	int obj_used= 0;
	int rules[3]={3,5,7};
	int	allumette=15;

	setup_game_palet();
	setup_VRAM();
	setup_background();

	while(42)
	{
		menu_main(&allumette,rules,&obj_used);
		game_main(allumette,rules,&obj_used);
	}
	return 0;
}
