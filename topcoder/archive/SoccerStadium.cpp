#include <bits/stdc++.h>

using namespace std;

class SoccerStadium {
public:
	int maximumGames(int H, int W, vector <string> placement) {
		vector<int> p(H * W, -1), lef(H * W), rig(H * W), top(H * W), bot(H * W);
		auto encode = [&](int r, int c) {
			return r * W + c;
		};
		auto decode = [&](int x) {
			return make_pair(x / W, x % W);
		};
		for (int i = 0; i < H; ++i) {
			for (int j = 0; j < W; ++j) {
				int now = encode(i, j);
				lef[now] = rig[now] = j;
				top[now] = bot[now] = i;
			}
		}
		function<int(int)> find = [&](int x) {
			return p[x] < 0 ? x : p[x] = find(p[x]);
		};
		function<bool(int, int)> merge = [&](int u, int v) {
			u = find(u);
			v = find(v);
			if (u == v)
				return false;
			if (-p[u] > -p[v])
				swap(u, v);
			p[v] += p[u];
			p[u] = v;
			lef[v] = min(lef[v], lef[u]);
			rig[v] = max(rig[v], rig[u]);
			top[v] = min(top[v], top[u]);
			bot[v] = max(bot[v], bot[u]);
			return true;
		};
		for (int i = 0; i < H; ++i) {
			for (int j = 0; j < W; ++j) {
				if (i + 1 < H) {
					char c = placement[2 + 2 * i][1 + 2 * j];
					if (c == '.')
						merge(encode(i, j), encode(i+1, j));
				}
				if (j + 1 < W) {
					char c = placement[1 + 2 * i][2 + 2 * j];
					if (c == '.')
						merge(encode(i, j), encode(i, j+1));
				}
			}
		}
		vector<bool> vis(H * W, false);
		for (int i = 0; i < H * W; ++i) {
			if (vis[find(i)]) continue;
			auto pos = decode(i);
			int t, b, l, r;
			t = b = pos.first;
			l = r = pos.second;
			while (lef[find(i)] < l || rig[find(i)] > r || top[find(i)] < t || bot[find(i)] > b) {
				if (lef[find(i)] < l) {
					for (int j = t; j <= b; ++j) {
						merge(encode(j, l-1), encode(j, l));
					}
					--l;
				} else if (rig[find(i)] > r) {
					for (int j = t; j <= b; ++j) {
						merge(encode(j, r), encode(j, r+1));
					}
					++r;
				} else if (top[find(i)] < t) {
					for (int j = l; j <= r; ++j) {
						merge(encode(t-1, j), encode(t, j));
					}
					--t;
				} else {
					for (int j = l; j <= r; ++j) {
						merge(encode(b, j), encode(b+1, j));
					}
					++b;
				}
			}
			vis[find(i)] = true;
		}
		int ans = 0;
		for (int i = 0; i < H * W; ++i) {
			ans += find(i) == i;
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
		cout << "Testing SoccerStadium (600.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1595589552;
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
		SoccerStadium _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int H = 4;
				int W = 4;
				string placement[] = { "+-+-+-+-+" ,
				                       "|.|.....|" ,
				                       "+.+-+-+-+" ,
				                       "|.|.|...|" ,
				                       "+-+-+.+.+" ,
				                       "|.|.|...|" ,
				                       "+-+.+.+-+" ,
				                       "|...|...|" ,
				                       "+-+-+-+-+" };
				_expected = 5;
				_received = _obj.maximumGames(H, W, vector <string>(placement, placement+sizeof(placement)/sizeof(string))); break;
			}
			case 1:
			{
				int H = 3;
				int W = 3;
				string placement[] = { "+-+-+-+" ,
				                       "|.....|" ,
				                       "+-+-+.+" ,
				                       "|.|.|.|" ,
				                       "+-+-+-+" ,
				                       "|.|.|.|" ,
				                       "+-+-+-+" };
				_expected = 4;
				_received = _obj.maximumGames(H, W, vector <string>(placement, placement+sizeof(placement)/sizeof(string))); break;
			}
			case 2:
			{
				int H = 3;
				int W = 3;
				string placement[] = { "+-+-+-+" ,
				                       "|.|...|" ,
				                       "+.+-+.+" ,
				                       "|.|.|.|" ,
				                       "+.+.+-+" ,
				                       "|.|...|" ,
				                       "+-+-+-+" };
				_expected = 2;
				_received = _obj.maximumGames(H, W, vector <string>(placement, placement+sizeof(placement)/sizeof(string))); break;
			}
			case 3:
			{
				int H = 3;
				int W = 3;
				string placement[] = { "+-+-+-+" ,
				                       "|.....|" ,
				                       "+.+-+.+" ,
				                       "|.|.|.|" ,
				                       "+.+-+.+" ,
				                       "|.....|" ,
				                       "+-+-+-+" };
				_expected = 1;
				_received = _obj.maximumGames(H, W, vector <string>(placement, placement+sizeof(placement)/sizeof(string))); break;
			}
			case 4:
			{
				int H = 3;
				int W = 4;
				string placement[] = { "+-+-+-+-+" ,
				                       "|.|.|...|" ,
				                       "+-+-+-+-+" ,
				                       "|.......|" ,
				                       "+.+-+-+.+" ,
				                       "|.......|" ,
				                       "+-+-+-+-+" };
				_expected = 4;
				_received = _obj.maximumGames(H, W, vector <string>(placement, placement+sizeof(placement)/sizeof(string))); break;
			}
			case 5:
			{
				int H = 7;
				int W = 9;
				string placement[] = { "+-+-+-+-+-+-+-+-+-+" ,
				                       "|.|...|...|...|...|" ,
				                       "+.+-+-+-+-+-+-+-+-+" ,
				                       "|.|.|...|...|...|.|" ,
				                       "+-+.+-+-+-+-+-+-+.+" ,
				                       "|.|.|.|...|...|.|.|" ,
				                       "+.+-+.+-+-+-+-+.+-+" ,
				                       "|.|.|.|.|.|.|.|.|.|" ,
				                       "+-+.+-+.+.+-+.+-+.+" ,
				                       "|.|.|...|...|.|.|.|" ,
				                       "+.+-+-+-+-+-+-+.+-+" ,
				                       "|.|...|...|...|.|.|" ,
				                       "+-+-+-+-+-+-+-+-+.+" ,
				                       "|...|...|...|...|.|" ,
				                       "+-+-+-+-+-+-+-+-+-+" };
				_expected = 25;
				_received = _obj.maximumGames(H, W, vector <string>(placement, placement+sizeof(placement)/sizeof(string))); break;
			}
			/*case 6:
			{
				int H = ;
				int W = ;
				string placement[] = ;
				_expected = ;
				_received = _obj.maximumGames(H, W, vector <string>(placement, placement+sizeof(placement)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				int H = ;
				int W = ;
				string placement[] = ;
				_expected = ;
				_received = _obj.maximumGames(H, W, vector <string>(placement, placement+sizeof(placement)/sizeof(string))); break;
			}*/
			/*case 8:
			{
				int H = ;
				int W = ;
				string placement[] = ;
				_expected = ;
				_received = _obj.maximumGames(H, W, vector <string>(placement, placement+sizeof(placement)/sizeof(string))); break;
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
