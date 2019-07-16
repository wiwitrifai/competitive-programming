#include <bits/stdc++.h>

using namespace std;

const int M = 5e6 + 5;

int euler[M];

class CatAndMice {
public:
	long long countDirections(int N, int C) {
		if (N == C)
			return 8LL;
		for (int i = 1; i < M; ++i)
			euler[i] = i;
		for (int i = 2; i < M; ++i) {
			if (euler[i] != i) continue;
			for (int j = i; j <= M; j += i) {
				euler[j] -= euler[j]/i;
			}
		}
		int from = N, to = 1;
		for (int i = 1; i <= N; ++i) {
			int x = N / i;
			if (x <= C)
				from = min(from, i);
			if (x >= C)
				to = max(to, i);
		}
		long long ans = 0;
		for (int i = from; i <= to; ++i) {
			ans += (i == 1 ? 4LL : 8LL) * euler[i];
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
		cout << "Testing CatAndMice (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1560388599;
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
		CatAndMice _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 2;
				int C = 2;
				_expected = 8LL;
				_received = _obj.countDirections(N, C); break;
			}
			case 1:
			{
				int N = 2;
				int C = 1;
				_expected = 8LL;
				_received = _obj.countDirections(N, C); break;
			}
			case 2:
			{
				int N = 19;
				int C = 3;
				_expected = 48LL;
				_received = _obj.countDirections(N, C); break;
			}
			case 3:
			{
				int N = 1234;
				int C = 3;
				_expected = 180608LL;
				_received = _obj.countDirections(N, C); break;
			}
			case 4:
			{
				int N = 1234;
				int C = 1212;
				_expected = 0LL;
				_received = _obj.countDirections(N, C); break;
			}
			case 5:
			{
				int N = 12314;
				int C = 12314;
				_expected = 8LL;
				_received = _obj.countDirections(N, C); break;
			}
			/*case 6:
			{
				int N = ;
				int C = ;
				_expected = LL;
				_received = _obj.countDirections(N, C); break;
			}*/
			/*case 7:
			{
				int N = ;
				int C = ;
				_expected = LL;
				_received = _obj.countDirections(N, C); break;
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
