#include <bits/stdc++.h>

using namespace std;

class SwapTheString {
public:
	long long findNumberOfSwaps(string P, int A0, int X, int Y, int N, int K) {
		vector<int> A(N);
		A[0] = A0;
		for (int i = 1; i < N; ++i) {
			A[i] = ((long long)A[i-1] * X + Y) % 1812447359;
		}

		string S = P;
		S.resize(N);
		for (int i = P.size(); i < N; ++i)
			S[i] = (char)((A[i] % 26) + 'a');
		int cnt[26];
		long long ans = 0;
		for (int i = 0; i < K; ++i) {
			memset(cnt, 0, sizeof cnt);
			for (int j = i; j < N; j += K) {
				int now = S[j] - 'a';
				for (int k = 0; k < now; ++k) {
					ans += cnt[k];
				}
				++cnt[now];
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
		cout << "Testing SwapTheString (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1589555176;
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
		SwapTheString _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string P = "cbexa";
				int A0 = 0;
				int X = 0;
				int Y = 0;
				int N = 5;
				int K = 2;
				_expected = 2LL;
				_received = _obj.findNumberOfSwaps(P, A0, X, Y, N, K); break;
			}
			case 1:
			{
				string P = "";
				int A0 = 5;
				int X = 2;
				int Y = 3;
				int N = 4;
				int K = 1;
				_expected = 3LL;
				_received = _obj.findNumberOfSwaps(P, A0, X, Y, N, K); break;
			}
			case 2:
			{
				string P = "b";
				int A0 = 1001;
				int X = 1001;
				int Y = 1001;
				int N = 5;
				int K = 2;
				_expected = 3LL;
				_received = _obj.findNumberOfSwaps(P, A0, X, Y, N, K); break;
			}
			case 3:
			{
				string P = "";
				int A0 = 9999;
				int X = 50000;
				int Y = 4797;
				int N = 6;
				int K = 3;
				_expected = 2LL;
				_received = _obj.findNumberOfSwaps(P, A0, X, Y, N, K); break;
			}
			case 4:
			{
				string P = "";
				int A0 = 3435;
				int X = 1000000000;
				int Y = 1812447358;
				int N = 7;
				int K = 2;
				_expected = 5LL;
				_received = _obj.findNumberOfSwaps(P, A0, X, Y, N, K); break;
			}
			/*case 5:
			{
				string P = ;
				int A0 = ;
				int X = ;
				int Y = ;
				int N = ;
				int K = ;
				_expected = LL;
				_received = _obj.findNumberOfSwaps(P, A0, X, Y, N, K); break;
			}*/
			/*case 6:
			{
				string P = ;
				int A0 = ;
				int X = ;
				int Y = ;
				int N = ;
				int K = ;
				_expected = LL;
				_received = _obj.findNumberOfSwaps(P, A0, X, Y, N, K); break;
			}*/
			/*case 7:
			{
				string P = ;
				int A0 = ;
				int X = ;
				int Y = ;
				int N = ;
				int K = ;
				_expected = LL;
				_received = _obj.findNumberOfSwaps(P, A0, X, Y, N, K); break;
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
