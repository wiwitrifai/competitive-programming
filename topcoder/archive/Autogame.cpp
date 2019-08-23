#include <bits/stdc++.h>

using namespace std;

const int N = 55, mod = 1e9 + 7;
int to[N], tmp[N];

class Autogame {
public:
	int wayscnt(vector <int> a, int K) {
		int n = a.size();
		for (int i = 0; i < n; i++)
			a[i]--, to[i] = i;
		while (K) {
			if (K & 1) {
				for (int i = 0; i < n; i++)
					to[i] = a[to[i]];
			}
			for (int i = 0; i < n; i++)
				tmp[i] = a[a[i]];
			for (int i = 0; i < n; i++)
				a[i] = tmp[i];
			K >>= 1;
		}
		long long ans = 1;
		for (int i = 0; i < n; i++) {
			int cnt = 1;
			for (int j = 0; j < n; j++)
				cnt += to[j] == i;
			ans = (ans * cnt) % mod; 
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
		cout << "Testing Autogame (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1491194553;
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
		Autogame _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int a[] = {1,2,3};
				int K = 5;
				_expected = 8;
				_received = _obj.wayscnt(vector <int>(a, a+sizeof(a)/sizeof(int)), K); break;
			}
			case 1:
			{
				int a[] = {1,1,1};
				int K = 1;
				_expected = 4;
				_received = _obj.wayscnt(vector <int>(a, a+sizeof(a)/sizeof(int)), K); break;
			}
			case 2:
			{
				int a[] = {2,1}	;
				int K = 42;
				_expected = 4;
				_received = _obj.wayscnt(vector <int>(a, a+sizeof(a)/sizeof(int)), K); break;
			}
			case 3:
			{
				int a[] = {2,3,4,3};
				int K = 3;
				_expected = 9;
				_received = _obj.wayscnt(vector <int>(a, a+sizeof(a)/sizeof(int)), K); break;
			}
			case 4:
			{
				int a[] = {4,4,3,2,1};
				int K = 3;
				_expected = 18;
				_received = _obj.wayscnt(vector <int>(a, a+sizeof(a)/sizeof(int)), K); break;
			}
			/*case 5:
			{
				int a[] = ;
				int K = ;
				_expected = ;
				_received = _obj.wayscnt(vector <int>(a, a+sizeof(a)/sizeof(int)), K); break;
			}*/
			/*case 6:
			{
				int a[] = ;
				int K = ;
				_expected = ;
				_received = _obj.wayscnt(vector <int>(a, a+sizeof(a)/sizeof(int)), K); break;
			}*/
			/*case 7:
			{
				int a[] = ;
				int K = ;
				_expected = ;
				_received = _obj.wayscnt(vector <int>(a, a+sizeof(a)/sizeof(int)), K); break;
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
