#include <bits/stdc++.h>

using namespace std;
long long cnt[33];
long long dp[1024];

class XorOrderDiv2 {
public:
	vector<long long> getExpectation(int m, vector <int> a) {
		int n = a.size();
		vector< long long > ans;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= n; j++)
				dp[j] = 0;
			for (int j = 0; j <= m; j++)
				cnt[j] = 0;
			int all = 0;
			for (int j = 0; j < n; j++) if (j != i) {
				all += a[i] > a[j];
				for (int k = m-1; k >= 0; k--) {
					if ((a[i] & (1<< k)) != (a[j] & (1<<k))) {
						cnt[k] += (a[i] & (1<<k)) ? -1 : 1;
						break;
					}
				}
			}
			dp[all] = 1;
			for (int j = 0; j < m; j++) {
				// cerr << cnt[j] << endl;
				if (cnt[j] < 0)
					for (int k = -cnt[j]; k <= n; k++)
						dp[k+cnt[j]] += dp[k];
				else
					for (int k = n-cnt[j]; k >= 0; k--)
						dp[k+cnt[j]] += dp[k];
			}
			long long now = 0;
			for (int j = 0; j <= n; j++) {
				now += dp[j] * j * j;
				// cerr << dp[j] << " ";
			}
			// cerr << endl;
			ans.push_back(now);
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
		cout << "Testing XorOrderDiv2 (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1487304198;
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
		XorOrderDiv2 _obj;
		vector<long long> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int m = 2;
				int a[] = {0,1,2};
				long long __expected[] = {6, 6, 8 };
				_expected = vector<long long>(__expected, __expected+sizeof(__expected)/sizeof(long long));
				_received = _obj.getExpectation(m, vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			case 1:
			{
				int m = 1;
				int a[] = {1};
				long long __expected[] = {0 };
				_expected = vector<long long>(__expected, __expected+sizeof(__expected)/sizeof(long long));
				_received = _obj.getExpectation(m, vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			case 2:
			{
				int m = 5;
				int a[] = {13,17};
				long long __expected[] = {16, 16 };
				_expected = vector<long long>(__expected, __expected+sizeof(__expected)/sizeof(long long));
				_received = _obj.getExpectation(m, vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			case 3:
			{
				int m = 30;
				int a[] = {1,2,3,4,5,6,7,8,9,10};
				long long __expected[] = {29527900160, 28991029248, 28991029248, 27917287424, 27917287424, 27917287424, 27917287424, 35433480192, 35433480192, 35970351104 };
				_expected = vector<long long>(__expected, __expected+sizeof(__expected)/sizeof(long long));
				_received = _obj.getExpectation(m, vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			/*case 4:
			{
				int m = ;
				int a[] = ;
				long long __expected[] = ;
				_expected = vector<long long>(__expected, __expected+sizeof(__expected)/sizeof(long long));
				_received = _obj.getExpectation(m, vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int m = ;
				int a[] = ;
				long long __expected[] = ;
				_expected = vector<long long>(__expected, __expected+sizeof(__expected)/sizeof(long long));
				_received = _obj.getExpectation(m, vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int m = ;
				int a[] = ;
				long long __expected[] = ;
				_expected = vector<long long>(__expected, __expected+sizeof(__expected)/sizeof(long long));
				_received = _obj.getExpectation(m, vector <int>(a, a+sizeof(a)/sizeof(int))); break;
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
			cout << "           Expected: {";
			for (unsigned i = 0; i < _expected.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _expected[i];
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _received[i];
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
