#include <bits/stdc++.h>

using namespace std;

const int N = 55;
bool cek(char a, char b) {
	if (a == 'a')
		return b == '0' || b == '1';
	if (a == 'A')
		return b == '2' || b == '3';
	if (a == 'b')
		return b == '0' || b == '2';
	if (a == 'B')
		return b == '1' || b == '3';
}
char to[256];

class Softmatchd2 {
public:
	int count(string S, string pattern) {
		to['A'] = 'a';
		to['a'] = 'A';
		to['B'] = 'b';
		to['b'] = 'B';
		long long dp[N], cnt[N];
		int n = S.size(), m = pattern.size();
		dp[0] = 1;
		long long best = 0, ans = 0;
		for (int i = 0; i+m <= n; i++) {
			dp[i] = 1;
			cnt[i] = 1LL<<i;
			for (int j = 0; j < i; j++) {
				bool ok = 1;
				for (int k = 0; k < m; k++)
					if (j+k >= i) {
						if (cek(S[j+k], pattern[k]) != cek(S[j+k], pattern[j+k-i])) {
							ok = 0;
							break;
						}
					}
				if (ok) {
					if (dp[i] < dp[j]+1) {
						dp[i] = dp[j]+1;
						int sisa = max(i-j-m, 0);
						cnt[i] = cnt[j] * (1LL << sisa);
					}
					else if (dp[i] == dp[j]+1) {
						int sisa = max(i-j-m, 0);
						cnt[i] += cnt[j] * (1LL << sisa);
					}
				}
			}
			if (best < dp[i])
				best = dp[i];
		}
		for (int i = 0; i + m <= n; i++) {
			if (best == dp[i]) {
				int sisa = max(n-i-m, 0);
				ans += cnt[i] * (1LL << sisa);
			}
		}
		return best;
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
		cout << "Testing Softmatchd2 (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1487695316;
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
		Softmatchd2 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string S = "aba";
				string pattern = "13";
				_expected = 2;
				_received = _obj.count(S, pattern); break;
			}
			case 1:
			{
				string S = "abbaa";
				string pattern = "123";
				_expected = 2;
				_received = _obj.count(S, pattern); break;
			}
			case 2:
			{
				string S = "aaaa";
				string pattern = "1230";
				_expected = 1;
				_received = _obj.count(S, pattern); break;
			}
			case 3:
			{
				string S = "ababbaaba";
				string pattern = "0311";
				_expected = 3;
				_received = _obj.count(S, pattern); break;
			}
			case 4:
			{
				string S = "aabbbabbbb";
				string pattern = "332233";
				_expected = 2;
				_received = _obj.count(S, pattern); break;
			}
			case 5:
			{
				string S = "aaaabbbababababababaaabaa";
				string pattern = "02232";
				_expected = 9;
				_received = _obj.count(S, pattern); break;
			}
			/*case 6:
			{
				string S = ;
				string pattern = ;
				_expected = ;
				_received = _obj.count(S, pattern); break;
			}*/
			/*case 7:
			{
				string S = ;
				string pattern = ;
				_expected = ;
				_received = _obj.count(S, pattern); break;
			}*/
			/*case 8:
			{
				string S = ;
				string pattern = ;
				_expected = ;
				_received = _obj.count(S, pattern); break;
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
