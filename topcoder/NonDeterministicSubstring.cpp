#include <bits/stdc++.h>

using namespace std;

bool match(string a, string b) {
	if (a.size() != b.size())
		return 0;
	for (int i = 0; i < a.size(); i++) {
		if (b[i] == '?' || a[i] == '?')
			continue;
		if (a[i] != b[i])
			return 0; 
	}
	return 1;
}

class NonDeterministicSubstring {
public:
	long long ways(string A, string B) {
		int n = A.size(), m = B.size();
		set< string > st;
		for (int i = 0; i + m <= n; i++) {
			string now = A.substr(i, m);
			if (match(now, B))
				st.insert(now);
		}
		return st.size();
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
		cout << "Testing NonDeterministicSubstring (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1489506199;
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
		NonDeterministicSubstring _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string A = "00010001";
				string B = "??";
				_expected = 3LL;
				_received = _obj.ways(A, B); break;
			}
			case 1:
			{
				string A = "00000000";
				string B = "??0??0";
				_expected = 1LL;
				_received = _obj.ways(A, B); break;
			}
			case 2:
			{
				string A = "001010101100010111010";
				string B = "???";
				_expected = 8LL;
				_received = _obj.ways(A, B); break;
			}
			case 3:
			{
				string A = "00101";
				string B = "??????";
				_expected = 0LL;
				_received = _obj.ways(A, B); break;
			}
			case 4:
			{
				string A = "1101010101111010101011111111110001010101";
				string B = "???????????????????????????????????";
				_expected = 6LL;
				_received = _obj.ways(A, B); break;
			}
			/*case 5:
			{
				string A = ;
				string B = ;
				_expected = LL;
				_received = _obj.ways(A, B); break;
			}*/
			/*case 6:
			{
				string A = ;
				string B = ;
				_expected = LL;
				_received = _obj.ways(A, B); break;
			}*/
			/*case 7:
			{
				string A = ;
				string B = ;
				_expected = LL;
				_received = _obj.ways(A, B); break;
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
