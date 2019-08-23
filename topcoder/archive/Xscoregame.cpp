#include <bits/stdc++.h>

using namespace std;

const int inf = 1e7;
long long dp[64][1<<15];
vector< int > a;

long long get(int x, int mask) {
	if (mask == 0)
		return x;
	int cur = x & 63;
	if (dp[cur][mask] != -1)
		return dp[cur][mask] + ((x-cur) << (__builtin_popcount(mask)));
	dp[cur][mask] = -inf;
	for (int i = 0; i < a.size(); i++) {
		if (mask & (1<<i)) {
			long long now = get(cur+(cur ^ a[i]), mask ^ (1<<i));
			dp[cur][mask] = max(dp[cur][mask], now);
		}
	}
	// cerr << cur << " " << mask << " " << dp[cur][mask] << endl;
	return dp[cur][mask] + ((x-cur) << (__builtin_popcount(mask)));
}

class Xscoregame {
public:
	int getscore(vector <int> A) {
		memset(dp, -1, sizeof dp);
		a = A;
		int n = A.size();
		return get(0, (1<<n) - 1);
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
		cout << "Testing Xscoregame (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1487699830;
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
		Xscoregame _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int A[] = {1,2,3};
				_expected = 12;
				_received = _obj.getscore(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}
			case 1:
			{
				int A[] = {10,0,0,0};
				_expected = 80;
				_received = _obj.getscore(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}
			case 2:
			{
				int A[] = {1,1,1,1,1,1};
				_expected = 1;
				_received = _obj.getscore(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}
			case 3:
			{
				int A[] = {1,0,1,0,1,0,1,0};
				_expected = 170;
				_received = _obj.getscore(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}
			case 4:
			{
				int A[] = {50,0,1,0,1,0,1,0,1,0,1,0,1,0,1};
				_expected = 830122;
				_received = _obj.getscore(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}
			/*case 5:
			{
				int A[] = ;
				_expected = ;
				_received = _obj.getscore(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int A[] = ;
				_expected = ;
				_received = _obj.getscore(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int A[] = ;
				_expected = ;
				_received = _obj.getscore(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
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
