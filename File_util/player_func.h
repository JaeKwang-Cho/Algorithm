#ifndef PLAYER_FUNC_H
#define PLAYER_FUNC_H

#define DEFAULT_STR_LEN (64)
#define MAX_HP (1024)
#define MAX_MP (512)
#define MAX_STAT (32)

#include "File_utils.h"

typedef struct player_stats {
	unsigned int stats[8];
	unsigned int hit_point;
	unsigned int magic_point;
}player_stats_t;

typedef union {
	unsigned char dbuff;
	struct {
		unsigned char db0_speed : 1;
		unsigned char db1_offense : 1;
		unsigned char db2_magical : 1;
		unsigned char db3_defense : 1;
		unsigned char db4_resist : 1;
		unsigned char db5_lucky : 1;
		unsigned char db6_accuracy : 1;
		unsigned char db7_critical : 1;
	}dbuffs;
}dbuff_t;


enum dbff {
	DBFF_speed,
	DBFF_offense,
	DBFF_magical,
	DBFF_defense,
	DBFF_resist,
	DBFF_lucky,
	DBFF_accuracy,
	DBFF_critical,
}dbff_t;

typedef enum life { LIFE_ALLIVE, LIFE_DEATH }life_t;

typedef struct player {
	char name[DEFAULT_STR_LEN];
	player_stats_t* stats;
	dbuff_t* buff_state;
	dbuff_t* debuff_state;
	life_t life;
}player_t;


void damaged(struct player*, unsigned int damage);

void healed(struct player*, unsigned int cure);

void buff_player(struct player* , enum dbff);

void debuff_player(struct player* , enum dbff );

player_t* create_player(const char* name, unsigned int stat);

player_t* copy_player(struct player*, const char* name);

player_stats_t* set_player_stats(player_stats_t*, unsigned int );

dbuff_t* player_default_buff(dbuff_t*);

dbuff_t* player_default_debuff(dbuff_t*);

void print_player(player_t*);

void destory_player(player_t*);

#endif


