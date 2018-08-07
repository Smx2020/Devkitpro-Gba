/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@doussaud.org>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 13:03:41 by olivier           #+#    #+#             */
/*   Updated: 2018/08/07 13:48:52 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "bot.h"

t_game *create_game(int allumette,int *rules, int *obj_used)
{
	t_sprite *test;
	t_list *fioles=NULL;
	int i=0;
	int* temp;
	t_game *board= NULL;

	board = (t_game*)malloc(sizeof(t_game));
	while (i < allumette)
	{
		if (i%2)
			setup_sprite(&test,0,0,12,2,1,obj_used);
		else
			setup_sprite(&test,0,0,16,0,1,obj_used);
		list_push_back(&fioles,test);
		i = i + 1;
	}
	list_shape(fioles,24,24);

	board->disp = (t_sprite**)malloc(3*sizeof(t_sprite));
	setup_sprite(&(board->disp[0]),172,28,20,1,1,obj_used);
	setup_sprite(&(board->disp[2]),188,60,20,1,1,obj_used);
	setup_sprite(&(board->disp[1]),204,28,20,1,1,obj_used);

	i = 0;
	temp = (int*)malloc(3*sizeof(int));
	while (i < 3)
	{
		temp[i] = rules[i];
		set_object_tile((board->disp[i])->attribute,20 + 4 * rules[i]);
		i++;
	}

	board->rules = temp;
	board->objects = fioles;
	board->allumette = allumette;
	board->turn = 1;
	board->ani = 0;
	return(board);
}

void refresh_game(t_game *board)
{
	t_list *list;
	t_sprite *tmp;

	int i=0;

	list = board->objects;
	while (list)
	{
		tmp = list->data;
		if (i < board->allumette + board->ani)
			set_object_mode(tmp->attribute,0);
		else
			set_object_mode(tmp->attribute,2);
		list = list->next;
		i++;
	}
	board->ani--;
	if (board->ani < 0)
		board->ani = 0;
}

void player_play(t_game *board, int play)
{
	if (board->turn > 0 && board->ani == 0)
	{
		board->allumette = board->allumette - play;
		board->turn = - board->turn;
		board->ani = play;
		refresh_game(board);
	}
}

void bot_play(t_game *board)
{
	int play;

	if (board->turn < 0 && board->ani == 0)
	{
		play = bot(board->allumette);
		board->allumette = board->allumette - play;
		board->turn = - board->turn;
		board->ani = play;
		refresh_game(board);
	}
}
