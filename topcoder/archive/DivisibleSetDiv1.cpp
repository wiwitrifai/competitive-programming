#include <bits/stdc++.h>

using namespace std;

class DivisibleSetDiv1 {
public:
	string isPossible(vector <int> b) {
		int n = b.size();
		vector< int > a(n, 0);		
		sort(b.begin(), b.end());
		reverse(b.begin(), b.end());
		for (int i = 0; i < n; i++) b[i]++;
		bool ok = 0;
		long long p = n * (n+1)/2;
		for (int i = 0; i < 1000000; i++) {
			long long now = 0;
			ok = 1;
			for (int j = 0; j < n; j++) {
				now += a[j]+1;
				if (now * b[j] < p) {
					ok = 0;
					a[j]++;
					p += (n-j);
					break;
				}
			}
			if (ok)
				break;
		}
		return ok ? "Possible" : "Impossible";
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
		cout << "Testing DivisibleSetDiv1 (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1487326909;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 300.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		DivisibleSetDiv1 _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int b[] = {2,1};
				_expected = "Possible";
				_received = _obj.isPossible(vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 1:
			{
				int b[] = {1,1};
				_expected = "Impossible";
				_received = _obj.isPossible(vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 2:
			{
				int b[] = {7, 7, 7};
				_expected = "Possible";
				_received = _obj.isPossible(vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 3:
			{
				int b[] = {5,3,5,4,6,1,3,7,9,6,2,5,4,1,1,9,6,10,10,6,10,7,7,8};
				_expected = "Impossible";
				_received = _obj.isPossible(vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			/*case 4:
			{
				int b[] = ;
				_expected = ;
				_received = _obj.isPossible(vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int b[] = ;
				_expected = ;
				_received = _obj.isPossible(vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int b[] = ;
				_expected = ;
				_received = _obj.isPossible(vector <int>(b, b+sizeof(b)/sizeof(int))); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
