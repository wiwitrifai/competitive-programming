#include <bits/stdc++.h>

using namespace std;

class BrownieGame {
public:
	vector <int> HowToCheat(int n, vector <int> r, vector <int> c) {
		
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
		cout << "Testing BrownieGame (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1522375277;
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
		BrownieGame _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 1;
				int r[] = {2};
				int c[] = {2};
				int __expected[] = {0, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.HowToCheat(n, vector <int>(r, r+sizeof(r)/sizeof(int)), vector <int>(c, c+sizeof(c)/sizeof(int))); break;
			}
			case 1:
			{
				int n = 2;
				int r[] = {2,2};
				int c[] = {2,2};
				int __expected[] = {0, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.HowToCheat(n, vector <int>(r, r+sizeof(r)/sizeof(int)), vector <int>(c, c+sizeof(c)/sizeof(int))); break;
			}
			case 2:
			{
				int n = 1;
				int r[] = {2};
				int c[] = {4};
				int __expected[] = {1, 2 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.HowToCheat(n, vector <int>(r, r+sizeof(r)/sizeof(int)), vector <int>(c, c+sizeof(c)/sizeof(int))); break;
			}
			case 3:
			{
				int n = 1;
				int r[] = {91};
				int c[] = {5};
				int __expected[] = {0, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.HowToCheat(n, vector <int>(r, r+sizeof(r)/sizeof(int)), vector <int>(c, c+sizeof(c)/sizeof(int))); break;
			}
			case 4:
			{
				int n = 2;
				int r[] = {87,36};
				int c[] = {100,23};
				int __expected[] = {0, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.HowToCheat(n, vector <int>(r, r+sizeof(r)/sizeof(int)), vector <int>(c, c+sizeof(c)/sizeof(int))); break;
			}
			/*case 5:
			{
				int n = ;
				int r[] = ;
				int c[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.HowToCheat(n, vector <int>(r, r+sizeof(r)/sizeof(int)), vector <int>(c, c+sizeof(c)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int n = ;
				int r[] = ;
				int c[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.HowToCheat(n, vector <int>(r, r+sizeof(r)/sizeof(int)), vector <int>(c, c+sizeof(c)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int n = ;
				int r[] = ;
				int c[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.HowToCheat(n, vector <int>(r, r+sizeof(r)/sizeof(int)), vector <int>(c, c+sizeof(c)/sizeof(int))); break;
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
