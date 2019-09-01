#include <stdio.h>
#include <stdlib.h>
#include "museum.h"

static int N;
static std::vector<int> Badge, Tshirt, Gift;

static void my_assert(int TF, const char* message){
	if(!TF){ puts(message); exit(1); }
}

int main(){
	my_assert(scanf("%d", &N) == 1, "Error: Invalid Input");
	my_assert(2 <= N && N <= 200000, "Error: Invalid Input");

	for(int i=0; i<N; i++){
		int a;
		my_assert(scanf("%d", &a) == 1, "Error: Invalid Input");
		my_assert(1 <= a && a <= 100, "Error: Invalid Input");
		Badge.push_back(a);
	}
	for(int i=0; i<N; i++){
		int a;
		my_assert(scanf("%d", &a) == 1, "Error: Invalid Input");
		my_assert(1 <= a && a <= 100, "Error: Invalid Input");
		Tshirt.push_back(a);
	}
	for(int i=0; i<N; i++){
		int a;
		my_assert(scanf("%d", &a) == 1, "Error: Invalid Input");
		my_assert(1 <= a && a <= 100, "Error: Invalid Input");
		Gift.push_back(a);
	}

	printf("%lld\n", CountSimilarPairs(Badge, Tshirt, Gift));
	return 0;
}
