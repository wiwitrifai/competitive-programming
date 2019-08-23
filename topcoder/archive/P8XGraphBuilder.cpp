#include <bits/stdc++.h>

using namespace std;
const int N = 105;

int dp[N][N];

class P8XGraphBuilder {
public:
	int solve(vector <int> scores) {
		int n = scores.size() + 1;
		int sum = n-2;
		memset(dp, -1, sizeof dp);
		dp[0][0] = 0;		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= sum; j++) if (dp[i][j] >= 0) {
				for (int k = 0; k <= sum-j; k++)
					dp[i+1][j+k] = max(dp[i+1][j+k], dp[i][j] + scores[k]);
			}
		}
		return dp[n][sum];
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
		cout << "Testing P8XGraphBuilder (275.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1483055723;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 275.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		P8XGraphBuilder _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int scores[] = {1, 3, 0};
				_expected = 8;
				_received = _obj.solve(vector <int>(scores, scores+sizeof(scores)/sizeof(int))); break;
			}
			case 1:
			{
				int scores[] = {0, 0, 0, 10};
				_expected = 10;
				_received = _obj.solve(vector <int>(scores, scores+sizeof(scores)/sizeof(int))); break;
			}
			case 2:
			{
				int scores[] = {1, 2, 3, 4, 5, 6};
				_expected = 12;
				_received = _obj.solve(vector <int>(scores, scores+sizeof(scores)/sizeof(int))); break;
			}
			case 3:
			{
				int scores[] = {5, 0, 0};
				_expected = 15;
				_received = _obj.solve(vector <int>(scores, scores+sizeof(scores)/sizeof(int))); break;
			}
			case 4:
			{
				int scores[] = {1, 3, 2, 5, 3, 7, 5};
				_expected = 20;
				_received = _obj.solve(vector <int>(scores, scores+sizeof(scores)/sizeof(int))); break;
			}
			/*case 5:
			{
				int scores[] = ;
				_expected = ;
				_received = _obj.solve(vector <int>(scores, scores+sizeof(scores)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int scores[] = ;
				_expected = ;
				_received = _obj.solve(vector <int>(scores, scores+sizeof(scores)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int scores[] = ;
				_expected = ;
				_received = _obj.solve(vector <int>(scores, scores+sizeof(scores)/sizeof(int))); break;
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
