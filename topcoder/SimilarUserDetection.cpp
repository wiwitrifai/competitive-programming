#include <bits/stdc++.h>

using namespace std;

class SimilarUserDetection {
public:
	string haveSimilar(vector <string> handles) {
		for (string & s : handles) {
			int len = s.size();
			for (int i = 0; i < len; i++) {
				if (s[i] == 'O')
					s[i] = '0';
				else if (s[i] == 'l' || s[i] == 'I')
					s[i] = '1';
			}
		}
		for (int i = 0; i < handles.size(); i++) {
			for (int j = 0; j < i; j++)
				if (handles[i] == handles[j])
					return "Similar handles found";
		}
		return "Similar handles not found";
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
		cout << "Testing SimilarUserDetection (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1489505958;
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
		SimilarUserDetection _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string handles[] = {"top", "coder", "TOPCODER", "TOPC0DER"};
				_expected = "Similar handles found";
				_received = _obj.haveSimilar(vector <string>(handles, handles+sizeof(handles)/sizeof(string))); break;
			}
			case 1:
			{
				string handles[] = {"Topcoder", "topcoder", "t0pcoder", "topcOder"};
				_expected = "Similar handles not found";
				_received = _obj.haveSimilar(vector <string>(handles, handles+sizeof(handles)/sizeof(string))); break;
			}
			case 2:
			{
				string handles[] = {"same", "same", "same", "different"};
				_expected = "Similar handles found";
				_received = _obj.haveSimilar(vector <string>(handles, handles+sizeof(handles)/sizeof(string))); break;
			}
			case 3:
			{
				string handles[] = {"0123", "0I23", "0l23", "O123", "OI23", "Ol23"};
				_expected = "Similar handles found";
				_received = _obj.haveSimilar(vector <string>(handles, handles+sizeof(handles)/sizeof(string))); break;
			}
			case 4:
			{
				string handles[] = {"i23", "123", "456", "789", "000", "o", "O"};
				_expected = "Similar handles not found";
				_received = _obj.haveSimilar(vector <string>(handles, handles+sizeof(handles)/sizeof(string))); break;
			}
			/*case 5:
			{
				string handles[] = ;
				_expected = ;
				_received = _obj.haveSimilar(vector <string>(handles, handles+sizeof(handles)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string handles[] = ;
				_expected = ;
				_received = _obj.haveSimilar(vector <string>(handles, handles+sizeof(handles)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string handles[] = ;
				_expected = ;
				_received = _obj.haveSimilar(vector <string>(handles, handles+sizeof(handles)/sizeof(string))); break;
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
