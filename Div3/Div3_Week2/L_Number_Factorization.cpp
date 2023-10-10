#include <bits/stdc++.h>

using namespace std;

//#pragma GCC optimize("03,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#define Morshedy_22 ios_base::sync_with_stdio(false);cin.tie(nullptr);
#define F first
#define S second
#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define FILL(a, b) memset(a, b, sizeof(a))
#define popCnt(x) (__builtin_popcountll(x))
#define sz(x) (int)(x).size()
#define el '\n'
#define int ll

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;

const int inf = 0x3f3f3f3f;
const ll infLL = 0x3f3f3f3f3f3f3f3fLL;
const int N = 1e5+5;
const int mod = 1e9+7;
const int d4x[4]={-1, 0, 1, 0}, d4y[4]={0, 1, 0, -1};
const int d8x[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8y[8]={0, 1, 1, 1, 0, -1, -1, -1};

/*
---> وتظل تسعى جاهدا في همةٍ   ..  والله يعطي من يشاءُ إذا شكر <---
*/


void testCase()
{
    int n;
    cin >> n;
    int cnt;

    vii pf;
    for(int i=2; i*i <= n; i++)
    {
        cnt = 0;
        
        while(n%i==0)
        {
            cnt++;
            n/=i;

        }
        if(cnt)
            pf.push_back({cnt,i});
    }
    if(n>1)
        pf.push_back({1,n});

    sort(all(pf));

    // for(auto [x,y] : pf)
    //     cout << x << " " << y << el;

    ll ans = 0, mul = 1;
    for(int i=0; i<sz(pf); i++)
    {
        int mn = pf[i].F;
        mul = 1;
        for(int j=i; j<sz(pf) && pf[j].F; j++)
        {
            mul *= pf[j].S;
            pf[j].F -= mn;
        }
        ans += (mul * mn);
    }

    cout << ans << el;
    
}


int32_t main()
{
    Morshedy_22

    int tc = 1;
    cin >> tc;
    while(tc--)
        testCase();


    return 0;
}