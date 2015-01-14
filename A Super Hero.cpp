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
#include<set>
#include<sstream>
#include<ctime>
#include <stack>
#include <iomanip>
#include <cassert>
#include<cmath>


using namespace std;


#define PB push_back
#define i64 long long
#define FOR(i,a,b) for(i=(a);i<(b);++i)
#define FORE(i,a,b) for(i=(a);i<=(b);++i)
#define REP(i,n) FOR(i,0,n)
#define REPE(i,n) FORE(i,0,n)
#define SZ(v) ((v).size())
#define LD long double
#define VI vector<int>
#define VS vector<string>
#define VD vector<double>
#define VLD vector<LD>
#define MSET(x,y) memset((x),(y),sizeof(x))
#define SZOF(x) sizeof((x))
#define VVI vector< VI >
#define PII pair< int,int >
#define VPII vector< PII >
#define MP make_pair
#define PIPII pair<int, PII >
#define PIPIPII pair< int, PIPII >
#define u64 unsigned i64
#define Vi64 vector<i64>
#define Vu64 vector<u64>

#define INF 99999999
#define MAXN 111
#define MAXM 555555
#define MAXP 1111
#define MM 111111

int arr[MAXN][MAXP];
int tarr[MAXN][MAXM];
int n,m;
int dp[MAXN][MAXP];
int ans;

void solve()
{
    ans=INF;
    MSET(dp,0x7f);
    int i,j;
    int k;

    for(i=1;i<MAXP;++i)
    {
        if(arr[0][i])
        {
            //printf("DD\n");
            dp[0][i]=i;
        }
    }

    for(i=1;i<n;++i)
    {
        for(j=1;j<MAXP;++j)
        {
            if(arr[i][j])
            {
                for(k=1;k<MAXP;++k)
                {
                    if(arr[i-1][k])
                    {
                        dp[i][j]=min(dp[i][j],dp[i-1][k]+max(0,j-arr[i-1][k]));
                    }
                }
            }
        }
    }

    for(i=1;i<MAXP;++i)
    {
        ans=min(ans,dp[n-1][i]);
    }

}

void MAIN()
{
    int cases;
    int i,j,ti;
    int l,r,midd;

    scanf("%d",&cases);
    //printf("%d\n",cases);
    while(cases--)
    {
        MSET(arr,0);
        scanf("%d %d",&n,&m);
        for(i=0;i<n;++i)
        {
            for(j=0;j<m;++j)
            {
                scanf("%d",&tarr[i][j]);
            }
        }

        for(i=0;i<n;++i)
        {
            for(j=0;j<m;++j)
            {
                scanf("%d",&ti);
                //printf("DD\t%d\n",ti);
                arr[i][tarr[i][j]]=max(arr[i][tarr[i][j]],ti);
            }
        }

        solve();
        printf("%d\n",ans);


    }

}

int main()
{
    freopen("Text/A Super Hero.txt","r",stdin);

    MAIN();
    return 0;
}




