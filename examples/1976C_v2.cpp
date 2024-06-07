#define MULTI // comment this line when there is only one testcase

#include <bits/stdc++.h>

using namespace std;

int N1, N2, N, cnt[2];
long long ok, ans;
vector<long long> p, t;
vector<pair<int, long long> > diff[2];

int signum(long long a) {
    return (a > 0) - (a < 0);
}

long long f(int i, int k, int opt) {
    int s = (opt == 0 ? 1 : -1);
    int n = diff[opt].size();

    if(i == N) {
        return diff[opt][n - 1].second;
    }

    if(signum(p[i] - t[i]) == s && diff[opt][n - k - 1].first <= i) {
        return diff[opt][n - 1].second - diff[opt][n - k - 2].second - abs(p[i] - t[i]);
    }

    return diff[opt][n - 1].second - diff[opt][n - k - 1].second;
}

void calc(int i, int opt) {
    ans = ok - max(t[i], p[i]);

    --cnt[opt];
    if(cnt[0] > N1) {
        ans -= f(i, cnt[0] - N1, 0); 
    }
    
    if(cnt[1] > N2) {
        ans -= f(i, cnt[1] - N2, 1);
    }
    ++cnt[opt];
    cout << ans << ' ';
}

void solve() {
    cin >> N1 >> N2;
    N = N1 + N2 + 1;
    p.assign(N + 1, 0);
    t.assign(N + 1, 0);

    diff[0].assign(1, {0, 0});
    diff[1].assign(1, {0, 0});

    for(int i = 1; i <= N; ++i) {
        cin >> p[i];
    }

    for(int i = 1; i <= N; ++i) {
        cin >> t[i];
    }

    ok = 0;
    cnt[0] = cnt[1] = 0;

    for(int i = 1; i <= N; ++i) {
        int opt = signum(p[i] - t[i]);
        opt = (opt == 1 ? 0 : 1);
        
        ++cnt[opt];

        long long s = diff[opt].back().second;
        diff[opt].push_back({i, s + abs(p[i] - t[i])});

        ok += max(p[i], t[i]);
    }

    for(int i = 1; i < N; ++i) {
        calc(i, signum(p[i] - t[i]) != 1);
    }

    cnt[0] = cnt[1] = 0;
    ans = 0;
    for(int i = 1; i < N; ++i) {
        if(p[i] > t[i]) {
            if(cnt[0] < N1) {
                ++cnt[0];
                ans += p[i];
            }
            else {
                ++cnt[1];
                ans += t[i];
            }
        }
        else {
            if(cnt[1] < N2) {
                ++cnt[1];
                ans += t[i];
            } 
            else {
                ++cnt[0];
                ans += p[i];
            }
        }
    }

    cout << ans << '\n';
}

void precalc() {
	// some precalculations if needed
}

int main() {
	precalc();

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
#ifdef MULTI
	int T;
	cin >> T;
	while(T--) {
		solve();
	}
#else 
	solve();
#endif

	return 0;
}