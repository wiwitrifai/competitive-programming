#include <bits/stdc++.h>

using namespace std;

const int N = 55;
int mge[N][N], mv[N][N];

class MovingTokens {
public:
	int move(int n, int m, vector <int> moves) {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				mv[i][j] = moves[i * n + j];
			}
		}
		memset(mge, -1, sizeof mge);
		queue< pair< int, int > > que;
		for (int i = 0; i < n; i++) {
			que.push(make_pair(i, i));
		}
		while (!que.empty()) {
			pair< int, int > now = que.front(); que.pop();
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) if (now.first == mv[i][j]) {
					for (int k = 0; k < n; k++) if (mv[i][k] == now.second && mge[j][k] == -1) {
						mge[j][k] = i;
						que.push(make_pair(j, k));
					}
				}
			}
		}
		vector< int > token;
		for (int i = 0; i < n; i++)
			token.push_back(i);
		bool changed = 1;
		while (changed) {
			changed = 0;
			int a = -1, b = -1;
			for (int i = 0; i < token.size(); i++) {
				for (int j = i+1; j < token.size(); j++) if (mge[token[i]][token[j]] != -1) {
					a = token[i], b = token[j];
					changed = 1;
					break;
				}
			}
			if (changed) {
				while (a != b) {
					int id = mge[a][b];
					for (int i = 0; i < token.size(); i++) {
						token[i] = mv[id][token[i]];
					}
					a = mv[id][a];
					b = mv[id][b];
				}
				sort(token.begin(), token.end());
				token.erase(unique(token.begin(), token.end()), token.end());
			}
		}
		return token.size();
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
		cout << "Testing MovingTokens (450.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1484995320;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 450.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		MovingTokens _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 2;
				int m = 2;
				int moves[] = {0,1,
				              0,1};
				_expected = 2;
				_received = _obj.move(n, m, vector <int>(moves, moves+sizeof(moves)/sizeof(int))); break;
			}
			case 1:
			{
				int n = 2;
				int m = 2;
				int moves[] = {0,0,
				              1,1};
				_expected = 1;
				_received = _obj.move(n, m, vector <int>(moves, moves+sizeof(moves)/sizeof(int))); break;
			}
			case 2:
			{
				int n = 3;
				int m = 1;
				int moves[] = {0,1,1};
				_expected = 2;
				_received = _obj.move(n, m, vector <int>(moves, moves+sizeof(moves)/sizeof(int))); break;
			}
			case 3:
			{
				int n = 2;
				int m = 5;
				int moves[] = {0,0,
				               0,0,
				               0,0,
				               1,1,
				               1,1};
				_expected = 1;
				_received = _obj.move(n, m, vector <int>(moves, moves+sizeof(moves)/sizeof(int))); break;
			}
			case 4:
			{
				int n = 3;
				int m = 2;
				int moves[] = {0,2,2,
				               1,1,0};
				_expected = 1;
				_received = _obj.move(n, m, vector <int>(moves, moves+sizeof(moves)/sizeof(int))); break;
			}
			/*case 5:
			{
				int n = ;
				int m = ;
				int moves[] = ;
				_expected = ;
				_received = _obj.move(n, m, vector <int>(moves, moves+sizeof(moves)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int n = ;
				int m = ;
				int moves[] = ;
				_expected = ;
				_received = _obj.move(n, m, vector <int>(moves, moves+sizeof(moves)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int n = ;
				int m = ;
				int moves[] = ;
				_expected = ;
				_received = _obj.move(n, m, vector <int>(moves, moves+sizeof(moves)/sizeof(int))); break;
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
