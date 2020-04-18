#include <bits/stdc++.h>

using namespace std;

class AveragePrice {
public:
	double nonDuplicatedAverage(vector <int> prices) {
		set<int> st;
		for (int x : prices)
			st.insert(x);
		long long ans = 0;
		for (auto it : st)
			ans += it;
		return (long double)ans / (int)st.size();
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
		cout << "Testing AveragePrice (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1587226236;
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
		AveragePrice _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int prices[] = { 10, 20, 10 };
				_expected = 15.0;
				_received = _obj.nonDuplicatedAverage(vector <int>(prices, prices+sizeof(prices)/sizeof(int))); break;
			}
			case 1:
			{
				int prices[] = { 1, 2, 3, 4, 5 };
				_expected = 3.0;
				_received = _obj.nonDuplicatedAverage(vector <int>(prices, prices+sizeof(prices)/sizeof(int))); break;
			}
			case 2:
			{
				int prices[] = { 10, 10, 10, 10, 10, 10 };
				_expected = 10.0;
				_received = _obj.nonDuplicatedAverage(vector <int>(prices, prices+sizeof(prices)/sizeof(int))); break;
			}
			/*case 3:
			{
				int prices[] = ;
				_expected = ;
				_received = _obj.nonDuplicatedAverage(vector <int>(prices, prices+sizeof(prices)/sizeof(int))); break;
			}*/
			/*case 4:
			{
				int prices[] = ;
				_expected = ;
				_received = _obj.nonDuplicatedAverage(vector <int>(prices, prices+sizeof(prices)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int prices[] = ;
				_expected = ;
				_received = _obj.nonDuplicatedAverage(vector <int>(prices, prices+sizeof(prices)/sizeof(int))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
