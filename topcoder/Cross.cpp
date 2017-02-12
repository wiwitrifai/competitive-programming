#include <bits/stdc++.h>

using namespace std;

int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};

class Cross {
public:
	string exist(vector <string> board) {
		int n = board.size(), m = board[0].size();
		bool ok = false;
		for (int i = 1; i < n-1 && !ok; i++) {
			for (int j = 1; j < m-1 && !ok; j++) {
				if (board[i][j] == '.') continue;
				bool found = 1;
				for (int k = 0; k < 4; k++) {
					if (board[i+dx[k]][j+dy[k]] == '.') {
						found = 0;
						break;
					}
				}	
				if (found)
					return "Exist";
			}
		}
		return "Does not exist";
		
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
		cout << "Testing Cross (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1486939098;
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
		Cross _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string board[] = {".##",
				                  "###",
				                  "##."};
				_expected = "Exist";
				_received = _obj.exist(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 1:
			{
				string board[] = {".##",
				                  "###",
				                  "#.."};
				_expected = "Does not exist";
				_received = _obj.exist(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 2:
			{
				string board[] = {"######",
				                  "######",
				                  "######",
				                  "######",
				                  "######",
				                  "######",
				                  "######"};
				_expected = "Exist";
				_received = _obj.exist(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 3:
			{
				string board[] = {".#.#",
				                  "#.#.",
				                  ".#.#",
				                  "#.#."};
				_expected = "Does not exist";
				_received = _obj.exist(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 4:
			{
				string board[] = {".#.#",
				                  "###.",
				                  ".###",
				                  "#.#."};
				_expected = "Exist";
				_received = _obj.exist(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			/*case 5:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.exist(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.exist(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.exist(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
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
