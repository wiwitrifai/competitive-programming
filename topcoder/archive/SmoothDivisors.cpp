#include <bits/stdc++.h>

using namespace std;

const int N = 4e7 + 2;

int fp[N];

struct SmoothDivisors {
	int count(int A, int B) {
		fp[1] = 1;
		for (int i = 2; i < N; ++i) {
			if (fp[i])
				continue;
			for (int j = i; j < N; j += i)
				if (fp[j] == 0)
					fp[j] = i;
		}
		int ans = 0;
		for (int i = A; i <= B; ++i) {
			int p = fp[i], q = i / p;
			if (q == 1 || q == p) {
				++ans;
			} else if (fp[q] == q) {
			} else {
				int x = fp[q];
				q /= x;
				int cnt = (p == q) + (p == x) + (q == x);
				ans += (!(fp[q] == q && cnt == 1));
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
		cout << "Testing SmoothDivisors (600.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1629562678;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 600.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		SmoothDivisors _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int A = 213;
				int B = 219;
				_expected = 1;
				_received = _obj.count(A, B); break;
			}
			case 1:
			{
				int A = 47;
				int B = 49;
				_expected = 3;
				_received = _obj.count(A, B); break;
			}
			case 2:
			{
				int A = 1;
				int B = 5;
				_expected = 5;
				_received = _obj.count(A, B); break;
			}
			case 3:
			{
				int A = 34000046;
				int B = 34000046;
				_expected = 0;
				_received = _obj.count(A, B); break;
			}
			case 4:
			{
				int A = 27;
				int B = 27;
				_expected = 1;
				_received = _obj.count(A, B); break;
			}
			case 5:
			{
				int A = 1;
				int B = 4e7;
				_expected = 0;
				_received = _obj.count(A, B); break;
			}
			/*case 6:
			{
				int A = ;
				int B = ;
				_expected = ;
				_received = _obj.count(A, B); break;
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
