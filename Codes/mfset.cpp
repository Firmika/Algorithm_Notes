#include <bits/stdc++.h>
using namespace std;
// 并查集封装模板
class MfSet {
    vector<int> fa;
    vector<int> rank;
    MfSet(int n) : fa(vector<int>(n,-1)),rank(vector<int>(n,1)) {
        for (int i=0; i<n; i++)
            fa[i] = i;
    }
    int Find(int x) {
        return fa[x] = fa[x]==x ? x : Find(fa[x]);
    }
    int Merge(int x,int y) {
        int fax = Find(x);
        int fay = Find(y);
        if (rank[fax]<=rank[fay])
            fa[x] = fay;
        else
            fa[fay] = fax;
        if (rank[fax]==rank[fay]&&fax!=fay)
            rank[fay]++;
    }
    bool IsRelavant(int x,int y) {
        return Find(x)==Find(y);
    }
};