#include <bits/stdc++.h>

using namespace std;

const int N = 4004, mod = 1e9 + 7, LG = 14;

long long dp[LG][N][2], C[N][N];
int tot[LG];

long long rec(int lv, int n, int ada) {
	long long & ret = dp[lv][n][ada];
	if (ret != -1)
		return ret;
	if (n > tot[lv])
		return 0;
	if (lv == 1) {
		return 1;
	}
	if (lv == 2) {
		if (ada) {
			return n == 0;
		}
	}
	if (n == 0) {
		return ada;
	}
	ret = 0;
	for (int i = 0; i < n; ++i) {
		int lef = i, rig = n - 1 - i;
		long long cur = C[n-1][lef];
		for (int a = 0; a < 2; ++a) {
			for (int b = 0; b < 2; ++b) {
				if ((a | b) == ada) {
					long long now = rec(lv-1, lef, a) * rec(lv-1, rig, b) % mod;
					ret = (ret + cur * now) % mod;
				}
			}
		}
	}
	return ret;
}

struct AlmostOptimalBST {
	vector <int> count(int N) {
		for (int i = 0; i < ::N; ++i) {
			C[i][0] = C[i][i] = 1;
			for (int j = 1; j < i; ++j) {
				C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
			}
		}
		memset(dp, -1, sizeof dp);
		tot[0] = 0;
		for (int i = 1; i < LG; ++i) {
			tot[i] = tot[i-1] * 2 + 1;
		}
		int lg = 1;
		while (tot[lg] < N) ++lg;
		int ans = 0;
		if (lg > 2)
			ans = rec(lg, N, 1) % mod;
		return {ans, 0};
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
		cout << "Testing AlmostOptimalBST (900.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1628078144;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 900.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		AlmostOptimalBST _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 4;
				int __expected[] = {4, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.count(N); break;
			}
			case 1:
			{
				int N = 8;
				int __expected[] = {9680, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.count(N); break;
			}
			case 2:
			{
				int N = 31;
				int __expected[] = {0, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.count(N); break;
			}
			/*case 3:
			{
				int N = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.count(N); break;
			}*/
			/*case 4:
			{
				int N = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.count(N); break;
			}*/
			/*case 5:
			{
				int N = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.count(N); break;
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
			cout << "           Expected: {";
			for (unsigned i = 0; i < _expected.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _expected[i];
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _received[i];
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
