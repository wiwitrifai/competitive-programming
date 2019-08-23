#include <bits/stdc++.h>

using namespace std;

class TwoLadders {
public:
	long long minSteps(int sx, int lx1, int lx2, vector <int> X, vector <int> Y) {
		vector<pair<int, int>> points;
		int n = X.size();
		for (int i = 0; i < n; ++i)
			points.emplace_back(Y[i], X[i]);
		sort(points.begin(), points.end());
		int nowy = 0, lasty = points.back().first;
		if (nowy == lasty) {
			int left = points[0].second, right = points.back().second;
			return min((long long)abs(sx-left) + abs(right-left), (long long)abs(sx - right) + abs(right - left));
		}
		vector<tuple<int, int, int>> vp;
		for (int i = 0; i < n;) {
			int y = points[i].first;
			int j = i;
			while (j < n && points[j].first == y) {
				++j;
			}
			vp.emplace_back(y, points[i].second, points[j-1].second);
			i = j;
		}
		auto calc = [](long long st, long long en, long long lef, long long rig) {
			return min(abs(st - lef) + abs(rig - en), abs(st - rig) + abs(lef - en)) + abs(rig - lef); 
		};
		long long dp[2];
		int lad[2];
		lad[0] = lx1;
		lad[1] = lx2;
		if (get<0>(vp[0]) == nowy) {
			dp[0] = calc(sx, lx1, get<1>(vp[0]), get<2>(vp[0]));
			dp[1] = calc(sx, lx2, get<1>(vp[0]), get<2>(vp[0]));
		}
		else {
			dp[0] = abs(lx1 - sx);
			dp[1] = abs(lx2 - sx);
		}
		long long ans = 1e18;
		for (auto it : vp) {
			int y, l, r;
			tie(y, l, r) = it;
			if (y <= nowy) continue;
			dp[0] += y - nowy;
			dp[1] += y - nowy;
			nowy = y;
			long long tmp[2];
			if (nowy == lasty) {
				for (int i = 0; i < 2; ++i) {
					ans = min(ans, dp[i] + abs(l - lad[i]) + abs(r-l));
					ans = min(ans, dp[i] + abs(r - lad[i]) + abs(r-l));
				}
				return ans;
			}
			tmp[0] = tmp[1] = 1e18;
			for (int i = 0; i < 2; ++i) {
				for (int j = 0; j < 2; ++j) {
					tmp[i] = min(tmp[i], calc(lad[j], lad[i], l, r) + dp[j]);
				}
			}
			dp[0] = tmp[0];
			dp[1] = tmp[1];
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
		cout << "Testing TwoLadders (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1563498009;
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
		TwoLadders _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int sx = 10;
				int lx1 = 0;
				int lx2 = 100;
				int X[] = {47, 42};
				int Y[] = {0, 0};
				_expected = 37LL;
				_received = _obj.minSteps(sx, lx1, lx2, vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int))); break;
			}
			case 1:
			{
				int sx = 10;
				int lx1 = 8;
				int lx2 = 11;
				int X[] = {10, 12};
				int Y[] = {1, 1};
				_expected = 5LL;
				_received = _obj.minSteps(sx, lx1, lx2, vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int))); break;
			}
			case 2:
			{
				int sx = 10;
				int lx1 = 8;
				int lx2 = 42;
				int X[] = {10, 12};
				int Y[] = {1, 1};
				_expected = 7LL;
				_received = _obj.minSteps(sx, lx1, lx2, vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int))); break;
			}
			case 3:
			{
				int sx = 10;
				int lx1 = 8;
				int lx2 = 42;
				int X[] = {10, 100, 12};
				int Y[] = {1, 0, 1};
				_expected = 181LL;
				_received = _obj.minSteps(sx, lx1, lx2, vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int))); break;
			}
			case 4:
			{
				int sx = 500000000;
				int lx1 = 1;
				int lx2 = 999999999;
				int X[] = {0, 1000000000, 0, 1000000000, 0, 1000000000, 0, 1000000000, 0, 1000000000, 0, 1000000000, 0, 1000000000};
				int Y[] = {1, 1, 2, 2, 3, 3, 4, 4, 7, 7, 999999947, 999999947, 900000047, 900000047};
				_expected = 8499999959LL;
				_received = _obj.minSteps(sx, lx1, lx2, vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int))); break;
			}
			/*case 5:
			{
				int sx = ;
				int lx1 = ;
				int lx2 = ;
				int X[] = ;
				int Y[] = ;
				_expected = LL;
				_received = _obj.minSteps(sx, lx1, lx2, vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int sx = ;
				int lx1 = ;
				int lx2 = ;
				int X[] = ;
				int Y[] = ;
				_expected = LL;
				_received = _obj.minSteps(sx, lx1, lx2, vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int sx = ;
				int lx1 = ;
				int lx2 = ;
				int X[] = ;
				int Y[] = ;
				_expected = LL;
				_received = _obj.minSteps(sx, lx1, lx2, vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int))); break;
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
