#include "def.h"

void chain_main_nx(void);

int chaincont=0;
struct st_chain ret[Ceilings];

int main()
{
	chain_main_nx();
	printchain();
	return 0;
}
