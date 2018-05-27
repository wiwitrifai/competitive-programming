#include <bits/stdc++.h>

using namespace std;

int n, m;
int b[13][13];
long long dp[13][1 << 13];

int c[15];
bool check(int from, int to) {
	c[m] = 0;
	for (int i = 0; i < m; i++) {
		if (to & (1 << i))
			c[i] = 1;
		else
			c[i] = 0;
		if (from & (1 << i)) continue;
		if (c[i] == 0) return false;
		c[i] = 0;
	}
	for (int i = 0; i < m; i++) {
		if (c[i]) {
			if (c[i+1] == 0) return false;
			c[i] = 0;
			c[i+1] = 0;
		}
	}
	return true;
}

class DominoTiling {
public:
	long long count(vector <string> grid) {
		n = grid.size();
		m = grid[0].size();
		memset(dp, 0, sizeof dp);
		int mm = 1 << m;
		dp[0][mm-1] = 1;
		for (int i = 0; i < n; i++) {
			int kosong = 0;
			for (int j = 0; j < m; j++)
				if (grid[i][j] == 'X')
					kosong |= 1 << j;
			for (int mask = 0; mask < mm; mask++) {
				if ((kosong & mask) != kosong) continue;
				long long & now = dp[i+1][mask];
				now = 0;
				int isi = mask ^ kosong;
				if (check(mm-1, isi))
					now += dp[i][mm-1];
				for (int bef = isi; bef; bef = (bef - 1) & isi) {
					int cur = (mm-1) ^ bef;
					if (dp[i][cur] == 0) continue;
					if (check(cur, isi))
						now += dp[i][cur];
				}
			}
		}
		return dp[n][mm-1];
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
		cout << "Testing DominoTiling (600.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1507807773;
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
		DominoTiling _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string grid[] = {"..",
				                 ".."};
				_expected = 2LL;
				_received = _obj.count(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}
			case 1:
			{
				string grid[] = {"...",
				                 ".X.",
				                 "..."};
				_expected = 2LL;
				_received = _obj.count(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}
			case 2:
			{
				string grid[] = {"...",
				                 "...",
				                 "..X"};
				_expected = 4LL;
				_received = _obj.count(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}
			case 3:
			{
				string grid[] = {".....",
				                 ".....",
				                 ".X...",
				                 ".X..."};
				_expected = 29LL;
				_received = _obj.count(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}
			/*case 4:
			{
				string grid[] = ;
				_expected = LL;
				_received = _obj.count(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string grid[] = ;
				_expected = LL;
				_received = _obj.count(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string grid[] = ;
				_expected = LL;
				_received = _obj.count(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
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
