#include <bits/stdc++.h>

using namespace std;

int calc(vector<string> & grid) {
	int R = grid.size(), C = grid[0].size();
	int ret = 0;
	for (int i = 0; i < R; ++i) {
		char last = '.';
		for (int j = 0; j < C; ++j) {
			if (grid[i][j] == '.') continue;
			if (last != grid[i][j] && last != '.') {
				++ret;
			}
			last = grid[i][j];
		}
	}
	for (int j = 0; j < C; ++j) {
		char last = '.';
		for (int i = 0; i < R; ++i) {
			if (grid[i][j] == '.') continue;
			if (last != grid[i][j] && last != '.') {
				++ret;
			}
			last = grid[i][j];
		}
	}
	return ret;
}

class RealWithRooks {
public:
	vector <string> construct(int R, int C, int N) {
		vector<string> ans(R, string(C, '.'));
		int cost = -1;
		for (int x = 1; x <= R; ++x) {
			int y = (N + x - 1) / x;
			if (y > C) continue;
			vector<string> grid(R, string(C, '.'));	
			int now = N;
			for (int j = 0; j < C; ++j) {
				for (int i = 0; i < x; ++i) {
					if (now > 0) {
						grid[i][j] = (i+j) & 1 ? 'B' : 'W';
						--now;
					}
				}
			}
			int cur = calc(grid);
			if (cur > cost) {
				cost = cur;
				ans = grid;
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
		cout << "Testing RealWithRooks (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1564808409;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 300.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		RealWithRooks _obj;
		vector <string> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int R = 2;
				int C = 4;
				int N = 8;
				string __expected[] = {"WBWB", "BWBW" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(R, C, N); break;
			}
			case 1:
			{
				int R = 5;
				int C = 5;
				int N = 9;
				string __expected[] = {"W.B.W", ".....", "B.W.B", ".....", "W.B.W" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(R, C, N); break;
			}
			case 2:
			{
				int R = 4;
				int C = 7;
				int N = 3;
				string __expected[] = {".......", ".W...BW", ".......", "......." };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(R, C, N); break;
			}
			case 3:
			{
				int R = 5;
				int C = 6;
				int N = 27;
				string __expected[] = {"..WBWB", ".WBWBW", "WBWBWB", "BWBWBW", "WBWBWB" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(R, C, N); break;
			}
			case 4:
			{
				int R = 2;
				int C = 2;
				int N = 1;
				string __expected[] = {"W.", ".."};
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(R, C, N); break;
			}
			/*case 5:
			{
				int R = ;
				int C = ;
				int N = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(R, C, N); break;
			}*/
			/*case 6:
			{
				int R = ;
				int C = ;
				int N = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(R, C, N); break;
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
			cout << "           Expected: {";
			for (unsigned i = 0; i < _expected.size(); i++)
			{
				if (i) cout << ",";
				cout << " \"" << _expected[i] << "\"";
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " \"" << _received[i] << "\"";
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
