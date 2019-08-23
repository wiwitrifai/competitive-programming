#include <bits/stdc++.h>

using namespace std;

class TwoSquares {
public:
	int maxOnes(vector <string> t) {
		
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
		cout << "Testing TwoSquares (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1487112091;
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
		TwoSquares _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string t[] = {
				             "000",
				             "010",
				             "011"};
				_expected = 8;
				_received = _obj.maxOnes(vector <string>(t, t+sizeof(t)/sizeof(string))); break;
			}
			case 1:
			{
				string t[] = {"0"};
				_expected = 1;
				_received = _obj.maxOnes(vector <string>(t, t+sizeof(t)/sizeof(string))); break;
			}
			case 2:
			{
				string t[] = {
				             "0001",
				             "0001",
				             "0111",
				             "1001"};
				_expected = 16;
				_received = _obj.maxOnes(vector <string>(t, t+sizeof(t)/sizeof(string))); break;
			}
			case 3:
			{
				string t[] = {
				             "001111",
				             "111111",
				             "110001",
				             "110001",
				             "110001",
				             "111111"};
				_expected = 35;
				_received = _obj.maxOnes(vector <string>(t, t+sizeof(t)/sizeof(string))); break;
			}
			/*case 4:
			{
				string t[] = ;
				_expected = ;
				_received = _obj.maxOnes(vector <string>(t, t+sizeof(t)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string t[] = ;
				_expected = ;
				_received = _obj.maxOnes(vector <string>(t, t+sizeof(t)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string t[] = ;
				_expected = ;
				_received = _obj.maxOnes(vector <string>(t, t+sizeof(t)/sizeof(string))); break;
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
