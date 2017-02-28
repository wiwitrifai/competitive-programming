#include <bits/stdc++.h>

using namespace std;

class BipartiteConstruction {
public:
	vector <int> construct(int K) {
		stack< int > st;
		while (K) st.push(K % 3), K /= 3;
		vector< int > ret;
		int n = 20;
		ret.push_back(n);
		for (int i = 1; i < n; i++)
			ret.push_back(i * n + i), ret.push_back(i * n + i-1);
		int cur = 0;
		while (!st.empty()) {
			if (cur) {
				ret.push_back(cur * n + cur);
				ret.push_back(cur * n + cur);
			}
			for (int i = 0; i < st.top(); i++)
				ret.push_back(cur);
			st.pop();
			cur++;
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
	if (argc == 1) 
	{
		cout << "Testing BipartiteConstruction (600.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1488081663;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 600.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		BipartiteConstruction _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int K = 2;
				int __expected[] = {3, 8, 1, 7, 4, 3, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(K); break;
			}
			case 1:
			{
				int K = 5;
				int __expected[] = {1, 0, 0, 0, 0, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(K); break;
			}
			case 2:
			{
				int K = 0;
				int __expected[] = {2, 1, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(K); break;
			}
			case 3:
			{
				int K = 2333333;
				int __expected[] = {20, 93, 195, 195, 211, 87, 114, 369, 390, 216, 195, 305, 17, 370, 356, 308, 150, 263, 20, 153, 331, 79, 344, 108, 114, 257, 245, 289, 211, 388, 388, 359, 293, 263, 219, 131, 201, 293, 279, 204, 97, 367, 90, 279, 308, 324, 323, 359, 338, 63, 26, 318, 218, 226, 164, 361, 276, 388, 343, 149, 17, 336, 88, 161, 76, 237, 136, 278, 302, 107, 271, 15, 382, 45, 338, 264, 78, 150, 220, 341, 180, 20, 252, 94, 114, 161 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(K); break;
			}
			/*case 4:
			{
				int K = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(K); break;
			}*/
			/*case 5:
			{
				int K = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(K); break;
			}*/
			/*case 6:
			{
				int K = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(K); break;
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
