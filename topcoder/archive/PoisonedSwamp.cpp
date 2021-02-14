#include <bits/stdc++.h>

using namespace std;

const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, -1, 0, 1};

class PoisonedSwamp {
public:
	string cross(vector <string> swamp) {
		int n = swamp.size();
		int m = swamp[0].size();
		vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(10, -1)));
		queue<int> que;
		auto enc = [&](int r, int c, int d) {
			return (r * m + c) * 10 + d;
		};
		que.emplace(enc(0, 0, 0));
		while (!que.empty()) {
			int r, c, d;
			int v = que.front();
			que.pop();
			d = v % 10;
			v /= 10;
			r = v / m;
			c = v % m;
			for (int i = 0; i < 4; ++i) {
				int rr = r + dr[i];
				int cc = c + dc[i];
				if (rr < 0 || rr >= n || cc < 0 || cc >= m) continue;
				if (swamp[rr][cc] == '#') continue;
				int dd = d;
				if (swamp[rr][cc] == 'S')
					dd = 0;
				else if ('0' <= swamp[rr][cc] && swamp[rr][cc] <= '9') {
					dd += swamp[rr][cc] - '0';
				}
				if (dd > 9) continue;
				if (dist[rr][cc][dd] != -1) continue;
				dist[rr][cc][dd] = 1;
				que.emplace(enc(rr, cc, dd));
			}
		}
		for (int i = 0; i <= 9; ++i) {
			if (dist[n-1][m-1][i] != -1)
				return "possible";
		}
		return "impossible";
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
		cout << "Testing PoisonedSwamp (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1613236210;
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
		PoisonedSwamp _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string swamp[] = {".....",
				                  "####.",
				                  ".....",
				                  ".####",
				                  "....."};
				_expected = "possible";
				_received = _obj.cross(vector <string>(swamp, swamp+sizeof(swamp)/sizeof(string))); break;
			}
			case 1:
			{
				string swamp[] = {".....",
				                  "####.",
				                  "97...",
				                  "9#2##",
				                  "97..."};
				_expected = "possible";
				_received = _obj.cross(vector <string>(swamp, swamp+sizeof(swamp)/sizeof(string))); break;
			}
			case 2:
			{
				string swamp[] = {".111111111.",
				                  ".#########.",
				                  "..22222...."};
				_expected = "possible";
				_received = _obj.cross(vector <string>(swamp, swamp+sizeof(swamp)/sizeof(string))); break;
			}
			case 3:
			{
				string swamp[] = {".#222#111",
				                  "4#S#2#1#S",
				                  "4#3#S#1#9",
				                  "S33#111#."};
				_expected = "possible";
				_received = _obj.cross(vector <string>(swamp, swamp+sizeof(swamp)/sizeof(string))); break;
			}
			case 4:
			{
				string swamp[] = {"..111111111111..",
				                  "###############."};
				_expected = "impossible";
				_received = _obj.cross(vector <string>(swamp, swamp+sizeof(swamp)/sizeof(string))); break;
			}
			case 5:
			{
				string swamp[] = {"..111111111111..",
				                  "#######S#######."};
				_expected = "possible";
				_received = _obj.cross(vector <string>(swamp, swamp+sizeof(swamp)/sizeof(string))); break;
			}
			case 6:
			{
				string swamp[] = {"..#.#.",
				                  "..#.#.",
				                  "#5#.5.",
				                  "....#."};
				_expected = "impossible";
				_received = _obj.cross(vector <string>(swamp, swamp+sizeof(swamp)/sizeof(string))); break;
			}
			case 7:
			{
				string swamp[] = {".1.#.",
				                  ".9.#.",
				                  ".###.",
				                  "2#.1.",
				                  ".#.7."};
				_expected = "impossible";
				_received = _obj.cross(vector <string>(swamp, swamp+sizeof(swamp)/sizeof(string))); break;
			}
			/*case 8:
			{
				string swamp[] = ;
				_expected = ;
				_received = _obj.cross(vector <string>(swamp, swamp+sizeof(swamp)/sizeof(string))); break;
			}*/
			/*case 9:
			{
				string swamp[] = ;
				_expected = ;
				_received = _obj.cross(vector <string>(swamp, swamp+sizeof(swamp)/sizeof(string))); break;
			}*/
			/*case 10:
			{
				string swamp[] = ;
				_expected = ;
				_received = _obj.cross(vector <string>(swamp, swamp+sizeof(swamp)/sizeof(string))); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
