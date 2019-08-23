#include <bits/stdc++.h>

using namespace std;

const int N = 50;

long long dp[N][N][3];
int p[N];


class DigitStringDiv1 {
public:
	long long count(string S, int X) {
		int n = S.size();
		for (int i = 0; i < n; ++i)
			S[i] -= '0';
		int m = 0;
		while (X) {
			p[m++] = X % 10;
			X /= 10;
		}
		reverse(p, p+m);
		memset(dp, 0, sizeof dp);
		dp[0][0][1] = 1;
		for (int i = 0; i < n; ++i) {
			dp[i+1][0][1] += dp[i][0][1];
			if (S[i] != 0) {
				dp[i+1][1][(S[i] >= p[0]) + (S[i] > p[0])] += dp[i][0][1];
			}
			for (int j = 1; j <= m+1; ++j) {
				for (int k = 0; k < 3; ++k) {
					dp[i+1][j][k] += dp[i][j][k];
					if (k != 1) {
						dp[i+1][min(j+1, m+1)][k] += dp[i][j][k];
					}
					else {
						int jj = min(j+1, m+1);
						int kk = k;
						if (jj > m)
							kk = 2;
						if (j < m) {
							if (S[i] < p[j])
								kk = 0;
							else if (S[i] == p[j])
								kk = 1;
							else
								kk = 2;
						}
						dp[i+1][jj][kk] += dp[i][j][k];						
					}
				}
			}
		}
		long long ans = dp[n][m][2];
		for (int i = 0; i < 3; ++i) {
			ans += dp[n][m+1][i];
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
		cout << "Testing DigitStringDiv1 (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1540947627;
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
		DigitStringDiv1 _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string S = "0";
				int X = 1;
				_expected = 0LL;
				_received = _obj.count(S, X); break;
			}
			case 1:
			{
				string S = "101";
				int X = 9;
				_expected = 3LL;
				_received = _obj.count(S, X); break;
			}
			case 2:
			{
				string S = "471";
				int X = 47;
				_expected = 2LL;
				_received = _obj.count(S, X); break;
			}
			case 3:
			{
				string S = "2222";
				int X = 97;
				_expected = 5LL;
				_received = _obj.count(S, X); break;
			}
			/*case 4:
			{
				string S = ;
				int X = ;
				_expected = LL;
				_received = _obj.count(S, X); break;
			}*/
			/*case 5:
			{
				string S = ;
				int X = ;
				_expected = LL;
				_received = _obj.count(S, X); break;
			}*/
			/*case 6:
			{
				string S = ;
				int X = ;
				_expected = LL;
				_received = _obj.count(S, X); break;
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
