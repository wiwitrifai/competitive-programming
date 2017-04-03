#include <bits/stdc++.h>

using namespace std;

class PingPongQueue {
public:
	vector <int> whoPlaysNext(vector <int> skills, int N, int K) {
		queue< int > que;
		for (int v : skills)
			que.push(v);
		int now = que.front(), cnt = 0, win, lose;
		que.pop();
		while (K--) {
			int cur = que.front();
			que.pop();
			if (now > cur) {
				win = now;
				lose = cur;
				cnt++;
				que.push(cur);
			}
			else {
				win = cur;
				lose = now;
				cnt = 1;
				que.push(now);
				now = cur;
			}
			if (cnt >= N) {
				cnt = 0;
				que.push(now);
				now = que.front();
				que.pop();
			}
		}
		return vector<int> {lose, win};
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
		cout << "Testing PingPongQueue (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1491182705;
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
		PingPongQueue _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int skills[] = {1, 2, 3};
				int N = 2;
				int K = 2;
				int __expected[] = {2, 3 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.whoPlaysNext(vector <int>(skills, skills+sizeof(skills)/sizeof(int)), N, K); break;
			}
			case 1:
			{
				int skills[] = {1, 2, 3};
				int N = 2;
				int K = 4;
				int __expected[] = {1, 2 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.whoPlaysNext(vector <int>(skills, skills+sizeof(skills)/sizeof(int)), N, K); break;
			}
			case 2:
			{
				int skills[] = {49, 24, 26, 12, 5, 33, 25, 30, 35, 41, 46, 23, 21, 3, 38, 43, 11, 19, 34, 29, 20, 32, 39, 7, 50};
				int N = 10;
				int K = 399;
				int __expected[] = {12, 50 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.whoPlaysNext(vector <int>(skills, skills+sizeof(skills)/sizeof(int)), N, K); break;
			}
			case 3:
			{
				int skills[] = {30, 12};
				int N = 34;
				int K = 80;
				int __expected[] = {12, 30 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.whoPlaysNext(vector <int>(skills, skills+sizeof(skills)/sizeof(int)), N, K); break;
			}
			/*case 4:
			{
				int skills[] = ;
				int N = ;
				int K = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.whoPlaysNext(vector <int>(skills, skills+sizeof(skills)/sizeof(int)), N, K); break;
			}*/
			/*case 5:
			{
				int skills[] = ;
				int N = ;
				int K = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.whoPlaysNext(vector <int>(skills, skills+sizeof(skills)/sizeof(int)), N, K); break;
			}*/
			/*case 6:
			{
				int skills[] = ;
				int N = ;
				int K = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.whoPlaysNext(vector <int>(skills, skills+sizeof(skills)/sizeof(int)), N, K); break;
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
