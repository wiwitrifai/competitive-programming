#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7, N = 3030;

long long powmod(long long b, long long p) {
	long long ret = 1;
	while (p) {
		if (p & 1)
			ret =(ret * b) % mod;
		b = (b * b) % mod;
		p >>= 1;
	}
	return ret;
}
int last[N], cnt[N];

class MappingABC {
public:
	int countStrings(vector <int> t) {
		int n = t.size();
		memset(last, -1, sizeof last);
		memset(cnt, 0, sizeof cnt);
		for (int i = 0; i < n; i++) {
			last[t[i]] = i;
		}
		int diff = 0;
		for (int i = 0; i < N; i++) if (last[i] != -1)
			diff++;
		long long ans = 0;
		int clast = -1;
		for (int i = 0; i < n; i++) {
			if (cnt[t[i]] == 0)
				diff--;
			cnt[t[i]]++;
			int dlast = clast;
			for (int j = i + 1; j < n; j++) {
				if (cnt[t[j]] == 0)
					diff--;
				cnt[t[j]]++;
				if (t[i] != t[j]) {
					ans += powmod(3, diff);
					if (dlast <= j)
						ans += mod - powmod(2, diff);
					while (ans >= mod)
						ans -= mod;
				}
				dlast = max(last[t[j]], dlast);
			}
			for (int j = i+1; j < n; j++) {
				cnt[t[j]]--;
				if (cnt[t[j]] == 0)
					diff++;
			}
			clast = max(last[t[i]], clast);
		}
		ans %= mod;
		if (ans < 0)
			ans += mod;
		return (int)ans;
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
		cout << "Testing MappingABC (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1485016548;
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
		MappingABC _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int t[] = {9,9,2,9,4};
				_expected = 2;
				_received = _obj.countStrings(vector <int>(t, t+sizeof(t)/sizeof(int))); break;
			}
			case 1:
			{
				int t[] = {1,2,3};
				_expected = 1;
				_received = _obj.countStrings(vector <int>(t, t+sizeof(t)/sizeof(int))); break;
			}
			case 2:
			{
				int t[] = {1,2,2,1,2,1,2};
				_expected = 0;
				_received = _obj.countStrings(vector <int>(t, t+sizeof(t)/sizeof(int))); break;
			}
			case 3:
			{
				int t[] = {7,3000,1,3000,1,3000,1,10,7};
				_expected = 20;
				_received = _obj.countStrings(vector <int>(t, t+sizeof(t)/sizeof(int))); break;
			}
			case 4:
			{
				int t[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,
				          26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48};
				_expected = 166952139;
				_received = _obj.countStrings(vector <int>(t, t+sizeof(t)/sizeof(int))); break;
			}
			/*case 5:
			{
				int t[] = ;
				_expected = ;
				_received = _obj.countStrings(vector <int>(t, t+sizeof(t)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int t[] = ;
				_expected = ;
				_received = _obj.countStrings(vector <int>(t, t+sizeof(t)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int t[] = ;
				_expected = ;
				_received = _obj.countStrings(vector <int>(t, t+sizeof(t)/sizeof(int))); break;
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
