#include <bits/stdc++.h>

using namespace std;

const long long inf = 1e16;

long long mul(long long a, long long b) {
	if (a <= 0 || b <= 0)
		return a * b;
	if (inf / a < b)
		return inf;
	return a * b;
}

long long add(long long a, long long b) {
	long long ret = a + b;
	if (ret > inf)
		ret = inf;
	return ret;
}

long long attack1(long long time, long long a, long long b) {
	long long ans = add(mul(a, time), mul(mul(time, time-1)/2, b));
	return ans;
}

long long attack2(long long time, long long a, long long b, long long duration) {
	long long sisa = time - duration - 1;
	if (sisa < 0)
		sisa = 0;
	time -= sisa + 1;
	if (time < 0)
		time = 0;
	long long ans = attack1(sisa, a, b);
	a = add(a, mul(b, sisa));
	ans = add(ans, mul(attack1(time, a, b), 5));
	return ans;
}

class FightMonsterDiv1 {
public:
	long long fightTime(long long hp, long long attack, int level, long long duration) {
		long long b = attack / 100 * level;
		long long lo = 0, hi = hp/attack + 1;
		while (lo < hi) {
			long long mid = (lo + hi) / 2;
			if (attack1(mid, attack, b) < hp)
				lo = mid + 1;
			else
				hi = mid;
		}
		long long ans = hi;
		lo = 0, hi = hp/attack + 1;
		while (lo < hi) {
			long long mid = (lo + hi) / 2;
			if (attack2(mid, attack, b, duration) < hp)
				lo = mid + 1;
			else
				hi = mid;
		}
		ans = min(ans, hi);
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
		cout << "Testing FightMonsterDiv1 (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1549109552;
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
		FightMonsterDiv1 _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				long long hp = 201LL;
				long long attack = 100LL;
				int level = 10;
				long long duration = 10LL;
				_expected = 2LL;
				_received = _obj.fightTime(hp, attack, level, duration); break;
			}
			case 1:
			{
				long long hp = 74900LL;
				long long attack = 100LL;
				int level = 0;
				long long duration = 2LL;
				_expected = 742LL;
				_received = _obj.fightTime(hp, attack, level, duration); break;
			}
			case 2:
			{
				long long hp = 1000000000000LL;
				long long attack = 1000000000000LL;
				int level = 100;
				long long duration = 1000000000000LL;
				_expected = 1LL;
				_received = _obj.fightTime(hp, attack, level, duration); break;
			}
			case 3:
			{
				long long hp = 1338LL;
				long long attack = 100LL;
				int level = 1;
				long long duration = 2LL;
				_expected = 6LL;
				_received = _obj.fightTime(hp, attack, level, duration); break;
			}
			case 4:
			{
				long long hp = 1LL;
				long long attack = 100LL;
				int level = 0;
				long long duration = 1LL;
				_expected = 1LL;
				_received = _obj.fightTime(hp, attack, level, duration); break;
			}
			/*case 5:
			{
				long long hp = LL;
				long long attack = LL;
				int level = ;
				long long duration = LL;
				_expected = LL;
				_received = _obj.fightTime(hp, attack, level, duration); break;
			}*/
			/*case 6:
			{
				long long hp = LL;
				long long attack = LL;
				int level = ;
				long long duration = LL;
				_expected = LL;
				_received = _obj.fightTime(hp, attack, level, duration); break;
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
