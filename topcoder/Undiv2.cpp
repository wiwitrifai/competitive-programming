#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) {
	return a ? gcd(b % a, a) : b;
}
long long lcm(long long a, long long b) {
	return (a/gcd(a, b)) * b;
}

class Undiv2 {
public:
	long long getsum(int n) {
		vector< pair< long long, pair<int, long long > > > v;
		for (int i = 2; i < 30; i++) {
			for (int j = i+1; j < 30; j++) {
				long long now = 1;
				for (int z = 2; z < j; z++) {
					if (z == i) continue;
					now = lcm(now, z);
					if (now > n) break;
				}
				if (now > n) continue;
				if ((now % i) == 0 || (now % j) == 0) continue;
				long long cnt = n/now;
				v.push_back({now, {j, cnt}});
			}
		}
		sort(v.begin(), v.end());
		long long ans = 0;
		for (int i = (int)v.size()-1; i >= 0; i--) {
			ans += v[i].second.second * v[i].second.first;
			for (int j = i-1; j >= 0; j--)
				if (!(v[i].first % v[j].first))
					v[j].second.second -= v[i].second.second;
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
		cout << "Testing Undiv2 (900.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1489452134;
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
		Undiv2 _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 1;
				_expected = 3LL;
				_received = _obj.getsum(n); break;
			}
			case 1:
			{
				int n = 2;
				_expected = 7LL;
				_received = _obj.getsum(n); break;
			}
			case 2:
			{
				int n = 3;
				_expected = 11LL;
				_received = _obj.getsum(n); break;
			}
			case 3:
			{
				int n = 5;
				_expected = 19LL;
				_received = _obj.getsum(n); break;
			}
			case 4:
			{
				int n = 8;
				_expected = 32LL;
				_received = _obj.getsum(n); break;
			}
			case 5:
			{
				int n = 13;
				_expected = 53LL;
				_received = _obj.getsum(n); break;
			}
			/*case 6:
			{
				int n = ;
				_expected = LL;
				_received = _obj.getsum(n); break;
			}*/
			/*case 7:
			{
				int n = ;
				_expected = LL;
				_received = _obj.getsum(n); break;
			}*/
			/*case 8:
			{
				int n = ;
				_expected = LL;
				_received = _obj.getsum(n); break;
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
