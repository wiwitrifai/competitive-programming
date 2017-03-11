#include <bits/stdc++.h>

using namespace std;

int moveA(vector< int > & a, int id) {
	int now = a[id];
	a[id] = 0;
	while (now--) {
		id++;
		if (id >= a.size())
			id -= a.size();
		a[id]++;
	}
	return id;
}
int moveB(vector < int > &a, int id) {
	int now = 0;
	while (a[id] > 0) {
		a[id]--;
		now++;
		id--;
		if (id < 0) id += a.size();
	}
	a[id] += now;
	return id;
}

void debug(vector< int > now) {
		for (int i = 0; i < now.size(); i++)
			cerr << now[i] << " ";
		cerr << endl;
}

vector< int > process(vector<int> v, bool rev) {
	vector< int > ans;
	bool ok = 1;
	while (ok) {
		ok = 0;
		for (int i = 0; i + 1 < v.size(); i++)
			if (v[i] > 0) {
				int id = moveA(v, i);
				ans.push_back(rev ? id + v.size() : i);
				ok = 1;
			}

	}
	return ans;
}

class ReverseMancala {
public:
	vector <int> findMoves(vector <int> start, vector <int> target) {
		vector< int > res1 = process(start, 0), res2 = process(target, 1);
		reverse(res2.begin(), res2.end());
		res1.insert(res1.end(), res2.begin(), res2.end());
		return res1;
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
		cout << "Testing ReverseMancala (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1489111216;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 300.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		ReverseMancala _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int start[] = {6, 3, 4, 0};
				int target[] = {1, 5, 6, 1};
				int __expected[] = {0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findMoves(vector <int>(start, start+sizeof(start)/sizeof(int)), vector <int>(target, target+sizeof(target)/sizeof(int))); break;
			}
			case 1:
			{
				int start[] = {1, 5, 6, 1};
				int target[] = {6, 3, 4, 0};
				int __expected[] = {6 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findMoves(vector <int>(start, start+sizeof(start)/sizeof(int)), vector <int>(target, target+sizeof(target)/sizeof(int))); break;
			}
			case 2:
			{
				int start[] = {10, 0, 1, 2, 3};
				int target[] = {10, 0, 0, 2, 4};
				int __expected[] = {2, 4, 8 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findMoves(vector <int>(start, start+sizeof(start)/sizeof(int)), vector <int>(target, target+sizeof(target)/sizeof(int))); break;
			}
			case 3:
			{
				int start[] = {2, 0, 1, 7};
				int target[] = {0, 2, 1, 7};
				int __expected[] = {2, 0, 1, 7 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findMoves(vector <int>(start, start+sizeof(start)/sizeof(int)), vector <int>(target, target+sizeof(target)/sizeof(int))); break;
			}
			case 4:
			{
				int start[] = {3, 2, 4, 5};
				int target[] = {0, 1, 6, 7};
				int __expected[] = {7, 1, 0, 7, 1, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findMoves(vector <int>(start, start+sizeof(start)/sizeof(int)), vector <int>(target, target+sizeof(target)/sizeof(int))); break;
			}
			case 5:
			{
				int start[] = {2, 1, 6, 4, 5, 2, 4, 5, 3, 0};
				int target[] = {6, 4, 8, 0, 2, 6, 0, 1, 3, 2};
				int __expected[] = {10, 8, 2, 16, 19, 2, 4, 11, 7, 6, 12, 19, 14, 14, 15, 3, 4, 17, 11, 3, 9, 16, 4, 8, 13, 12, 11, 9, 17, 12, 19, 4, 9, 8, 10, 2, 0, 17, 10, 3, 4, 8, 16, 0, 19, 15, 7, 6, 17, 6 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findMoves(vector <int>(start, start+sizeof(start)/sizeof(int)), vector <int>(target, target+sizeof(target)/sizeof(int))); break;
			}
			case 6:
			{
				int start[] = {3, 4, 6, 7, 2, 2, 3, 9, 4, 6};
				int target[] = {6, 0, 5, 10, 10, 3, 1, 2, 8, 1};
				int __expected[] = {8, 14, 1, 12, 11, 4, 9, 10, 15, 16, 2, 19, 2, 16, 17, 11, 16, 0, 12, 7, 4, 5, 17, 14, 0, 5, 13, 3, 7, 10, 12, 1, 16, 14, 1, 9, 1, 8, 7, 5, 5, 11, 19, 16, 18, 1, 15, 10, 16, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findMoves(vector <int>(start, start+sizeof(start)/sizeof(int)), vector <int>(target, target+sizeof(target)/sizeof(int))); break;
			}
			/*case 7:
			{
				int start[] = ;
				int target[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findMoves(vector <int>(start, start+sizeof(start)/sizeof(int)), vector <int>(target, target+sizeof(target)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int start[] = ;
				int target[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findMoves(vector <int>(start, start+sizeof(start)/sizeof(int)), vector <int>(target, target+sizeof(target)/sizeof(int))); break;
			}*/
			/*case 9:
			{
				int start[] = ;
				int target[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findMoves(vector <int>(start, start+sizeof(start)/sizeof(int)), vector <int>(target, target+sizeof(target)/sizeof(int))); break;
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
