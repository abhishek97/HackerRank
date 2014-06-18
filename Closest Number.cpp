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


#define MOD 1234567891
VVI cache;
int n;

class TheCardLineDivTwo
{
    VS cards;


    bool red(int card)
    {
        char suit=cards[card][1];

        return suit=='H' || suit=='D';
    }

    bool compatible(int card1,int card2)
    {
        char rank1=cards[card1][0];
        char rank2=cards[card2][0];

        return rank1==rank2 || red(card1)==red(card2);
    }

    int recurse(int last,int valid)
    {
        if(cache[last][valid]!=-1)
        {
            return cache[last][valid];
        }

        if(valid==0)
        {
            return cache[last][valid]=1;
        }

        i64 ans=0;
        int i;
        REP(i,n)
        {
            if((valid & (1<<i)) && compatible(last,i))
            {
                ans=(ans+recurse(i,valid^(1<<i))) % MOD;
            }
        }

        return cache[last][valid]=(int)ans;
    }

public  :

    int count(vector<string> cards)
    {
        this->cards=cards;
        n=cards.size();
        cache=VVI(n,VI(1<<n,-1));

        i64 ans=0;
        int all=(1<<n)-1;
        int i;

        REP(i,n)
        {
            ans=(ans+recurse(i,all^(1<<i))) % MOD;
        }

        return (int)ans;
    }
};


int main()
{
    string x[]={"KH", "QD", "KC"};
    VS a;
    arrayToVectorString(x,a,sizeof(x)/sizeof(*x));
    TheCardLineDivTwo cc;
    printf("%d\n",cc.count(a));
    return 0;
}

