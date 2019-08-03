#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7, N = 255;

int dp[N][N][N];

int solve(int h, int a, int c) {
	assert(h >= a);
	if (c < 0)
		return 0;
	if (h + a == 0) {
		if (c > 0)
			return 0;
		return 1;
	}
	int & ret = dp[h][a][c];
	if (ret != -1) return ret;
	ret = 0;
	if (a > 0) {
		ret = solve(h, a-1, c);
	}
	if (h-1 < a)
		ret += solve(a, h-1, c-1);
	else
		ret += solve(h-1, a, c);
	if (ret >= mod)
		ret -= mod;
	return ret;
}

class ChangesInTheLead {
public:
	int count(int H, int A, int C) {
		memset(dp, -1, sizeof dp);
		if (H < A)
			swap(H, A);
		int ans;
		if (H == 0)
			ans = solve(H, A, C);
		else if (H == A)
			ans = 2 * solve(H, A-1, C);
		else
			ans = solve(H, A, C);
		ans %= mod;
		if (ans < 0)
			ans += mod;
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
		cout << "Testing ChangesInTheLead (450.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1564809442;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 450.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		ChangesInTheLead _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int H = 7;
				int A = 0;
				int C = 0;
				_expected = 1;
				_received = _obj.count(H, A, C); break;
			}
			case 1:
			{
				int H = 0;
				int A = 6;
				int C = 250;
				_expected = 0;
				_received = _obj.count(H, A, C); break;
			}
			case 2:
			{
				int H = 3;
				int A = 1;
				int C = 1;
				_expected = 1;
				_received = _obj.count(H, A, C); break;
			}
			case 3:
			{
				int H = 6;
				int A = 4;
				int C = 2;
				_expected = 35;
				_received = _obj.count(H, A, C); break;
			}
			case 4:
			{
				int H = 6;
				int A = 7;
				int C = 3;
				_expected = 208;
				_received = _obj.count(H, A, C); break;
			}
			case 5:
			{
				int H = 0;
				int A = 0;
				int C = 0;
				_expected = 1;
				_received = _obj.count(H, A, C); break;
			}
			case 6:
			{
				int H = 2;
				int A = 2;
				int C = 0;
				_expected = 4;
				_received = _obj.count(H, A, C); break;
			}
			case 7:
			{
				int H = 2;
				int A = 2;
				int C = 2;
				_expected = 0;
				_received = _obj.count(H, A, C); break;
			}
			/*case 8:
			{
				int H = ;
				int A = ;
				int C = ;
				_expected = ;
				_received = _obj.count(H, A, C); break;
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
