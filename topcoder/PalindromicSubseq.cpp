#include <bits/stdc++.h>

using namespace std;

const int N = 3030, mod = 1e9 + 7;

int dout[N][N][2], din[N][N][2];
string ss;
long long sout(int l, int r, int w) {
	if (l < 0 || r >= ss.size()) return !w;
	int & ret = dout[l][r][w];
	if (ret != -1) return ret;
	ret = 0;
	if (w) {
		if (ss[l] == ss[r]) {
			ret = sout(l-1, r+1, 0) + sout(l-1, r+1, 1);
			if (ret >= mod) ret -= mod;
		}
		ret += sout(l-1, r, 1);
		if (ret >= mod) ret -= mod;
	}
	else {
		ret = sout(l, r+1, 0) + sout(l, r+1, 1);
		if (ret >= mod) ret -= mod;
	}
	return ret;
}
long long sin(int l, int r, int w) {
	if (l < 0 || r >= ss.size()) return !w;
	if (l == r) return 1;
	if (l > r) return !w;
	int & ret = din[l][r][w];
	if (ret != -1) return ret;
	ret = 0;
	if (w) {
		if (ss[l] == ss[r]) {
			ret = sin(l+1, r-1, 0) + sin(l+1, r-1, 1);
			if (ret >= mod) ret -= mod;
		}
		ret += sin(l+1, r, 1);
		if (ret >= mod) ret -= mod;
	}
	else {
		ret = sin(l, r-1, 0) + sin(l, r-1, 1);
		if (ret >= mod) ret -= mod;
	}
	return ret;
}

class PalindromicSubseq {
public:
	int solve(string s) {
		memset(dout, -1, sizeof dout);
		memset(din, -1, sizeof din);
		ss = s;
		int n = s.size();
		int ans = 0;
		for (int i = 0; i < n; i++) {
			long long x = sout(i-1, i+1, 0) + sout(i-1, i+1, 1);
			if (x >= mod) x -= mod;
			for (int j = 0; j < i; j++) if (ss[i] == ss[j]) {
				long long rout = sout(j-1, i+1, 0) + sout(j-1, i+1, 1);
				if (rout >= mod) rout -= mod;
				long long rin = sin(j+1, i-1, 0) + sin(j+1, i-1, 1);
				if (rin >= mod) rin -= mod;
				x = (1LL * rout * rin + x) % mod;
			}
			for (int j = i+1; j < n; j++) if (ss[i] == ss[j]) {
				long long rout = sout(i-1, j+1, 0) + sout(i-1, j+1, 1);
				if (rout >= mod) rout -= mod;
				long long rin = sin(i+1, j-1, 0) + sin(i+1, j-1, 1);
				if (rin >= mod) rin -= mod;
				x = (1LL * rout * rin + x) % mod;
			}
			if (x < 0) x += mod;
			int y = (x * (i+1)) % mod;
			ans ^= y;
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
		cout << "Testing PalindromicSubseq (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1486907463;
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
		PalindromicSubseq _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string s = "aaba";
				_expected = 30;
				_received = _obj.solve(s); break;
			}
			case 1:
			{
				string s = "abcd";
				_expected = 4;
				_received = _obj.solve(s); break;
			}
			case 2:
			{
				string s = "tcoct";
				_expected = 60;
				_received = _obj.solve(s); break;
			}
			case 3:
			{
				string s = "zyzyzzzzxzyz";
				_expected = 717;
				_received = _obj.solve(s); break;
			}
			case 4:
			{
				string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
				_expected = 1025495382;
				_received = _obj.solve(s); break;
			}
			/*case 5:
			{
				string s = ;
				_expected = ;
				_received = _obj.solve(s); break;
			}*/
			/*case 6:
			{
				string s = ;
				_expected = ;
				_received = _obj.solve(s); break;
			}*/
			/*case 7:
			{
				string s = ;
				_expected = ;
				_received = _obj.solve(s); break;
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
