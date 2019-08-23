#include <bits/stdc++.h>

using namespace std;

struct node {
	int a, b;
	node(int a, int b) : a(a), b(b) {};
	bool operator<(node other) const {
		return 1LL * other.b * a > 1LL * other.a * b;
	}
};

int sum[55], dp[55][55][550];

class Moneymanager {
public:
	int getbest(vector <int> a, vector <int> b, int X) {
		vector< node > v;
		int n = a.size();
		for (int i = 0; i < n; i++)
			v.push_back(node(a[i], b[i]));
		sort(v.begin(), v.end());
		sum[n] = 0;
		for (int i = n-1; i >= 0; i--)
			sum[i] = sum[i+1] + v[i].b;
		int n2 = n/2, ans = 0;
		for (int br = 0; br <= 10 * n2; br++) {
			memset(dp, -1, sizeof dp);
			dp[0][0][0] = 0;
			for (int i = 0; i <= n2; i++) {
				for (int j = 0; j <= n2; j++) {
					int x = i + j;
					if (x >= n) continue;
					for (int k = 0; k <= min(j * 10, br); k++) {
						if (dp[i][j][k] < 0) continue;
						dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k] + v[x].a * (sum[x]+k));
						dp[i][j+1][k+v[x].b] = max(dp[i][j+1][k+v[x].b], dp[i][j][k] + v[x].a * (br-k));
					}
				}
			}
			if (dp[n2][n2][br] >= 0)
				ans = max(ans, dp[n2][n2][br] + X * br);
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
		cout << "Testing Moneymanager (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1489456339;
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
		Moneymanager _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int a[] = {1,1};
				int b[] = {2,1};
				int X = 0;
				_expected = 5;
				_received = _obj.getbest(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), X); break;
			}
			case 1:
			{
				int a[] = {1,1};
				int b[] = {1,5};
				int X = 10;
				_expected = 61;
				_received = _obj.getbest(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), X); break;
			}
			case 2:
			{
				int a[] = {4,4,6,6};
				int b[] = {2,2,3,3};
				int X = 100;
				_expected = 726;
				_received = _obj.getbest(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), X); break;
			}
			case 3:
			{
				int a[] = {30,13,28,59,26,62,48,75,6,69,94,51};
				int b[] = {4,6,4,5,4,3,1,5,6,5,2,2};
				int X = 62;
				_expected = 22096;
				_received = _obj.getbest(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), X); break;
			}
			/*case 4:
			{
				int a[] = ;
				int b[] = ;
				int X = ;
				_expected = ;
				_received = _obj.getbest(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), X); break;
			}*/
			/*case 5:
			{
				int a[] = ;
				int b[] = ;
				int X = ;
				_expected = ;
				_received = _obj.getbest(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), X); break;
			}*/
			/*case 6:
			{
				int a[] = ;
				int b[] = ;
				int X = ;
				_expected = ;
				_received = _obj.getbest(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), X); break;
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
