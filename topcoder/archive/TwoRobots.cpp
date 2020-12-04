#include <bits/stdc++.h>

using namespace std;
const int inf = 1e9 + 7;
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, -1, 0, 1};

class TwoRobots {
public:
	int move(vector <string> plan) {
		int n = plan.size(), m = plan[0].size();
		auto enc = [&](int r, int c) {
			return r * m + c;
		};
		vector<vector<int>> dist(n * m, vector<int>(n * m, inf));
		auto color = [&](int x) {
			int r = x / m, c = x % m;
			return (r+c) & 1;
		};
		int sa, sb, fa, fb;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (plan[i][j] == 'A') {
					sa = enc(i, j);
				} else if (plan[i][j] == 'B') {
					sb = enc(i, j);
				} else if (plan[i][j] == 'a') {
					fa = enc(i, j);
				} else if (plan[i][j] == 'b') {
					fb = enc(i, j);
				}
			}
		}
		bool diff = color(sa) != color(sb);
		if ((color(fa) != color(fb)) != diff)
			return -1;
		dist[sa][sb] = 0;
		queue<pair<int, int>> que;
		que.emplace(sa, sb);
		while (!que.empty()) {
			int a, b;
			tie(a, b) = que.front();
			que.pop();
			int ra = a / m, ca = a % m;
			int rb = b / m, cb = b % m;
			for (int i = 0; i < 4; ++i) {
				int pa = ra + dr[i], qa = ca + dc[i];
				if (pa < 0 || pa >= n || qa < 0 || qa >= m) continue;
				if (plan[pa][qa] == '#') continue;
				int nowa = enc(pa, qa);
				for (int j = 0; j < 4; ++j) {
					int pb = rb + dr[j], qb = cb + dc[j];
					if (pb < 0 || pb >= n || qb < 0 || qb >= m) continue;
					if (plan[pb][qb] == '#') continue;
					int nowb = enc(pb, qb);
					if (nowa == b && nowb == a) continue;
					if (nowa == nowb) continue;
					if (dist[nowa][nowb] != inf) continue;
					dist[nowa][nowb] = dist[a][b] + 1;
					que.emplace(nowa, nowb);
				}
			}
		}
		int ans = dist[fa][fb];
		if (ans >= inf)
			return -1;
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
		cout << "Testing TwoRobots (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1603450824;
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
		TwoRobots _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string plan[] = {"Ab.a",
				                 "...B"};
				_expected = 3;
				_received = _obj.move(vector <string>(plan, plan+sizeof(plan)/sizeof(string))); break;
			}
			case 1:
			{
				string plan[] = {"#a#",
				                 "A.b",
				                 "#B#"};
				_expected = -1;
				_received = _obj.move(vector <string>(plan, plan+sizeof(plan)/sizeof(string))); break;
			}
			case 2:
			{
				string plan[] = {"#b#",
				                 "A.a",
				                 "#B#",
				                 "#.#"};
				_expected = -1;
				_received = _obj.move(vector <string>(plan, plan+sizeof(plan)/sizeof(string))); break;
			}
			case 3:
			{
				string plan[] = {"...",
				                 "#a#",
				                 "A.b",
				                 "#B#",
				                 "#.#"};
				_expected = 4;
				_received = _obj.move(vector <string>(plan, plan+sizeof(plan)/sizeof(string))); break;
			}
			case 4:
			{
				string plan[] = {"AB......ab"};
				_expected = 8;
				_received = _obj.move(vector <string>(plan, plan+sizeof(plan)/sizeof(string))); break;
			}
			case 5:
			{
				string plan[] = {"bA......Ba"};
				_expected = -1;
				_received = _obj.move(vector <string>(plan, plan+sizeof(plan)/sizeof(string))); break;
			}
			case 6:
			{
				string plan[] = {"bA.......Ba"};
				_expected = -1;
				_received = _obj.move(vector <string>(plan, plan+sizeof(plan)/sizeof(string))); break;
			}
			case 7:
			{
				string plan[] = {"AB.........",
				                 "...........",
				                 "...........",
				                 "........b.a"};
				_expected = -1;
				_received = _obj.move(vector <string>(plan, plan+sizeof(plan)/sizeof(string))); break;
			}
			case 8:
			{
				string plan[] = {"...A...",
				                 ".#####.",
				                 ".#####b",
				                 "B#####.",
				                 ".#####.",
				                 ".#####.",
				                 "..a...."};
				_expected = 13;
				_received = _obj.move(vector <string>(plan, plan+sizeof(plan)/sizeof(string))); break;
			}
			/*case 9:
			{
				string plan[] = ;
				_expected = ;
				_received = _obj.move(vector <string>(plan, plan+sizeof(plan)/sizeof(string))); break;
			}*/
			/*case 10:
			{
				string plan[] = ;
				_expected = ;
				_received = _obj.move(vector <string>(plan, plan+sizeof(plan)/sizeof(string))); break;
			}*/
			/*case 11:
			{
				string plan[] = ;
				_expected = ;
				_received = _obj.move(vector <string>(plan, plan+sizeof(plan)/sizeof(string))); break;
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
