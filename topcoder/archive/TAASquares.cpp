#include <bits/stdc++.h>

using namespace std;

class TAASquares {
public:
	vector <string> construct(int N) {
		vector<string> answer;
		for (int i = 0; i < N; ++i) {
			string line;
			for (int j = i; j < N; ++j) {
				if (i >= N/ 2 && j == N-1)
					line += '1';
				else
					line += '2';
			}
			for (int k = 0; k < i; ++k) {
				line += '0';
			}
			answer.push_back(line);
		}
		set<int> sum;
		for (int i = 0; i < N; ++i) {
			int tot = 0;
			for (int j = 0; j < N; ++j) {
				tot += answer[i][j] - '0';
			}
			sum.insert(tot);
			tot = 0;
			for (int j = 0; j < N; ++j) {
				tot += answer[j][i] - '0';
			}
			sum.insert(tot);
		}
		int cur = sum.size();
		int now = 2 * N;
		while ((now * (now - 1) / 2) & 1)
			--now;
		assert((int)sum.size() == now);
		return answer;
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
	for (int n = 1; n <= 50; ++n) {
		TAASquares _obj;
		_obj.construct(n);
	}
	if (argc == 1) 
	{
		cout << "Testing TAASquares (800.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1587742825;
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
		TAASquares _obj;
		vector <string> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 4;
				string __expected[] = {"2212", "2002", "0002", "2102" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(N); break;
			}
			case 1:
			{
				int N = 5;
				string __expected[] = {"12222", "00012", "02221", "00110", "00122" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(N); break;
			}
			case 2:
			{
				int N = 1;
				string __expected[] = {"1" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(N); break;
			}
			// case 3:
			// {
			// 	int N = 49;
			// 	string __expected[] = {};
			// 	_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
			// 	_received = _obj.construct(N); break;
			// }
			/*case 4:
			{
				int N = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(N); break;
			}*/
			/*case 5:
			{
				int N = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(N); break;
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
