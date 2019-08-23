#include <bits/stdc++.h>

using namespace std;

class UpDownHiking {
public:
	int maxHeight(int N, int A, int B) {
		long long le, ri;
		le = ri = 0;
		for (int i = 0; i < N; i++) {
			if (le < ri)
				le += A;
			else
				ri += B;
		}		
		return min(le, ri);
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
		cout << "Testing UpDownHiking (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1487107443;
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
		UpDownHiking _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 3;
				int A = 7;
				int B = 10;
				_expected = 10;
				_received = _obj.maxHeight(N, A, B); break;
			}
			case 1:
			{
				int N = 5;
				int A = 40;
				int B = 30;
				_expected = 80;
				_received = _obj.maxHeight(N, A, B); break;
			}
			case 2:
			{
				int N = 2;
				int A = 50;
				int B = 1;
				_expected = 1;
				_received = _obj.maxHeight(N, A, B); break;
			}
			case 3:
			{
				int N = 3;
				int A = 42;
				int B = 42;
				_expected = 42;
				_received = _obj.maxHeight(N, A, B); break;
			}
			case 4:
			{
				int N = 20;
				int A = 7;
				int B = 9;
				_expected = 77;
				_received = _obj.maxHeight(N, A, B); break;
			}
			/*case 5:
			{
				int N = ;
				int A = ;
				int B = ;
				_expected = ;
				_received = _obj.maxHeight(N, A, B); break;
			}*/
			/*case 6:
			{
				int N = ;
				int A = ;
				int B = ;
				_expected = ;
				_received = _obj.maxHeight(N, A, B); break;
			}*/
			/*case 7:
			{
				int N = ;
				int A = ;
				int B = ;
				_expected = ;
				_received = _obj.maxHeight(N, A, B); break;
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
