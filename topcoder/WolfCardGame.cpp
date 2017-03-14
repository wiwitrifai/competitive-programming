#include <bits/stdc++.h>

using namespace std;

class WolfCardGame {
public:
	vector <int> createAnswer(int N, int K) {
		vector<int> v;
		if (N == 60 && K == 15) {
			v.push_back(1);
			K--;
		}
		for (int i = 2; i <= 7; i++) if (N % i) {
			for (int j = 1; j <= K; j++)
				v.push_back(j * i);
			return v;
		}
		return vector< int >();
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
		cout << "Testing WolfCardGame (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1489481202;
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
		WolfCardGame _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 20;
				int K = 4;
				int __expected[] = {1, 2, 3, 4 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.createAnswer(N, K); break;
			}
			case 1:
			{
				int N = 40;
				int K = 1;
				int __expected[] = {39 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.createAnswer(N, K); break;
			}
			case 2:
			{
				int N = 97;
				int K = 6;
				int __expected[] = {7, 68, 9, 10, 62, 58 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.createAnswer(N, K); break;
			}
			case 3:
			{
				int N = 2;
				int K = 12;
				int __expected[] = {33, 69, 42, 45, 96, 15, 57, 12, 93, 9, 54, 99 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.createAnswer(N, K); break;
			}
			case 4:
			{
				int N = 60;
				int K = 15;
				int __expected[] = {0};
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.createAnswer(N, K); break;
			}
			/*case 5:
			{
				int N = ;
				int K = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.createAnswer(N, K); break;
			}*/
			/*case 6:
			{
				int N = ;
				int K = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.createAnswer(N, K); break;
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
