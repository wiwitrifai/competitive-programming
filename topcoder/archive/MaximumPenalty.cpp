#include <bits/stdc++.h>

using namespace std;

class MaximumPenalty {
public:
	vector <int> schedule(vector <int> L, vector <int> P) {
		int n = L.size();
		auto get = [&](int id, int t) {
			int offset = id * 4;
			long long ret = 0;
			for (int i = 3; i >= 0; --i) {
				ret = ret * t + P[offset + i];
			}
			return ret;
		};
		int sum = 0;
		for (int x : L)
			sum += x;
		auto get_t = [&](int id, long long val) {
			int low = 0, hig = sum;
			while (low < hig) {
				int mid = low + ((hig-low+1) >> 1);
				if (get(id, mid) > val)
					hig = mid - 1;
				else
					low = mid;
			}
			return low;
		};
		long long low = 0, hig = 0;
		for (int i = 0; i < n; ++i) {
			low = max(low, get(i, 0));
			hig = max(hig, get(i, sum));
		}
		vector<pair<int, int>> events(n);
		while (low < hig) {
			long long mid = low + ((hig-low) >> 1);
			for (int i = 0; i < n; ++i) {
				events[i] = make_pair(get_t(i, mid), i);
			}
			sort(events.begin(), events.end());
			int now = 0;
			bool ok = true;
			for (int i = 0; i < n; ++i) {
				now += L[events[i].second];
				if (now > events[i].first) {
					ok = false;
				}
			}
			if (ok)
				hig = mid;
			else
				low = mid + 1;
		}
		for (int i = 0; i < n; ++i) {
			events[i] = make_pair(get_t(i, low), i);
		}
		sort(events.begin(), events.end());
		vector<int> ans(n);
		for (int i = 0; i < n; ++i)
			ans[i] = events[i].second;
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
		cout << "Testing MaximumPenalty (550.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1613237356;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 550.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		MaximumPenalty _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int L[] = {7, 4, 1};
				int P[] = {0, 0, 0, 1,
				           0, 0, 2, 0,
				           0, 3, 0, 0};
				int __expected[] = {0, 2, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.schedule(vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(P, P+sizeof(P)/sizeof(int))); break;
			}
			case 1:
			{
				int L[] = {7, 4, 2, 5};
				int P[] = {47, 0, 0, 0,
				           47, 0, 0, 0,
				           47, 0, 0, 0,
				           47, 0, 0, 0};
				int __expected[] = {3, 2, 1, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.schedule(vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(P, P+sizeof(P)/sizeof(int))); break;
			}
			case 2:
			{
				int L[] = {7, 4, 2, 5};
				int P[] = {0, 47, 0, 0,
				           0, 47, 0, 0,
				           0, 47, 0, 0,
				           0, 47, 0, 0};
				int __expected[] = {3, 2, 1, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.schedule(vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(P, P+sizeof(P)/sizeof(int))); break;
			}
			case 3:
			{
				int L[] = {7, 4, 2, 5};
				int P[] = {0, 7, 8,  15,
				           1, 6, 9,  14,
				           2, 5, 10, 13,
				           3, 4, 11, 12};
				int __expected[] = {0, 1, 2, 3 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.schedule(vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(P, P+sizeof(P)/sizeof(int))); break;
			}
			/*case 4:
			{
				int L[] = ;
				int P[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.schedule(vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(P, P+sizeof(P)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int L[] = ;
				int P[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.schedule(vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(P, P+sizeof(P)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int L[] = ;
				int P[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.schedule(vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(P, P+sizeof(P)/sizeof(int))); break;
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
