#include <bits/stdc++.h>

using namespace std;

string s[51 * 30];

class BuildingStrings {
public:
	vector <string> findAny(int K) {
		for (int i = 0; i < 26; i++) {
			for (int j = i+1; j <= 50; j++) {
				string st(j, 'a');
				for (int k = 0; k <= i; k++) {
					st[k] = 'a' + k;
				}
				s[(i+1) * j] = st;
			}
		}
		vector<string > ans;
		while (K) {
			int now = min(K, 50 * 26);
			while (now >= 0 && !s[now].size()) now--;
			if (now < 0)
				return vector<string>();
			ans.push_back(s[now]);
			K -= now;
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
		cout << "Testing BuildingStrings (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1486879224;
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
		BuildingStrings _obj;
		vector <string> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int K = 49;
				string __expected[] = {"little", "limak" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.findAny(K); break;
			}
			case 1:
			{
				int K = 15;
				string __expected[] = {"azz", "xyz" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.findAny(K); break;
			}
			case 2:
			{
				int K = 704;
				string __expected[] = {"aaaaaaaaaa", "abcdefghijklmnopqrstuvwxyz", "aabbcc" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.findAny(K); break;
			}
			case 3:
			{
				int K = 37521;
				string __expected[] = {"aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "abcd", "aa", "a", "a", "a" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.findAny(K); break;
			}
			case 4:
			{
				int K = 1;
				string __expected[] = {"a" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.findAny(K); break;
			}
			/*case 5:
			{
				int K = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.findAny(K); break;
			}*/
			/*case 6:
			{
				int K = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.findAny(K); break;
			}*/
			/*case 7:
			{
				int K = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.findAny(K); break;
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
