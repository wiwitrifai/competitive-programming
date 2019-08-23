#include <bits/stdc++.h>

using namespace std;

const int N = 55;

int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
char dir[] = {'U', 'L', 'D', 'R'};

class StepsConstruct {
	int d[N][N], from[N][N];
public:
	string construct(vector <string> board, int k) {
		int n = board.size(), m = board[0].size();
		memset(d, -1, sizeof d);
		memset(from, -1, sizeof from);
		queue< int > que;
		if (board[0][0] == '.') {
			que.push(0);
			d[0][0] = 0;
		}
		while (!que.empty()) {
			int now = que.front();
			int x = now / m, y = now % m;
			que.pop();
			for (int j = 0; j < 4; j++) {
				int xx = x + dx[j], yy = y + dy[j];
				if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
				if (d[xx][yy] >= 0) continue;
				if (board[xx][yy] == '#') continue;
				d[xx][yy] = d[x][y] + 1;
				from[xx][yy] = j;
				que.push(xx * m + yy);
			}
		}
		if (d[n-1][m-1] == -1 || ((d[n-1][m-1] & 1) != (k & 1)) || k < d[n-1][m-1])
			return "";
		int x = n-1, y = m-1;
		string ans;
		while (x != 0 || y != 0) {
			int f = from[x][y];
			ans.push_back(dir[f]);
			x -= dx[f], y -= dy[f];
		}
		reverse(ans.begin(), ans.end());
		k -= ans.size();
		if (k & 1) return "";
		if (n-2 >= 0 && board[n-2][m-1] == '.') {
			while (k) {
				ans.push_back('U');
				ans.push_back('D');
				k -= 2;
			}
		}
		else if (m-2 >= 0 && board[n-1][m-2] == '.') {
			while (k) {
				ans.push_back('L');
				ans.push_back('R');
				k -= 2;
			}
		}	
		return k ? "" : ans; 

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
		cout << "Testing StepsConstruct (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1486939384;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 500.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		StepsConstruct _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string board[] = {"...",
				                  ".#.",
				                  "..."};
				int k = 4;
				_expected = "DDRR";
				_received = _obj.construct(vector <string>(board, board+sizeof(board)/sizeof(string)), k); break;
			}
			case 1:
			{
				string board[] = {"...",
				                  ".#.",
				                  "..."};
				int k = 12;
				_expected = "DDRRUULLDDRR";
				_received = _obj.construct(vector <string>(board, board+sizeof(board)/sizeof(string)), k); break;
			}
			case 2:
			{
				string board[] = {"...#.",
				                  "..#..",
				                  ".#..."};
				int k = 100;
				_expected = "";
				_received = _obj.construct(vector <string>(board, board+sizeof(board)/sizeof(string)), k); break;
			}
			case 3:
			{
				string board[] = {"..#",
				                  "#.#",
				                  "..#",
				                  ".#.",
				                  "..."};
				int k = 6;
				_expected = "";
				_received = _obj.construct(vector <string>(board, board+sizeof(board)/sizeof(string)), k); break;
			}
			case 4:
			{
				string board[] = {".#...",
				                  ".#.#.",
				                  ".#.#.",
				                  ".#.#.",
				                  "...#."};
				int k = 16;
				_expected = "DDDDRRUUUURRDDDD";
				_received = _obj.construct(vector <string>(board, board+sizeof(board)/sizeof(string)), k); break;
			}
			case 5:
			{
				string board[] = {"#.", 
				                  ".."};
				int k = 2;
				_expected = "";
				_received = _obj.construct(vector <string>(board, board+sizeof(board)/sizeof(string)), k); break;
			}
			/*case 6:
			{
				string board[] = ;
				int k = ;
				_expected = ;
				_received = _obj.construct(vector <string>(board, board+sizeof(board)/sizeof(string)), k); break;
			}*/
			/*case 7:
			{
				string board[] = ;
				int k = ;
				_expected = ;
				_received = _obj.construct(vector <string>(board, board+sizeof(board)/sizeof(string)), k); break;
			}*/
			/*case 8:
			{
				string board[] = ;
				int k = ;
				_expected = ;
				_received = _obj.construct(vector <string>(board, board+sizeof(board)/sizeof(string)), k); break;
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
