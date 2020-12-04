#include <bits/stdc++.h>

using namespace std;


const int dx[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int dy[] = {0, -1, 0, 1, -1, 1, -1, 1};

class IslandInALake {
public:
	int build(vector <string> country) {
		int n = country.size();
		int m = country[0].size();
		vector<vector<int>> col(n, vector<int>(m, 0));
		auto bfs = [&](int r, int c, int s, int cnt, char ch) {
			queue<pair<int, int>> que;
			col[r][c] = s;
			que.emplace(r, c);
			int ret = 0;
			while (!que.empty()) {
				++ret;
				tie(r, c) = que.front();
				que.pop();
				for (int i = 0; i < cnt; ++i) {
					int rr = r + dx[i];
					int cc = c + dy[i];
					if (rr < 0 || rr >= n) continue;
					if (cc < 0 || cc >= m) continue;
					if (country[rr][cc] != ch) continue;
					if (col[rr][cc] == s) continue;
					col[rr][cc] = s;
					que.emplace(rr, cc);
				}
			}
			return ret;
		};
		bfs(0, 0, 1, 4, '.');
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (country[i][j] != '#') continue;
				col[i][j] = 2;
				for (int k = 0; k < 8; ++k) {
					int r = i + dx[k];
					int c = j + dy[k];
					col[r][c] = 2;					
				}
			}
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (col[i][j] == 2)
					country[i][j] = '#';
			}
		}
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (col[i][j] || country[i][j] == '#') continue;
				ans = max(ans, bfs(i, j, 3, 8, '.'));
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
		cout << "Testing IslandInALake (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1607097923;
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
		IslandInALake _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string country[] = {"......",
				                    "......",
				                    "......",
				                    "......",
				                    "......"};
				_expected = 0;
				_received = _obj.build(vector <string>(country, country+sizeof(country)/sizeof(string))); break;
			}
			case 1:
			{
				string country[] = {".......",
				                    "..##...",
				                    ".##..#.",
				                    "..#.#..",
				                    "......."};
				_expected = 0;
				_received = _obj.build(vector <string>(country, country+sizeof(country)/sizeof(string))); break;
			}
			case 2:
			{
				string country[] = {".......",
				                    ".####..",
				                    ".#...#.",
				                    ".#####.",
				                    "......."};
				_expected = 0;
				_received = _obj.build(vector <string>(country, country+sizeof(country)/sizeof(string))); break;
			}
			case 3:
			{
				string country[] = {"..........",
				                    ".####.....",
				                    ".#...#....",
				                    ".#...#....",
				                    ".#...#....",
				                    ".#####....",
				                    ".........."};
				_expected = 1;
				_received = _obj.build(vector <string>(country, country+sizeof(country)/sizeof(string))); break;
			}
			case 4:
			{
				string country[] = {"............",
				                    ".####.#####.",
				                    ".#...#....#.",
				                    ".#........#.",
				                    ".#...#....#.",
				                    ".#########..",
				                    "............"};
				_expected = 2;
				_received = _obj.build(vector <string>(country, country+sizeof(country)/sizeof(string))); break;
			}
			case 5:
			{
				string country[] = {"...........",
				                    "..#####....",
				                    "..#....##..",
				                    "..#.....#..",
				                    "...#.....#.",
				                    "..#.#....#.",
				                    ".#...#...#.",
				                    "..###.###..",
				                    "..........."};
				_expected = 3;
				_received = _obj.build(vector <string>(country, country+sizeof(country)/sizeof(string))); break;
			}
			case 6:
			{
				string country[] = {"...........",
				                    ".#########.",
				                    ".#.......#.",
				                    ".#.#####.#.",
				                    ".#.#...#.#.",
				                    ".#.#...#.#.",
				                    ".#.#...#.#.",
				                    ".#.#####.#.",
				                    ".#.......#.",
				                    ".#########.",
				                    "..........."};
				_expected = 1;
				_received = _obj.build(vector <string>(country, country+sizeof(country)/sizeof(string))); break;
			}
			case 7:
			{
				string country[] = {"...........",
				                    ".#########.",
				                    ".#.......#.",
				                    ".#.#####.#.",
				                    ".#.#...#...",
				                    ".#.#...#.#.",
				                    ".#.#...#.#.",
				                    ".#.###.#.#.",
				                    ".#.......#.",
				                    ".#########.",
				                    "..........."};
				_expected = 0;
				_received = _obj.build(vector <string>(country, country+sizeof(country)/sizeof(string))); break;
			}
			case 8:
			{
				string country[] = {"...........",
				                    ".#########.",
				                    ".#.......#.",
				                    ".#.......#.",
				                    ".#.......#.",
				                    ".#.......#.",
				                    ".#.......#.",
				                    ".#.......#.",
				                    ".#...#...#.",
				                    ".#.......#.",
				                    ".#.......#.",
				                    ".#.......#.",
				                    ".#########.",
				                    "..........."};
				_expected = 31;
				_received = _obj.build(vector <string>(country, country+sizeof(country)/sizeof(string))); break;
			}
			/*case 9:
			{
				string country[] = ;
				_expected = ;
				_received = _obj.build(vector <string>(country, country+sizeof(country)/sizeof(string))); break;
			}*/
			/*case 10:
			{
				string country[] = ;
				_expected = ;
				_received = _obj.build(vector <string>(country, country+sizeof(country)/sizeof(string))); break;
			}*/
			/*case 11:
			{
				string country[] = ;
				_expected = ;
				_received = _obj.build(vector <string>(country, country+sizeof(country)/sizeof(string))); break;
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
