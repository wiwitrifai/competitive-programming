#include <bits/stdc++.h>

using namespace std;

const int N = 1024;
int dp[N];
int cnt[N];
int take[N];

class FindStringHard {
public:
	string withAntipalindromicSubstrings(int n) {
		if (n == 0)
			return "a";
		cnt[0] = 0;
		cnt[1] = 0;
		for (int i = 2; i < N; ++i) {
			cnt[i] = cnt[i-1] + i/2;
		}
		int h = 0, mi = 1e9;
		dp[0] = 0;
		for (int i = 1; i < N; ++i) {
			dp[i] = 1e9;
			for (int j = 2; j < N; ++j) {
				if (cnt[j] > i) break;
				if (dp[i] <= dp[i-cnt[j]] + j) continue;
				dp[i] = dp[i-cnt[j]] + j;
				take[i] = j;
			}
			mi = min(mi, dp[i]);
			h = max(h, dp[i]);
		}
		// cerr << h << " " << mi << endl;
		char last = 0;
		string ans = "";
		while (n > 0) {
			int t = take[n];
			last ^= 1;
			for (int i = 0; i < t; ++i) {
				last ^= 1;
				ans += char ('a' + last);
			}
			n -= cnt[t];
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
		cout << "Testing FindStringHard (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1547573051;
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
		FindStringHard _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 3;
				_expected = "bbaab";
				_received = _obj.withAntipalindromicSubstrings(n); break;
			}
			case 1:
			{
				int n = 8;
				_expected = "ababbaab";
				_received = _obj.withAntipalindromicSubstrings(n); break;
			}
			case 2:
			{
				int n = 139;
				_expected = "ababaabbaabbaaabbbaaabbbaaaabbbbaaaabbbbaaaaabbbbbaaaaabbbbbaaaaaabbbbbbaaaaaabbbbbb";
				_received = _obj.withAntipalindromicSubstrings(n); break;
			}
			case 3:
			{
				int n = 0;
				_expected = 'a';
				_received = _obj.withAntipalindromicSubstrings(n); break;
			}
			/*case 4:
			{
				int n = ;
				_expected = ;
				_received = _obj.withAntipalindromicSubstrings(n); break;
			}*/
			/*case 5:
			{
				int n = ;
				_expected = ;
				_received = _obj.withAntipalindromicSubstrings(n); break;
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
