#include <bits/stdc++.h>

using namespace std;

struct OlympicShooting {
	vector <int> sort(vector <string> results) {
		vector<int> id(results.size());
		iota(id.begin(), id.end(), 0);
		int m = results[0].size();
		std::sort(id.begin(), id.end(), [&](int l, int r) {
			int tot = 0;
			for (int i = m-1; i >= 0; --i) {
				tot += results[l][i] - '0';
				tot -= results[r][i] - '0';
			}
			if (tot != 0)
				return tot > 0;
			for (int i = m-1; i >= 0; i -= 25) {
				tot = 0;
				for (int j = 0; j < 25; ++j) {
					tot += results[l][i-j] - '0';
					tot -= results[r][i-j] - '0';
				}
				if (tot != 0)
					return tot > 0;
			}
			for (int i = m-1; i >= 0; --i) {
				if (results[l][i] != results[r][i])
					return results[l][i] > results[r][i];
			}
			return l < r;
		});
		return id;
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
		cout << "Testing OlympicShooting (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1628075104;
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
		OlympicShooting _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string results[] = {"1111111111101111111111111",
				                    "1111111111111111111111100",
				                    "1111111111111111111110111",
				                    "1111111111111111111111111",
				                    "1111111111111111111110111"};
				int __expected[] = {3, 0, 2, 4, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.sort(vector <string>(results, results+sizeof(results)/sizeof(string))); break;
			}
			case 1:
			{
				string results[] = {"11111111111011111111111110000000000000000000010000",
				                    "11111111111111111111111000000000000000000000001000",
				                    "11111111111111111111101110000000000000000000000100",
				                    "11111111111111111111111110000000000000000000000010",
				                    "11111111111111111111101110000000000000000000000001"};
				int __expected[] = {3, 4, 2, 0, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.sort(vector <string>(results, results+sizeof(results)/sizeof(string))); break;
			}
			case 2:
			{
				string results[] = {"11111111111011111111111110000000000000000000000100",
				                    "11111111111111111111111000000000000000000000011000",
				                    "11111111111111111111101110000000000000000000000100",
				                    "11111111111111111111111110000000000000000000000010",
				                    "11111111111111111111101110000000000000000000000001"};
				int __expected[] = {3, 1, 4, 0, 2 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.sort(vector <string>(results, results+sizeof(results)/sizeof(string))); break;
			}
			case 3:
			{
				string results[] = {"00000000000000000000000000000000000000000000000000",
				                    "00000000000000000000000000000000000000000000000000",
				                    "00000000000000000000000000000000000000000000000000",
				                    "00000000000000000000000000000000000000000000000000",
				                    "00000000000000000000000000000000000000000000000000",
				                    "00000000000000000000000000000000000000000000000000"};
				int __expected[] = {0, 1, 2, 3, 4, 5 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.sort(vector <string>(results, results+sizeof(results)/sizeof(string))); break;
			}
			case 4:
			{
				string results[] = {"10000000000000000000000000000000000000000000000000",
				                    "01000000000000000000000000000000000000000000000000"};
				int __expected[] = {1, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.sort(vector <string>(results, results+sizeof(results)/sizeof(string))); break;
			}
			/*case 5:
			{
				string results[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.sort(vector <string>(results, results+sizeof(results)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string results[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.sort(vector <string>(results, results+sizeof(results)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string results[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.sort(vector <string>(results, results+sizeof(results)/sizeof(string))); break;
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
