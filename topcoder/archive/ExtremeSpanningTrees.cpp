#include <bits/stdc++.h>

using namespace std;

class ExtremeSpanningTrees {
public:
	long long minTime(vector <int> a, vector <int> b, vector <int> w, vector <int> m1, vector <int> m2) {
		
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
		cout << "Testing ExtremeSpanningTrees (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1503575366;
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
		ExtremeSpanningTrees _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int a[] = {0,1,2,3,4};
				int b[] = {1,2,3,4,0};
				int w[] = {6,1,2,4,9};
				int m1[] = {1,0,3,2};
				int m2[] = {3,1,2,0};
				_expected = 12LL;
				_received = _obj.minTime(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(w, w+sizeof(w)/sizeof(int)), vector <int>(m1, m1+sizeof(m1)/sizeof(int)), vector <int>(m2, m2+sizeof(m2)/sizeof(int))); break;
			}
			case 1:
			{
				int a[] = {0,1,2,3,4};
				int b[] = {1,2,3,4,0};
				int w[] = {1000000000, 1, 50000, 230, 78778878};
				int m1[] = {1,2,3,4};
				int m2[] = {0,1,2,4};
				_expected = 229LL;
				_received = _obj.minTime(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(w, w+sizeof(w)/sizeof(int)), vector <int>(m1, m1+sizeof(m1)/sizeof(int)), vector <int>(m2, m2+sizeof(m2)/sizeof(int))); break;
			}
			case 2:
			{
				int a[] = {2, 3, 2, 1, 4, 3, 1, 2};
				int b[] = {4, 0, 1, 0, 0, 4, 3, 0};
				int w[] = {35, 69, 83, 48, 23, 77, 18, 75};
				int m1[] = {7, 2, 4, 6};
				int m2[] = {6, 0, 3, 5};
				_expected = 126LL;
				_received = _obj.minTime(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(w, w+sizeof(w)/sizeof(int)), vector <int>(m1, m1+sizeof(m1)/sizeof(int)), vector <int>(m2, m2+sizeof(m2)/sizeof(int))); break;
			}
			case 3:
			{
				int a[] = {18, 10, 7, 20, 25, 16, 0, 25, 1, 1, 18, 5, 21, 29, 0,
				          19, 27, 5, 5, 2, 5, 14, 24, 28, 17, 17, 13, 28, 29, 21,
				          27, 14, 3, 4, 0, 6, 7, 2, 19, 22, 1, 15, 28, 28, 22, 4,
				          18, 27, 25, 25, 16, 26, 14, 24, 28, 23, 23, 2, 7, 25, 27,
				          28, 24, 21, 3, 1, 4, 4, 23, 21};
				int b[] = {26, 1, 0, 25, 6, 7, 19, 10, 3, 25, 19, 28, 24, 10, 10,
				          1, 4, 21, 2, 13, 11, 9, 23, 27, 22, 25, 16, 25, 3, 3, 23,
				          21, 20, 25, 5, 27, 12, 10, 10, 9, 13, 8, 22, 29, 16, 21,
				          0, 8, 8, 11, 20, 29, 13, 7, 20, 11, 5, 3, 6, 22, 2, 21,
				          16, 18, 0, 24, 2, 15, 16, 23};
				int w[] = {178550173, 70889251, 552583494, 693530287, 913018412,
				          813354729, 22559015, 790019960, 417638821, 350031148,
				          342183709, 546736964, 846258018, 288707281, 910585230,
				          217659326, 472037330, 407441317, 869355814, 510462471,
				          495766436, 645229822, 817030, 843038598, 814619628, 144969408,
				          832500308, 150645645, 400781547, 266132945, 112756643,
				          991866897, 166797713, 408918210, 192114032, 765168046,
				          69601053, 422959288, 206902656, 71012802, 520439340, 779668518,
				          457709439, 792537906, 212760134, 200551833, 511130875,
				          811123320, 772309593, 734005608, 802837429, 982498923,
				          335250225, 43356697,621725643, 161179558, 278880928, 88948197,
				          77554027, 686360474, 851408784, 777256397, 279272225, 856462366,
				          912791986, 518766837, 430982430, 985439708, 307712218, 659114756};
				int m1[] = {60, 44, 62, 66, 0, 34, 69, 1, 17, 40, 65, 6, 30, 21, 50, 8,
				           10, 37, 41, 23, 9, 39, 36, 35, 58, 48, 28, 24, 20};
				int m2[] = {20, 12, 29, 23, 26, 10, 55, 58, 53, 40, 24, 50, 15, 11, 35,
				           48, 43, 63, 60, 39, 59, 46, 7, 42, 52, 41, 51, 36, 67};
				_expected = 11341657393LL;
				_received = _obj.minTime(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(w, w+sizeof(w)/sizeof(int)), vector <int>(m1, m1+sizeof(m1)/sizeof(int)), vector <int>(m2, m2+sizeof(m2)/sizeof(int))); break;
			}
			case 4:
			{
				int a[] = {0};
				int b[] = {1};
				int w[] = {123456789};
				int m1[] = {0};
				int m2[] = {0};
				_expected = 0LL;
				_received = _obj.minTime(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(w, w+sizeof(w)/sizeof(int)), vector <int>(m1, m1+sizeof(m1)/sizeof(int)), vector <int>(m2, m2+sizeof(m2)/sizeof(int))); break;
			}
			/*case 5:
			{
				int a[] = ;
				int b[] = ;
				int w[] = ;
				int m1[] = ;
				int m2[] = ;
				_expected = LL;
				_received = _obj.minTime(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(w, w+sizeof(w)/sizeof(int)), vector <int>(m1, m1+sizeof(m1)/sizeof(int)), vector <int>(m2, m2+sizeof(m2)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int a[] = ;
				int b[] = ;
				int w[] = ;
				int m1[] = ;
				int m2[] = ;
				_expected = LL;
				_received = _obj.minTime(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(w, w+sizeof(w)/sizeof(int)), vector <int>(m1, m1+sizeof(m1)/sizeof(int)), vector <int>(m2, m2+sizeof(m2)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int a[] = ;
				int b[] = ;
				int w[] = ;
				int m1[] = ;
				int m2[] = ;
				_expected = LL;
				_received = _obj.minTime(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(w, w+sizeof(w)/sizeof(int)), vector <int>(m1, m1+sizeof(m1)/sizeof(int)), vector <int>(m2, m2+sizeof(m2)/sizeof(int))); break;
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
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
