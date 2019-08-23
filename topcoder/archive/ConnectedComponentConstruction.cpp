#include <bits/stdc++.h>

using namespace std;

vector< int > v[100];

class ConnectedComponentConstruction {
public:
	vector <string> construct(vector <int> s) {
		vector <string> ret;
		string tot;
		int n = s.size();
		tot.assign(n, 'N');
		ret.assign(n, tot);
		for (int i = 0; i < n; i++)
			v[s[i]].push_back(i);
		for (int i = 1; i <= n; i++) {
			if (v[i].size() % i)
				return vector<string>();
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < v[i].size(); j += i) {
				for (int k = j; k < j+i; k++) {
					for (int l = j; l < k; l++) {
						ret[v[i][l]][v[i][k]] = 'Y';
						ret[v[i][k]][v[i][l]] = 'Y';
					}
				}
			}
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
		cout << "Testing ConnectedComponentConstruction (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1483049833;
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
		ConnectedComponentConstruction _obj;
		vector <string> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int s[] = {2,1,1,2,1};
				string __expected[] = {"NNNYN", "NNNNN", "NNNNN", "YNNNN", "NNNNN" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(vector <int>(s, s+sizeof(s)/sizeof(int))); break;
			}
			case 1:
			{
				int s[] = {1,1,1,1};
				string __expected[] = {"NNNN", "NNNN", "NNNN", "NNNN" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(vector <int>(s, s+sizeof(s)/sizeof(int))); break;
			}
			case 2:
			{
				int s[] = {3,3,3};
				string __expected[] = {"NYY", "YNY", "YYN" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(vector <int>(s, s+sizeof(s)/sizeof(int))); break;
			}
			case 3:
			{
				int s[] = {4,4,4,4,4};
				string __expected[] = { };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(vector <int>(s, s+sizeof(s)/sizeof(int))); break;
			}
			case 4:
			{
				int s[] = {1};
				string __expected[] = {"N" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(vector <int>(s, s+sizeof(s)/sizeof(int))); break;
			}
			/*case 5:
			{
				int s[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(vector <int>(s, s+sizeof(s)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int s[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(vector <int>(s, s+sizeof(s)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int s[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(vector <int>(s, s+sizeof(s)/sizeof(int))); break;
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
