#include <bits/stdc++.h>

using namespace std;

int fix;
vector<int> ans;
void revers(vector<int> & v, int l, int r) {
	ans.push_back(l);
	ans.push_back(r+1);
	while (l < r) {
		swap(v[l], v[r]);
		++l;
		--r;
	}
	assert(v[fix] == fix);
}

ostream& operator<<(ostream& os, vector<int> v) {
	os << "{";
	for (int i = 0; i < v.size(); ++i) {
		if (i)
			os << ",";
		os << v[i];
	}
	return os << "}";
}

class FixedPointReversals {
public:
	vector <int> sort(vector <int> A, int fixed) {
		fix = fixed;
		vector<int> B = A;
		::sort(B.begin(), B.end());
		if (B[fixed] != A[fixed])
			return {-1};
		int n = A.size();
		vector<bool> used(n, false);
		used[fixed] = 1;
		A[fixed] = fixed;
		for (int i = 0; i < n; ++i) {
			if (i == fixed) continue;
			for (int j = 0; j < n; ++j) {
				if (used[j]) continue;
				if (B[j] != A[i]) continue;
				used[j] = 1;
				A[i] = j;
				break;
			}
		}
		int l = 0, r = fixed-1;
		while (l < r) {
			while (l < r && A[l] < fixed) ++l;
			while (l < r && A[r] > fixed) --r;
			if (l < r) {
				revers(A, l, r);
			}
		}
		l = fixed + 1, r = n-1;
		while (l < r) {
			while (l < r && A[l] < fixed) ++l;
			while (l < r && A[r] > fixed) --r;
			if (l < r) {
				revers(A, l, r);
			}
		}
		int cur = fixed-1;
		while (cur >= 0 && A[cur] > fixed) --cur;
		++cur;
		if (cur < fixed)
			revers(A, cur, fixed + (fixed - cur));
		for (int i = 0; i < n; ++i) {
			if (A[i] == i) continue;
			int pos = -1;
			for (int j = i+1; j < n; ++j) {
				if (A[j] == i) {
					pos = j;
					break;
				}
			}
			if (pos > i)
				revers(A, i, pos);
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
		cout << "Testing FixedPointReversals (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1566572410;
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
		FixedPointReversals _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			// case 0:
			// {
			// 	int A[] = {10, 20, 30, 40, 50};
			// 	int fixed = 2;
			// 	int __expected[] = { };
			// 	_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
			// 	_received = _obj.sort(vector <int>(A, A+sizeof(A)/sizeof(int)), fixed); break;
			// }
			// case 1:
			// {
			// 	int A[] = {10, 20, 40, 30, 50};
			// 	int fixed = 2;
			// 	int __expected[] = {-1 };
			// 	_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
			// 	_received = _obj.sort(vector <int>(A, A+sizeof(A)/sizeof(int)), fixed); break;
			// }
			// case 2:
			// {
			// 	int A[] = {20, 10, 10, 10, 10, 10};
			// 	int fixed = 4;
			// 	int __expected[] = {0, 6 };
			// 	_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
			// 	_received = _obj.sort(vector <int>(A, A+sizeof(A)/sizeof(int)), fixed); break;
			// }
			// case 3:
			// {
			// 	int A[] = {1, 50, 40, 30, 20, 10};
			// 	int fixed = 0;
			// 	int __expected[] = {1, 6 };
			// 	_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
			// 	_received = _obj.sort(vector <int>(A, A+sizeof(A)/sizeof(int)), fixed); break;
			// }
			// case 4:
			// {
			// 	int A[] = {20, 10, 30, 50, 40};
			// 	int fixed = 2;
			// 	int __expected[] = {0, 2, 3, 5 };
			// 	_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
			// 	_received = _obj.sort(vector <int>(A, A+sizeof(A)/sizeof(int)), fixed); break;
			// }
			case 5:
			{
				int A[] = {41, 46, 33, 26, 21, 19, 32, 25, 21, 18, 25, 24, 50, 25, 35, 43, 48, 18, 27, 26, 31, 24, 26, 35, 47, 48, 46, 36, 43, 45, 28, 17, 44, 48, 48, 43, 38, 40, 36, 36, 42, 41, 19, 50, 34, 26, 46, 42, 23};
				int fixed = 27;
				int __expected[] = {43, 49, 7, 13, 7, 48, 8, 21, 8, 47, 33, 46, 10, 26, 10, 45, 35, 44, 35, 43, 11, 14, 13, 42, 14, 27, 14, 41, 1, 16, 15, 40, 29, 39, 35, 38, 34, 37, 28, 36, 20, 21, 20, 35, 4, 22, 21, 34, 5, 23, 22, 33, 1, 24, 23, 32, 0, 25, 24, 31, 23, 26, 25, 30, 24, 27, 26, 29, 4, 27, 8, 26, 3, 25, 3, 24, 13, 23, 17, 22, 17, 21, 0, 20, 16, 19, 12, 18, 9, 17, 10, 16, 13, 15, 2, 14, 9, 13, 7, 12, 7, 11, 2, 10, 4, 9, 6, 8, 2, 7, 1, 6, 2, 5, 0, 4, 0, 3, 0, 2};
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.sort(vector <int>(A, A+sizeof(A)/sizeof(int)), fixed); break;
			}
			/*case 6:
			{
				int A[] = ;
				int fixed = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.sort(vector <int>(A, A+sizeof(A)/sizeof(int)), fixed); break;
			}*/
			/*case 7:
			{
				int A[] = ;
				int fixed = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.sort(vector <int>(A, A+sizeof(A)/sizeof(int)), fixed); break;
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
