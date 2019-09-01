#include <stdio.h>
#include <stdlib.h>
#include "king.h"
#include "vassal.h"

static int N, chk[101010];
static std::vector<int> W, C;

static void my_assert(int TF, const char* message){
	if(!TF){ puts(message); exit(0); }
}

int main(){
	my_assert(scanf("%d", &N) == 1, "Error: Invalid Input");
	my_assert(1 <= N && N <= 100000, "Error: Invalid Input");

	W.resize(N);
	for(int i = 0; i < N; i++){
		my_assert(scanf("%d", &W[i]) == 1, "Error: Invalid Input");
		my_assert(1 <= W[i] && W[i] <= 1000000, "Error: Invalid Input");
	}

	C.resize(N);
	for(int i = 0; i < N; i++){
		my_assert(scanf("%d", &C[i]) == 1, "Error: Invalid Input");
		my_assert(1 <= C[i] && C[i] <= 1000000, "Error: Invalid Input");
		if(i) my_assert(C[i-1] <= C[i], "Error: Invalid Input");
	}

	long long num = SendInfo(W, C);
	my_assert(0 <= num && num < (1ll << 60), "Wrong[1] : Invalid Number");

	int chair_cnt = 0;
	Init(num, C);
	for(int i = 0; i < N; i++){
		int ci = Maid(W[i]);
		my_assert(-1 <= ci && ci < N, "Wrong[2] : Invalid Chair Number");
		my_assert(-1 == ci || !chk[ci], "Wrong[2] : Invalid Chair Number");
		my_assert(-1 == ci || W[i] <= C[ci], "Wrong[2] : Invalid Chair");
		chk[ci] = 1;
		if(ci >= 0) chair_cnt++;
	}

	printf("Correct\n%d\n", chair_cnt);
	return 0;
}
