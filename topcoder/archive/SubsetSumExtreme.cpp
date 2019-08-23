#include <bits/stdc++.h>

using namespace std;

vector< int > b, f;
bool vis[1 << 12];
double dp[1 << 12];
double expect(int mask) {
	if (!mask)
		return 0;
	if (vis[mask])
		return dp[mask];
	double & ret = dp[mask];
	vis[mask] = 1;
	ret = 0;
	for (int c : f) {
		double cur = 1e10;
		bool suc = 0;
		for (int bit = mask; bit; bit = (bit-1) & mask) {
			int sum = 0;
			for (int j = 0; j < b.size(); j++) if (bit & (1<<j))
				sum += b[j];
			if (sum == c) {
				suc = 1;
				cur = min(cur, expect(mask ^ bit));
			}
		}
		if (!suc) {
			cur = 0;
			for (int j = 0; j < b.size(); j++) if (mask & (1<<j))
				cur += b[j];
		}
		ret += cur;
	}
	ret /= f.size();
	return ret;
}

class SubsetSumExtreme {
public:
	double getExpectation(vector <int> block, vector <int> face) {
		b = block;
		f = face;
		return expect((1<<b.size())-1);
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
		cout << "Testing SubsetSumExtreme (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1486971998;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		SubsetSumExtreme _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int block[] = {1,2,3};
				int face[] = {6,5};
				_expected = 0.5;
				_received = _obj.getExpectation(vector <int>(block, block+sizeof(block)/sizeof(int)), vector <int>(face, face+sizeof(face)/sizeof(int))); break;
			}
			case 1:
			{
				int block[] = {1,2,1}	;
				int face[] = {1,2};
				_expected = 0.5;
				_received = _obj.getExpectation(vector <int>(block, block+sizeof(block)/sizeof(int)), vector <int>(face, face+sizeof(face)/sizeof(int))); break;
			}
			case 2:
			{
				int block[] = {10,11,12};
				int face[] = {3,4,5,6};
				_expected = 33.0;
				_received = _obj.getExpectation(vector <int>(block, block+sizeof(block)/sizeof(int)), vector <int>(face, face+sizeof(face)/sizeof(int))); break;
			}
			case 3:
			{
				int block[] = {1,1,1,1};
				int face[] = {1};
				_expected = 0.0;
				_received = _obj.getExpectation(vector <int>(block, block+sizeof(block)/sizeof(int)), vector <int>(face, face+sizeof(face)/sizeof(int))); break;
			}
			case 4:
			{
				int block[] = {3,2,2,3};
				int face[] = {2,3,2,3,2,3};
				_expected = 2.1875;
				_received = _obj.getExpectation(vector <int>(block, block+sizeof(block)/sizeof(int)), vector <int>(face, face+sizeof(face)/sizeof(int))); break;
			}
			case 5:
			{
				int block[] = {968,423,592,419,321,253,62,42,12,32,2,4};
				int face[] = {968,423,592,419,321,253,62,42,12,32,2,4};
				_expected = 1996.9320680897076;
				_received = _obj.getExpectation(vector <int>(block, block+sizeof(block)/sizeof(int)), vector <int>(face, face+sizeof(face)/sizeof(int))); break;
			}
			case 6:
			{
				int block[] = {12,11,10,9,8,7,6,5,4,3,2,1};
				int face[] = {12,12,12,12,12,6,6,6,3,3,2,1};
				_expected = 40.03765576104895;
				_received = _obj.getExpectation(vector <int>(block, block+sizeof(block)/sizeof(int)), vector <int>(face, face+sizeof(face)/sizeof(int))); break;
			}
			/*case 7:
			{
				int block[] = ;
				int face[] = ;
				_expected = ;
				_received = _obj.getExpectation(vector <int>(block, block+sizeof(block)/sizeof(int)), vector <int>(face, face+sizeof(face)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int block[] = ;
				int face[] = ;
				_expected = ;
				_received = _obj.getExpectation(vector <int>(block, block+sizeof(block)/sizeof(int)), vector <int>(face, face+sizeof(face)/sizeof(int))); break;
			}*/
			/*case 9:
			{
				int block[] = ;
				int face[] = ;
				_expected = ;
				_received = _obj.getExpectation(vector <int>(block, block+sizeof(block)/sizeof(int)), vector <int>(face, face+sizeof(face)/sizeof(int))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
