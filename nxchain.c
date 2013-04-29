#include "def.h"

_Bool code[X][X];
int tatecont[X], yokocont[X];

extern int chaincont;

extern struct st_chain ret[Ceilings];

enum fbconst{
	FB_TATE, FB_YOKO
};

void chain_name();
void chain_e1_label();
void subst_code(int x, int y);
void subst_chain(enum ident ify, int x, int y);
void chk_afill();
void find_blank_and_add_afill(enum fbconst t, int elem);
void add_afill(enum fbconst t, int x, int y);

void chain_main_nx(void)
{
	int i;

	for(i=0; i<X; i++)
		ret[i].toafillcont=0;

	chain_name();
	chain_e1_label();
	return;
}

void chain_name()
{
	int i;

	subst_chain(NAME1, 0, 0);
	subst_chain(NAME2, X-1, 0);

	for(i=0; i<X; i++){
		subst_code(i, i);
		subst_code(i, X-1);
	}

	chk_afill();

	return;
}

void chain_e1_label()
{
	int i, j;
	int c;
	enum ident ify;

	for(i=0; i<X; i++){
		c=yokocont[i];
		if(c==X-2)
			ify=E1;
		else if(c==X-1)
			ify=E2;
		else if(c==X-4)
			ify=E3;
		subst_chain(ify, 0, i);
		for(j=0; j<X; j++)
			if(!code[j][i])
				subst_code(j, i);
		chk_afill();
	}
	return;
}

void chain_e2_spam()
{
	return;
}

void chain_e3_box()
{
	return;
}

void subst_code(int x, int y)
{
	code[x][y]=1;
	tatecont[x]++;
	yokocont[y]++;
	return;
}

void subst_chain(enum ident ify, int x, int y)
{
	ret[chaincont].chain=ify;
	ret[chaincont].x=x;
	ret[chaincont].y=y;
	chaincont++;
}

void chk_afill()
{
	int i;

	for(i=0; i<X; i++)
		if(tatecont[i]==X-1)
			find_blank_and_add_afill(FB_TATE, i);
		if(yokocont[i]==X-1)
			find_blank_and_add_afill(FB_YOKO, i);

	return;
}

void find_blank_and_add_afill(enum fbconst t, int elem)
{
	int i;
	int blank=-1;

	for(i=0; i<X; i++)
		if(t==FB_TATE)
			if(!code[elem][i])
				blank=i;
			else
				add_afill(t, elem, i);
		else
			if(!code[i][elem])
				blank=i;
			else
				add_afill(t, i, elem);
	assert(blank != -1);
}

void add_afill(enum fbconst t, int x, int y)
{
	int i, c=0;

	ret[chaincont].toafill[ret[chaincont].toafillcont].x=x;
	ret[chaincont].toafill[ret[chaincont].toafillcont].y=y;
	ret[chaincont].toafillcont++;

	for(i=0; i<X; i++)
		if(t==FB_TATE){
			if(i!=y){
				ret[Ceilings].toafillroad[ret[chaincont].toafillcont][c].x=x;
				ret[Ceilings].toafillroad[ret[chaincont].toafillcont][c].y=i;
				c++;
			}
		}else{
			if(i!=x){
				ret[Ceilings].toafillroad[ret[chaincont].toafillcont][c].x=i;
				ret[Ceilings].toafillroad[ret[chaincont].toafillcont][c].y=y;
				c++;
			}
		}

	return;
}
