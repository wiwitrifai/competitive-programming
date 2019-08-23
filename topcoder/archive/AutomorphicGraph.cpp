#include <bits/stdc++.h>

using namespace std;

const int N = 105, P = 31, mod = 1e9 + 7;
vector< int > g[N];
long long hs[N], tmp[N], s[N];

class AutomorphicGraph {
public:
	int count(int n, vector <int> a, vector <int> b) {
		for (int i = 0; i < a.size(); i++) {
			g[a[i]].push_back(b[i]);
			g[b[i]].push_back(a[i]);
		}
		int ans = 1;
		for (int i = 0; i < n; i++) {
			for (int k = 0; k < n; k++)
				hs[k] = k < i ? n + k + 1 : 1;
			for (int it = 0; it < n + 10; it++) {
				for (int j = 0; j < n; j++) {
					tmp[j] = hs[j];
					vector< int > val;
					for (int u : g[j])
						val.push_back(hs[u]);
					sort(val.begin(), val.end());
					for (int z: val)
						tmp[j] = tmp[j] * 31 + z;
				}
				for (int j = 0; j < n; j++) hs[j] = tmp[j];
			}
			int cnt = 0;
			for (int j = i; j < n; j++)
				cnt += hs[j] == hs[i];
			ans = (1LL * ans * cnt) % mod;
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
		cout << "Testing AutomorphicGraph (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1486967029;
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
		AutomorphicGraph _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 5;
				int a[] = {0,0,0,0,1,1,1,2,2,3};
				int b[] = {1,2,3,4,2,3,4,3,4,4};
				_expected = 120;
				_received = _obj.count(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 1:
			{
				int n = 4;
				int a[] = {0,0,0,2,2};
				int b[] = {1,2,3,1,3};
				_expected = 4;
				_received = _obj.count(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 2:
			{
				int n = 6;
				int a[] = {0,0,1,1,1,3,2,2,4};
				int b[] = {1,2,2,3,4,4,4,5,5};
				_expected = 6;
				_received = _obj.count(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 3:
			{
				int n = 12;
				int a[] = {0,1,2,3,4,5,6,7,8,0,3,6,1,4,7};
				int b[] = {1,2,3,4,5,6,7,8,0,3,6,0,9,10,11};
				_expected = 3;
				_received = _obj.count(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 4:
			{
				int n = 7;
				int a[] = {0,1,2,3,1,2,5,1};
				int b[] = {1,2,3,4,5,6,6,6};
				_expected = 1;
				_received = _obj.count(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 5:
			{
				int n = 27;
				int a[] = {0,1,2,3,0,0,7,6,5,1,8,8,2,11,11,3,7,6,18,18,5,15,15,22,22,0,0,23,4,4,25};
				int b[] = {1,2,3,4,4,7,6,5,4,8,9,10,11,12,13,14,21,18,19,20,15,16,17,0,4,23,24,24,25,26,26};
				_expected = 128;
				_received = _obj.count(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 6:
			{
				int n = 67;
				int a[] = {0,1,2,3,1,2,5,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66};
				int b[] = {1,2,3,4,5,6,6,4,4,5,5,6,6,7,7,8,8,9,9,10,10,11,11,12,12,13,13,14,14,15,15,16,16,17,17,18,18,19,19,20,20,21,21,22,22,23,23,24,24,25,25,26,26,27,27,28,28,29,29,30,30,31,31,32,32,33,33,34,34};
				_expected = 73741817;
				_received = _obj.count(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 7:
			{
				int n = 32;
				int a[] = {10, 16, 11, 28, 31, 0, 23, 30, 19, 12, 0, 15, 27, 31, 27, 30, 6, 10, 26, 12, 25, 24, 27, 22, 5, 25, 27, 26, 16, 4, 16, 9, 14, 28};
				int b[] = {27, 1, 8, 24, 30, 14, 12, 11, 13, 10, 19, 21, 3, 20, 30, 15, 27, 29, 1, 0, 18, 30, 29, 31, 13, 16, 7, 2, 30, 14, 27, 16, 17, 13};
				_expected = 48;
				_received = _obj.count(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			/*case 8:
			{
				int n = ;
				int a[] = ;
				int b[] = ;
				_expected = ;
				_received = _obj.count(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}*/
			/*case 9:
			{
				int n = ;
				int a[] = ;
				int b[] = ;
				_expected = ;
				_received = _obj.count(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
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
