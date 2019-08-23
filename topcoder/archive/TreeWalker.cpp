#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7, N = 1e6 + 6;

vector< int > child[N];
long long powmod(long long a, long long p) {
	long long ret = 1;
	for (; p; p >>= 1, a = a * a % mod)
		if (p & 1) ret = ret * a % mod;
	return ret;
}
void add(long long &v, long long x) {
	v += x;
	if (v >= mod) v -= mod;
}
long long ans = 0, inv2 = powmod(2, mod-2), inv2n, pw2n;
int n;
long long dfs(int v) {
	long long ret = pw2n, sum = 0, sum2 = 0;
	for (int u : child[v]) {
		long long now = dfs(u);
		add(ret, now);
		add(sum, now);
		add(sum2, now * now % mod);
	}
	add(ans, sum);
	sum = (sum * sum - sum2) % mod;
	sum = (sum * inv2) % mod;
	(sum *= inv2n) %= mod;
	add(ans, sum);
	ret = ret * inv2 % mod;
	return ret;
}

class TreeWalker {
public:
	int calc(int N, int A0, int B, int C, int MOD) {
		for (int i = 0; i < N; i++)
			child[i].clear();
		for (int i = 1; i < N; i++) {
			int p = A0 % i;
			child[p].push_back(i);
			A0 = (1LL * A0 * B + C) % MOD;
		}
		ans = 0;
		n = N;
		inv2n = powmod(2, mod-1-(n));
		pw2n = powmod(2, n);
		dfs(0);
		return ans;
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
		cout << "Testing TreeWalker (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1489482411;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 500.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		TreeWalker _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 4;
				int A0 = 0;
				int B = 1;
				int C = 1;
				int MOD = 1000;
				_expected = 34;
				_received = _obj.calc(N, A0, B, C, MOD); break;
			}
			case 1:
			{
				int N = 10;
				int A0 = 0;
				int B = 0;
				int C = 0;
				int MOD = 1;
				_expected = 13824;
				_received = _obj.calc(N, A0, B, C, MOD); break;
			}
			case 2:
			{
				int N = 16;
				int A0 = 15;
				int B = 1;
				int C = 1;
				int MOD = 16;
				_expected = 917506;
				_received = _obj.calc(N, A0, B, C, MOD); break;
			}
			case 3:
			{
				int N = 1000;
				int A0 = 385498676;
				int B = 349131547;
				int C = 115776323;
				int MOD = 614879544;
				_expected = 245566366;
				_received = _obj.calc(N, A0, B, C, MOD); break;
			}
			case 4:
			{
				int N = 100000;
				int A0 = 111222333;
				int B = 444555666;
				int C = 777888999;
				int MOD = 123456789;
				_expected = 119729770;
				_received = _obj.calc(N, A0, B, C, MOD); break;
			}
			/*case 5:
			{
				int N = ;
				int A0 = ;
				int B = ;
				int C = ;
				int MOD = ;
				_expected = ;
				_received = _obj.calc(N, A0, B, C, MOD); break;
			}*/
			/*case 6:
			{
				int N = ;
				int A0 = ;
				int B = ;
				int C = ;
				int MOD = ;
				_expected = ;
				_received = _obj.calc(N, A0, B, C, MOD); break;
			}*/
			/*case 7:
			{
				int N = ;
				int A0 = ;
				int B = ;
				int C = ;
				int MOD = ;
				_expected = ;
				_received = _obj.calc(N, A0, B, C, MOD); break;
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
