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

#define MAXN 131073


int main()
{
    freopen("Text/Mice V1.txt","r",stdin);

    int cases;

    scanf("%d",&cases);

    int mice[MAXN];
    int holes[MAXN];
    int ans=0;
    int n;

    while(cases--)
    {
        ans=0;

        scanf("%d",&n);

        for(int i=0;i<n;++i)
        {
            scanf("%d",mice+i);
        }

        for(int i=0;i<n;++i)
        {
            scanf("%d",holes+i);
        }

        sort(mice,mice+n);
        sort(holes,holes+n);

        for(int i=0;i<n;++i)
        {
            ans=max(ans,abs(mice[i]-holes[i]));
        }

        printf("%d\n",ans);
    }

    return 0;
}


