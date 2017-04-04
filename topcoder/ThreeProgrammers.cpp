#include <bits/stdc++.h>

using namespace std;

bool vis[55][55][55][3][3];
char ans[55 * 3];

bool go(int a, int b, int c, int x = 0, int y = 0, int id = 0) {
	if (a == 0 && b == 0 && c == 0) {
		ans[id] = '\0';
		return true;
	}
	if (vis[a][b][c][x][y])
		return false;
	vis[a][b][c][x][y] = 1;
	if (a) {
		ans[id] = 'A';
		if (go(a-1, b, c, y, 0, id+1))
			return true;
	}
	if (b && y != 1) {
		ans[id] = 'B';
		if (go(a, b-1, c, y, 1, id+1))
			return true;
	}
	if (c && x != 2 && y != 2) {
		ans[id] = 'C';
		if (go(a, b, c-1, y, 2, id+1))
			return true;
	}
	return false;
}

class ThreeProgrammers {
public:
	string validCodeHistory(string code) {
		int a, b, c;
		a = b = c = 0;
		for (char ch : code) {
			a += ch == 'A';
			b += ch == 'B';
			c += ch == 'C';
		}
		if (!go(a, b, c))
			return "impossible";
		return string(ans);
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
		cout << "Testing ThreeProgrammers (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1491278212;
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
		ThreeProgrammers _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string code = "CAB";
				_expected = "BCA";
				_received = _obj.validCodeHistory(code); break;
			}
			case 1:
			{
				string code = "CBB";
				_expected = "BCB";
				_received = _obj.validCodeHistory(code); break;
			}
			case 2:
			{
				string code = "BB";
				_expected = "impossible";
				_received = _obj.validCodeHistory(code); break;
			}
			case 3:
			{
				string code = "BBA";
				_expected = "BAB";
				_received = _obj.validCodeHistory(code); break;
			}
			case 4:
			{
				string code = "CAC";
				_expected = "impossible";
				_received = _obj.validCodeHistory(code); break;
			}
			case 5:
			{
				string code = "ACAC";
				_expected = "CAAC";
				_received = _obj.validCodeHistory(code); break;
			}
			case 6:
			{
				string code = "ACABC";
				_expected = "ACABC";
				_received = _obj.validCodeHistory(code); break;
			}
			case 7:
			{
				string code = "BAABCABBCCACBAACABAABABBCCAACABCCAACCABCACACCBABAB";
				_expected = "BACBABCAACBACABCBACBACABCBACBACABCABCAACBACAACABCA";
				_received = _obj.validCodeHistory(code); break;
			}
			/*case 8:
			{
				string code = ;
				_expected = ;
				_received = _obj.validCodeHistory(code); break;
			}*/
			/*case 9:
			{
				string code = ;
				_expected = ;
				_received = _obj.validCodeHistory(code); break;
			}*/
			/*case 10:
			{
				string code = ;
				_expected = ;
				_received = _obj.validCodeHistory(code); break;
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
