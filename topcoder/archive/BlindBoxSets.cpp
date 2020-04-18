#include <bits/stdc++.h>

using namespace std;

const int N = 51;

int n;
double dp[N][N][N][N], p[N];
bool vis[N][N][N][N];

double solve(int a, int b, int c, int d) {
	if (vis[a][b][c][d])
		return dp[a][b][c][d];
	if (a == 0 && b == 0 && c == 0 && d == 0)
		return 0;
	double & ret = dp[a][b][c][d];
	vis[a][b][c][d] = 1;
	ret = 1;
	if (a)
		ret += p[a] * solve(a-1, b+1, c, d);
	if (b)
		ret += p[b] * solve(a, b-1, c+1, d);
	if (c)
		ret += p[c] * solve(a, b, c-1, d+1);
	if (d)
		ret += p[d] * solve(a, b, c, d-1);
	int sum = a + b + c + d;
	if (sum < n) {
		ret /= (1.0 - p[n - sum]);
	}
	return ret;
}

class BlindBoxSets {
public:
	double expectedPurchases(int numSets, int numItems) {
		n = numItems;
		for (int i = 0; i <= n; ++i) {
			p[i] = (long double)i / n;
		}
		int r[4];
		memset(r, 0, sizeof r);
		r[4 - numSets] = numItems;
		return solve(r[0], r[1], r[2], r[3]);
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
		cout << "Testing BlindBoxSets (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1587227107;
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
		BlindBoxSets _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int numSets = 1;
				int numItems = 1;
				_expected = 1.0;
				_received = _obj.expectedPurchases(numSets, numItems); break;
			}
			case 1:
			{
				int numSets = 1;
				int numItems = 2;
				_expected = 3.0;
				_received = _obj.expectedPurchases(numSets, numItems); break;
			}
			case 2:
			{
				int numSets = 2;
				int numItems = 1;
				_expected = 2.0;
				_received = _obj.expectedPurchases(numSets, numItems); break;
			}
			case 3:
			{
				int numSets = 2;
				int numItems = 2;
				_expected = 5.5;
				_received = _obj.expectedPurchases(numSets, numItems); break;
			}
			/*case 4:
			{
				int numSets = 4;
				int numItems = 49;
				_expected = 100;
				_received = _obj.expectedPurchases(numSets, numItems); break;
			}*/
			/*case 5:
			{
				int numSets = ;
				int numItems = ;
				_expected = ;
				_received = _obj.expectedPurchases(numSets, numItems); break;
			}*/
			/*case 6:
			{
				int numSets = ;
				int numItems = ;
				_expected = ;
				_received = _obj.expectedPurchases(numSets, numItems); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
