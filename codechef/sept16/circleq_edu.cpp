#include <bits/stdc++.h>
#define st first
#define nd second
#define MAXX 50200
#define MAXR 50
#define BIAS 70
#define PI 3.1415926535897932384626L
using namespace std;
typedef pair<long double,pair<long double,int> > pddi;
 
int n,q;
int X[50010],Y[50010],R[50010];
int X1[100010],Y1[100010],X2[100010],Y2[100010];
long double ans[100010];
 
struct point
{
    bool isQuery;
    int x,y,id;
    long double v;
    
    bool operator < (const point &a)
    {
        if(x != a.x) return x<a.x;
        if(y != a.y) return y<a.y;
        return !isQuery && a.isQuery;
    }
};
vector<point> lst;
long double tree[MAXX];
 
vector<pddi> cutX[55][MAXX],cutY[55][MAXX];
 
void add(int pos,long double v)
{
    for(;pos<MAXX;pos+=pos&(-pos)) tree[pos] += v;
}
 
long double query(int pos)
{
    long double ret = 0;
    for(;pos;pos-=pos&(-pos)) ret += tree[pos];
    return ret;
}
 
long double calcArc(int i,int r)
{
    long double theta = acos(1.0*abs(i)/r)*2;
    if(i < 0) return 0.5*theta*r*r + i*sqrt(r*r-i*i);
    return PI*r*r - 0.5*theta*r*r + i*sqrt(r*r-i*i);
}
 
long double calcCorner(int x,int y,int id)
{
    long double x0,y0,l,theta,ret = 0;
    if((X[id]-x)*(X[id]-x)+(Y[id]-y)*(Y[id]-y) < R[id]*R[id])
    {
        x0 = X[id] - sqrt(R[id]*R[id]-(Y[id]-y)*(Y[id]-y));
        y0 = Y[id] - sqrt(R[id]*R[id]-(X[id]-x)*(X[id]-x));
        
        ret += 0.5*(x-x0)*(y-y0);
        l = sqrt((x-x0)*(x-x0)+(y-y0)*(y-y0))/2;
        theta = asin(l/R[id])*2;
        ret += 0.5*theta*R[id]*R[id] - l*sqrt(R[id]*R[id]-l*l);
    }
    else
    {
        if(x<X[id] && y<Y[id]) ret = 0;
        else if(x<X[id] && y>=Y[id]) ret = calcArc(x-X[id],R[id]);
        else if(x>=X[id] && y<Y[id]) ret = calcArc(y-Y[id],R[id]);
        else ret = PI*R[id]*R[id] - calcArc(X[id]-x,R[id]) - calcArc(Y[id]-y,R[id]);
    }
    return ret;
}
 
void preCircle(int id)
{
    int i,x = X[id],y = Y[id],r = R[id];
    long double S;
    for(i=-r+1;i<r;i++)
    {
        S = calcArc(i,r);
        cutX[r][x+i].push_back(pddi(y+r,make_pair(S,id)));
        cutY[r][y+i].push_back(pddi(x+r,make_pair(S,id)));
    }
    
    point cir;
    cir.isQuery = false;
    cir.x = x+r; cir.y = y+r; cir.v = PI*r*r;
    lst.push_back(cir);
}
 
void preCut()
{
    int i,j,k;
    for(i=1;i<=MAXR;i++) for(j=1;j<MAXX;j++)
    {
        sort(cutX[i][j].begin(),cutX[i][j].end());
        for(k=1;k<cutX[i][j].size();k++) cutX[i][j][k].nd.st += cutX[i][j][k-1].nd.st;
        sort(cutY[i][j].begin(),cutY[i][j].end());
        for(k=1;k<cutY[i][j].size();k++) cutY[i][j][k].nd.st += cutY[i][j][k-1].nd.st;
    }
}
 
void preQuery(int x,int y,int id,int v)
{
    point qry;
    qry.isQuery = true;
    qry.x = x; qry.y = y;
    qry.id = id; qry.v = v;
    lst.push_back(qry);
}
 
void workInner()
{
    int i;
    sort(lst.begin(),lst.end());
    for(i=0;i<lst.size();i++)
    {
        if(lst[i].isQuery) ans[lst[i].id] += lst[i].v*query(lst[i].y);
        else add(lst[i].y,lst[i].v);
    }
}
 
int find(const vector<pddi> &vec,int lim)
{
    int head = 0,tail = vec.size()-1,mid;
    if(tail == -1) return -1;
    while(head < tail)
    {
        mid = (head+tail+1)>>1;
        if(vec[mid].st <= lim) head = mid;
        else tail = mid-1;
    }
    return vec[head].st <= lim ? head : -1;
}
 
long double calcCut(int x,int y)
{
    int i,id;
    long double x0,y0,l,theta,ret = 0;
    
    for(i=1;i<=MAXR;i++)
    {
        id = find(cutX[i][x],y);
        if(id >= 0) ret += cutX[i][x][id].nd.st;
        id = find(cutY[i][y],x);
        if(id >= 0) ret += cutY[i][y][id].nd.st;
        
        if(id+1 == cutY[i][y].size()) continue;
        for(id++;id<cutY[i][y].size() && cutY[i][y][id].st<=x+i*2;id++) ret += calcCorner(x,y,cutY[i][y][id].nd.nd);
    }
    return ret;
}
 
void workCut()
{
    int i;
    for(i=1;i<=q;i++)
    {
        ans[i] += calcCut(X2[i],Y2[i]) + calcCut(X1[i],Y1[i]);
        ans[i] -= calcCut(X1[i],Y2[i]) + calcCut(X2[i],Y1[i]);
    }
}
 
int main()
{
    int i;
    scanf("%d%d",&n,&q);
    for(i=1;i<=n;i++)
    {
        scanf("%d%d%d",&X[i],&Y[i],&R[i]);
        X[i] += BIAS; Y[i] += BIAS;
        preCircle(i);
    }
    preCut();
    
    for(i=1;i<=q;i++)
    {
        scanf("%d%d%d%d",&X1[i],&Y1[i],&X2[i],&Y2[i]);
        X1[i] += BIAS; Y1[i] += BIAS; X2[i] += BIAS; Y2[i] += BIAS;
        preQuery(X2[i],Y2[i],i,1); preQuery(X1[i],Y1[i],i,1);
        preQuery(X1[i],Y2[i],i,-1); preQuery(X2[i],Y1[i],i,-1);
    }
    
    workInner();
    workCut();
    
    for(i=1;i<=q;i++) printf("%.15Lf\n",ans[i]);
    return 0;
}