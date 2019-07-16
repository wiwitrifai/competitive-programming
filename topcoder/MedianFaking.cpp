#include <bits/stdc++.h>

using namespace std;

class MedianFaking {
public:
	vector <int> minimize(int F, int M, vector <int> data, int goal) {
		int pos = ((int)data.size() - 1) / 2;
		vector<pair<int, int>> cnt(F);
		int tl = 0, tm = 0;
		for (int i = 0; i < F; ++i) {
			int less = 0, more = 0;
			for (int j = 0; j < M; ++j) {
				int id = i * M + j;
				if (data[id] < goal)
					++less;
				else if (data[id] > goal)
					++more;
			}
			cnt[i] = {less, more};
			tl += less;
			tm += more;
		}
		int maxl = pos, maxm = (data).size() - pos - 1;
		int hapus = 0, org = 0;
		if (tl > maxl) {
			hapus = tl - maxl;
			sort(cnt.begin(), cnt.end(), [](pair<int, int> le, pair<int, int> ri) {
				return le.first > ri.first;
			});
			for (int i = 0; i < F && tl > maxl; ++i) {
				tl -= cnt[i].first;
				++org;
			}
		}
		else if (tm > maxm) {
			hapus = tm - maxm;
			sort(cnt.begin(), cnt.end(), [](pair<int, int> le, pair<int, int> ri) {
				return le.second > ri.second;
			});
			for (int i = 0; i < F && tm > maxm; ++i) {
				tm -= cnt[i].second;
				++org;
			}
		}
		return {org, hapus};
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
		cout << "Testing MedianFaking (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1559660408;
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
		MedianFaking _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int F = 5;
				int M = 5;
				int data[] = {1,2,3,4,5, 10,9,8,7,6, 25,24,23,22,21, 18,16,17,19,20, 11,13,12,14,15};
				int goal = 8;
				int __expected[] = {1, 5 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.minimize(F, M, vector <int>(data, data+sizeof(data)/sizeof(int)), goal); break;
			}
			case 1:
			{
				int F = 5;
				int M = 5;
				int data[] = {1,2,25,24,23, 3,4,22,21,20, 5,6,19,18,17, 7,16,15,14,13, 8,12,11,10,9};
				int goal = 8;
				int __expected[] = {2, 5 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.minimize(F, M, vector <int>(data, data+sizeof(data)/sizeof(int)), goal); break;
			}
			case 2:
			{
				int F = 1;
				int M = 4;
				int data[] = {10, 40, 30, 20};
				int goal = 20;
				int __expected[] = {0, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.minimize(F, M, vector <int>(data, data+sizeof(data)/sizeof(int)), goal); break;
			}
			case 3:
			{
				int F = 4;
				int M = 3;
				int data[] = {3,8,12, 3,8,12, 3,8,12, 8,12,17};
				int goal = 12;
				int __expected[] = {1, 2 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.minimize(F, M, vector <int>(data, data+sizeof(data)/sizeof(int)), goal); break;
			}
			case 4:
			{
				int F = 5;
				int M = 1;
				int data[] = {10, 20, 30, 40, 50};
				int goal = 23;
				int __expected[] = {1, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.minimize(F, M, vector <int>(data, data+sizeof(data)/sizeof(int)), goal); break;
			}
			/*case 5:
			{
				int F = ;
				int M = ;
				int data[] = ;
				int goal = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.minimize(F, M, vector <int>(data, data+sizeof(data)/sizeof(int)), goal); break;
			}*/
			/*case 6:
			{
				int F = ;
				int M = ;
				int data[] = ;
				int goal = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.minimize(F, M, vector <int>(data, data+sizeof(data)/sizeof(int)), goal); break;
			}*/
			/*case 7:
			{
				int F = ;
				int M = ;
				int data[] = ;
				int goal = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.minimize(F, M, vector <int>(data, data+sizeof(data)/sizeof(int)), goal); break;
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
