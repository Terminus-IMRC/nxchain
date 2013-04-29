#ifndef __DEF_INSIDE__
#define __DEF_INSIDE__
	#include <stdio.h>
	#include <assert.h>
	#include "x.h"

	enum ident{
		NAME1, NAME2, E1, E2, E3
	};

	struct coord{
		int x, y;
	};

	struct st_chain{
		enum ident chain;
		int x, y;
		struct coord toafill[Ceilings];
		int toafillcont;
		struct coord toafillroad[Ceilings][X-1];
	};

	extern struct st_chain ret[Ceilings];
	extern int chaincont;

	void will_and_die(char*, int);
	void printchain();

#endif
