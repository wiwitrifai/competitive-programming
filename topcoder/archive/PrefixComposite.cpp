#include <bits/stdc++.h>

using namespace std;

bool is_prime(long long p) {
	if (p <= 0)
		return false;
	for (int x = 2; (long long)x * x <= p; ++x) {
		if (p % x) continue;
		return false;
	}
	return true;
}

long long calc_low(long long A, long long B) {
	if (B < A)
		return A;
	vector<int> dig;
	while (A) {
		dig.push_back(A % 10);
		A /= 10;
	}
	reverse(dig.begin(), dig.end());
	long long cur = 0;
	for (int i = 0; i < (int)dig.size(); ++i){
		int d = dig[i];
		cur *= 10;
		cur += d;
		while (is_prime(cur)) {
			++cur;
			++d;
		}
		if (d > dig[i]) {
			for (int j = i+1; j < (int)dig.size(); ++j)
				cur *= 10;
			return calc_low(cur, B);
		}
	}
	return cur;
}

long long calc_high(long long A, long long B) {
	if (B < A)
		return B;
	vector<int> dig;
	while (B) {
		dig.push_back(B % 10);
		B /= 10;
	}
	reverse(dig.begin(), dig.end());
	long long cur = 0;
	for (int i = 0; i < (int)dig.size(); ++i){
		int d = dig[i];
		cur *= 10;
		cur += d;
		int cnt = 7;
		while (is_prime(cur) && cnt-- > 0) {
			--cur;
			--d;
		}
		if (d < dig[i]) {
			for (int j = i+1; j < (int)dig.size(); ++j) {
				cur *= 10;
				cur += 9;
			}
			return calc_high(A, cur);
		}
	}
	return cur;
}

class PrefixComposite {
public:
	vector<long long> minMax(long long A, long long B) {
		long long low = calc_low(A, B), high = calc_high(A, B);
		if (low > high)
			return vector<long long>();
		return {low, high};
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
		cout << "Testing PrefixComposite (450.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1563499649;
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
		PrefixComposite _obj;
		vector<long long> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				long long A = 1LL;
				long long B = 3LL;
				long long __expected[] = { };
				_expected = vector<long long>(__expected, __expected+sizeof(__expected)/sizeof(long long));
				_received = _obj.minMax(A, B); break;
			}
			case 1:
			{
				long long A = 1LL;
				long long B = 4LL;
				long long __expected[] = {4, 4 };
				_expected = vector<long long>(__expected, __expected+sizeof(__expected)/sizeof(long long));
				_received = _obj.minMax(A, B); break;
			}
			case 2:
			{
				long long A = 123LL;
				long long B = 838LL;
				long long __expected[] = {400, 828 };
				_expected = vector<long long>(__expected, __expected+sizeof(__expected)/sizeof(long long));
				_received = _obj.minMax(A, B); break;
			}
			case 3:
			{
				long long A = 409LL;
				long long B = 87343LL;
				long long __expected[] = {420, 87343 };
				_expected = vector<long long>(__expected, __expected+sizeof(__expected)/sizeof(long long));
				_received = _obj.minMax(A, B); break;
			}
			case 4:
			{
				long long A = 979797LL;
				long long B = 979898LL;
				long long __expected[] = { };
				_expected = vector<long long>(__expected, __expected+sizeof(__expected)/sizeof(long long));
				_received = _obj.minMax(A, B); break;
			}
			case 5:
			{
				long long A = 600LL;
				long long B = 703LL;
				long long __expected[] = {600, 699 };
				_expected = vector<long long>(__expected, __expected+sizeof(__expected)/sizeof(long long));
				_received = _obj.minMax(A, B); break;
			}
			case 6:
			{
				long long A = 1LL;
				long long B = 100000000000LL;
				long long __expected[] = {4, 99999999999 };
				_expected = vector<long long>(__expected, __expected+sizeof(__expected)/sizeof(long long));
				_received = _obj.minMax(A, B); break;
			}
			case 7:
			{
				long long A = 37337999LL;
				long long B = 37337999LL;
				long long __expected[] = { };
				_expected = vector<long long>(__expected, __expected+sizeof(__expected)/sizeof(long long));
				_received = _obj.minMax(A, B); break;
			}
			case 8:
			{
				long long A = 22LL;
				long long B = 39LL;
				long long __expected[] = { };
				_expected = vector<long long>(__expected, __expected+sizeof(__expected)/sizeof(long long));
				_received = _obj.minMax(A, B); break;
			}
			/*case 9:
			{
				long long A = LL;
				long long B = LL;
				long long __expected[] = ;
				_expected = vector<long long>(__expected, __expected+sizeof(__expected)/sizeof(long long));
				_received = _obj.minMax(A, B); break;
			}*/
			/*case 10:
			{
				long long A = LL;
				long long B = LL;
				long long __expected[] = ;
				_expected = vector<long long>(__expected, __expected+sizeof(__expected)/sizeof(long long));
				_received = _obj.minMax(A, B); break;
			}*/
			/*case 11:
			{
				long long A = LL;
				long long B = LL;
				long long __expected[] = ;
				_expected = vector<long long>(__expected, __expected+sizeof(__expected)/sizeof(long long));
				_received = _obj.minMax(A, B); break;
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
