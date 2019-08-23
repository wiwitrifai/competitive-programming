#include <bits/stdc++.h>

using namespace std;

class OthersXor {
public:
	long long minSum(vector <int> x) {
		int cnt = 0, n = x.size();
		for (int i = 0; i < n; i++)
			if (x[i] == -1)
				cnt++;
		long long ans = 0;
		vector< int > v;
		for (int i = 0; i < n; i++)
			if (x[i] != -1)
				v.push_back(x[i]);
		n = v.size();
		for (int j = 0; j < 30; j++) {
			int bit[2];
			bit[0] = bit[1] = 0;
			for (int i = 0; i < n; i++) {
				bit[(v[i] >> j) & 1]++;
			}
			long long allz = bit[1], allo = bit[0];
			if (cnt) {
				if (allz & 1) allz++;
				if ((allo  & 1) == 0) allo++;
				allz = min(allz, allo);
			}
			else {
				if ((allz & 1) && ((allo & 1) == 0))
					return -1;
				else if (allz & 1)
					allz = allo;
				else if (allo & 1)
					allz = min(allo, allz);
			}
			ans += allz << j;
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
		cout << "Testing OthersXor (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1487109814;
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
		OthersXor _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x[] = {1,-1,3};
				_expected = 3LL;
				_received = _obj.minSum(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 1:
			{
				int x[] = {0,0,1};
				_expected = -1LL;
				_received = _obj.minSum(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 2:
			{
				int x[] = {70,100};
				_expected = 170LL;
				_received = _obj.minSum(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 3:
			{
				int x[] = {-1,0,-1,100,36};
				_expected = 164LL;
				_received = _obj.minSum(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 4:
			{
				int x[] = {0,536870912,0,536870912,0,536870912,0,536870912,0,536870912,
				          0,536870912,0,536870912,0,536870912,0,536870912,0,536870912,
				          1073741823,1073741823,1073741823,123456789,987654321,804289383};
				_expected = 11992352010LL;
				_received = _obj.minSum(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 5:
			{
				int x[] = {1287325,424244444,92759185,812358213,1000000000,825833522,749092703};
				_expected = -1LL;
				_received = _obj.minSum(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 6:
			{
				int x[] = {-1,-1};
				_expected = 0LL;
				_received = _obj.minSum(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			/*case 7:
			{
				int x[] = ;
				_expected = LL;
				_received = _obj.minSum(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int x[] = ;
				_expected = LL;
				_received = _obj.minSum(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}*/
			/*case 9:
			{
				int x[] = ;
				_expected = LL;
				_received = _obj.minSum(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
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
