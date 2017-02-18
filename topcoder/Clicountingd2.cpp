#include <bits/stdc++.h>

using namespace std;

int id[22][22];

class Clicountingd2 {
public:
	int count(vector <string> g) {
		int n = g.size(), nmask = 1<<n;
		int k = 0;
		memset(id, -1, sizeof id);
		for (int i = 0; i < n; i++) {
			for (int j = i+1; j < n; j++)
				if (g[i][j] == '?') {
					id[i][j] = id[j][i] = k++;
				}
		}
		int kmask = 1<<k;
		vector< int > ans(kmask, 0);
		for (int mask = 0; mask < nmask; mask++) {
			int bmask = 0, ok = 1;
			for (int i = 0; ok && i < n; i++) if (mask & (1<<i)) {
				for (int j = 0; ok && j < n; j++) if (j != i && (mask & (1<<j))) {
					if (g[i][j] == '0')
						ok = 0;
					else if (g[i][j]  == '?') 
						bmask |= (1<<id[i][j]);
				}
			}
			if (!ok)
				continue;
			ans[bmask] = max(ans[bmask], __builtin_popcount(mask));
		}
		int tot = 0;
		for (int mask = 0; mask < kmask; mask++) {
			tot += ans[mask];
			for (int i = 0; i < k; i++) if ((mask & (1<<i)) == 0)
				ans[mask | (1<<i)] = max(ans[mask | (1<<i)], ans[mask]);
		}
		return tot;
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
		cout << "Testing Clicountingd2 (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1487340299;
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
		Clicountingd2 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string g[] = {"01","10"};
				_expected = 2;
				_received = _obj.count(vector <string>(g, g+sizeof(g)/sizeof(string))); break;
			}
			case 1:
			{
				string g[] = {"0?","?0"};
				_expected = 3;
				_received = _obj.count(vector <string>(g, g+sizeof(g)/sizeof(string))); break;
			}
			case 2:
			{
				string g[] = {"011","101","110"};
				_expected = 3;
				_received = _obj.count(vector <string>(g, g+sizeof(g)/sizeof(string))); break;
			}
			case 3:
			{
				string g[] = {"0?1","?01","110"};
				_expected = 5;
				_received = _obj.count(vector <string>(g, g+sizeof(g)/sizeof(string))); break;
			}
			case 4:
			{
				string g[] = {"0???","?0??","??0?","???0"};
				_expected = 151;
				_received = _obj.count(vector <string>(g, g+sizeof(g)/sizeof(string))); break;
			}
			/*case 5:
			{
				string g[] = ;
				_expected = ;
				_received = _obj.count(vector <string>(g, g+sizeof(g)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string g[] = ;
				_expected = ;
				_received = _obj.count(vector <string>(g, g+sizeof(g)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string g[] = ;
				_expected = ;
				_received = _obj.count(vector <string>(g, g+sizeof(g)/sizeof(string))); break;
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
