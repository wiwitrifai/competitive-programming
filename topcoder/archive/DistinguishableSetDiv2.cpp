#include <bits/stdc++.h>

using namespace std;

class DistinguishableSetDiv2 {
public:
	int count(vector <string> answer) {
		int n = answer.size(), m = answer[0].size();
		int ans = 0;
		for (int mask = 0; mask < (1<<m); mask++) {
			bool ok = 1;
			for (int i = 0; i < n && ok; i++) {
				for (int j = i+1; j < n && ok; j++) {
					bool same = 1;
					for (int k = 0; k < m; k++) if (mask & (1<<k)) {
						if (answer[i][k] != answer[j][k]) {
							same = 0;
							break;
						}
					}
					if (same) {
						ok = 0;
					}
				}
			}
			ans += ok;
		}
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
		cout << "Testing DistinguishableSetDiv2 (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1487993788;
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
		DistinguishableSetDiv2 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string answer[] = {"AA","AB","CC"};
				_expected = 2;
				_received = _obj.count(vector <string>(answer, answer+sizeof(answer)/sizeof(string))); break;
			}
			case 1:
			{
				string answer[] = {"XYZ","XYZ","XYZ"};
				_expected = 0;
				_received = _obj.count(vector <string>(answer, answer+sizeof(answer)/sizeof(string))); break;
			}
			case 2:
			{
				string answer[] = {"AAAA","BACA","CDCE"};
				_expected = 11;
				_received = _obj.count(vector <string>(answer, answer+sizeof(answer)/sizeof(string))); break;
			}
			case 3:
			{
				string answer[] = {"HGHHGUHUHI","BQHJWOSZMM","NDKSKCNXND","QOEOEIWIDS","IIQIWUNNZM"};
				_expected = 1017;
				_received = _obj.count(vector <string>(answer, answer+sizeof(answer)/sizeof(string))); break;
			}
			case 4:
			{
				string answer[] = {"XYZ","XAB","YAC"};
				_expected = 5;
				_received = _obj.count(vector <string>(answer, answer+sizeof(answer)/sizeof(string))); break;
			}
			/*case 5:
			{
				string answer[] = ;
				_expected = ;
				_received = _obj.count(vector <string>(answer, answer+sizeof(answer)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string answer[] = ;
				_expected = ;
				_received = _obj.count(vector <string>(answer, answer+sizeof(answer)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string answer[] = ;
				_expected = ;
				_received = _obj.count(vector <string>(answer, answer+sizeof(answer)/sizeof(string))); break;
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
