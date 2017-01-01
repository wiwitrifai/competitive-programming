#include <bits/stdc++.h>

using namespace std;

class HamiltonianConstruction {
public:
	vector <string> construct(int k) {
		int n = 20;
		vector< string > ans(n, string(n, 'N'));
		for (int i = 0; i + 1 < n; i++)
			ans[i+1][i] = 'Y';
		for (int i = 1; i < n; i++)
			for (int j = i+1; j < n; j++)
				ans[i][j] = 'Y';
	  for (int i = n-3; i >= 0 && k; i--) {
			if (k & 1)
			 	ans[0][i] = 'Y';
			k >>= 1;
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
		cout << "Testing HamiltonianConstruction (800.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1483078840;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 800.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		HamiltonianConstruction _obj;
		vector <string> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int k = 1;
				string __expected[] = {"NY", "NN" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(k); break;
			}
			case 1:
			{
				int k = 3;
				string __expected[] = {"NYYNY", "YNYYY", "YYNYY", "YNYNY", "YYYYN" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(k); break;
			}
			case 2:
			{
				int k = 720;
				string __expected[] = {"NYYYYYYY", "YNYYYYYY", "YYNYYYYY", "YYYNYYYY", "YYYYNYYY", "YYYYYNYY", "YYYYYYNY", "YYYYYYYN" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(k); break;
			}
			case 3:
			{
				int k = 288;
				string __expected[] = {"NYYYYNYY", "YNYYYYYY", "YYNYYYNY", "YYYNYYYY", "YNYYNYYY", "YYYYYNYN", "YYNYYYNY", "YYYYYNNN" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(k); break;
			}
			/*case 4:
			{
				int k = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(k); break;
			}*/
			/*case 5:
			{
				int k = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(k); break;
			}*/
			/*case 6:
			{
				int k = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(k); break;
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
				cout << " \"" << _expected[i] << "\"";
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " \"" << _received[i] << "\"";
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
