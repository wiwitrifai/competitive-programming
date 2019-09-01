#include <stdio.h>
#include <stdlib.h>
#include "cross.h"

static int N, K;
static std::vector<int> In, Out;

static void my_assert(int TF, const char* message){
	if(!TF){ puts(message); exit(1); }
}

int main(){
	my_assert(scanf("%d%d", &N, &K) == 2, "Error: Invalid Input");
	my_assert(1 <= K && K <= N && N <= 200000, "Error: Invalid Input");

	for(int i=0; i<N; i++){
		int a;
		my_assert(scanf("%d", &a) == 1, "Error: Invalid Input");
		my_assert(1 <= a && a <= 1000000000, "Error: Invalid Input");
		In.push_back(a);
	}
	for(int i=0; i<N; i++){
		int a;
		my_assert(scanf("%d", &a) == 1, "Error: Invalid Input");
		my_assert(In[i] < a && a <= 1000000000, "Error: Invalid Input");
		Out.push_back(a);
	}

	printf("%lld\n", SelectCross(K, In, Out));
	return 0;
}
