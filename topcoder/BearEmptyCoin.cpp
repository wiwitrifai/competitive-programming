#include <bits/stdc++.h>

using namespace std;

class BearEmptyCoin {
	int gcd(int a, int b) {
		return a ? gcd(b % a, a) : b;
	}
public:
	long long winProbability(int K, int S) {
		long long C[62][62];
		for (int i = 0; i < 62; i++) {
			C[i][0] = C[i][i] = 1;
			for (int j = 1; j < i; j++)
				C[i][j] = C[i-1][j-1] + C[i-1][j];
		}		
		if (S % K == 0)
			return 1LL << K;
		bool can[62];
		for (int i = 1; i <= K; i++)
			can[i] = S % gcd(i, K-i) == 0;
		long long ans = 0;
		for (int i = 1; i < K; i++) {
			long long best = 0;
			for (int j = 1; j <= K-i; j++)
				if (can[j]) best = max(best, C[K-i-1][j-1]);
			ans += best;
		}
		return ans << 1;
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
		cout << "Testing BearEmptyCoin (800.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1487556793;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 800.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		BearEmptyCoin _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int K = 1;
				int S = 17;
				_expected = 2LL;
				_received = _obj.winProbability(K, S); break;
			}
			case 1:
			{
				int K = 2;
				int S = -50;
				_expected = 4LL;
				_received = _obj.winProbability(K, S); break;
			}
			case 2:
			{
				int K = 2;
				int S = -49;
				_expected = 2LL;
				_received = _obj.winProbability(K, S); break;
			}
			case 3:
			{
				int K = 4;
				int S = 42;
				_expected = 8LL;
				_received = _obj.winProbability(K, S); break;
			}
			case 4:
			{
				int K = 4;
				int S = -123456789;
				_expected = 6LL;
				_received = _obj.winProbability(K, S); break;
			}
			case 5:
			{
				int K = 18;
				int S = 123456;
				_expected = 49870LL;
				_received = _obj.winProbability(K, S); break;
			}
			case 6:
			{
				int K = 60;
				int S = 0;
				_expected = 1152921504606846976LL;
				_received = _obj.winProbability(K, S); break;
			}
			/*case 7:
			{
				int K = ;
				int S = ;
				_expected = LL;
				_received = _obj.winProbability(K, S); break;
			}*/
			/*case 8:
			{
				int K = ;
				int S = ;
				_expected = LL;
				_received = _obj.winProbability(K, S); break;
			}*/
			/*case 9:
			{
				int K = ;
				int S = ;
				_expected = LL;
				_received = _obj.winProbability(K, S); break;
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
