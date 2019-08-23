#include <bits/stdc++.h>

using namespace std;

class ColoringEdgesDiv1 {
public:
	vector <int> findColoring(int n, vector <int> x, vector <int> y) {
		
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
		cout << "Testing ColoringEdgesDiv1 (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1530983149;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		ColoringEdgesDiv1 _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 6;
				int x[] = {2, 0, 3, 1, 1, 0, 0, 2, 4};
				int y[] = {3, 3, 1, 5, 4, 2, 4, 5, 5};
				int __expected[] = {0, 1, 0, 1, 0, 1, 0, 0, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findColoring(n, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 1:
			{
				int n = 6;
				int x[] = {3, 5, 4, 1, 4, 2, 0, 1, 2};
				int y[] = {4, 2, 1, 3, 5, 0, 5, 0, 3};
				int __expected[] = {0, 0, 0, 1, 1, 1, 0, 1, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findColoring(n, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 2:
			{
				int n = 8;
				int x[] = {0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3};
				int y[] = {1, 2, 3, 4, 5, 6, 7, 0, 4, 5, 7, 6};
				int __expected[] = {0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findColoring(n, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 3:
			{
				int n = 6;
				int x[] = {0, 1, 2, 3, 4, 5, 0, 1, 2};
				int y[] = {1, 2, 3, 4, 5, 0, 3, 4, 5};
				int __expected[] = {1, 0, 1, 0, 1, 0, 1, 0, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findColoring(n, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 4:
			{
				int n = 4;
				int x[] = {0, 1, 2, 3, 0, 1};
				int y[] = {1, 2, 3, 0, 2, 3};
				int __expected[] = {0, 1, 0, 1, 0, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findColoring(n, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			/*case 5:
			{
				int n = ;
				int x[] = ;
				int y[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findColoring(n, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int n = ;
				int x[] = ;
				int y[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findColoring(n, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int n = ;
				int x[] = ;
				int y[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findColoring(n, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
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
				cout << " " << _expected[i];
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _received[i];
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
