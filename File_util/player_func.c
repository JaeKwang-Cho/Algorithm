#include "player_func.h"

#define FLAG_ON(a,b) 

const size_t p_size = sizeof(player_t);
const size_t p_stat_size = sizeof(player_stats_t);
const size_t dbuff_size = sizeof(dbuff_t);
const size_t stat_num = 8;
const char* stat_name[] = { "speed",	"offense",	"magical",	"defense",	"resist",	"lucky",	"accuracy",	"critical", };

void damaged(struct player* p, unsigned int damage) {
	if (p->life == LIFE_DEATH) {
		printf("He's already dead : terminate this func\n");
		return;
	}
	unsigned int hp = p->stats->hit_point;
	if (hp <= damage) {
		p->life = LIFE_DEATH;
		p->stats->hit_point = 0;
		printf("you killed him : LIFE_DEATH\n");
		return;
	}
	hp = hp - damage;
	printf("you hit him : damage is %d, hp remains %d\n", damage, hp);
	p->stats->hit_point = hp;
	return;
}

void healed(struct player* p, unsigned int cure) {
	if (p-> life == LIFE_DEATH) {
		printf("He's in dead : terminate this func\n");
		return;
	}
	unsigned int hp = p->stats->hit_point;
	if ((hp + cure) >=  MAX_HP) {
		p->stats->hit_point = MAX_HP;
		printf("you healed him fully : MAX_HP\n");
		return;
	}
	hp = hp + cure;
	printf("you healed him : cure is %d, hp remains %d\n", cure, hp);
	p->stats->hit_point = hp;
	return;
}

void buff_player(struct player* p, enum dbff ff) {
	if (p == NULL) {
		printf("invalid p, p is NULL. terminate this func\n");
		return;
	}
	dbuff_t* pb = (p->buff_state);
	switch(ff){
		case  DBFF_speed :
			pb->dbuffs.db0_speed = 1;
			break;
		case  DBFF_offense :
			pb->dbuffs.db1_offense = 1;
			break;
		case  DBFF_magical :
			pb->dbuffs.db2_magical = 1;
			break;
		case  DBFF_defense :
			pb->dbuffs.db3_defense = 1;
			break;           
		case  DBFF_resist :
			pb->dbuffs.db4_resist = 1;
			break;
		case  DBFF_lucky :
			pb->dbuffs.db5_lucky = 1;
			break; 
		case  DBFF_accuracy :
			pb->dbuffs.db6_accuracy = 1;
			break;
		case  DBFF_critical :
			pb->dbuffs.db7_critical = 1;
			break;
	}
	return;
}

void debuff_player(struct player* p, enum dbff ff) {
	if (p == NULL) {
		printf("invalid p, p is NULL. terminate this func\n");
		return;
	}
	dbuff_t* pd = (p->debuff_state);
	switch (ff) {
	case  DBFF_speed:
		pd ->dbuffs.db0_speed = 1;
		break;
	case  DBFF_offense:
		pd->dbuffs.db1_offense = 1;
		break;
	case  DBFF_magical:
		pd->dbuffs.db2_magical = 1;
		break;
	case  DBFF_defense:
		pd->dbuffs.db3_defense = 1;
		break;
	case  DBFF_resist:
		pd->dbuffs.db4_resist = 1;
		break;
	case  DBFF_lucky:
		pd->dbuffs.db5_lucky = 1;
		break;
	case  DBFF_accuracy:
		pd->dbuffs.db6_accuracy = 1;
		break;
	case  DBFF_critical:
		pd->dbuffs.db7_critical = 1;
		break;
	}
	return;
}

player_t* create_player(const char* name,unsigned int stat) {
	if (name == NULL) {
		printf("***\"name\" is NULL ptr : terminate create_player..\n");
		return NULL;
	}
	player_t* np = (player_t*)malloc(p_size);
	if (np == NULL) {
		printf("player_t allocation is failed\n");
		free(np);
		return NULL;
	}
	size_t arrlen = strlen(name);
	if (arrlen >= DEFAULT_STR_LEN-1) {
		printf("name is too long.\n");
		strncpy(np->name, name,DEFAULT_STR_LEN);
		(np->name)[DEFAULT_STR_LEN - 1] = '\0';
	}
	else if(arrlen == (int)0){
		printf("name is NULL : strlen(name) is 0\n");
		return NULL; 
	}
	else {
		strncpy(np->name, name, arrlen);
		(np->name)[arrlen] = '\0';
	}
	player_stats_t* ps = set_player_stats((np->stats),stat);
	(np->stats) = ps;

	dbuff_t* pb = player_default_buff((np->buff_state));
	(np->buff_state) = pb;

	dbuff_t* pd = player_default_buff((np->debuff_state));
	(np->debuff_state) = pd;

	np->life = LIFE_ALLIVE;

	return np;
}

