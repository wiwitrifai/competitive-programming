#include <bits/stdc++.h>

using namespace std;

class ColorfulGarden {
public:
	vector <string> rearrange(vector <string> garden) {
		int cnt[128];
		memset(cnt, 0, sizeof cnt);
		int n = garden[0].size();
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < n; j++)
				cnt[garden[i][j]]++;
		int ma = 0;
		for (int i = 'a'; i <= 'z'; i++)
			ma = max(cnt[i], ma);
		if (ma > n)
			return vector< string > ();
		int last = -1, slast = -1;
		for (int i = 0; i < n; i++) {
			int best = 0, sbest = 1;
			if (cnt[best] < cnt[sbest])
				swap(best, sbest);
			for (int j = 'a'; j <= 'z'; j++)
				if (cnt[j] > cnt[best]) {
					sbest = best;
					best = j;
				}
				else if (cnt[j] > cnt[sbest])
					sbest = j;
			if (best == last || sbest == slast)
				swap(best, sbest);
			last = best;
			slast = sbest;
			cnt[best]--;
			cnt[sbest]--;
			garden[0][i] = char(best);
			garden[1][i] = char(sbest);
		}
		return garden;
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
		cout << "Testing ColorfulGarden (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1489507636;
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
		ColorfulGarden _obj;
		vector <string> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string garden[] = {"aa",
				                   "bb"};
				string __expected[] = {"ba", "ab" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.rearrange(vector <string>(garden, garden+sizeof(garden)/sizeof(string))); break;
			}
			case 1:
			{
				string garden[] = {"xxxx",
				                   "xxxx"};
				string __expected[] = { };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.rearrange(vector <string>(garden, garden+sizeof(garden)/sizeof(string))); break;
			}
			case 2:
			{
				string garden[] = {"abcd",
				                   "abcd"};
				string __expected[] = {"abcd", "dcba" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.rearrange(vector <string>(garden, garden+sizeof(garden)/sizeof(string))); break;
			}
			case 3:
			{
				string garden[] = {"abcdefghijklm",
				                   "nopqrstuvwxyz"};
				string __expected[] = {"abcdefghijklm", "nopqrstuvwxyz" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.rearrange(vector <string>(garden, garden+sizeof(garden)/sizeof(string))); break;
			}
			case 4:
			{
				string garden[] = {"aaa",
				                   "aab"};
				string __expected[] = { };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.rearrange(vector <string>(garden, garden+sizeof(garden)/sizeof(string))); break;
			}
			case 5:
			{
				string garden[] = {"abeebebaeabababbaebabe", "bbbdcdcbbbcbcbcdbbbbdc"};
				string __expected[] = {"edecdcbcbebabababababa", "decececbdbabababababab"};
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.rearrange(vector <string>(garden, garden+sizeof(garden)/sizeof(string))); break;
			}
			/*case 6:
			{
				string garden[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.rearrange(vector <string>(garden, garden+sizeof(garden)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string garden[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.rearrange(vector <string>(garden, garden+sizeof(garden)/sizeof(string))); break;
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
