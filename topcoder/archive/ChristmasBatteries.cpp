#include <bits/stdc++.h>

using namespace std;

class ChristmasBatteries {
public:
	int mostFun(int B, int N, int X, int Y, int Z, int M) {
		vector<vector<int>> fun(5, vector<int>());
		vector<int> dp(B+1, -1), pre(B+1, -1);
		for (int i = 0; i < N; ++i) {
			long long f = ((1LL * X * i % M) * i + 1LL * Y * i + Z) % M; 
			fun[i % 5].push_back(f);
		}
		long long ans = 0;
		for (int x : fun[0]) {
			ans += x;
		}
		dp[0] = 0;
		for (int i = 1; i < 5; ++i) {
			sort(fun[i].begin(), fun[i].end());
			reverse(fun[i].begin(), fun[i].end());
			int cnt = fun[i].size();
			for (int j = 0; j < cnt && (j+1) * i <= B; ++j) {
				int now = fun[i][j];
				pre = dp;
				for (int k = B-i; k >= 0; --k) {
					if (pre[k] <= -1) continue;
					dp[k+i] = max(dp[k+i], pre[k] + now);
				}
			}
		}
		ans += *max_element(dp.begin(), dp.end());
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
		cout << "Testing ChristmasBatteries (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1608725206;
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
		ChristmasBatteries _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int B = 0;
				int N = 5;
				int X = 1;
				int Y = 1;
				int Z = 1;
				int M = 1000;
				_expected = 1;
				_received = _obj.mostFun(B, N, X, Y, Z, M); break;
			}
			case 1:
			{
				int B = 3;
				int N = 5;
				int X = 1;
				int Y = 1;
				int Z = 1;
				int M = 1000;
				_expected = 14;
				_received = _obj.mostFun(B, N, X, Y, Z, M); break;
			}
			case 2:
			{
				int B = 3;
				int N = 5;
				int X = 1;
				int Y = 1;
				int Z = 1;
				int M = 13;
				_expected = 11;
				_received = _obj.mostFun(B, N, X, Y, Z, M); break;
			}
			case 3:
			{
				int B = 4;
				int N = 10000;
				int X = 123;
				int Y = 456;
				int Z = 789;
				int M = 1;
				_expected = 0;
				_received = _obj.mostFun(B, N, X, Y, Z, M); break;
			}
			case 4:
			{
				int B = 7;
				int N = 4;
				int X = 3;
				int Y = 5;
				int Z = 7;
				int M = 997;
				_expected = 100;
				_received = _obj.mostFun(B, N, X, Y, Z, M); break;
			}
			case 5:
			{
				int B = 2;
				int N = 12345;
				int X = 234;
				int Y = 34;
				int Z = 5;
				int M = 117;
				_expected = 143371;
				_received = _obj.mostFun(B, N, X, Y, Z, M); break;
			}
			/*case 6:
			{
				int B = ;
				int N = ;
				int X = ;
				int Y = ;
				int Z = ;
				int M = ;
				_expected = ;
				_received = _obj.mostFun(B, N, X, Y, Z, M); break;
			}*/
			/*case 7:
			{
				int B = ;
				int N = ;
				int X = ;
				int Y = ;
				int Z = ;
				int M = ;
				_expected = ;
				_received = _obj.mostFun(B, N, X, Y, Z, M); break;
			}*/
			/*case 8:
			{
				int B = ;
				int N = ;
				int X = ;
				int Y = ;
				int Z = ;
				int M = ;
				_expected = ;
				_received = _obj.mostFun(B, N, X, Y, Z, M); break;
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
