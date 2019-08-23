#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int dp[1<<16][30];

class ColorfulGardenHard {
public:
	int count(string garden, string forbid) {
		sort(garden.begin(), garden.end());
		int n = garden.size();
		for (int i = 0; i < n; i++)
			garden[i] -= 'a', forbid[i] -= 'a';
		int nmask = 1<<n;
		memset(dp, 0, sizeof dp);
		dp[0][26] = 1;
		for (int mask = 0; mask < nmask; mask++) {
			int id = __builtin_popcount(mask);
			for (int i = 0; i < 27; i++) {
				if (!dp[mask][i]) continue;
				for (int j = 0; j < n; j++) {
					if (mask & (1<<j)) continue;
					if (j > 0 && garden[j] == garden[j-1] && (mask & (1<<(j-1))) == 0) continue;
					if (garden[j] == i) continue;
					if (garden[j] == forbid[id]) continue;
					int curm = mask | (1<<j);
					(dp[curm][garden[j]] += dp[mask][i]) %= mod;
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < 26; i++) {
			ans += dp[nmask-1][i];
			if (ans >= mod) ans -= mod;
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
		cout << "Testing ColorfulGardenHard (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1489506586;
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
		ColorfulGardenHard _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string garden = "aaabbb";
				string forbid = "cccccc";
				_expected = 2;
				_received = _obj.count(garden, forbid); break;
			}
			case 1:
			{
				string garden = "aabbcc";
				string forbid = "aabbcc";
				_expected = 5;
				_received = _obj.count(garden, forbid); break;
			}
			case 2:
			{
				string garden = "aaaabb";
				string forbid = "xxxxxx";
				_expected = 0;
				_received = _obj.count(garden, forbid); break;
			}
			case 3:
			{
				string garden = "abcdefghijklmno";
				string forbid = "zzzzzzzzzzzzzzz";
				_expected = 674358851;
				_received = _obj.count(garden, forbid); break;
			}
			case 4:
			{
				string garden = "a";
				string forbid = "b";
				_expected = 1;
				_received = _obj.count(garden, forbid); break;
			}
			/*case 5:
			{
				string garden = ;
				string forbid = ;
				_expected = ;
				_received = _obj.count(garden, forbid); break;
			}*/
			/*case 6:
			{
				string garden = ;
				string forbid = ;
				_expected = ;
				_received = _obj.count(garden, forbid); break;
			}*/
			/*case 7:
			{
				string garden = ;
				string forbid = ;
				_expected = ;
				_received = _obj.count(garden, forbid); break;
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
