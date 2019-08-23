#include <bits/stdc++.h>

using namespace std;

const string some = "SOME";
const string all = "ALL";
const string none = "NONE";


class MinDegreeSubgraph {
public:
	string exists(int n, long long m, int k) {
		if (k == 0)
			return all;
		if (k == 1)
			return m == 0 ? none : all;
		if (n <= k) return none;
		if (m < 1LL * k * (k + 1) / 2)
			return none;
		if (m > 1LL * k * (k + 1) / 2 + 1LL * (n-1) * k)
			return all;
		return some;
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
		cout << "Testing MinDegreeSubgraph (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1534346816;
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
		MinDegreeSubgraph _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 3;
				long long m = 3LL;
				int k = 2;
				_expected = "ALL";
				_received = _obj.exists(n, m, k); break;
			}
			case 1:
			{
				int n = 4;
				long long m = 3LL;
				int k = 2;
				_expected = "SOME";
				_received = _obj.exists(n, m, k); break;
			}
			case 2:
			{
				int n = 6;
				long long m = 10LL;
				int k = 3;
				_expected = "ALL";
				_received = _obj.exists(n, m, k); break;
			}
			case 3:
			{
				int n = 6;
				long long m = 15LL;
				int k = 4;
				_expected = "ALL";
				_received = _obj.exists(n, m, k); break;
			}
			case 4:
			{
				int n = 17;
				long long m = 53LL;
				int k = 11;
				_expected = "NONE";
				_received = _obj.exists(n, m, k); break;
			}
			/*case 5:
			{
				int n = ;
				long long m = LL;
				int k = ;
				_expected = ;
				_received = _obj.exists(n, m, k); break;
			}*/
			/*case 6:
			{
				int n = ;
				long long m = LL;
				int k = ;
				_expected = ;
				_received = _obj.exists(n, m, k); break;
			}*/
			/*case 7:
			{
				int n = ;
				long long m = LL;
				int k = ;
				_expected = ;
				_received = _obj.exists(n, m, k); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
