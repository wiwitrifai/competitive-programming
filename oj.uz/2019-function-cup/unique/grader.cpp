#include <stdio.h>
#include <stdlib.h>
#include "unique.h"

static int N, arr[222], unq[222][222], chk[222];

static void my_assert(int TF, const char* message){
	if(!TF){ puts(message); exit(0); }
}

static int call_cnt = 0;
int UniqueCount(int R, int C){
	call_cnt++;
	my_assert(call_cnt <= 40000, "Wrong : Too Much Calls");
	my_assert(R >= 0 && C < N && R <= C, "Wrong : Invalid R, C");

	return unq[R][C];
}

int main(){
	my_assert(scanf("%d", &N) == 1, "Error: Invalid Input");
	my_assert(2 <= N && N <= 200, "Error: Invalid Input");

	for(int i = 0; i < N; i++){
		my_assert(scanf("%d", &arr[i]) == 1, "Error: Invalid Input");
		my_assert(1 <= arr[i] && arr[i] <= 200, "Error: Invalid Input");
	}
	for(int i = 0; i < N; i++){
		int u = 0;
		for(int j = 1; j <= 200; j++) chk[j] = 0;
		for(int j = i; j < N; j++){
			chk[arr[j]]++;
			if(chk[arr[j]] == 1) u++;
			if(chk[arr[j]] == 2) u--;
			unq[i][j] = u;
		}
	}
	for(int i = 1; i <= 200; i++) chk[i] = 0;
	for(int i = 0; i < N; i++) chk[arr[i]]++;

	std::vector<int> rpd = PickUnique(N);
	my_assert((int) rpd.size() == N, "Wrong: Wrong Answer");
	for(int i = 0; i < N; i++){
		my_assert(rpd[i] == 0 || rpd[i] == 1, "Wrong: Wrong Answer");
		if(chk[arr[i]] == 1) my_assert(rpd[i], "Wrong : Wrong Answer");
		if(rpd[i]) my_assert(chk[arr[i]] == 1, "Wrong : Wrong Answer");
	}
	printf("Correct\n%d\n", call_cnt);
	return 0;
}
