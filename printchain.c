#include "def.h"
#include <string.h>

void printchain()
{
	int i;
	char s[0xff];

	printf("chaincont: %d\n", chaincont);
	for(i=0; i<chaincont; i++){
		printf("#%d: x: %d, y: %d\n", i, ret[i].x, ret[i].y);
		switch(ret[i].chain){
			case NAME1:
				strcpy(s, "NAME1");
				break;
			case NAME2:
				strcpy(s, "NAME2");
				break;
			case E1:
				strcpy(s, "E1");
				break;
			case E2:
				strcpy(s, "E2");
				break;
			case E3:
				strcpy(s, "E3");
				break;
			default:
				will_and_die("printchain: invalid the identifier", 1);
				break;
		}
		printf("\tidentifier: %s\n", s);
	}
	return;
}
