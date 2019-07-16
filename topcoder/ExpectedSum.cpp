#include <bits/stdc++.h>

using namespace std;

const int N = 2501;

double dp[2][N][N];

class ExpectedSum {
public:
	double solve(vector <int> sequence, vector <int> probMinus) {
		int n = sequence.size();
		for (int c = 0; c < 2; ++c)
			for (int j = 0; j < N; ++j)
				for (int k = 0; k < N; ++k)
					dp[c][j][k] = 0;
		int sum = 0;
		int c = 0, b = 1;
		dp[c][0][0] = 1;
		for (int it = 0; it < n; ++it) {
			swap(c, b);
			int now = sequence[it];
			int nsum = sum + now;
			for (int i = 0; i <= nsum; ++i)
				for (int j = 0; j <= nsum; ++j)
					dp[c][i][j] = 0;
			double p = probMinus[it] / 100.0, q = 1 - p;
			for (int i = 0; i <= sum; ++i) {
				for (int j = 0; j <= i; ++j) {
					int jj = j + now, ii = max(jj, i);
					dp[c][ii][jj] += dp[b][i][j] * q;
					dp[c][i][max(j-now, 0)] += dp[b][i][j] * p;
				}
			}
			sum = nsum;
		}
		double ans = 0;
		for (int i = 0; i <= sum; ++i)
			for (int j = 0; j <= i; ++j) {
				ans += i * dp[c][i][j];
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
		cout << "Testing ExpectedSum (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1544376085;
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
		ExpectedSum _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int sequence[] = {10, 20, 30};
				int probMinus[] = {0, 0, 0};
				_expected = 60.0;
				_received = _obj.solve(vector <int>(sequence, sequence+sizeof(sequence)/sizeof(int)), vector <int>(probMinus, probMinus+sizeof(probMinus)/sizeof(int))); break;
			}
			case 1:
			{
				int sequence[] = {10, 40, 20};
				int probMinus[] = {0, 100, 0};
				_expected = 20.0;
				_received = _obj.solve(vector <int>(sequence, sequence+sizeof(sequence)/sizeof(int)), vector <int>(probMinus, probMinus+sizeof(probMinus)/sizeof(int))); break;
			}
			case 2:
			{
				int sequence[] = {1, 1, 1};
				int probMinus[] = {50, 50, 50};
				_expected = 1.375;
				_received = _obj.solve(vector <int>(sequence, sequence+sizeof(sequence)/sizeof(int)), vector <int>(probMinus, probMinus+sizeof(probMinus)/sizeof(int))); break;
			}
			case 3:
			{
				int sequence[] = {1, 1, 1};
				int probMinus[] = {30, 27, 43};
				_expected = 1.89227;
				_received = _obj.solve(vector <int>(sequence, sequence+sizeof(sequence)/sizeof(int)), vector <int>(probMinus, probMinus+sizeof(probMinus)/sizeof(int))); break;
			}
			case 4:
			{
				int sequence[] = {47};
				int probMinus[] = {100};
				_expected = 0.0;
				_received = _obj.solve(vector <int>(sequence, sequence+sizeof(sequence)/sizeof(int)), vector <int>(probMinus, probMinus+sizeof(probMinus)/sizeof(int))); break;
			}
			/*case 5:
			{
				int sequence[] = ;
				int probMinus[] = ;
				_expected = ;
				_received = _obj.solve(vector <int>(sequence, sequence+sizeof(sequence)/sizeof(int)), vector <int>(probMinus, probMinus+sizeof(probMinus)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int sequence[] = ;
				int probMinus[] = ;
				_expected = ;
				_received = _obj.solve(vector <int>(sequence, sequence+sizeof(sequence)/sizeof(int)), vector <int>(probMinus, probMinus+sizeof(probMinus)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int sequence[] = ;
				int probMinus[] = ;
				_expected = ;
				_received = _obj.solve(vector <int>(sequence, sequence+sizeof(sequence)/sizeof(int)), vector <int>(probMinus, probMinus+sizeof(probMinus)/sizeof(int))); break;
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
