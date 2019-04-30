#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int dp[N][N];

class CentipedeSocks {
public:
	int fewestSocks(int C, int F, vector <int> sockCounts) {
		memset(dp, -1, sizeof dp);
		dp[0][0] = 0;
		int sum = 0;
		for (int i = 0; i < sockCounts.size(); ++i) {
			for (int j = 0; j <= C; ++j) {
				int & now = dp[i][j];
				if (now == -1) continue;
				for (int k = 0; k + j <= C; ++k) {
					int ambil = min(k * F + F-1, sockCounts[i]);
					if (ambil < k * F) break;
					dp[i+1][k+j] = max(dp[i+1][k+j], now + ambil);
				}
			}
			sum += sockCounts[i];
		}
		int res = dp[sockCounts.size()][C-1];
		return (res == sum || res == -1) ? -1 : res + 1;
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
		cout << "Testing CentipedeSocks (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1556586008;
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
		CentipedeSocks _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int C = 1;
				int F = 100;
				int sockCounts[] = {1, 1, 1, 1, 100};
				_expected = 104;
				_received = _obj.fewestSocks(C, F, vector <int>(sockCounts, sockCounts+sizeof(sockCounts)/sizeof(int))); break;
			}
			case 1:
			{
				int C = 1;
				int F = 100;
				int sockCounts[] = {40, 50, 60, 70};
				_expected = -1;
				_received = _obj.fewestSocks(C, F, vector <int>(sockCounts, sockCounts+sizeof(sockCounts)/sizeof(int))); break;
			}
			case 2:
			{
				int C = 3;
				int F = 10;
				int sockCounts[] = {12345};
				_expected = 30;
				_received = _obj.fewestSocks(C, F, vector <int>(sockCounts, sockCounts+sizeof(sockCounts)/sizeof(int))); break;
			}
			case 3:
			{
				int C = 2;
				int F = 3;
				int sockCounts[] = {4, 4, 5};
				_expected = 10;
				_received = _obj.fewestSocks(C, F, vector <int>(sockCounts, sockCounts+sizeof(sockCounts)/sizeof(int))); break;
			}
			/*case 4:
			{
				int C = ;
				int F = ;
				int sockCounts[] = ;
				_expected = ;
				_received = _obj.fewestSocks(C, F, vector <int>(sockCounts, sockCounts+sizeof(sockCounts)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int C = ;
				int F = ;
				int sockCounts[] = ;
				_expected = ;
				_received = _obj.fewestSocks(C, F, vector <int>(sockCounts, sockCounts+sizeof(sockCounts)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int C = ;
				int F = ;
				int sockCounts[] = ;
				_expected = ;
				_received = _obj.fewestSocks(C, F, vector <int>(sockCounts, sockCounts+sizeof(sockCounts)/sizeof(int))); break;
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
