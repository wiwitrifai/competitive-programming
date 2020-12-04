#include <bits/stdc++.h>

using namespace std;

class IncreasingJumpsDiv1 {
public:
	vector <int> jump(vector <int> frogs) {
		int n = frogs.size();
		vector<pair<int, int>> tmp;
		for (int i = 0; i < n; ++i) {
			tmp.emplace_back(frogs[i], i);
		}
		sort(tmp.begin(), tmp.end());
		int step = 1;
		vector<int> ret;
		for (int i = 0; i < n; ++i) {
			int id = tmp[i].second;
			// ret.push_back((id+1));
			frogs[id] += i;
			// ++step;
		}
		int pivot = *min_element(frogs.begin(), frogs.end()), maxi = *max_element(frogs.begin(), frogs.end());
		int best = maxi - pivot;
		for (int i = pivot; i <= maxi; ++i) {
			set<int> st;
			bool ok = true;
			for (int j = 0; j < n; ++j) {
				int diff = abs(i - frogs[j]);
				if (st.count(diff)) {
					ok = false;
					break;
				}
				st.insert(diff);
			}
			if (!ok) continue;
			int cur = *st.rbegin();
			if (cur < best) {
				best = cur;
				pivot = i;
			}
		}
		vector<pair<int, int>> pp;
		for (int i = 0; i < n; ++i) {
			int diff = abs(pivot - frogs[i]);
			pp.emplace_back(diff, i);
		}
		sort(pp.begin(), pp.end());
		int x = pp.back().second;
		for (int i = 0; i < n-1; ++i) {
			if (pp[i].first == 0) continue;
			while (step < pp[i].first) {
				int diff = abs(frogs[x] - pivot);
				int sign = -1;
				if (diff * 2 >= step) {
					if (frogs[x] < pivot)
						sign = +1;
				} else {
					if (frogs[x] > pivot)
						sign = +1;
				}
				frogs[x] += sign * step;
				++step;
				ret.push_back(sign * (x+1));
			}
			int now = pp[i].second;
			int sign = + 1;
			if (frogs[now] > pivot) {
				sign = -1;
			}
			frogs[now] += sign * step;
			ret.emplace_back(sign * (now + 1));
			++step;
		}
		while (frogs[x] != pivot) {
			int diff = abs(frogs[x] - pivot);
			int sign = -1;
			if (diff * 2 >= step) {
				if (frogs[x] < pivot)
					sign = +1;
			} else {
				if (frogs[x] > pivot)
					sign = +1;
			}
			frogs[x] += sign * step;
			++step;
			ret.push_back(sign * (x+1));			
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
		cout << "Testing IncreasingJumpsDiv1 (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1603452979;
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
		IncreasingJumpsDiv1 _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int frogs[] = {5, 6, 1, 9, 8};
				int __expected[] = {3, 3, 3 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.jump(vector <int>(frogs, frogs+sizeof(frogs)/sizeof(int))); break;
			}
			case 1:
			{
				int frogs[] = {0, 0, 1, 0};
				int __expected[] = {-2, 4 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.jump(vector <int>(frogs, frogs+sizeof(frogs)/sizeof(int))); break;
			}
			case 2:
			{
				int frogs[] = {0, 35};
				int __expected[] = {1, 1, 1, 1, 1, 1, -2, -2 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.jump(vector <int>(frogs, frogs+sizeof(frogs)/sizeof(int))); break;
			}
			case 3:
			{
				int frogs[] = {4, 7, 3, 9, 5, 6, 10, 8};
				int __expected[] = {3, 3, -3 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.jump(vector <int>(frogs, frogs+sizeof(frogs)/sizeof(int))); break;
			}
			/*case 4:
			{
				int frogs[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.jump(vector <int>(frogs, frogs+sizeof(frogs)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int frogs[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.jump(vector <int>(frogs, frogs+sizeof(frogs)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int frogs[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.jump(vector <int>(frogs, frogs+sizeof(frogs)/sizeof(int))); break;
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
