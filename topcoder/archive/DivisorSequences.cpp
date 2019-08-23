#include <bits/stdc++.h>

using namespace std;

unordered_map<int, int> memo;

int solve(int N) {
	if (N <= 1)
		return 0;
	auto it = memo.find(N);
	if (it != memo.end())
		return it->first;
	int ret = 1;
	for (int i = 2; 1L * i * i <= N; ++i) {
		if (N % i) continue;
		int res;
		ret = max(ret, (res =solve(i-1)) + 1);
		// cerr << i-1 << " " << N << " " << res << endl;
		int w = N / i;
		if (w != i) {
			ret = max(ret, (res = solve(w-1)) + 1);
			// cerr << w-1 << " " << N << " " << res << endl;
		}
	}
	// cerr << N << " " << ret << endl;
	return memo[N] = ret;
}

class DivisorSequences {
public:
	int longest(int N) {
		return max(solve(N), solve(N-1) + 1);
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
	// DivisorSequences obj;
	// for (int i = 0; i < 100000; ++i) {
	// 	int N = 2e9 - i;
	// 	auto t_start = clock();
	// 	int w = obj.longest(N);
	// 	double elapsed = (double)(clock()-t_start)/CLOCKS_PER_SEC;
	// 	cerr << i << " time: " << elapsed << endl; 
	// }
	// return 0;
	if (argc == 1) 
	{
		cout << "Testing DivisorSequences (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1559661283;
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
		DivisorSequences _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 15;
				_expected = 4;
				_received = _obj.longest(N); break;
			}
			case 1:
			{
				int N = 12;
				_expected = 2;
				_received = _obj.longest(N); break;
			}
			case 2:
			{
				int N = 34;
				_expected = 4;
				_received = _obj.longest(N); break;
			}
			case 3:
			{
				int N = 2;
				_expected = 1;
				_received = _obj.longest(N); break;
			}
			case 4:
			{
				int N = 3;
				_expected = 2;
				_received = _obj.longest(N); break;
			}
			case 5:
			{
				int N = 1234567899;
				_expected = 10;
				_received = _obj.longest(N); break;
			}
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
