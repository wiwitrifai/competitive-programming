#include <bits/stdc++.h>

using namespace std;

class ComponentsForever {
public:
	int countComponents(int n, vector <int> Xprefix, vector <int> Yprefix, int seed, int Xrange, int Yrange, int Llo, int Rhi) {
		
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
		cout << "Testing ComponentsForever (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1560390583;
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
		ComponentsForever _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 2;
				int Xprefix[] = {1,4};
				int Yprefix[] = {1,3};
				int seed = 1;
				int Xrange = 1;
				int Yrange = 1;
				int Llo = 1;
				int Rhi = 5;
				_expected = 2;
				_received = _obj.countComponents(n, vector <int>(Xprefix, Xprefix+sizeof(Xprefix)/sizeof(int)), vector <int>(Yprefix, Yprefix+sizeof(Yprefix)/sizeof(int)), seed, Xrange, Yrange, Llo, Rhi); break;
			}
			case 1:
			{
				int n = 2;
				int Xprefix[] = {1,3};
				int Yprefix[] = {1,3};
				int seed = 1;
				int Xrange = 1;
				int Yrange = 1;
				int Llo = 1;
				int Rhi = 5;
				_expected = 1;
				_received = _obj.countComponents(n, vector <int>(Xprefix, Xprefix+sizeof(Xprefix)/sizeof(int)), vector <int>(Yprefix, Yprefix+sizeof(Yprefix)/sizeof(int)), seed, Xrange, Yrange, Llo, Rhi); break;
			}
			case 2:
			{
				int n = 2;
				int Xprefix[] = {5,21232};
				int Yprefix[] = {6,123};
				int seed = 1;
				int Xrange = 1;
				int Yrange = 1;
				int Llo = 1;
				int Rhi = 5132;
				_expected = 2;
				_received = _obj.countComponents(n, vector <int>(Xprefix, Xprefix+sizeof(Xprefix)/sizeof(int)), vector <int>(Yprefix, Yprefix+sizeof(Yprefix)/sizeof(int)), seed, Xrange, Yrange, Llo, Rhi); break;
			}
			case 3:
			{
				int n = 18;
				int Xprefix[] = {16, 21, 33, 46, 10};
				int Yprefix[] = {22, 25, 46, 18, 8};
				int seed = 1253;
				int Xrange = 47;
				int Yrange = 31;
				int Llo = 12;
				int Rhi = 86;
				_expected = 394234239;
				_received = _obj.countComponents(n, vector <int>(Xprefix, Xprefix+sizeof(Xprefix)/sizeof(int)), vector <int>(Yprefix, Yprefix+sizeof(Yprefix)/sizeof(int)), seed, Xrange, Yrange, Llo, Rhi); break;
			}
			case 4:
			{
				int n = 9;
				int Xprefix[] = {28, 33, 6, 14, 20, 35, 49, 15, 46};
				int Yprefix[] = {48, 32, 11, 28, 1, 22, 24, 41, 1};
				int seed = 1522;
				int Xrange = 9;
				int Yrange = 35;
				int Llo = 18;
				int Rhi = 55;
				_expected = 512091044;
				_received = _obj.countComponents(n, vector <int>(Xprefix, Xprefix+sizeof(Xprefix)/sizeof(int)), vector <int>(Yprefix, Yprefix+sizeof(Yprefix)/sizeof(int)), seed, Xrange, Yrange, Llo, Rhi); break;
			}
			case 5:
			{
				int n = 70874;
				int Xprefix[] = {};
				int Yprefix[] = {};
				int seed = 477403840;
				int Xrange = 153268855;
				int Yrange = 153409203;
				int Llo = 523210;
				int Rhi = 465494481;
				_expected = 248460139;
				_received = _obj.countComponents(n, vector <int>(Xprefix, Xprefix+sizeof(Xprefix)/sizeof(int)), vector <int>(Yprefix, Yprefix+sizeof(Yprefix)/sizeof(int)), seed, Xrange, Yrange, Llo, Rhi); break;
			}
			/*case 6:
			{
				int n = ;
				int Xprefix[] = ;
				int Yprefix[] = ;
				int seed = ;
				int Xrange = ;
				int Yrange = ;
				int Llo = ;
				int Rhi = ;
				_expected = ;
				_received = _obj.countComponents(n, vector <int>(Xprefix, Xprefix+sizeof(Xprefix)/sizeof(int)), vector <int>(Yprefix, Yprefix+sizeof(Yprefix)/sizeof(int)), seed, Xrange, Yrange, Llo, Rhi); break;
			}*/
			/*case 7:
			{
				int n = ;
				int Xprefix[] = ;
				int Yprefix[] = ;
				int seed = ;
				int Xrange = ;
				int Yrange = ;
				int Llo = ;
				int Rhi = ;
				_expected = ;
				_received = _obj.countComponents(n, vector <int>(Xprefix, Xprefix+sizeof(Xprefix)/sizeof(int)), vector <int>(Yprefix, Yprefix+sizeof(Yprefix)/sizeof(int)), seed, Xrange, Yrange, Llo, Rhi); break;
			}*/
			/*case 8:
			{
				int n = ;
				int Xprefix[] = ;
				int Yprefix[] = ;
				int seed = ;
				int Xrange = ;
				int Yrange = ;
				int Llo = ;
				int Rhi = ;
				_expected = ;
				_received = _obj.countComponents(n, vector <int>(Xprefix, Xprefix+sizeof(Xprefix)/sizeof(int)), vector <int>(Yprefix, Yprefix+sizeof(Yprefix)/sizeof(int)), seed, Xrange, Yrange, Llo, Rhi); break;
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
