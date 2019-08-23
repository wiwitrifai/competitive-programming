#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 9;
const int N = 55 * 55;
int add[N][30];
int dp[N][N];

class LinenCenterEasy {
public:
	int countStrings(string S, int N, int K) {
		int L = S.size();
		for (int i = 0; i < L; i++) {
			for (int j = 0; j < 26; j++) {
				if (S[i] == char(j+'a'))
					add[i][j] = i+1;
				else {
					string pre = S.substr(0, i) + char(j+'a');
					for (int k = 1; k <= pre.size(); k++)
						if (pre.substr(i+1-k, i+1) == S.substr(0, k))
							add[i][j] = k;
				}
			}
		}
		memset(dp, 0, sizeof dp);
		dp[0][0] = 1;
		for (int i = 1; i <= L * K + N; i++) {
			for (int j = 0; j < i; j++) {
				int full = (j/L) * L, res = j % L;
				for (int c = 0; c < 26; c++)
					(dp[i][full + add[res][c]] += dp[i-1][j]) %= mod;
			}
		} 
		long long ans = 0;
		for (int i = L * K; i <= L * K + N; i++)
			for (int j = 0; j < L; j++)
				ans = (ans + dp[i][K * L + j]) % mod;  
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
		cout << "Testing LinenCenterEasy (900.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1488176177;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 900.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		LinenCenterEasy _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string S = "xy";
				int N = 2;
				int K = 1;
				_expected = 2079;
				_received = _obj.countStrings(S, N, K); break;
			}
			case 1:
			{
				string S = "q";
				int N = 2;
				int K = 1;
				_expected = 1926;
				_received = _obj.countStrings(S, N, K); break;
			}
			// case 2:
			// {
			// 	string S = "ababab";
			// 	int N = 5;
			// 	int K = 4;
			// 	_expected = 527166180;
			// 	_received = _obj.countStrings(S, N, K); break;
			// }
			// case 3:
			// {
			// 	string S = "fgcdx";
			// 	int N = 10;
			// 	int K = 3;
			// 	_expected = 586649223;
			// 	_received = _obj.countStrings(S, N, K); break;
			// }
			// case 4:
			// {
			// 	string S = "ghjhhhgjhjhgjhghghjhjg";
			// 	int N = 8;
			// 	int K = 10;
			// 	_expected = 192161304;
			// 	_received = _obj.countStrings(S, N, K); break;
			// }
			// case 5:
			// {
			// 	string S = "pdpfrpfdfdpfdpfdpfpdfldfpfldpfe" ;
			// 	int N = 49;
			// 	int K = 25;
			// 	_expected = 164673990;
			// 	_received = _obj.countStrings(S, N, K); break;
			// }
			// case 6:
			// {
			// 	string S = "a";
			// 	int N = 7;
			// 	int K = 0;
			// 	_expected = 357828722;
			// 	_received = _obj.countStrings(S, N, K); break;
			// }
			// case 7:
			// {
			// 	string S = "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee" ;
			// 	int N = 50;
			// 	int K = 50;
			// 	_expected = 960113657;
			// 	_received = _obj.countStrings(S, N, K); break;
			// }
			/*case 8:
			{
				string S = ;
				int N = ;
				int K = ;
				_expected = ;
				_received = _obj.countStrings(S, N, K); break;
			}*/
			/*case 9:
			{
				string S = ;
				int N = ;
				int K = ;
				_expected = ;
				_received = _obj.countStrings(S, N, K); break;
			}*/
			/*case 10:
			{
				string S = ;
				int N = ;
				int K = ;
				_expected = ;
				_received = _obj.countStrings(S, N, K); break;
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
