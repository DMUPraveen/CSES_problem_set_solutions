#include <bits/stdc++.h>

using namespace std;

using ll = int64_t;
using vecl = vector<ll>;
using setl = multiset<ll>;

void solution(vecl& a){
    setl s = setl();
    for(auto x: a){
        auto vp = s.upper_bound(x);
        if(vp != s.end()){
            s.erase(vp);
        }
        s.insert(x);

    }
    cout << s.size() << endl;
    
}

int main()
{

    int N;
    cin >> N ;
    vecl v = vecl(N, 0L);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }
    solution(v);
    return 0;
}