player_t* copy_player(struct player* sp, const char* name) {
	size_t arrlen;
	if (sp == NULL) {
		printf("source player is NULL, default return NULL\n");
		return NULL;
	}
	if (name == NULL) {
		printf("name is NULL, daefault return NULL\n");
		return NULL;
	}
	player_t* np = (player_t*)malloc(p_size);
	if (np == NULL) {
		printf("new player allocation is failed. return NULL\n");
		return NULL;
	}
	player_stats_t* np_s = (player_stats_t*)malloc(p_stat_size);
	if (np_s == NULL) {
		printf("new player_stats allocation is failed. return NULL\n");
		return NULL;
	}
	np->stats = np_s;
	dbuff_t* np_bf = (dbuff_t*)malloc(dbuff_size);
	if (np_bf == NULL) {
		printf("new player_buff allocation is failed. return NULL\n");
		return NULL;
	}
	np->buff_state = np_bf;
	dbuff_t* np_df = (dbuff_t*)malloc(dbuff_size);
	if (np_df == NULL) {
		printf("new player_buff allocation is failed. return NULL\n");
		return NULL;
	}
	np->debuff_state = np_df;

	memcpy(np->stats, sp->stats, p_stat_size);
	*(np->buff_state) = *(sp->buff_state);
	*(np->debuff_state) = *(sp->debuff_state);
	np->life = np->life;

	arrlen = strlen(name);
	if (arrlen >= DEFAULT_STR_LEN - 1) {
		printf("name is too long.\n");
		strncpy(np->name, name, DEFAULT_STR_LEN);
		(np->name)[DEFAULT_STR_LEN - 1] = '\0';
	}
	else if (arrlen == (int)0) {
		printf("name is NULL : strlen(name) is 0\n");
		return NULL;
	}
	else {
		strncpy(np->name, name, arrlen);
		(np->name)[arrlen] = '\0';
	}
	return np;
}

player_stats_t* set_player_stats(player_stats_t* p, unsigned int stat) {
	int i;
	p = (player_stats_t*)malloc(p_stat_size);
	if (p == NULL) {
		printf("player_stats_t allocation is failed\n");
		free(p);
		return NULL;
	}
	p->hit_point = MAX_HP;
	p->magic_point = MAX_MP;

	for (i = 0; i < 8; i++) {
		p->stats[i] = stat;
	}
	return p;
}
dbuff_t* player_default_buff(dbuff_t* b) {
	if (b == NULL) {
		printf("input dbuff_t* is NULL\n");
		return NULL;
	}
	b = (dbuff_t*)malloc(dbuff_size);
	if (b == NULL) {
		printf("dbuff_t allcation is failed\n");
		free(b);
		return NULL;
	}
	b->dbuff = 0;
	return b;
}
dbuff_t* player_default_debuff(dbuff_t* d) {
	if (d == NULL) {
		printf("input dbuff_t* is NULL\n");
		return NULL;
	}
	d = (dbuff_t*)malloc(dbuff_size);
	if (d == NULL) {
		printf("dbuff_t allcation is failed\n");
		free(d);
		return NULL;
	}
	d->dbuff = 0;
	return d;
}

void print_player(player_t* p) {
	unsigned int i;
	player_stats_t* ps = p->stats;
	dbuff_t* pb = p->buff_state;
	dbuff_t* pd = p->debuff_state;
	printf("name : %s\n", p->name);
	if (ps != NULL) {
		printf("hp : %d mp : %d\n", ps->hit_point, ps->magic_point);
		for (i = 0; i < stat_num; i++) {
			printf("%s : %d\n", stat_name[i], ps->stats[i]);
		}
	}
	if (pb != NULL) {
	printf("buff : %c , %d, %x\n", pb->dbuff, pb->dbuff, pb->dbuff);
	}
	if (pd != NULL) {
	printf("buff : %c , %d, %x\n", pd->dbuff, pb->dbuff, pd->dbuff);
	}

	return;
}

void destory_player(player_t* p) {
	free((p->buff_state));
	(p->buff_state) = NULL;

	free((p->debuff_state));
	(p->debuff_state) = NULL;

	free((p->stats));
	(p->stats) = NULL;

	free(p);
	p = NULL;

	return;
}


