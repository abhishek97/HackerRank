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


#define gc getchar
//#define gc getchar_unlocked

inline int readPosInt()
{
    int ret=0;
    char c;
    c=gc();

    while(c<'0' || c>'9')
    {
        //scanf("%c",&c);
        c=gc();
    }

    while(c>='0' && c<='9')
    {
        ret=ret*10+(c-'0');
        c=gc();
    }

    return ret;
}

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



int main()
{
    freopen("Text/Find the Minima of AND.txt","r",stdin);

    int cases,n;

    unsigned i64 ret,tll;

    scanf("%d",&cases);

    while(cases--)
    {
        ret=(1<<64)-1;
        //printf("%llu\n",ret);
        scanf("%d",&n);
        while(n--)
        {
            scanf("%llu",&tll);
            ret&=tll;
        }

        printf("%lld\n",ret);
    }


    return 0;
}

