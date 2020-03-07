#include <bits/stdc++.h>

using namespace std;

class PreviousOccurrence {
public:
	int findValue(int defaultValue, int query) {
    if (query == 0)
    	return 0;
    if (defaultValue == 1) {
    	if (query == 1)
    		return 1;
    	return -1;
    }
		map<int, int> first, second;
    first[0] = 0;
    int last = 0;
    map<int, int> ans;
    ans[0] = 0;
    for (int i = 1; ; ++i) {
      auto it2 = second.find(last), it = first.find(last);
      int now = defaultValue;
      if (it2 != second.end()) {
        now = it->second - it2->second;
      }
      it = first.find(now);
      if (it != first.end()) {
        second[now] = it->second;
      }
      first[now] = i;
      last = now;
      if (now == query)
      	return i;
    }
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
		cout << "Testing PreviousOccurrence (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1580746760;
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
		PreviousOccurrence _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int defaultValue = 7;
				int query = 0;
				_expected = 0;
				_received = _obj.findValue(defaultValue, query); break;
			}
			case 1:
			{
				int defaultValue = 7;
				int query = 2;
				_expected = 5;
				_received = _obj.findValue(defaultValue, query); break;
			}
			case 2:
			{
				int defaultValue = 7;
				int query = 47;
				_expected = 1261;
				_received = _obj.findValue(defaultValue, query); break;
			}
			case 3:
			{
				int defaultValue = 47;
				int query = 7;
				_expected = 66;
				_received = _obj.findValue(defaultValue, query); break;
			}
			case 4:
			{
				int defaultValue = 47;
				int query = 6763;
				_expected = 540153;
				_received = _obj.findValue(defaultValue, query); break;
			}
			/*case 5:
			{
				int defaultValue = ;
				int query = ;
				_expected = ;
				_received = _obj.findValue(defaultValue, query); break;
			}*/
			/*case 6:
			{
				int defaultValue = ;
				int query = ;
				_expected = ;
				_received = _obj.findValue(defaultValue, query); break;
			}*/
			/*case 7:
			{
				int defaultValue = ;
				int query = ;
				_expected = ;
				_received = _obj.findValue(defaultValue, query); break;
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
