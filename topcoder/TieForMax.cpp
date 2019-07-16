#include <bits/stdc++.h>

using namespace std;

const int N = 55;

double cost[N][N];
double dp[N][N][N][2];

class TieForMax {
public:
	double getProbability(int t, int p) {
		cost[0][0] = 1;
		for (int i = 1; i <= t; ++i) {
			cost[i][0] = cost[i-1][0];
			cost[i][i] = cost[i-1][i-1]/p;
			for (int j = 1; j < i; ++j)
				cost[i][j] = cost[i-1][j-1]/p + cost[i-1][j];
		}
		dp[0][t][0][0] = 1;
		for (int j = 0; j < p; ++j) {
			for (int i = 0; i <= t; ++i) {
				for (int m = 0; m <= t; ++m) {
					for (int b = 0; b < 2; ++b) {
						for (int k = 0; k <= i; ++k) {
							double now = dp[j][i][m][b] * cost[i][k];
							if (k < m) {
								dp[j+1][i-k][m][b] += now;
							}
							else if (k == m) {
								dp[j+1][i-k][m][1] += now;
							}
							else {
								dp[j+1][i-k][k][0] += now;
							}
						}
					}
				}
			}
		}
		double ans = 0;
		for (int i = 0; i <= t; ++i) {
			// cerr << i << " " << dp[p][0][i][1] << endl;
			ans += dp[p][0][i][1];
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
		cout << "Testing TieForMax (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1547914707;
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
		TieForMax _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int t = 7;
				int p = 1;
				_expected = 0.0;
				_received = _obj.getProbability(t, p); break;
			}
			case 1:
			{
				int t = 2;
				int p = 2;
				_expected = 0.5;
				_received = _obj.getProbability(t, p); break;
			}
			case 2:
			{
				int t = 3;
				int p = 3;
				_expected = 0.2222222222222222;
				_received = _obj.getProbability(t, p); break;
			}
			case 3:
			{
				int t = 6;
				int p = 4;
				_expected = 0.380859375;
				_received = _obj.getProbability(t, p); break;
			}
			/*case 4:
			{
				int t = ;
				int p = ;
				_expected = ;
				_received = _obj.getProbability(t, p); break;
			}*/
			/*case 5:
			{
				int t = ;
				int p = ;
				_expected = ;
				_received = _obj.getProbability(t, p); break;
			}*/
			/*case 6:
			{
				int t = ;
				int p = ;
				_expected = ;
				_received = _obj.getProbability(t, p); break;
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
