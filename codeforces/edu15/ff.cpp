// copas from FatalEagele
// Using TREAP
#include <bits/stdc++.h>

using namespace std;

struct item
{
    int c, q;
    bool operator< (const item& other) const
    {
        if(q!=other.q)
            return q>other.q;
        return c<other.c;
    }
} A[200000];

int N, M;
int ans[200000];

struct node
{
    node *left, *right;
    unsigned int pri;
    int val, lazyVal;
    int sum, lazySum, i;
};

unsigned int genPri()
{
    unsigned int x=rand();
    unsigned int y=rand();
    return (x<<16)|y;
}

node* reassign(node *n, node *l, node *r, unsigned int pri, int val, int sum, int i)
{
    n->left=l;
    n->right=r;
    n->pri=pri;
    n->val=val;
    n->lazyVal=0;
    n->sum=sum;
    n->lazySum=0;
    n->i=i;
    return n;
}

node* reassign(node *n, node *l, node *r)
{
    return reassign(n, l, r, n->pri, n->val, n->sum, n->i);
}

void apply(node *n, int lazyVal, int lazySum)
{
    n->val+=lazyVal;
    n->lazyVal+=lazyVal;
    n->sum+=lazySum;
    n->lazySum+=lazySum;
}

void down(node *n)
{
    if(n->left)
        apply(n->left, n->lazyVal, n->lazySum);
    if(n->right)
        apply(n->right, n->lazyVal, n->lazySum);
    n->lazyVal=0;
    n->lazySum=0;
}

node* getLeft(node *n)
{
    while(n->left)
    {
        down(n);
        n=n->left;
    }
    return n;
}

node* getRight(node *n)
{
    while(n->right)
    {
        down(n);
        n=n->right;
    }
    return n;
}

// {<, >=}
pair<node*, node*> split(node *n, int k)
{
    if(!n)
        return {nullptr, nullptr};
    down(n);
    node *l, *r;
    if(n->val<k)
    {
        tie(l, r)=split(n->right, k);
        reassign(n, n->left, l);
        return {n, r};
    }
    tie(l, r)=split(n->left, k);
    reassign(n, r, n->right);
    return {l, n};
}

// all l <= r
node* merge(node *l, node *r)
{
    if(!l)
        return r;
    if(!r)
        return l;
    down(l);
    down(r);
    if(l->pri<r->pri)
        return reassign(l, l->left, merge(l->right, r));
    return reassign(r, merge(l, r->left), r->right);
}

node* ins(node *root, node *n)
{
    node *l, *r;
    tie(l, r)=split(root, n->val);
    return merge(l, merge(n, r));
}

void traverse(node *n)
{
    if(!n)
        return;
    down(n);
    ans[n->i]=n->sum;
    traverse(n->left);
    traverse(n->right);
}

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d%d", &A[i].c, &A[i].q);
    sort(A, A+N);
    scanf("%d", &M);
    node *root=nullptr;
    for(int i=0; i<M; i++)
    {
        int a;
        scanf("%d", &a);
        node *n=reassign(new node(), nullptr, nullptr, genPri(), a, 0, i);
        if(!root)
            root=n;
        else
            root=ins(root, n);
    }
    for(int i=0; i<N; i++)
    {
        int c=A[i].c;
        node *l, *r;
        tie(l, r)=split(root, c);
        if(!r)
            continue;
        apply(r, -c, 1);
        if(!l)
        {
            root=r;
            continue;
        }
        node *rl=getLeft(r), *lr=getRight(l);
        while(rl->val<lr->val)
        {
            node *tl, *tr;
            tie(tl, tr)=split(r, rl->val+1);
            l=ins(l, tl);
            r=tr;
            if(!l || !r)
                break;
            rl=getLeft(r);
            lr=getRight(l);
        }
        root=merge(l, r);
    }
    traverse(root);
    for(int i=0; i<M; i++)
        printf("%d\n", ans[i]);
    return 0;
}