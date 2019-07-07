#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

const int N = 1024;

long long powmod(long long b, long long p) {
	long long r = 1;
	for (; p; p >>= 1, b = b * b % mod)
		if (p & 1)
			r = r * b % mod;
	return r;
}

int dp[N][N];

void add(int & var, int val) {
	var += val;
	if (var >= mod)
		var -= mod;
}

class FamilySeatingArrangement {
public:
	int countWays(vector <int> a, int k) {
		int n = a.size();
		for (int i = 0; i <= n; ++i)
			for (int j = 0; j <= k; ++j)
				dp[i][j] = 0;
		dp[0][0] = 1;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j <= k; ++j) {
				int now = dp[i][j];
				if (now == 0) continue;
				add(dp[i+1][j], 1LL * j * now % mod);
				add(dp[i+1][j+1], 1LL * (k - j) * now % mod);
			}
		}
		int sum = 0;
		for (int i = 0; i < n; ++i)
			sum += a[i];
		int ans = 0;
		for (int i = 1; i <= k; ++i) {
			int pilih = (k-i) + 1;
			add(ans, 1LL * powmod(pilih, sum) * dp[n][i] % mod);
		}
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
		cout << "Testing FamilySeatingArrangement (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1562429108;
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
		FamilySeatingArrangement _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int a[] = {2,1}	;
				int k = 2;
				_expected = 18;
				_received = _obj.countWays(vector <int>(a, a+sizeof(a)/sizeof(int)), k); break;
			}
			case 1:
			{
				int a[] = {2,1};
				int k = 3;
				_expected = 129;
				_received = _obj.countWays(vector <int>(a, a+sizeof(a)/sizeof(int)), k); break;
			}
			case 2:
			{
				int a[] = {2,1};
				int k = 1000;
				_expected = 989021965;
				_received = _obj.countWays(vector <int>(a, a+sizeof(a)/sizeof(int)), k); break;
			}
			case 3:
			{
				int a[] = {1,1,1,1,1,1,1,1,1,1,1,1};
				int k = 8;
				_expected = 604306839;
				_received = _obj.countWays(vector <int>(a, a+sizeof(a)/sizeof(int)), k); break;
			}
			case 4:
			{
				int a[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20}	;
				int k = 211;
				_expected = 775937801;
				_received = _obj.countWays(vector <int>(a, a+sizeof(a)/sizeof(int)), k); break;
			}
			/*case 5:
			{
				int a[] = ;
				int k = ;
				_expected = ;
				_received = _obj.countWays(vector <int>(a, a+sizeof(a)/sizeof(int)), k); break;
			}*/
			/*case 6:
			{
				int a[] = ;
				int k = ;
				_expected = ;
				_received = _obj.countWays(vector <int>(a, a+sizeof(a)/sizeof(int)), k); break;
			}*/
			/*case 7:
			{
				int a[] = ;
				int k = ;
				_expected = ;
				_received = _obj.countWays(vector <int>(a, a+sizeof(a)/sizeof(int)), k); break;
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
