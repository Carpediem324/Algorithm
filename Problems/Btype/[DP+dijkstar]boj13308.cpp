#include <bits/stdc++.h>
using namespace std;

static const long long INF = LLONG_MAX / 4;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    // 각 도시의 리터당 기름 가격
    vector<long long> cost(N);
    for (int i = 0; i < N; i++) {
        cin >> cost[i];
    }

    // 양방향 그래프 인접 리스트 (도시: 0~N-1)
    vector<vector<pair<int, long long>>> graph(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        long long dist;
        cin >> u >> v >> dist;
        // 문제에서 도시가 1~N 으로 들어온다면 0-based로 맞춤
        u--;
        v--;
        graph[u].push_back({ v, dist });
        graph[v].push_back({ u, dist });
    }

    // ----------------------------------------------------------------------------
    // (1) 기름 단가를 '좌표 압축'(coordinate compression)하여 관리
    //     → 다익스트라 상태에서 'fuelCost' 자체를 배열 인덱스로 써야 하므로,
    //       실제 도시별 가격들을 정렬 & 중복제거 후 인덱스로 사용.
    // ----------------------------------------------------------------------------
    vector<long long> uniqueCosts = cost;
    sort(uniqueCosts.begin(), uniqueCosts.end());
    uniqueCosts.erase(unique(uniqueCosts.begin(), uniqueCosts.end()), uniqueCosts.end());

    // 특정 기름 단가 c가 uniqueCosts에서 몇 번째 인덱스인지를 반환
    auto getCostIndex = [&](long long c) {
        // lower_bound를 써서 해당 단가가 정렬된 uniqueCosts상 몇 번째 위치인지 확인
        return int(lower_bound(uniqueCosts.begin(), uniqueCosts.end(), c) - uniqueCosts.begin());
        };

    // dp[city][ci] : "도시 city에, 기름단가가 uniqueCosts[ci]인 상태"로 도달하는 최소 비용
    // 초깃값 무한대
    vector<vector<long long>> dp(N, vector<long long>(uniqueCosts.size(), INF));

    // ----------------------------------------------------------------------------
    // (2) 시작점(0번 도시)에서의 초기 상태 설정
    //     처음에는 "자기 도시의 기름단가(cost[0])"로 출발할 수밖에 없음. 비용은 0원
    // ----------------------------------------------------------------------------
    int startCostIndex = getCostIndex(cost[0]);
    dp[0][startCostIndex] = 0LL;

    // ----------------------------------------------------------------------------
    // (3) 우선순위 큐(최소 힙) 준비
    //     원소: (현재까지의 누적 비용, 현재 도시, 현재 fuelCostIndex)
    // ----------------------------------------------------------------------------
    using State = tuple<long long, int, int>;
    priority_queue<State, vector<State>, greater<State>> pq;
    pq.push({ 0LL, 0, startCostIndex });

    // ----------------------------------------------------------------------------
    // (4) 다익스트라 확장
    // ----------------------------------------------------------------------------
    while (!pq.empty()) {
        auto [curCost, u, ci] = pq.top();
        pq.pop();

        // 이미 더 좋은(더 낮은) 비용으로 (u, ci)에 도착한 적 있으면 스킵
        if (dp[u][ci] < curCost) continue;

        // 만약 목적지(여기서는 N-1)에 도달했다면, 그 비용이 곧 최소비용
        if (u == N - 1) {
            cout << curCost << "\n";
            return 0;
        }

        long long currentFuelPrice = uniqueCosts[ci];

        // (4-1) "현재 도시 u에서 기름단가 갱신" 가능 여부
        //        만약 u도시의 기름단가가 더 싸다면 그것으로 교체
        if (cost[u] < currentFuelPrice) {
            int cheaperIndex = getCostIndex(cost[u]);
            // 비용은 늘어나지 않는다(탱크 용량 무제한, 단가만 바꾸는 개념)
            if (dp[u][cheaperIndex] > curCost) {
                dp[u][cheaperIndex] = curCost;
                pq.push({ curCost, u, cheaperIndex });
            }
        }

        // (4-2) "도로를 통해 다른 도시로 이동"
        //        (currentFuelPrice × 거리)만큼 비용이 추가
        for (auto& e : graph[u]) {
            int v = e.first;
            long long distUV = e.second;
            long long nextCost = curCost + currentFuelPrice * distUV;
            if (nextCost < dp[v][ci]) {
                dp[v][ci] = nextCost;
                pq.push({ nextCost, v, ci });
            }
        }
    }

    // 만약 큐가 다 비었는데도 N-1 도시까지 못 갔다면(문제 조건상 그런 케이스는 드물겠지만)
    // dp[N-1] 값 중 최솟값을 찾아본다.
    long long ans = INF;
    for (int i = 0; i < (int)uniqueCosts.size(); i++) {
        ans = min(ans, dp[N - 1][i]);
    }
    cout << ans << "\n";
    return 0;
}
