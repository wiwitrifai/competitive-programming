#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;
int vis[N];
bool dp[N][2];

class PartisanGame {
public:
	string getWinner(int n, vector <int> a, vector <int> b) {
		memset(vis, -1, sizeof vis);
		dp[0][0] = dp[0][1] = 0;
		int ma = 0, mb = 0;
		for (int i = 1; i <= 5; i++) {
			dp[i][0] = 0;
			for (int v : a)
				if (i >= v && dp[i-v][1] == 0)
					dp[i][0] = 1;
			dp[i][1] = 0;
			for (int v : b)
				if (i >= v && dp[i-v][0] == 0)
					dp[i][1] = 1;
			ma = 31 & ((ma << 1) | dp[i][0]);
			mb = 31 & ((mb << 1) | dp[i][1]);
		}
		vis[(ma << 5) | mb] = 1;
		int f, l;
		f = l = -1;
		for (int i = 6; i <= n; i++) {
			dp[i][0] = 0;
			for (int v : a)
				if (i >= v && dp[i-v][1] == 0)
					dp[i][0] = 1;
			dp[i][1] = 0;
			for (int v : b)
				if (i >= v && dp[i-v][0] == 0)
					dp[i][1] = 1;
			ma = 31 & ((ma << 1) | dp[i][0]);
			mb = 31 & ((mb << 1) | dp[i][1]);
			int mask = (ma << 5) | mb;
			if (vis[mask] != -1) {
				f = vis[mask];
				l = i-4;
				break;
			}
			vis[mask] = i-4;
		}
		if (f == -1)
			return dp[n][0] ? "Alice" : "Bob";
		n -= f;
		n %= (l-f);
		n += f;
		return dp[n][0] ? "Alice" : "Bob";
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
		cout << "Testing PartisanGame (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1487033881;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 300.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		PartisanGame _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 7;
				int a[] = {3, 4};
				int b[] = {4};
				_expected = "Alice";
				_received = _obj.getWinner(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 1:
			{
				int n = 10;
				int a[] = {1};
				int b[] = {4, 3, 2};
				_expected = "Bob";
				_received = _obj.getWinner(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 2:
			{
				int n = 104982;
				int a[] = {2, 3, 4, 5};
				int b[] = {2, 5};
				_expected = "Alice";
				_received = _obj.getWinner(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 3:
			{
				int n = 999999999;
				int a[] = {4};
				int b[] = {5};
				_expected = "Bob";
				_received = _obj.getWinner(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 4:
			{
				int n = 1000000000;
				int a[] = {1,2,3,4,5};
				int b[] = {1,2,3,4,5};
				_expected = "Alice";
				_received = _obj.getWinner(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			/*case 5:
			{
				int n = ;
				int a[] = ;
				int b[] = ;
				_expected = ;
				_received = _obj.getWinner(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int n = ;
				int a[] = ;
				int b[] = ;
				_expected = ;
				_received = _obj.getWinner(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int n = ;
				int a[] = ;
				int b[] = ;
				_expected = ;
				_received = _obj.getWinner(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
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
