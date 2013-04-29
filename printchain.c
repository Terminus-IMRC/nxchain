#include "def.h"

void printchain()
{
	int i;

	printf("chaincont: %d\n", chaincont);
	for(i=0; i<chaincont; i++){
		printf("#%d: x: %d, y: %d\n", i, ret[i].x, ret[i].y);
	}
	return;
}
