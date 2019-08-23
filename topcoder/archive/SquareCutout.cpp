#include <bits/stdc++.h>

using namespace std;

vector<string> b;

class SquareCutout {
public:
	int verify(vector <string> cutout) {
		b = cutout;
		int n = b.size();
		int m = b[0].size();
		int ada = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) {
				b[i][j] = b[i][j] == '#' ? 1 : 0;
				ada += b[i][j];
			}
		if (!ada) return 1;
		int xa = -1, ya = -1, xb = -1, yb = -1;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (b[i][j] && xa == -1)
					ya = i, xa = j;
				if (b[n-1-i][m-1-j] && xb == -1)
					yb = n-1-i, xb = m-1-j;
			}
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (ya <= i && i <= yb && xa <= j && j <= xb) {
					if (!b[i][j]) return 0;
				}
				else {
					if (b[i][j]) return 0;
				}
			}
		}
		if (xb - xa == yb - ya)
			return xb - xa + 1;
		if (xb -xa < yb - ya) {
			if (xb == m-1 || xa == 0)
				return yb - ya + 1;
		}
		else {
			if (yb == n-1 || ya == 0)
				return xb - xa + 1;
		}
		return 0;
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
		cout << "Testing SquareCutout (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1532048408;
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
		SquareCutout _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string cutout[] = {".....",
				                   "..##.",
				                   "..##.",
				                   ".....",
				                   "....."};
				_expected = 2;
				_received = _obj.verify(vector <string>(cutout, cutout+sizeof(cutout)/sizeof(string))); break;
			}
			case 1:
			{
				string cutout[] = {"...",
				                   "..."};
				_expected = 1;
				_received = _obj.verify(vector <string>(cutout, cutout+sizeof(cutout)/sizeof(string))); break;
			}
			case 2:
			{
				string cutout[] = {".....",
				                   ".###.",
				                   ".#.#.",
				                   ".###.",
				                   "....."};
				_expected = 0;
				_received = _obj.verify(vector <string>(cutout, cutout+sizeof(cutout)/sizeof(string))); break;
			}
			case 3:
			{
				string cutout[] = {"..####",
				                   "..####",
				                   "......"};
				_expected = 4;
				_received = _obj.verify(vector <string>(cutout, cutout+sizeof(cutout)/sizeof(string))); break;
			}
			case 4:
			{
				string cutout[] = {"..#..",
				                   ".###.",
				                   "#####",
				                   ".###.",
				                   "..#.."};
				_expected = 0;
				_received = _obj.verify(vector <string>(cutout, cutout+sizeof(cutout)/sizeof(string))); break;
			}
			/*case 5:
			{
				string cutout[] = ;
				_expected = ;
				_received = _obj.verify(vector <string>(cutout, cutout+sizeof(cutout)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string cutout[] = ;
				_expected = ;
				_received = _obj.verify(vector <string>(cutout, cutout+sizeof(cutout)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string cutout[] = ;
				_expected = ;
				_received = _obj.verify(vector <string>(cutout, cutout+sizeof(cutout)/sizeof(string))); break;
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
