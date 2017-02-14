#include <bits/stdc++.h>

using namespace std;

class KthStringAgain {
public:
	string str;
	long long calc(string s) {
		long long dp[55][55];
		memset(dp, 0, sizeof dp);
		dp[0][0] = 1;
		int m = s.size(), n = str.size();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= i; j++) if (dp[i][j]) {
				if (j >= m || (j < m && s[j] == str[i]))
					dp[i+1][j+1] += dp[i][j];
				int jr = n-1 - (i-j);
				if (jr >= m || (jr < m && s[jr] == str[i]))
					dp[i+1][j] += dp[i][j];
			}
		}
		long long ans = 0;
		for (int i = 0; i <= n; i++)
			ans += dp[n][i];
		return ans;
	}

	string getKth(string s, long long k) {
		str = s;
		int n = s.size();
		string ans = "";
		for (int i = 0; i < n; i++) {
			for (char c = 'a'; c <= 'z'; c++) {
				string tmp = ans;
				ans += c;
				long long cnt = calc(ans);
				if (cnt >= k)
					break;
				k -= cnt;
				ans = tmp;
			}
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
		cout << "Testing KthStringAgain (600.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1487034977;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 600.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		KthStringAgain _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string s = "xyz";
				long long k = 5LL;
				_expected = "yzx";
				_received = _obj.getKth(s, k); break;
			}
			case 1:
			{
				string s = "abc";
				long long k = 1LL;
				_expected = "abc";
				_received = _obj.getKth(s, k); break;
			}
			case 2:
			{
				string s = "abc";
				long long k = 8LL;
				_expected = "cba";
				_received = _obj.getKth(s, k); break;
			}
			case 3:
			{
				string s = "topcoder";
				long long k = 58LL;
				_expected = "ooredcpt";
				_received = _obj.getKth(s, k); break;
			}
			case 4:
			{
				string s = "aaaabcdeeeghhhhhiijjjkllmmooooqqrrrrssttuuvvvvvwyy";
				long long k = 38517901796974LL;
				_expected = "aaaacdeehhhijklmmqqrsttvvvvwyyvuusrrrooooljjihhgeb";
				_received = _obj.getKth(s, k); break;
			}
			/*case 5:
			{
				string s = ;
				long long k = LL;
				_expected = ;
				_received = _obj.getKth(s, k); break;
			}*/
			/*case 6:
			{
				string s = ;
				long long k = LL;
				_expected = ;
				_received = _obj.getKth(s, k); break;
			}*/
			/*case 7:
			{
				string s = ;
				long long k = LL;
				_expected = ;
				_received = _obj.getKth(s, k); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
