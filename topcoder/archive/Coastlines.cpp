#include <bits/stdc++.h>

using namespace std;

const int N = 55;

int cnt[N][N];
int n, m;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int calc(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m)
		return 0;
	if (cnt[x][y] == -1)
		return 0;
	int ret = cnt[x][y];
	cnt[x][y] = -1;
	for (int k = 0; k < 4; ++k) {
		ret += calc(x + dx[k], y + dy[k]);
	}
	return ret;
}

class Coastlines {
public:
	int longest(vector <string> map) {
		memset(cnt, -1, sizeof cnt);
		n = map.size(), m = map[0].size();
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (map[i][j] == '.') continue;
				cnt[i][j] = 0;
				for (int k = 0; k < 4; ++k) {
					int x = i + dx[k], y = j + dy[k];
					if (0 <= x && x < n && 0 <= y && y < m && map[x][y] != '.') continue;
					++cnt[i][j];
				}
			}
		}
		int best = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (map[i][j] == '.') continue;
				int res = calc(i, j);
				best = max(best, res);
			}
		}
		return best;
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
		cout << "Testing Coastlines (275.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1565453586;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 275.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		Coastlines _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string map[] = {"...",
				                ".X.",
				                "..."};
				_expected = 4;
				_received = _obj.longest(vector <string>(map, map+sizeof(map)/sizeof(string))); break;
			}
			case 1:
			{
				string map[] = {".XX",
				                ".X.",
				                "..."};
				_expected = 8;
				_received = _obj.longest(vector <string>(map, map+sizeof(map)/sizeof(string))); break;
			}
			case 2:
			{
				string map[] = {"."};
				_expected = 0;
				_received = _obj.longest(vector <string>(map, map+sizeof(map)/sizeof(string))); break;
			}
			case 3:
			{
				string map[] = {".XX...",
				                "XX...X",
				                "X...XX",
				                "......",
				                ".XXXX."};
				_expected = 12;
				_received = _obj.longest(vector <string>(map, map+sizeof(map)/sizeof(string))); break;
			}
			case 4:
			{
				string map[] = {"XXX",
				                "X.X",
				                "XXX"};
				_expected = 16;
				_received = _obj.longest(vector <string>(map, map+sizeof(map)/sizeof(string))); break;
			}
			case 5:
			{
				string map[] = {"XXXXX",
				                "X...X",
				                "X.X.X",
				                "X...X",
				                "XXXXX"};
				_expected = 32;
				_received = _obj.longest(vector <string>(map, map+sizeof(map)/sizeof(string))); break;
			}
			/*case 6:
			{
				string map[] = ;
				_expected = ;
				_received = _obj.longest(vector <string>(map, map+sizeof(map)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string map[] = ;
				_expected = ;
				_received = _obj.longest(vector <string>(map, map+sizeof(map)/sizeof(string))); break;
			}*/
			/*case 8:
			{
				string map[] = ;
				_expected = ;
				_received = _obj.longest(vector <string>(map, map+sizeof(map)/sizeof(string))); break;
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
