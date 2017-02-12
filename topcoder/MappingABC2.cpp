#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int val[55];
bool fir[55], ok[55];

class MappingABC2 {
public:
	int countStrings(vector <int> t) {
		int n = t.size();
		memset(fir, 0, sizeof fir);
		memset(ok, 0, sizeof ok);
		for (int i = 0; i < n; i++) {
			if (ok[t[i]] == 0)
				fir[i] = 1;
			ok[t[i]] = 1;
		}
		memset(val, 0, sizeof val);
		long long ans = 0;
		for (int i = 0; i < n; i++) {
			if (!fir[i]) continue;
			int a = t[i];
			for (int j = i+1; j < n; j++) {
				int b = t[j];
				bool fail = 0;
				for (int z = i+1; z < j; z++) if (t[z] == b) fail = 1;
				if (a == b || fail) continue;
				for (int k = j+1; k < n; k++) {
					int c = t[k];
					bool fail2 = 0;
					for (int z = j+1; z < k; z++) if (t[z] == c) fail2 = 1;
					if (c == a || c == b || fail2) continue;
					memset(val, 0, sizeof val);
					val[a] = 7 ^ 1;
					val[b] = 7 ^ 2;
					val[c] = 7 ^ 4;
					int now = 0;
					for (int z = 0; z < n; z++) {
						if (z == i) now = 1;
						if (z == j) now = 2;
						if (z == k) break;
						if (z == i || z == j) continue;
						val[t[z]] |= (1<< now);				
					}
					long long mul = 1;
					for (int z = 0; z < 55; z++) if (ok[z]) {
						int cnt = 3-__builtin_popcount(val[z]);
						mul = (mul * cnt) % mod;
					}
					ans += mul;
					if (ans >= mod) ans -= mod; 
				}
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
		cout << "Testing MappingABC2 (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1486948532;
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
		MappingABC2 _obj;
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
				int t[] = {7,50,1,50,1,50,1,10,7};
				_expected = 20;
				_received = _obj.countStrings(vector <int>(t, t+sizeof(t)/sizeof(int))); break;
			}
			case 4:
			{
				int t[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48};
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
