#include <bits/stdc++.h>

using namespace std;

class FourSquareSum {
public:
	vector <int> DivideByTwo(int a, int b, int c, int d) {
		if ((a & 1) != (b & 1))
			swap(b, c);
		if ((a & 1) != (b & 1))
			swap(b, d);
		int s = abs(a + b) / 2, x = abs(a-b)/2, y = abs(c + d) / 2, z = abs(c-d)/2;
		return {s, x, y, z};
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
		cout << "Testing FourSquareSum (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1565456110;
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
		FourSquareSum _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int a = 1;
				int b = 2;
				int c = 3;
				int d = 4;
				int __expected[] = {1, 1, 2, 3 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.DivideByTwo(a, b, c, d); break;
			}
			case 1:
			{
				int a = 5;
				int b = 7;
				int c = 1;
				int d = 3;
				int __expected[] = {1, 1, 2, 6 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.DivideByTwo(a, b, c, d); break;
			}
			case 2:
			{
				int a = 0;
				int b = 0;
				int c = 0;
				int d = 0;
				int __expected[] = {0, 0, 0, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.DivideByTwo(a, b, c, d); break;
			}
			/*case 3:
			{
				int a = ;
				int b = ;
				int c = ;
				int d = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.DivideByTwo(a, b, c, d); break;
			}*/
			/*case 4:
			{
				int a = ;
				int b = ;
				int c = ;
				int d = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.DivideByTwo(a, b, c, d); break;
			}*/
			/*case 5:
			{
				int a = ;
				int b = ;
				int c = ;
				int d = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.DivideByTwo(a, b, c, d); break;
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
