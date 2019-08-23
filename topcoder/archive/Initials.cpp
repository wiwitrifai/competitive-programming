#include <bits/stdc++.h>

using namespace std;

class Initials {
public:
	string getInitials(string name) {
		string ans = "";
		bool add = 1;
		for (int i = 0; i < name.size(); i++) {
			if (name[i] == ' ')
				add = 1;
			else if (add)
				ans += name[i], add = 0;
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
		cout << "Testing Initials (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1487254325;
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
		Initials _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string name = "john fitzgerald kennedy";
				_expected = "jfk";
				_received = _obj.getInitials(name); break;
			}
			case 1:
			{
				string name = "single";
				_expected = "s";
				_received = _obj.getInitials(name); break;
			}
			case 2:
			{
				string name = "looks good to me";
				_expected = "lgtm";
				_received = _obj.getInitials(name); break;
			}
			case 3:
			{
				string name = "single round match";
				_expected = "srm";
				_received = _obj.getInitials(name); break;
			}
			case 4:
			{
				string name = "a aa aaa aa a bbb bb b bb bbb";
				_expected = "aaaaabbbbb";
				_received = _obj.getInitials(name); break;
			}
			/*case 5:
			{
				string name = ;
				_expected = ;
				_received = _obj.getInitials(name); break;
			}*/
			/*case 6:
			{
				string name = ;
				_expected = ;
				_received = _obj.getInitials(name); break;
			}*/
			/*case 7:
			{
				string name = ;
				_expected = ;
				_received = _obj.getInitials(name); break;
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
