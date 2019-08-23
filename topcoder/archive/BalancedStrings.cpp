#include <bits/stdc++.h>

using namespace std;

class BalancedStrings {
public:
	vector <string> findAny(int N) {
		if (N <= 26) {
			vector< string > ans;
			for (int i = 0; i < N; i++)
				ans.push_back(string(1, 'a'+i));
			return ans;
		}
		vector< string > ans;
		int sisa = N - 6;
		int tot = 0;
		int need = (sisa+10)/11;
		char last = 'a';
		for (int i = 0; i < need; i++) {
			int now = min(sisa, 11);
			sisa -= now;
			tot += now * (now-1)/2;
			for (int j = 0; j < now; j++)
				ans.push_back(string(1, last));
			last++;
		}
		for (int j = 0; j < 6; j++) {
			char seling = last+1;
			string s;
			s.push_back(last);
			int now = min(99, tot);
			tot -= now;
			for (int i = 0; i < now; i++)
				if (i & 1)
					s.push_back(last);
				else
					s.push_back(seling);
			ans.push_back(s);
			last += 2;
		}
		assert(ans.size() == N);
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
		cout << "Testing BalancedStrings (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1486904978;
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
		BalancedStrings _obj;
		vector <string> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 3;
				string __expected[] = {"eertree", "topcoder", "arena" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.findAny(N); break;
			}
			case 1:
			{
				int N = 4;
				string __expected[] = {"hello", "little", "polar", "bear" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.findAny(N); break;
			}
			case 2:
			{
				int N = 5;
				string __expected[] = {"abbbbbbbbbbbbczaaaaaao", "c", "zz", "c", "xxxyyyzvvv" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.findAny(N); break;
			}
			case 3:
			{
				int N = 1;
				string __expected[] = {"kkkkkkkkkkkkkkkkkkk" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.findAny(N); break;
			}
			case 4:
			{
				int N = 10;
				string __expected[] = {"asdflkjhsdfsfffkdhjfdlshlfds", "pudelek", "xo", "xo", "mnbvmnmbbr", "plox", "qqwwrrttyyy", "you", "are", "awesome" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.findAny(N); break;
			}
			/*case 5:
			{
				int N = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.findAny(N); break;
			}*/
			/*case 6:
			{
				int N = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.findAny(N); break;
			}*/
			/*case 7:
			{
				int N = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.findAny(N); break;
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
