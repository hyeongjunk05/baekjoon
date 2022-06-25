#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int INF = 5000000;
    int point, edge, start;
    cin >> point >> edge;
    cin >> start;
    
    vector<pair<int, int>> distanceMatrix[point+1];

    for(int i = 1; i <= edge; i++) {
        int first, second, distance;
        cin >> first >> second >> distance;
        distanceMatrix[first].push_back(make_pair(distance, second));
    }
    
    vector<int> distances(point+1);
    for(int i = 1; i <= point; i++) {
        distances[i] = INF;
    }
    
    priority_queue<pair<int, int>> pq;
    
    distances[start] = 0;
    pq.push(make_pair(0, start));
    
    while(!pq.empty()) {
        int curWeight = -pq.top().first;
        int curPoint = pq.top().second;
        pq.pop();
        
        if(distances[curPoint] < curWeight) {
            continue;
        }
        
        for(int i = 0; i < distanceMatrix[curPoint].size(); i++) {
            int nextWeight = distanceMatrix[curPoint][i].first;
            int nextPoint = distanceMatrix[curPoint][i].second;
            if(distances[nextPoint] > nextWeight + curWeight) {
                distances[nextPoint] = nextWeight + curWeight;
                pq.push(make_pair(-distances[nextPoint], nextPoint));
            }
        }
    }

    
    for(int i = 1; i <= point; i++) {
        if(distances[i] == INF) {
            cout << "INF" << endl;
        } else {
            cout << distances[i] << endl;
        }
    }
    
    return 0;
}
