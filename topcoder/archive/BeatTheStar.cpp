#include <bits/stdc++.h>

using namespace std;

const int N = 101, offset = N * N, M = offset + offset;

double dp[2][M];

class BeatTheStar {
public:
	double doesItMatter(int n, int g) {
		int c = 0, b = 1;
		fill(dp[c], dp[c]+M, 0.0f);
		dp[c][offset] = 1;
		for (int x = 1; x <= n; ++x) {
			if (x == g) continue;
			swap(c, b);
			fill(dp[c], dp[c]+M, 0.0f);
			for (int j = 0; j < M; ++j) {
				double cur = dp[b][j] * 0.5;
				if (j + x < M)
					dp[c][j+x] += cur;
				if (j - x >= 0)
					dp[c][j-x] += cur;
			}
		}
		double ans = 0;
		for (int i = 0; i < M; ++i) {
			if (abs(i-offset) < g) {
				ans += dp[c][i];
			}
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
		cout << "Testing BeatTheStar (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1583601081;
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
		BeatTheStar _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 2;
				int G = 1;
				_expected = 0.0;
				_received = _obj.doesItMatter(N, G); break;
			}
			case 1:
			{
				int N = 5;
				int G = 5;
				_expected = 0.625;
				_received = _obj.doesItMatter(N, G); break;
			}
			case 2:
			{
				int N = 5;
				int G = 1;
				_expected = 0.125;
				_received = _obj.doesItMatter(N, G); break;
			}
			case 3:
			{
				int N = 5;
				int G = 2;
				_expected = 0.125;
				_received = _obj.doesItMatter(N, G); break;
			}
			case 4:
			{
				int N = 9;
				int G = 7;
				_expected = 0.328125;
				_received = _obj.doesItMatter(N, G); break;
			}
			/*case 5:
			{
				int N = ;
				int G = ;
				_expected = ;
				_received = _obj.doesItMatter(N, G); break;
			}*/
			/*case 6:
			{
				int N = ;
				int G = ;
				_expected = ;
				_received = _obj.doesItMatter(N, G); break;
			}*/
			/*case 7:
			{
				int N = ;
				int G = ;
				_expected = ;
				_received = _obj.doesItMatter(N, G); break;
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
