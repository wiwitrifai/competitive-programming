#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7, N = 2018;
long long C[N][N], pw[N], dp[N];
class RndSubTree {
public:
	long long powmod(long long b, long long p) {
		long long r = 1;
		for (; p; p >>= 1, b = b * b % mod)
			if (p & 1)
				r = r * b % mod;
		return r;
	}
	int count(int k) {
		for (int i = 0; i < N; ++i) {
			C[i][0] = C[i][i] = 1;
			for (int j = 1; j < i; ++j)
				C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod; 
		}
		fill(dp, dp+k+1, 0);
		dp[0] = 0;
		for (int i = 0; i < k; ++i) {
			for (int j = 0; j <= i; ++j) {
				int now = i+j+1;
				if (now > k) continue;
				long long pl = C[now-1][i] * powmod(2, mod-now) % mod;
				if (i != j) pl = pl * 2 % mod;
				long long cost = (1LL * i*(k-i) + 1LL * j *(k-j)) % mod;
				dp[now] = (dp[now] + pl * (dp[i] + dp[j] + cost)) % mod;
				if (dp[now] < 0) dp[now] += mod;
			}
		}
		return dp[k];
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
		cout << "Testing RndSubTree (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1521303214;
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
		RndSubTree _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int k = 1;
				_expected = 0;
				_received = _obj.count(k); break;
			}
			case 1:
			{
				int k = 2;
				_expected = 1;
				_received = _obj.count(k); break;
			}
			case 2:
			{
				int k = 3;
				_expected = 4;
				_received = _obj.count(k); break;
			}
			case 3:
			{
				int k = 4;
				_expected = 875000016;
				_received = _obj.count(k); break;
			}
			case 4:
			{
				int k = 5;
				_expected = 531250023;
				_received = _obj.count(k); break;
			}
			/*case 5:
			{
				int k = ;
				_expected = ;
				_received = _obj.count(k); break;
			}*/
			/*case 6:
			{
				int k = ;
				_expected = ;
				_received = _obj.count(k); break;
			}*/
			/*case 7:
			{
				int k = ;
				_expected = ;
				_received = _obj.count(k); break;
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
