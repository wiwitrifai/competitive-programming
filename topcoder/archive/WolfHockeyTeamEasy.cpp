#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
long long powmod(long long a, long long p) {
	long long ret = 1;
	for (; p; p >>= 1, a = a * a % mod)
		if (p & 1) ret = ret * a % mod;
	return ret;
}
long long fac[2048];
long long dp[2048][1024];

class WolfHockeyTeamEasy {
public:
	int count(int N, int K) {
		memset(dp, 0, sizeof dp);
		dp[0][0] = 1;
		for (int i = 0; i <= 2 * N; i++) {
			for (int j = 0; j * 2 <= i; j++) {
				if (dp[i][j]) {
					(dp[i+1][j] += dp[i][j]) %= mod;
					if ((j + 1) * 2 <= i+1)
						(dp[i+1][j+1] += dp[i][j]) %= mod;
				}
			}
		}
		fac[0] = 1;
		for (int i = 1; i <= 2* N; i++)
			fac[i] = fac[i-1] * i % mod; 
		long long ans = 0;
		if (K < N)
			ans = 1;
		for (int i = max(K, N); i < 2 * N-1; i++) {
			ans = (ans + dp[i+1][i-N+1]) % mod;
		}
		ans = (ans * fac[N] * 2) % mod;
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
		cout << "Testing WolfHockeyTeamEasy (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1489477193;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		WolfHockeyTeamEasy _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 2;
				int K = 0;
				_expected = 12;
				_received = _obj.count(N, K); break;
			}
			case 1:
			{
				int N = 4;
				int K = 5;
				_expected = 1104;
				_received = _obj.count(N, K); break;
			}
			case 2:
			{
				int N = 100;
				int K = 120;
				_expected = 803057135;
				_received = _obj.count(N, K); break;
			}
			case 3:
			{
				int N = 234;
				int K = 467;
				_expected = 0;
				_received = _obj.count(N, K); break;
			}
			case 4:
			{
				int N = 810;
				int K = 893;
				_expected = 281618909;
				_received = _obj.count(N, K); break;
			}
			/*case 5:
			{
				int N = ;
				int K = ;
				_expected = ;
				_received = _obj.count(N, K); break;
			}*/
			/*case 6:
			{
				int N = ;
				int K = ;
				_expected = ;
				_received = _obj.count(N, K); break;
			}*/
			/*case 7:
			{
				int N = ;
				int K = ;
				_expected = ;
				_received = _obj.count(N, K); break;
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
