#include <bits/stdc++.h>

using namespace std;

const int N = 1202, mod = 1e9 + 7;

int dp[N][21][2][606];
int pw[N];

int len, prob[2];
int needed;

int solve(int pos, int streak, int last, int win) {
	if (win >= needed)
		return pw[len - pos];
	if (pos - win >= needed)
		return 0;
	if (pos >= len)
		return 1;
	int & ret = dp[pos][streak][last][win];
	if (ret != -1)
		return ret;
	int cur = (pos / 2) & 1;
	int p[2];
	p[cur] = prob[cur];
	p[cur^1] = 100 - prob[cur];
	p[last] += streak * 5;
	p[last] = min(p[last], 100);
	p[last^1] = 100 - p[last];
	ret = 0;
	{
		int nstreak = 1;
		if (last == 0)
			nstreak += streak;
		nstreak = min(nstreak, 20);
		ret = (ret + 1LL * p[0] * solve(pos+1, nstreak, 0, win+1)) % mod;
	}
	{
		int nstreak = 1;
		if (last == 1)
			nstreak += streak;
		nstreak = min(nstreak, 20);
		ret = (ret + 1LL * p[1] * solve(pos+1, nstreak, 1, win)) % mod;
	}
	return ret;
}

class HockeyPlayoff {
public:
	int winProbability(int winsNeeded, int AwinHome, int BwinHome) {
		pw[0] = 1;
		for (int i = 1; i < N; ++i) {
			pw[i] = pw[i-1] * 100LL % mod;
		}
		needed = winsNeeded;
		prob[0] = AwinHome;
		prob[1] = BwinHome;
		len = winsNeeded * 2 - 1;
		memset(dp, -1, sizeof dp);
		return solve(0, 0, 0, 0);
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
		cout << "Testing HockeyPlayoff (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1568163648;
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
		HockeyPlayoff _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int winsNeeded = 3;
				int AwinHome = 0;
				int BwinHome = 100;
				_expected = 0;
				_received = _obj.winProbability(winsNeeded, AwinHome, BwinHome); break;
			}
			case 1:
			{
				int winsNeeded = 4;
				int AwinHome = 100;
				int BwinHome = 0;
				_expected = 999300007;
				_received = _obj.winProbability(winsNeeded, AwinHome, BwinHome); break;
			}
			case 2:
			{
				int winsNeeded = 600;
				int AwinHome = 50;
				int BwinHome = 50;
				_expected = 594375906;
				_received = _obj.winProbability(winsNeeded, AwinHome, BwinHome); break;
			}
			case 3:
			{
				int winsNeeded = 4;
				int AwinHome = 53;
				int BwinHome = 57;
				_expected = 942200194;
				_received = _obj.winProbability(winsNeeded, AwinHome, BwinHome); break;
			}
			case 4:
			{
				int winsNeeded = 7;
				int AwinHome = 93;
				int BwinHome = 87;
				_expected = 545426737;
				_received = _obj.winProbability(winsNeeded, AwinHome, BwinHome); break;
			}
			/*case 5:
			{
				int winsNeeded = ;
				int AwinHome = ;
				int BwinHome = ;
				_expected = ;
				_received = _obj.winProbability(winsNeeded, AwinHome, BwinHome); break;
			}*/
			/*case 6:
			{
				int winsNeeded = ;
				int AwinHome = ;
				int BwinHome = ;
				_expected = ;
				_received = _obj.winProbability(winsNeeded, AwinHome, BwinHome); break;
			}*/
			/*case 7:
			{
				int winsNeeded = ;
				int AwinHome = ;
				int BwinHome = ;
				_expected = ;
				_received = _obj.winProbability(winsNeeded, AwinHome, BwinHome); break;
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
