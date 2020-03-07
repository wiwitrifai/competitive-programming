#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e18;

long long calc(string s, int len, vector<int>& val) {
	val.assign(s.size(), 0);
	long long ret = 0;
	for (int l = 0; l < len; ++l) {
		for (int i = 0; i < s.size(); ++i) {
			val[i] *= 27;
			if (i+l < s.size())
				val[i] += s[i+l] - 'a' + 1;
		}
		vector<int> all = val;
		sort(all.begin(), all.end());
		all.erase(unique(all.begin(), all.end()), all.end());
		for (int i = 0; i < s.size(); ++i) {
			val[i] = lower_bound(all.begin(), all.end(), val[i]) - all.begin();
		}
		int cur = 0;
		for (int i = 0; i + l < s.size(); ++i) {
			if (val[i] < val[cur])
				cur = i;
		}
		ret += cur;
	}
	return ret;
}

class SubstringQueries {
public:
	long long solve(string S, int k) {
		bool same = 1;
		for (int i = 0; i < S.size(); ++i)
			same &= S[i] == S[0];
		if (same) {
			return 0;
		}
		vector<int> val;
		if (k == 1) {
			return calc(S, S.size(), val);
		}
		long long ans = calc(S+S, S.size(), val);
		int sm = 0;
		for (int i = 0; i < S.size(); ++i) {
			if (val[i] < val[sm])
				sm = i;
			ans += sm;
		}
		long long tot = (long long)S.size() * (k-2);
		ans += tot * sm;
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
		cout << "Testing SubstringQueries (450.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1582301934;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 450.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		SubstringQueries _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string S = "aaaaaaaaa";
				int k = 1;
				_expected = 0LL;
				_received = _obj.solve(S, k); break;
			}
			case 1:
			{
				string S = "zaba";
				int k = 2;
				_expected = 7LL;
				_received = _obj.solve(S, k); break;
			}
			case 2:
			{
				string S = "acaa";
				int k = 2;
				_expected = 10LL;
				_received = _obj.solve(S, k); break;
			}
			case 3:
			{
				string S = "aa";
				int k = 4;
				_expected = 0LL;
				_received = _obj.solve(S, k); break;
			}
			case 4:
			{
				string S = "abaa";
				int k = 1;
				_expected = 2LL;
				_received = _obj.solve(S, k); break;
			}
			/*case 5:
			{
				string S = ;
				int k = ;
				_expected = LL;
				_received = _obj.solve(S, k); break;
			}*/
			/*case 6:
			{
				string S = ;
				int k = ;
				_expected = LL;
				_received = _obj.solve(S, k); break;
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
