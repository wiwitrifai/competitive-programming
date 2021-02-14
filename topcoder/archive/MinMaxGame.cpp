#include <bits/stdc++.h>

using namespace std;

class MinMaxGame {
public:
	int lastNumber(vector <int> A) {
		if (A.size() & 1)
			return max(A[0], A.back());
		else
			return min(A[0], A.back());
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
		cout << "Testing MinMaxGame (400.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1613236715;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 400.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		MinMaxGame _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int A[] = {3, 2, 1};
				_expected = 3;
				_received = _obj.lastNumber(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}
			case 1:
			{
				int A[] = {2, 5, 3, 7};
				_expected = 2;
				_received = _obj.lastNumber(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}
			case 2:
			{
				int A[] = {4, 5, 1, 6, 5};
				_expected = 5;
				_received = _obj.lastNumber(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}
			/*case 3:
			{
				int A[] = ;
				_expected = ;
				_received = _obj.lastNumber(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}*/
			/*case 4:
			{
				int A[] = ;
				_expected = ;
				_received = _obj.lastNumber(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int A[] = ;
				_expected = ;
				_received = _obj.lastNumber(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
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
