#include <bits/stdc++.h>

using namespace std;

long long dp[33][8];
vector< int > tri;
int v[3];

long long solve(int n, int mask) {
	if (n < 0)
		return 1;
	if (dp[n][mask] != -1)
		return dp[n][mask];
	long long & ret = dp[n][mask];
	ret = 0;
	for (int u : tri) {
		int was = u & mask;
		bool ok = 1;
		int nmask = mask;
		for (int i = 0; i < 3; i++) {
			if (was & (1 << i)) {
				if ((v[i] & (1<<n)) == 0) {
					ok = 0;
					break;
				}
			}
			if (((!(v[i] & (1<<n)) != !(u & (1<<i))) && (nmask & (1<<i)) > 0))
				nmask ^= (1<<i);
		}
		if (ok)
			ret += solve(n-1, nmask);
	}
	return ret;
}

class LittleElephantAndXor {
public:
	long long getNumber(int A, int B, int C) {
		v[0] = A;
		v[1] = B;
		v[2] = C;
		memset(dp, -1, sizeof dp);
		tri.clear();
		for (int i = 0; i < 8; i++) {
			if ((__builtin_popcount(i) & 1) == 0) {
				tri.push_back(i);
			}
		}
		return solve(31, 7);
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
		cout << "Testing LittleElephantAndXor (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1483053203;
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
		LittleElephantAndXor _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int A = 2;
				int B = 2;
				int C = 1;
				_expected = 5LL;
				_received = _obj.getNumber(A, B, C); break;
			}
			case 1:
			{
				int A = 4;
				int B = 7;
				int C = 3;
				_expected = 20LL;
				_received = _obj.getNumber(A, B, C); break;
			}
			case 2:
			{
				int A = 10;
				int B = 10;
				int C = 5;
				_expected = 57LL;
				_received = _obj.getNumber(A, B, C); break;
			}
			case 3:
			{
				int A = 774;
				int B = 477;
				int C = 447;
				_expected = 214144LL;
				_received = _obj.getNumber(A, B, C); break;
			}
			case 4:
			{
				int A = 1000000000;
				int B = 1000000000;
				int C = 500000000;
				_expected = 468566946385621507LL;
				_received = _obj.getNumber(A, B, C); break;
			}
			/*case 5:
			{
				int A = ;
				int B = ;
				int C = ;
				_expected = LL;
				_received = _obj.getNumber(A, B, C); break;
			}*/
			/*case 6:
			{
				int A = ;
				int B = ;
				int C = ;
				_expected = LL;
				_received = _obj.getNumber(A, B, C); break;
			}*/
			/*case 7:
			{
				int A = ;
				int B = ;
				int C = ;
				_expected = LL;
				_received = _obj.getNumber(A, B, C); break;
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
