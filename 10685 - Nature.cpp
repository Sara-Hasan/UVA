#include<bits/stdc++.h>
using namespace std;

#define           CIN              ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define           ll               long long int
#define           ull              unsigned long long int
#define           pii              pair < int, int>
#define           pll              pair < ll, ll>
#define           MOD              1000000007
#define           vi               vector<int>
#define           vl               vector<ll>
#define           pb               push_back
#define           sc               scanf
#define           pf               printf
#define         scin(x)            scanf("%d",&(x))
#define        scin2(x,y)          scanf("%d %d",&(x),&(y))
#define         scln(x)            scanf("%lld",&(x))
#define        scln2(x,y)          scanf("%lld %lld",&(x),&(y))
#define       min3(a,b,c)          min(a,min(b,c))
#define       min4(a,b,c,d)        min(d,min(a,min(b,c)))
#define       max3(a,b,c)          max(a,max(b,c))
#define       max4(a,b,c,d)        max(d,max(a,max(b,c)))
#define         ms(a,b)            memset(a,b,sizeof(a))
//#define           mp               make_pair
#define       gcd(a, b)            __gcd(a,b)
#define       lcm(a, b)            ((a)*(b)/gcd(a,b))
#define         input              freopen("input.txt","rt", stdin)
#define         output             freopen("output.txt","wt", stdout)
#define           PI               2*acos(0.0)
#define     rep( i , a , b )       for( i=a ; i<b ; i++)
#define     rev( i , a , b )       for( i=a ; i>=b ; i--)
#define     repx( i ,a,b, x)       for( i=a ; i<b ; i+=x)
#define       CASEL(t)             printf("Case %d:\n",t)
#define     RUN_CASE(t,T)          for(__typeof(t) t=1;t<=T;t++)
#define       zero(a)              memset(a,0,sizeof a)

///priority_queue<int,vector<int>,greater<int> >pq;
///--------------Graph Moves--------------------------------------
///const int fx[] = {+1,-1,+0,+0};
///const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
///---------------------------------------------------------------


map<string,ll>mp;
map<ll,ll>mp2;

ll parent[5009];

void initialization(ll n)
{
    for(ll i=0;i<=n;i++){
        parent[i]=i;
    }
}


ll findParent(ll x)
{
    if(x!=parent[x]){
        return parent[x]=findParent(parent[x]);
    }
    else{
        return x;
    }
}


void unionSet(ll x, ll y)
{
    ll px=findParent(x);
    ll py=findParent(y);
    if(px!=py) parent[px]=py;
}



int main()
{
    ll a,b,c,d,e,i,j,cnt=0,chk=0,mx=0;
    string s,s1;
    while(1)
    {
        cin>>a>>b;
        c=0;
        mx=0;
        mp2.clear();
        mp.clear();
        initialization(a);
        if(a==0 && b==0){
            return 0;
        }

        for(i=0;i<a;i++){
            cin>>s;
            mp[s]=c;
            c++;
        }
        for(i=0;i<b;i++){
            cin>>s>>s1;
            d=mp[s];
            e=mp[s1];
            unionSet(d,e);
        }

        for(i=0;i<a;i++){
            findParent(i);
        }

        for(i=0;i<a;i++){
            mp2[parent[i]]++;
            if(mp2[parent[i]]>mx){
                mx=mp2[parent[i]];
            }
        }
        cout<<mx<<endl;
    }

    return 0;
}
