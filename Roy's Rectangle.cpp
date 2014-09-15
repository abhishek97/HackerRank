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
    freopen("Text/Roy's Rectangle.txt","r",stdin);

    int cases;
    int x,y,x1,y1,x2,y2;

    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%d %d %d %d %d %d",&x,&y,&x1,&y1,&x2,&y2);

        printf("%d\n",min(abs(x-x1),min(abs(y-y1),min(abs(x-x2),abs(y-y2)))));
    }


    return 0;
}


