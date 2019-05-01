#include <bits/stdc++.h>

using namespace std;

class EllysPearls {
public:
	int getMin(int N, int M, vector <int> pearls) {
    vector<int> cnt(M, 0);
    vector<vector<int>> dp(M, vector<int>(1 << M, 0));
    for (int & x : pearls) {
      --x;
      ++cnt[x];
    }
    int nmask = 1 << M;
    for (int x : pearls) {
      for (int mask = 0; mask < nmask; ++mask) {
        if (mask & (1 << x)) {
          ++dp[x][mask];
        }
      }
      for (int mask = 0; mask < nmask; ++mask) {
        vector<int> one, zero;
        for (int j = 0; j < M; ++j) {
          if (mask & (1 << j))
            one.push_back(j);
          else
            zero.push_back(j);
        }
        for (int k : zero) {
          int tmask = mask | (1 << k);
          for (int j : one) {
            dp[k][tmask] = max(dp[j][mask], dp[k][tmask]);
          }
        }
      }
    }
    int best = 0;
    for (int i = 0; i < M; ++i) {
      for (int mask = 0; mask < nmask; ++mask) {
        if (mask & (1 << i)) {
          best = max(best, dp[i][mask]);
        }
      }
    }
    return N - best;
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
		cout << "Testing EllysPearls (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1556710919;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		EllysPearls _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 11;
				int M = 4;
				int pearls[] = {2, 4, 1, 1, 1, 3, 2, 1, 4, 2, 2};
				_expected = 3;
				_received = _obj.getMin(N, M, vector <int>(pearls, pearls+sizeof(pearls)/sizeof(int))); break;
			}
			case 1:
			{
				int N = 5;
				int M = 1;
				int pearls[] = {1, 1, 1, 1, 1};
				_expected = 0;
				_received = _obj.getMin(N, M, vector <int>(pearls, pearls+sizeof(pearls)/sizeof(int))); break;
			}
			case 2:
			{
				int N = 10;
				int M = 2;
				int pearls[] = {2, 2, 2, 1, 2, 2, 2, 1, 1, 2};
				_expected = 2;
				_received = _obj.getMin(N, M, vector <int>(pearls, pearls+sizeof(pearls)/sizeof(int))); break;
			}
			case 3:
			{
				int N = 30;
				int M = 7;
				int pearls[] = {5, 6, 2, 4, 7, 2, 2, 3, 3, 6, 1, 3, 6, 3, 7, 5, 1, 2, 3, 4, 6, 5, 6, 3, 2, 5, 3, 3, 5, 6};
				_expected = 16;
				_received = _obj.getMin(N, M, vector <int>(pearls, pearls+sizeof(pearls)/sizeof(int))); break;
			}
			case 4:
			{
				int N = 50;
				int M = 15;
				int pearls[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 1, 2, 3, 4, 5};
				_expected = 33;
				_received = _obj.getMin(N, M, vector <int>(pearls, pearls+sizeof(pearls)/sizeof(int))); break;
			}
			/*case 5:
			{
				int N = ;
				int M = ;
				int pearls[] = ;
				_expected = ;
				_received = _obj.getMin(N, M, vector <int>(pearls, pearls+sizeof(pearls)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int N = ;
				int M = ;
				int pearls[] = ;
				_expected = ;
				_received = _obj.getMin(N, M, vector <int>(pearls, pearls+sizeof(pearls)/sizeof(int))); break;
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
