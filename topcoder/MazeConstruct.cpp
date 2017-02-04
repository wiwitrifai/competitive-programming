#include <bits/stdc++.h>

using namespace std;

class MazeConstruct {
public:
	vector <string> construct(int k) {
		if (k <= 49 + 49) {
			if (k <= 49) {
				string s(k+1, '.');
				return vector< string > (1, s);
			}
			else {
				k -= 49;
				return vector< string > (k+1, string(50, '.'));
			}
		}
		int n = 50, m = 50;
		if (k & 1)
			m = 49;
		vector< string > ret(n, string(m, '.'));
		for (int i = m-2; i >= 0; i -= 4) {
			for (int j = n-1; j > 0; j--)
				ret[j][i] = '#';
		}
		k -= n + m - 2;
		int i = m-4, j = 0;
		while (k > 0) {
			if (j >= m-1) {
				i -= 4;
				j = 0;
			}
			ret[j][i] = '#';
			j++;
			k -= 2;
		}
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
	string str(5, '.');
	cerr << str << endl;
	if (argc == 1) 
	{
		cout << "Testing MazeConstruct (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1485828039;
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
		MazeConstruct _obj;
		vector <string> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int k = 3;
				string __expected[] = {"...." };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(k); break;
			}
			case 1:
			{
				int k = 4;
				string __expected[] = {"...", "...", "..." };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(k); break;
			}
			case 2:
			{
				int k = 10;
				string __expected[] = {"..#..", "#.#..", "..#..", ".#...", "....." };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(k); break;
			}
			case 3:
			{
				int k = 1000;
				string __expected[] = {"."};
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(k); break;
			}
			case 4:
			{
				int k = 999;
				string __expected[] = {"."};
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(k); break;
			}
			/*case 5:
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
