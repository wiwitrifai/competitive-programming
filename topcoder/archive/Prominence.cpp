#include <bits/stdc++.h>

using namespace std;
vector<vector<long long>> sparse;

long long get(int l, int r) {
	int len = (r-l+ 1);
	int lg = 31 - __builtin_clz(len);
	return min(sparse[lg][l], sparse[lg][r-(1<<lg)+1]);
}

class Prominence {
public:
	long long sumOfProminences(int N, vector <int> coef, vector <int> idx, vector <int> val) {
		vector<long long> H(N, 0);
		for (int i = 0; i < N; ++i) {
	    int parity = i % 2;
	    long long a = coef[3*parity];
	    long long b = coef[3*parity+1];
	    long long c = coef[3*parity+2];
	    H[i] = (((a*i + b) % 1000000007)*i + c) % 1000000007;
	  }
	  for (int j = 0; j < (int)idx.size(); ++j) {
	    H[idx[j]] = val[j];
		}
		sparse.clear();
		sparse.push_back(H);
		for (int i = 0; (1 << (i+1)) <= N; ++i) {
			sparse.push_back(vector<long long>(N + 1 - (1 << (i+1))));
			for (int j = 0; j + (1 << (i+1)) <= N; ++j) {
				sparse[i+1][j] = min(sparse[i][j], sparse[i][j+(1 << i)]);
			}
		}
		vector<int> lef(N,-1), rig(N, N);
		vector<int> pos;
		for (int i = 0; i < N; ++i) {
			while (!pos.empty() && H[pos.back()] <= H[i])
				pos.pop_back();
			if (!pos.empty())
				lef[i] = pos.back();
			pos.push_back(i);
		}
		pos.clear();
		for (int i = N-1; i >= 0; --i) {
			while (!pos.empty() && H[pos.back()] <= H[i])
				pos.pop_back();
			if (!pos.empty())
				rig[i] = pos.back();
			pos.push_back(i);
		}
		long long ans = 0;
		for (int i = 0; i < N; ++i) {
			bool peak = 1;
			if (i > 0 && H[i] <= H[i-1])
				peak = 0;
			if (i+1 < N && H[i] <= H[i+1])
				peak = 0;
			if (!peak) continue;
			long long low = 0;
			if (lef[i] >= 0) {
				low = max(low, get(lef[i], i));
			}
			if (rig[i] < N) {
				low = max(low, get(i, rig[i]));
			}
			ans += H[i] - low;
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
		cout << "Testing Prominence (450.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1583601721;
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
		Prominence _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 7;
				int coef[] = {0, 0, 47, 0, 0, 47};
				int idx[] = {};
				int val[] = {};
				_expected = 0LL;
				_received = _obj.sumOfProminences(N, vector <int>(coef, coef+sizeof(coef)/sizeof(int)), vector <int>(idx, idx+sizeof(idx)/sizeof(int)), vector <int>(val, val+sizeof(val)/sizeof(int))); break;
			}
			case 1:
			{
				int N = 8;
				int coef[] = {0, 0, 47, 0, 0, 42};
				int idx[] = {};
				int val[] = {};
				_expected = 188LL;
				_received = _obj.sumOfProminences(N, vector <int>(coef, coef+sizeof(coef)/sizeof(int)), vector <int>(idx, idx+sizeof(idx)/sizeof(int)), vector <int>(val, val+sizeof(val)/sizeof(int))); break;
			}
			case 2:
			{
				int N = 10;
				int coef[] = {0, 0, 0, 0, 0, 0};
				int idx[] = {0, 1, 2, 3, 4, 5, 6, 7, 9, 8};
				int val[] = {500, 300, 400, 200, 400, 700, 100, 300, 300, 100};
				_expected = 1500LL;
				_received = _obj.sumOfProminences(N, vector <int>(coef, coef+sizeof(coef)/sizeof(int)), vector <int>(idx, idx+sizeof(idx)/sizeof(int)), vector <int>(val, val+sizeof(val)/sizeof(int))); break;
			}
			case 3:
			{
				int N = 16;
				int coef[] = {123456789, 234567890, 345678901, 456789012, 567890123, 678901234};
				int idx[] = {7};
				int val[] = {890123456};
				_expected = 4543586810LL;
				_received = _obj.sumOfProminences(N, vector <int>(coef, coef+sizeof(coef)/sizeof(int)), vector <int>(idx, idx+sizeof(idx)/sizeof(int)), vector <int>(val, val+sizeof(val)/sizeof(int))); break;
			}
			/*case 4:
			{
				int N = ;
				int coef[] = ;
				int idx[] = ;
				int val[] = ;
				_expected = LL;
				_received = _obj.sumOfProminences(N, vector <int>(coef, coef+sizeof(coef)/sizeof(int)), vector <int>(idx, idx+sizeof(idx)/sizeof(int)), vector <int>(val, val+sizeof(val)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int N = ;
				int coef[] = ;
				int idx[] = ;
				int val[] = ;
				_expected = LL;
				_received = _obj.sumOfProminences(N, vector <int>(coef, coef+sizeof(coef)/sizeof(int)), vector <int>(idx, idx+sizeof(idx)/sizeof(int)), vector <int>(val, val+sizeof(val)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int N = ;
				int coef[] = ;
				int idx[] = ;
				int val[] = ;
				_expected = LL;
				_received = _obj.sumOfProminences(N, vector <int>(coef, coef+sizeof(coef)/sizeof(int)), vector <int>(idx, idx+sizeof(idx)/sizeof(int)), vector <int>(val, val+sizeof(val)/sizeof(int))); break;
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
