#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hiccup.h"

static char st[1000101]; static int len;

static void my_assert(int TF, const char* message){
	if(!TF){ puts(message); exit(0); }
}

int main(){
	my_assert(scanf("%s", st) == 1, "Error: Invalid Input");
	len = strlen(st);
	my_assert(1 <= len && len <= 1000000, "Error: Invalid Input");

	for(int i=0; i<len; i++){
		my_assert(st[i]=='H' || st[i]=='C' || st[i]=='!', "Error: Invalid Input");
	}

	std::string ss = st;
	printf("%d\n", HicCup(ss));
	return 0;
}
