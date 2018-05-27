#include <bits/stdc++.h>

using namespace std;

double calc(long long x, int p, int c, int s) {
	return (double) x / c / s + (c-1) * p;
}

int solve(long long x, int p, int s, int c) {
	int l = 1, r = c;
	int ans = 1;
	double val = x + p;
	while (r-l > 3) {
		int le = (l + l + r) / 3, ri = (l + r + r) / 3;
		double vle = calc(x, p, le, s), vri = calc(x, p, ri, s);
		if (vle < val)
			ans = le, val = vle;
		if (vri < val)
			ans = ri, val = vri;
		if (vle < val)
			r = ri;
		else
			l = le;
	}
	for (int i = l; i <= r; i++) {
		double cur = calc(x, p, i, s);
		if (cur < val) {
			val = cur;
			ans = i;
		}
	}
	return ans;
}

class MulticoreProcessing {
public:
	long long fastestTime(long long jobLength, int corePenalty, vector <int> speed, vector <int> cores) {
		int n = speed.size();
		long long ans = jobLength;
		for (int i = 0; i < n; i++) {
			int c = solve(jobLength, corePenalty, speed[i], cores[i]);
			long long d = 1LL * speed[i] * c;
			ans = min(ans, (c-1) * 1LL * corePenalty + (jobLength + d - 1) / d);
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
		cout << "Testing MulticoreProcessing (350.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1507806515;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 350.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		MulticoreProcessing _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				long long jobLength = 2000LL;
				int corePenalty = 5;
				int speed[] = {40,20};
				int cores[] = {2,4};
				_expected = 30LL;
				_received = _obj.fastestTime(jobLength, corePenalty, vector <int>(speed, speed+sizeof(speed)/sizeof(int)), vector <int>(cores, cores+sizeof(cores)/sizeof(int))); break;
			}
			case 1:
			{
				long long jobLength = 2000LL;
				int corePenalty = 5;
				int speed[] = {10,20};
				int cores[] = {2,4};
				_expected = 40LL;
				_received = _obj.fastestTime(jobLength, corePenalty, vector <int>(speed, speed+sizeof(speed)/sizeof(int)), vector <int>(cores, cores+sizeof(cores)/sizeof(int))); break;
			}
			case 2:
			{
				long long jobLength = 1000LL;
				int corePenalty = 0;
				int speed[] = {10};
				int cores[] = {3};
				_expected = 34LL;
				_received = _obj.fastestTime(jobLength, corePenalty, vector <int>(speed, speed+sizeof(speed)/sizeof(int)), vector <int>(cores, cores+sizeof(cores)/sizeof(int))); break;
			}
			case 3:
			{
				long long jobLength = 10000LL;
				int corePenalty = 5;
				int speed[] = {39,37,44};
				int cores[] = {8,16,6};
				_expected = 63LL;
				_received = _obj.fastestTime(jobLength, corePenalty, vector <int>(speed, speed+sizeof(speed)/sizeof(int)), vector <int>(cores, cores+sizeof(cores)/sizeof(int))); break;
			}
			/*case 4:
			{
				long long jobLength = LL;
				int corePenalty = ;
				int speed[] = ;
				int cores[] = ;
				_expected = LL;
				_received = _obj.fastestTime(jobLength, corePenalty, vector <int>(speed, speed+sizeof(speed)/sizeof(int)), vector <int>(cores, cores+sizeof(cores)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				long long jobLength = LL;
				int corePenalty = ;
				int speed[] = ;
				int cores[] = ;
				_expected = LL;
				_received = _obj.fastestTime(jobLength, corePenalty, vector <int>(speed, speed+sizeof(speed)/sizeof(int)), vector <int>(cores, cores+sizeof(cores)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				long long jobLength = LL;
				int corePenalty = ;
				int speed[] = ;
				int cores[] = ;
				_expected = LL;
				_received = _obj.fastestTime(jobLength, corePenalty, vector <int>(speed, speed+sizeof(speed)/sizeof(int)), vector <int>(cores, cores+sizeof(cores)/sizeof(int))); break;
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
