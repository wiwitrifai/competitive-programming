#include <bits/stdc++.h>

using namespace std;

string getww(string s) {
	int n = s.size();
	for (int i = 0; i < n; i++) {
		if (s[i] == 'o')
			s[i] = '0';
		if (s[i] == 'l')
			s[i] = '1';
		if (s[i] == 'm')
			s[i] = 'n';
	}
	return s;
}

class UnclearNotes {
public:
	string isMatch(string S, string T) {
		if (S.size() != T.size())
			return "Impossible";
		if (getww(S) == getww(T))
			return "Possible";
		return "Impossible";
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
		cout << "Testing UnclearNotes (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1504897245;
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
		UnclearNotes _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string S = "topc0der";
				string T = "topcoder";
				_expected = "Possible";
				_received = _obj.isMatch(S, T); break;
			}
			case 1:
			{
				string S = "topcoder";
				string T = "codertop";
				_expected = "Impossible";
				_received = _obj.isMatch(S, T); break;
			}
			case 2:
			{
				string S = "o0ol1lnmn";
				string T = "oo0ll1nnm";
				_expected = "Possible";
				_received = _obj.isMatch(S, T); break;
			}
			case 3:
			{
				string S = "c01unn";
				string T = "column";
				_expected = "Possible";
				_received = _obj.isMatch(S, T); break;
			}
			case 4:
			{
				string S = "0";
				string T = "l";
				_expected = "Impossible";
				_received = _obj.isMatch(S, T); break;
			}
			case 5:
			{
				string S = "81vdiu0n50mxlxopqn8olxbqromvkral21nbi";
				string T = "llv0i00p50nx1xs1qn1o13bqaomv0r152lmgi";
				_expected = "Impossible";
				_received = _obj.isMatch(S, T); break;
			}
			case 6:
			{
				string S = "nl91gn9lnnqpyo09ml1h140onnomoonr0ow24qfw0muf";
				string T = "nl9lgn91nmqpy009ml1hl4o0nm0mo0nro0w24qfwonuf";
				_expected = "Possible";
				_received = _obj.isMatch(S, T); break;
			}
			/*case 7:
			{
				string S = ;
				string T = ;
				_expected = ;
				_received = _obj.isMatch(S, T); break;
			}*/
			/*case 8:
			{
				string S = ;
				string T = ;
				_expected = ;
				_received = _obj.isMatch(S, T); break;
			}*/
			/*case 9:
			{
				string S = ;
				string T = ;
				_expected = ;
				_received = _obj.isMatch(S, T); break;
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
