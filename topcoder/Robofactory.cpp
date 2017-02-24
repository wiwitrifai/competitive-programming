#include <bits/stdc++.h>

using namespace std;

class Robofactory {
public:
	int reveal(vector <int> query, vector <string> answer) {
		int n = query.size();
		vector< bool > ans(n, false);
		for (int i = 1; i < n; i++) {
			if (query[i-1] & 1) {
				if (query[i] & 1) {
					ans[i] = (answer[i].size() == 4);
				}
				else {
					ans[i] = (answer[i].size() == 3);
				}
			}
			else {
				if ((query[i] & 1) && (answer[i].size() == 4))
					return -1;
				if ((query[i] & 1) == 0 && (answer[i].size() == 3))
					return -1;
			}
		}
		int cnt = 0, sel = 0;
		for (int i = 0; i < n; i++) {
			cnt += ans[i];
			if (ans[i])
				sel = i;
		} 
		if (cnt > 1)
			return -1;
		if (cnt == 1)
			return sel;
		cnt = 0;
		for (int i = 0; i < n-1; i++) {
			cnt += ((query[i] & 1) == 0);
		}
		if (cnt > 0)
			return -1;
		return 0;
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
		cout << "Testing Robofactory (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1487693105;
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
		Robofactory _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int query[] = {3,2,2};
				string answer[] = {"Odd", "Odd", "Even"};
				_expected = 1;
				_received = _obj.reveal(vector <int>(query, query+sizeof(query)/sizeof(int)), vector <string>(answer, answer+sizeof(answer)/sizeof(string))); break;
			}
			case 1:
			{
				int query[] = {1,3,5,10};
				string answer[] = {"Odd", "Odd", "Odd", "Even"};
				_expected = 0;
				_received = _obj.reveal(vector <int>(query, query+sizeof(query)/sizeof(int)), vector <string>(answer, answer+sizeof(answer)/sizeof(string))); break;
			}
			case 2:
			{
				int query[] = {2,3,5,10};
				string answer[] = {"Even", "Odd", "Odd", "Even"};
				_expected = -1;
				_received = _obj.reveal(vector <int>(query, query+sizeof(query)/sizeof(int)), vector <string>(answer, answer+sizeof(answer)/sizeof(string))); break;
			}
			case 3:
			{
				int query[] = {2,4,6,10};
				string answer[] = {"Even", "Even", "Even", "Even"};
				_expected = -1;
				_received = _obj.reveal(vector <int>(query, query+sizeof(query)/sizeof(int)), vector <string>(answer, answer+sizeof(answer)/sizeof(string))); break;
			}
			case 4:
			{
				int query[] = {107};
				string answer[] = {"Odd"};
				_expected = 0;
				_received = _obj.reveal(vector <int>(query, query+sizeof(query)/sizeof(int)), vector <string>(answer, answer+sizeof(answer)/sizeof(string))); break;
			}
			case 5:
			{
				int query[] = {1,1,1};
				string answer[] = {"Odd", "Odd", "Even"};
				_expected = 2;
				_received = _obj.reveal(vector <int>(query, query+sizeof(query)/sizeof(int)), vector <string>(answer, answer+sizeof(answer)/sizeof(string))); break;
			}
			/*case 6:
			{
				int query[] = ;
				string answer[] = ;
				_expected = ;
				_received = _obj.reveal(vector <int>(query, query+sizeof(query)/sizeof(int)), vector <string>(answer, answer+sizeof(answer)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				int query[] = ;
				string answer[] = ;
				_expected = ;
				_received = _obj.reveal(vector <int>(query, query+sizeof(query)/sizeof(int)), vector <string>(answer, answer+sizeof(answer)/sizeof(string))); break;
			}*/
			/*case 8:
			{
				int query[] = ;
				string answer[] = ;
				_expected = ;
				_received = _obj.reveal(vector <int>(query, query+sizeof(query)/sizeof(int)), vector <string>(answer, answer+sizeof(answer)/sizeof(string))); break;
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
