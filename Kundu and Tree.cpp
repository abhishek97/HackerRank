#include <cstdio>
#include <algorithm>
#include<iostream>
#include<vector>
#include<climits>
#include <complex>
#include <iostream>
#include <valarray>
#include<cstring>
#include<queue>
#include<bitset>
#include<map>

using namespace std;

#define PB push_back
#define i64 long long
#define FOR(i,a,b) for(i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define SZ(v) ((v).size())
#define LD long double
#define VI vector<int>
#define VS vector<string>
#define VD vector<double>
#define VLD vector<LD>
#define MSET(x,y) memset((x),(y),sizeof(x))
#define SZOF(x) sizeof((x))
#define VVI vector< VI >


void prVectInt(VI vect)
{
    int i;
    REP(i,vect.size())
    {
        printf("%d\t",vect[i]);
    }

    printf("\n");
}


void prVectString(VS vect)
{
    int i;
    REP(i,vect.size())
    {
        printf("%s\t",vect[i].c_str());
    }

    printf("\n");
}


void arrayToVectorString(string *arr,VS &vect,int len)
{
    int i;

    REP(i,len)
    {
        vect.PB(arr[i]);
    }
}

void arrayToVectorInt(int *arr,VI &vect,int len)
{
    int i;

    REP(i,len)
    {
        vect.PB(arr[i]);
    }
}



int s_bitcount(unsigned int set1)
{
    int ret=0;

    ret=(set1&0x55555555) + ((set1>>1) & 0x55555555);
    ret=(ret&0x33333333) + ((ret>>2) & 0x33333333);
    ret=(ret&0x0F0F0F0F) + ((ret>>4) & 0x0F0F0F0F);
    ret=(ret&0x00FF00FF) + ((ret>>8) & 0x00FF00FF);
    ret=(ret&0x0000FFFF) + ((ret>>16));

    return ret;
}


#define MAXN 100001
#define MOD 1000000007


VI adj[MAXN];
bitset<MAXN> visited;
VI cts;
int n,nm1,ct;


void dfs(int node)
{
    ++ct;

    visited.set(node);
    int i,szz;

    szz=adj[node].size();

    REP(i,szz)
    {
        if(!visited.test(adj[node][i]))
        {
            dfs(adj[node][i]);
        }
    }

}

int main()
{
    freopen("Text/Kundu and Tree.txt","r",stdin);

    scanf("%d",&n);
    nm1=n-1;
    int i,j,k;
    int x,y,sz,sz1,sz2,sz3;
    char c;
    i64 c3=0,c2=0,c1=0;

    REP(i,nm1)
    {
        scanf("%d %d %c",&x,&y,&c);
        --x;
        --y;
        if(c=='b')
        {
            adj[x].PB(y);
            adj[y].PB(x);
        }
    }

    REP(i,n)
    {
        ct=0;

        if(!visited.test(i))
        {
            dfs(i);
            //cts.PB(ct);

            c3+=c2*ct;
            c3%=MOD;

            c2+=c1*ct;
            c2%=MOD;

            c1+=ct;
            c1%=MOD;
        }
    }

    printf("%lld\n",c3%MOD);

    return 0;
}

