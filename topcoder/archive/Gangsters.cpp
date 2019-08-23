#include <bits/stdc++.h>

using namespace std;

const int N = 155, mod = 1e9 + 7;

int dp[N][N][N];
int n;

int solve(int x, int a, int b) {
	if (x == n)
		return a == 0 && b == 0;
	int & ret = dp[x][a][b];
	if (ret != -1)
		return ret;
	ret = 0;
	if (a > 0)
		ret = 1LL * solve(x+1, a, b) * a % mod;
	if (a > 0 && b > 0)
		ret = (ret + 1LL * solve(x+1, a-1, b-1) * b) % mod;
	if (b < a)
		ret = (ret + 1LL * solve(x+1, a, b+1) * (a-b)) % mod;
	cerr << x << " " << a << " " << b << " = " << ret << endl;
	return ret;
}

class Gangsters {
public:
	int countOrderings(int people, int alive) {
		memset(dp, -1, sizeof dp);
		n = people;
		return solve(0, alive, 0);
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
		cout << "Testing Gangsters (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1535214322;
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
		Gangsters _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int people = 4;
				int alive = 2;
				_expected = 12;
				_received = _obj.countOrderings(people, alive); break;
			}
			case 1:
			{
				int people = 3;
				int alive = 1;
				_expected = 6;
				_received = _obj.countOrderings(people, alive); break;
			}
			case 2:
			{
				int people = 3;
				int alive = 0;
				_expected = 0;
				_received = _obj.countOrderings(people, alive); break;
			}
			case 3:
			{
				int people = 9;
				int alive = 3;
				_expected = 203616;
				_received = _obj.countOrderings(people, alive); break;
			}
			case 4:
			{
				int people = 4;
				int alive = 1;
				_expected = 4;
				_received = _obj.countOrderings(people, alive); break;
			}
			/*case 5:
			{
				int people = ;
				int alive = ;
				_expected = ;
				_received = _obj.countOrderings(people, alive); break;
			}*/
			/*case 6:
			{
				int people = ;
				int alive = ;
				_expected = ;
				_received = _obj.countOrderings(people, alive); break;
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
