#include <bits/stdc++.h>

using namespace std;
vector<string> ans;

int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};

int check(int x, int y) {
	int ret = 0;
	for (int i = 0; i < 4; ++i) {
		int xx = x+dx[i], yy = y+dy[i];
		if (min(xx, yy) < 0 || max(xx, yy) >= (int)ans.size())
			continue;
		if (!ans[xx][yy]) continue;
		ret |= 1 << (ans[xx][yy]-'0');
	}
	return ret;
}

class BoardCoveringDiv1 {
public:
	vector <string> make(int N, int R, int C) {
		ans.clear();
		int tot = N  * N -1;
		if (tot % 3) return vector<string>();
		int bef = R * N + C, aft = tot - bef;
		for (int i = 0; i < N; ++i)
			ans.push_back(string(N, '\0'));
		if ((bef % 3) == 0) {
		} else if (bef % 3 == 1) {

		}
		else {

		}
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
		cout << "Testing BoardCoveringDiv1 (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1540949190;
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
		BoardCoveringDiv1 _obj;
		vector <string> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 1;
				int R = 0;
				int C = 0;
				string __expected[] = {"#" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.make(N, R, C); break;
			}
			case 1:
			{
				int N = 4;
				int R = 1;
				int C = 1;
				string __expected[] = {"0011", "0#21", "3220", "3300" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.make(N, R, C); break;
			}
			case 2:
			{
				int N = 7;
				int R = 1;
				int C = 5;
				string __expected[] = {"1123344", "12235#4", "0066557", "0446877", "1242889", "1232299", "1233000" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.make(N, R, C); break;
			}
			/*case 3:
			{
				int N = ;
				int R = ;
				int C = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.make(N, R, C); break;
			}*/
			/*case 4:
			{
				int N = ;
				int R = ;
				int C = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.make(N, R, C); break;
			}*/
			/*case 5:
			{
				int N = ;
				int R = ;
				int C = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.make(N, R, C); break;
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
