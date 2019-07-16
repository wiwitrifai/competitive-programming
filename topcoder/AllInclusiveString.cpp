#include <bits/stdc++.h>

using namespace std;

class AllInclusiveString {
public:
	vector <int> shortest(vector <string> a) {
		
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
		cout << "Testing AllInclusiveString (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1550803266;
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
		AllInclusiveString _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string a[] = {"aa", "ac"};
				int __expected[] = {3, 2 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.shortest(vector <string>(a, a+sizeof(a)/sizeof(string))); break;
			}
			case 1:
			{
				string a[] = {};
				int __expected[] = {0, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.shortest(vector <string>(a, a+sizeof(a)/sizeof(string))); break;
			}
			case 2:
			{
				string a[] = {"aa", "bb", "cc"};
				int __expected[] = {6, 90 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.shortest(vector <string>(a, a+sizeof(a)/sizeof(string))); break;
			}
			case 3:
			{
				string a[] = {"ac","ag","aj","bb","bf","bg","bh","ce","cg","da","de","df","dg","di","ea","eb","ef","ei","fb","fc","fg","gc","gf","gi","gj","hb","hh","hi","ib","ih","ij","jj"};
				int __expected[] = {15, 11461680 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.shortest(vector <string>(a, a+sizeof(a)/sizeof(string))); break;
			}
			/*case 4:
			{
				string a[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.shortest(vector <string>(a, a+sizeof(a)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string a[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.shortest(vector <string>(a, a+sizeof(a)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string a[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.shortest(vector <string>(a, a+sizeof(a)/sizeof(string))); break;
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
			cout << "           Expected: {";
			for (unsigned i = 0; i < _expected.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _expected[i];
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _received[i];
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
