#include <bits/stdc++.h>

using namespace std;

class LittleElephantAndBallsAgain {
public:
	int getNumber(string S) {
		int n = S.size();
		int ans = 0;
		int cnt = 0;
		char now = S[0];
		for (int i = 0; i < n; i++) {
			if (S[i] == now)
				cnt++;
			else {
				now = S[i];
				cnt = 1;
			}
			if (ans < cnt)
				ans = cnt;
		}
		return n - ans;
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
		cout << "Testing LittleElephantAndBallsAgain (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1483052529;
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
		LittleElephantAndBallsAgain _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string S = "RRGGBB";
				_expected = 4;
				_received = _obj.getNumber(S); break;
			}
			case 1:
			{
				string S = "R";
				_expected = 0;
				_received = _obj.getNumber(S); break;
			}
			case 2:
			{
				string S = "RGBRGB";
				_expected = 5;
				_received = _obj.getNumber(S); break;
			}
			case 3:
			{
				string S = "RGGGBB";
				_expected = 3;
				_received = _obj.getNumber(S); break;
			}
			case 4:
			{
				string S = "RGBRBRGRGRBBBGRBRBRGBGBBBGRGBBBBRGBGRRGGRRRGRBBBBR";
				_expected = 46;
				_received = _obj.getNumber(S); break;
			}
			/*case 5:
			{
				string S = ;
				_expected = ;
				_received = _obj.getNumber(S); break;
			}*/
			/*case 6:
			{
				string S = ;
				_expected = ;
				_received = _obj.getNumber(S); break;
			}*/
			/*case 7:
			{
				string S = ;
				_expected = ;
				_received = _obj.getNumber(S); break;
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
