#include <bits/stdc++.h>

using namespace std;

class CanidsSeesaw {
public:
	vector <int> construct(vector <int> wolf, vector <int> fox, int k) {
		int n = wolf.size();
		set<pair<int, int > > st;
		for (int i = 0; i < n;i++)
			st.insert(make_pair(fox[i], i));
		sort(fox.begin(), fox.end());
		int low = 0, le = 0, ri = 0;
		for (int i = 0; i < n; i++) {
			le += wolf[i];
			ri += fox[i];
			if (ri > le)
				low++;
		}
		if (k < low)
			return vector<int>();
		int hi = 0;		
		le = ri = 0;
		for (int i = 0; i < n; i++) {
			le += wolf[i];
			ri += fox[n-1-i];
			if (ri > le)
				hi++;
		}
		if (hi < k)
			return vector<int>();
		vector< int > ans;
		le = ri = 0;
		for (int i = 0; i < n; i++) {
			sort(fox.begin()+i, fox.end());
			for (int j = i+1; j < n; j++) {
				swap(fox[i], fox[j]);
				sort(fox.begin() + i + 1, fox.end());
				int cnt = 0;
				le = ri = 0;
				for (int k = 0; k < n; k++) {
					le += wolf[k];
					ri += fox[k];
					cnt += ri > le;
				}
				if (cnt > k) {
					swap(fox[i], fox[j]);
					break;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			auto it = st.lower_bound(make_pair(fox[i], -1));
			fox[i] = it->second;
			st.erase(it);
		}
		return fox;
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
		cout << "Testing CanidsSeesaw (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1500739242;
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
		CanidsSeesaw _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int wolf[] = {3,1};
				int fox[] = {4,2};
				int k = 1;
				int __expected[] = {1, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(vector <int>(wolf, wolf+sizeof(wolf)/sizeof(int)), vector <int>(fox, fox+sizeof(fox)/sizeof(int)), k); break;
			}
			case 1:
			{
				int wolf[] = {1,3};
				int fox[] = {4,2};
				int k = 1;
				int __expected[] = { };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(vector <int>(wolf, wolf+sizeof(wolf)/sizeof(int)), vector <int>(fox, fox+sizeof(fox)/sizeof(int)), k); break;
			}
			case 2:
			{
				int wolf[] = {10,10,10,10,10,10,10,10,10,10};
				int fox[] = {1,100,1,100,1,100,1,100,1,100};
				int k = 7;
				int __expected[] = {0, 2, 4, 1, 6, 3, 5, 7, 9, 8 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(vector <int>(wolf, wolf+sizeof(wolf)/sizeof(int)), vector <int>(fox, fox+sizeof(fox)/sizeof(int)), k); break;
			}
			case 3:
			{
				int wolf[] = {10,10,10,10,10,10,10,10,10,10};
				int fox[] = {1,100,1,100,1,100,1,100,1,100};
				int k = 4;
				int __expected[] = { };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(vector <int>(wolf, wolf+sizeof(wolf)/sizeof(int)), vector <int>(fox, fox+sizeof(fox)/sizeof(int)), k); break;
			}
			case 4:
			{
				int wolf[] = {2};
				int fox[] = {1};
				int k = 0;
				int __expected[] = {0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(vector <int>(wolf, wolf+sizeof(wolf)/sizeof(int)), vector <int>(fox, fox+sizeof(fox)/sizeof(int)), k); break;
			}
			/*case 5:
			{
				int wolf[] = ;
				int fox[] = ;
				int k = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(vector <int>(wolf, wolf+sizeof(wolf)/sizeof(int)), vector <int>(fox, fox+sizeof(fox)/sizeof(int)), k); break;
			}*/
			/*case 6:
			{
				int wolf[] = ;
				int fox[] = ;
				int k = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(vector <int>(wolf, wolf+sizeof(wolf)/sizeof(int)), vector <int>(fox, fox+sizeof(fox)/sizeof(int)), k); break;
			}*/
			/*case 7:
			{
				int wolf[] = ;
				int fox[] = ;
				int k = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(vector <int>(wolf, wolf+sizeof(wolf)/sizeof(int)), vector <int>(fox, fox+sizeof(fox)/sizeof(int)), k); break;
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
