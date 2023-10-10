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

set<int> st;
void init()
{

    int h = 0, m = 0;
    for(int i=0; i<3; i++)
    {   
        h = i;
        for(int j=0; j< (i==2 ? 4 : 6); j++)
        {
            h = h*10 + j;
            m = j;
            m = m*10 + i;

            st.insert(h*60+m);
            h = i;
            m = 0;
        }
        
    } 
}

void testCase()
{
    string s;
    int x; 
    cin >> s >> x;
    int clock = 0;
    clock = stoll(s.substr(0,2)) * 60 + stoll(s.substr(3));

    int cnt = 0;
    for(auto a : st)
    {
        if(a >= clock && abs(a-clock)%x == 0)
            cnt++;
        else
        {
            // cout << a << " " << clock <<  " " << (clock+(abs(1440-clock)/x)*x) << el;
            int cc = x - (1440-(clock+(abs(1440-clock)/x)*x)); 
            // cout << "xx: " << xx << el;
            if((a-cc)%x == 0)
                cnt++;
        }
    }
    cout << cnt << el;
}


int32_t main()
{
    Morshedy_22
    
    init();

    int tc = 1;
    cin >> tc;
    while(tc--)
        testCase();


    return 0;
}