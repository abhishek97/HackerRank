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



int main()
{
    freopen("Text/Above Average.txt","r",stdin);

    int cases;
    int n;

    scanf("%d",&cases);

    int arr[101];
    int ct=0,all_sum;

    while(cases--)
    {
        ct=0;
        all_sum=0;

        scanf("%d",&n);

        for(int i=0;i<n;++i)
        {
            scanf("%d",arr+i);
            all_sum+=arr[i];
        }

        for(int i=0;i<n;++i)
        {
            if(all_sum<arr[i]*n)
            {
                ++ct;
            }
        }

        printf("%d\n",ct);
    }


    return 0;
}


