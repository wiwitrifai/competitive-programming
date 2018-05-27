#include <bits/stdc++.h>

using namespace std;

int s, c;

class MaxNiceMatrixDiv1 {
public:
	vector <int> getMaxMatrix(int a, int b, int c) {
		::s = b - a;
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
		cout << "Testing MaxNiceMatrixDiv1 (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1527318666;
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
		MaxNiceMatrixDiv1 _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int a = 1;
				int b = 3;
				int c = 3;
				int __expected[] = {2, 2, 1, 1, 1, 3 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getMaxMatrix(a, b, c); break;
			}
			case 1:
			{
				int a = 1;
				int b = 3;
				int c = 2;
				int __expected[] = {2, 2, 1, 3, 3, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getMaxMatrix(a, b, c); break;
			}
			case 2:
			{
				int a = 5;
				int b = 10;
				int c = 3;
				int __expected[] = {5, 5, 10, 7, 6, 7, 6, 8, 6, 8, 7, 5 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getMaxMatrix(a, b, c); break;
			}
			case 3:
			{
				int a = 10;
				int b = 13;
				int c = 4;
				int __expected[] = {10, 10, 10, 13, 11, 11, 11, 10 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getMaxMatrix(a, b, c); break;
			}
			case 4:
			{
				int a = 3;
				int b = 10;
				int c = 5;
				int __expected[] = {3, 3, 3, 3, 10, 5, 4, 4, 4, 5, 4, 5, 5, 5, 3 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getMaxMatrix(a, b, c); break;
			}
			/*case 5:
			{
				int a = ;
				int b = ;
				int c = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getMaxMatrix(a, b, c); break;
			}*/
			/*case 6:
			{
				int a = ;
				int b = ;
				int c = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getMaxMatrix(a, b, c); break;
			}*/
			/*case 7:
			{
				int a = ;
				int b = ;
				int c = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getMaxMatrix(a, b, c); break;
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
