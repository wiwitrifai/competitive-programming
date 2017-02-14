#include <bits/stdc++.h>

using namespace std;

class XMarksTheSpot {
public:
	int countArea(vector <string> board) {
		vector< int > v;
		int n = board.size(), m = board[0].size();
		int t = n, b = 0, l = m, r = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == 'O') {
					t = min(t, i);
					b = max(b, i);
					l = min(l, j);
					r = max(r, j);
				}
				else if (board[i][j] == '?')
					v.push_back(i * m + j);
			}
		}
		long long ans = 0;
		for (int mask = 0; mask < (1<<v.size()); mask++) {
			int tt = t, bb = b, ll = l, rr = r; 
			for (int i = 0; i < v.size(); i++) if (mask & (1<<i)) {
				int x = v[i]/m, y = v[i] % m;
				tt = min(tt, x);
				bb = max(bb, x);
				ll = min(ll, y);
				rr = max(rr, y);
			}
			ans += 1LL * (bb-tt+1) * (rr-ll+1);
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
		cout << "Testing XMarksTheSpot (450.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1487045166;
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
		XMarksTheSpot _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string board[] = {
				                 "?.",
				                 ".O"
				                 };
				_expected = 5;
				_received = _obj.countArea(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 1:
			{
				string board[] = {
				                 "???",
				                 "?O?",
				                 "???"
				                 };
				_expected = 1952;
				_received = _obj.countArea(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 2:
			{
				string board[] = {
				                 "...?.",
				                 "?....",
				                 ".O...",
				                 "..?..",
				                 "....?"
				                 };
				_expected = 221;
				_received = _obj.countArea(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 3:
			{
				string board[] = {"OOOOOOOOOOOOOOOOOOOOO"};
				_expected = 21;
				_received = _obj.countArea(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 4:
			{
				string board[] = {"?????????OO??????????"};
				_expected = 9963008;
				_received = _obj.countArea(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 5:
			{
				string board[] = {
				                 "OOO",
				                 "O?O",
				                 "OOO",
				                 "..."
				                 };
				_expected = 18;
				_received = _obj.countArea(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			/*case 6:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.countArea(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.countArea(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}*/
			/*case 8:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.countArea(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
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
