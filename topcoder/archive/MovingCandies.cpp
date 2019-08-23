#include <bits/stdc++.h>

using namespace std;

const int N = 21, inf = 1e8;

bool vis[N][N][N * N][N * N];
int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};

class MovingCandies {
public:

	int minMoved(vector <string> t) {
		memset(vis, 0, sizeof vis);
		int r = t.size(), c = t[0].size();
		int tot = 0;
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				tot += t[i][j] == '#';
		queue< pair<pair< int, int >, pair<int, int > > > que;
		int ca = t[0][0] == '#';
		que.push({{0, 0}, {ca, 1-ca}});
		vis[0][0][ca][1-ca] = 1;
		int ans = inf;
		while (!que.empty()) {
			pair<pair< int, int >, pair<int, int > > now = que.front(); que.pop();
			int x = now.first.first, y = now.first.second, can = now.second.first, need = now.second.second;
			if (can + need > tot)
				continue;
			if (x == r-1 && y == c-1)
				ans = min(ans, need);
			for (int i = 0; i < 4; i++) {
				int xx = x + dx[i], yy = y + dy[i];
				if (xx < 0 || xx >= r || yy < 0 || yy >= c) continue;
				int ccan = can + (t[xx][yy] == '#'), nneed = need + (t[xx][yy] != '#');
				if (vis[xx][yy][ccan][nneed]) continue;
				vis[xx][yy][ccan][nneed] = 1;
				que.push({{xx, yy}, {ccan, nneed}});
			}
		}
		if (ans >= inf)
			ans = -1;
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
		cout << "Testing MovingCandies (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1485015048;
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
		MovingCandies _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string t[] = {
				             "#...###",
				             "#...#.#",
				             "##..#.#",
				             ".#....#"
				             };
				_expected = 3;
				_received = _obj.minMoved(vector <string>(t, t+sizeof(t)/sizeof(string))); break;
			}
			case 1:
			{
				string t[] = {
				             "#...###",
				             "#...#.#",
				             "##..###",
				             ".#....#"
				             };
				_expected = 2;
				_received = _obj.minMoved(vector <string>(t, t+sizeof(t)/sizeof(string))); break;
			}
			case 2:
			{
				string t[] = {
				             ".#..",
				             "##..",
				             "..#.",
				             "..#.",
				             "..##",
				             "..##"
				             };
				_expected = 2;
				_received = _obj.minMoved(vector <string>(t, t+sizeof(t)/sizeof(string))); break;
			}
			case 3:
			{
				string t[] = {
				             ".....",
				             ".###.",
				             "####.",
				             "....."
				             };
				_expected = -1;
				_received = _obj.minMoved(vector <string>(t, t+sizeof(t)/sizeof(string))); break;
			}
			case 4:
			{
				string t[] = {
				             ".#...#.###.#",
				             "#.#.##......",
				             ".#.#......#.",
				             "..#.......#.",
				             "##.........."
				             };
				_expected = 9;
				_received = _obj.minMoved(vector <string>(t, t+sizeof(t)/sizeof(string))); break;
			}
			case 5:
			{
				string t[] = {
				             "###.#########..#####",
				             ".#######.###########"
				             };
				_expected = 0;
				_received = _obj.minMoved(vector <string>(t, t+sizeof(t)/sizeof(string))); break;
			}
			case 6:
			{
				string t[] = {
				             "..",
				             ".."
				             };
				_expected = -1;
				_received = _obj.minMoved(vector <string>(t, t+sizeof(t)/sizeof(string))); break;
			}
			case 7:
			{
				string t[] = {
					"####................",
					"....................",
					"....................",
					"....................",
					"....................",
					"####################",
					"....................",
					"....................",
					"....................",
					"####################",
					"....................",
					"....................",
					"....................",
					"####################",
					"....................",
					"....................",
					"####################",
					"....................",
					"####################",
					"####################",
					};
				_expected = 13;
				_received = _obj.minMoved(vector <string>(t, t+sizeof(t)/sizeof(string))); break;
			}
			/*case 8:
			{
				string t[] = ;
				_expected = ;
				_received = _obj.minMoved(vector <string>(t, t+sizeof(t)/sizeof(string))); break;
			}*/
			/*case 9:
			{
				string t[] = ;
				_expected = ;
				_received = _obj.minMoved(vector <string>(t, t+sizeof(t)/sizeof(string))); break;
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
