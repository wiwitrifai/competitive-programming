#include <bits/stdc++.h>

using namespace std;

class Plusonegame {
public:
	string getorder(string s) {
		int cnt[15], plus = 0;
		memset(cnt, 0, sizeof cnt);
		int n = s.size();
		for (char c: s) if (c == '+')
			plus++;
		else
			cnt[c-'0']++;
		string ret = "";
		for (int i = 0; i < 10; i++) {
			if (i && plus > 0) {
				ret += '+';
				plus--;
			}
			ret += string(cnt[i], '0' + i);
		}
		ret += string(plus, '+');
		return ret;
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
		cout << "Testing Plusonegame (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1489413284;
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
		Plusonegame _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string s = "1++";
				_expected = "+1+";
				_received = _obj.getorder(s); break;
			}
			case 1:
			{
				string s = "549";
				_expected = "459";
				_received = _obj.getorder(s); break;
			}
			case 2:
			{
				string s = "++++++";
				_expected = "++++++";
				_received = _obj.getorder(s); break;
			}
			case 3:
			{
				string s = "+++++2+";
				_expected = "++2++++";
				_received = _obj.getorder(s); break;
			}
			case 4:
			{
				string s = "++++4++++200++2++1+6++++++";
				_expected = "00+1+22++4++6+++++++++++++";
				_received = _obj.getorder(s); break;
			}
			case 5:
			{
				string s = "++11199999";
				_expected = "+111+99999";
				_received = _obj.getorder(s); break;
			}
			/*case 6:
			{
				string s = ;
				_expected = ;
				_received = _obj.getorder(s); break;
			}*/
			/*case 7:
			{
				string s = ;
				_expected = ;
				_received = _obj.getorder(s); break;
			}*/
			/*case 8:
			{
				string s = ;
				_expected = ;
				_received = _obj.getorder(s); break;
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
