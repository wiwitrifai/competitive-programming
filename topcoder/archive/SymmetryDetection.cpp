#include <bits/stdc++.h>

using namespace std;

class SymmetryDetection {
public:
	string detect(vector <string> board) {
		int n = board.size(), m = board[0].size();
		bool h = 1, v = 1;
		for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; ++j) {
      	if (board[i][j] != board[i][m-1-j]) v = 0;
      	if (board[i][j] != board[n-1-i][j]) h = 0;
      }
		}
		if (v && h) return "Both";
		if (v) return "Vertically symmetric";
		if (h) return "Horizontally symmetric";
		return "Neither";
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
		cout << "Testing SymmetryDetection (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1493266024;
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
		SymmetryDetection _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string board[] = {"#####",
				                  ".###.",
				                  "..#.."};
				_expected = "Vertically symmetric";
				_received = _obj.detect(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 1:
			{
				string board[] = {"#####",
				                  "#...#",
				                  "#####"};
				_expected = "Both";
				_received = _obj.detect(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 2:
			{
				string board[] = {"#..",
				                  "#..",
				                  "#.."};
				_expected = "Horizontally symmetric";
				_received = _obj.detect(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 3:
			{
				string board[] = {"#.",
				                  ".#"};
				_expected = "Neither";
				_received = _obj.detect(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 4:
			{
				string board[] = {"#######",
				                  "#..#..#",
				                  "#######",
				                  "...#...",
				                  "#######"};
				_expected = "Vertically symmetric";
				_received = _obj.detect(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 5:
			{
				string board[] = {"#.....#",
				                  "#.....#",
				                  "#######",
				                  "#...#.#",
				                  "#.....#"};
				_expected = "Neither";
				_received = _obj.detect(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 6:
			{
				string board[] = {"#######.#.....#",
				                  "...#....#.....#",
				                  ".#####..#######",
				                  "...#....#.....#",
				                  "#######.#.....#"};
				_expected = "Horizontally symmetric";
				_received = _obj.detect(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 7:
			{
				string board[] = {"."};
				_expected = "Both";
				_received = _obj.detect(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			/*case 8:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.detect(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}*/
			/*case 9:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.detect(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}*/
			/*case 10:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.detect(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
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
