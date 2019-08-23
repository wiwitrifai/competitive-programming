#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9+ 7;
const int N = 3030;
long long dp[N][N][2];

string str;
long long solve2(int l, int r, int w) {
	if (l < 0 || r >= str.size()) return !w;
	long long & ret = dp[l][r][w];
	if (ret != -1)
		return ret;
	ret = 0;
	if (w) {
		if (str[l] == str[r]) {
			ret += solve2(l-1, r+1, 0) + solve2(l-1, r+1, 1);
			if (ret >= mod) ret -= mod;
		}
		ret += solve2(l-1, r, 1);
		if (ret >= mod) ret -= mod;
	}
	else {
		ret = solve2(l, r+1, 0) + solve2(l, r+1, 1);
		if (ret >= mod) ret -= mod;
	}
	return ret;
}

class PalindromicSubseq2 {
public:
	int solve(string s) {
		str = s;
		memset(dp, -1, sizeof dp);		
		int n = s.size();
		int ans = 0;
		for (int i = 0; i < n; i++) {
			long long x = solve2(i-1, i+1, 0) + solve2(i-1, i+1, 1);
			if (x >= mod) x -= mod;
			int y = (x * (i+1)) % mod;
			ans ^= y;
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
		cout << "Testing PalindromicSubseq2 (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1486879863;
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
		PalindromicSubseq2 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string s = "axbcba";
				_expected = 31;
				_received = _obj.solve(s); break;
			}
			case 1:
			{
				string s = "eeeee";
				_expected = 14;
				_received = _obj.solve(s); break;
			}
			case 2:
			{
				string s = "tcoct";
				_expected = 4;
				_received = _obj.solve(s); break;
			}
			case 3:
			{
				string s = "zyzyzzzzxzyz";
				_expected = 221;
				_received = _obj.solve(s); break;
			}
			case 4:
			{
				string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
				_expected = 1044407608;
				_received = _obj.solve(s); break;
			}
			/*case 5:
			{
				string s = ;
				_expected = ;
				_received = _obj.solve(s); break;
			}*/
			/*case 6:
			{
				string s = ;
				_expected = ;
				_received = _obj.solve(s); break;
			}*/
			/*case 7:
			{
				string s = ;
				_expected = ;
				_received = _obj.solve(s); break;
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
