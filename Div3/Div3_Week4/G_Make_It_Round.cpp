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
    int n, m;
    cin >> n >> m;
    
    int tn=n;
    int freq2=0, freq5=0;

    while(tn%2==0) tn/=2, freq2++;
    while(tn%5==0) tn/=5, freq5++;

    
    int k=1;
    while(freq2 < freq5)
    {
        if(k*2 <= m)
            k*=2, freq2++;
        else
            break;
    }
    
    while(freq5 < freq2)
    {
        if(k*5 <=m)
            k*=5, freq5++;
        else
            break;
    }

    while(k<=m)
    {
        if(k*10 <= m)
            k*=10;
        else
        {
            for(int i=9; i; i--)
                if(k*i <=m)
                    k*=i;
            break;
        }
    }

    cout << n * k << el;    
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