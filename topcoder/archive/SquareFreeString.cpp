#include <bits/stdc++.h>

using namespace std;

class SquareFreeString {
public:
	string isSquareFree(string s) {
		int n = s.size();
		bool sf = 1;
		for (int len = 2; len <= n; len += 2) {
			for (int i = 0; i + len <= n; i++) {
				int mid = len/2;
				bool sq = 1;
				for (int j = 0; j < mid; j++)
					sq &= s[i+j] == s[i+mid+j];
				if (sq) sf = 0;
			}
		}
		return sf ? "square-free" : "not square-free";
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
		cout << "Testing SquareFreeString (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1487027677;
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
		SquareFreeString _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string s = "bobo";
				_expected = "not square-free";
				_received = _obj.isSquareFree(s); break;
			}
			case 1:
			{
				string s = "apple";
				_expected = "not square-free";
				_received = _obj.isSquareFree(s); break;
			}
			case 2:
			{
				string s = "pen";
				_expected = "square-free";
				_received = _obj.isSquareFree(s); break;
			}
			case 3:
			{
				string s = "aydyamrbnauhftmphyrooyq";
				_expected = "not square-free";
				_received = _obj.isSquareFree(s); break;
			}
			case 4:
			{
				string s = "qwertyuiopasdfghjklzxcvbnm";
				_expected = "square-free";
				_received = _obj.isSquareFree(s); break;
			}
			/*case 5:
			{
				string s = ;
				_expected = ;
				_received = _obj.isSquareFree(s); break;
			}*/
			/*case 6:
			{
				string s = ;
				_expected = ;
				_received = _obj.isSquareFree(s); break;
			}*/
			/*case 7:
			{
				string s = ;
				_expected = ;
				_received = _obj.isSquareFree(s); break;
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
