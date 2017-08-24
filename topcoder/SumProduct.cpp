#include <bits/stdc++.h>

using namespace std;

const int N = 1017, mod = 1e9 + 7;

long long C[N][N];
long long dp[11][N];


class SumProduct {
public:
	int findSum(vector <int> amount, int blank1, int blank2) {
		for (int i = 0; i < N; i++) {
			C[i][0] = C[i][i] = 1;
			for (int j = 1; j < i; j++)
				C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
		}
		long long ans = 0;
		long long mula = 0, mulb = 0, cur = 1;
		for (int i = 0; i < max(blank1, blank2); i++) {
			if (i < blank1)
				mula = (mula + cur) % mod;
			if (i < blank2)
				mulb = (mulb + cur) % mod;
			cur = (cur * 10) % mod;
		}
		mula = (mula * mulb) % mod;
		int tot = blank1 + blank2 - 2;
		for (int a = 0; a < 10; a++) {
			if (amount[a] == 0) continue;
			amount[a]--;
			for (int b = 0; b < 10; b++) {
				if (amount[b] == 0) continue;
				amount[b]--;
				memset(dp, 0, sizeof dp);
				dp[0][0] = 1;
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j <= tot; j++) if (dp[i][j]) {
						for (int k = 0; k <= amount[i]; k++) {
							if (k + j > tot) continue;
							dp[i+1][k+j] = (dp[i+1][k+j] + dp[i][j] * C[tot-j][k]) % mod;
						}
					}
				}
				ans = (ans + (dp[10][tot] * a % mod) * b) % mod;
				amount[b]++;
			}
			amount[a]++;
		}
		ans = (ans * mula) % mod;
		if (ans < 0) ans += mod;
		return (int) ans;
	}
};

// BEGIN CUT HERE
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
	if (argc == 1) 
	{
		cout << "Testing SumProduct (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1503572411;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 250.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		SumProduct _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int amount[] = {0,2,1,1,0,0,0,0,0,0};
				int blank1 = 2;
				int blank2 = 2;
				_expected = 4114;
				_received = _obj.findSum(vector <int>(amount, amount+sizeof(amount)/sizeof(int)), blank1, blank2); break;
			}
			case 1:
			{
				int amount[] = {1,6,0,0,0,0,0,0,0,0};
				int blank1 = 1;
				int blank2 = 2;
				_expected = 22;
				_received = _obj.findSum(vector <int>(amount, amount+sizeof(amount)/sizeof(int)), blank1, blank2); break;
			}
			case 2:
			{
				int amount[] = {1,2,3,4,5,6,7,8,9,10};
				int blank1 = 15;
				int blank2 = 3;
				_expected = 340242570;
				_received = _obj.findSum(vector <int>(amount, amount+sizeof(amount)/sizeof(int)), blank1, blank2); break;
			}
			case 3:
			{
				int amount[] = {3,14,15,92,65,35,89,79,32,38};
				int blank1 = 46;
				int blank2 = 26;
				_expected = 417461139;
				_received = _obj.findSum(vector <int>(amount, amount+sizeof(amount)/sizeof(int)), blank1, blank2); break;
			}
			case 4:
			{
				int amount[] = {100,100,100,100,100,100,100,100,100,100};
				int blank1 = 100;
				int blank2 = 100;
				_expected = 372980218;
				_received = _obj.findSum(vector <int>(amount, amount+sizeof(amount)/sizeof(int)), blank1, blank2); break;
			}
			/*case 5:
			{
				int amount[] = ;
				int blank1 = ;
				int blank2 = ;
				_expected = ;
				_received = _obj.findSum(vector <int>(amount, amount+sizeof(amount)/sizeof(int)), blank1, blank2); break;
			}*/
			/*case 6:
			{
				int amount[] = ;
				int blank1 = ;
				int blank2 = ;
				_expected = ;
				_received = _obj.findSum(vector <int>(amount, amount+sizeof(amount)/sizeof(int)), blank1, blank2); break;
			}*/
			/*case 7:
			{
				int amount[] = ;
				int blank1 = ;
				int blank2 = ;
				_expected = ;
				_received = _obj.findSum(vector <int>(amount, amount+sizeof(amount)/sizeof(int)), blank1, blank2); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (_received == _expected)
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
