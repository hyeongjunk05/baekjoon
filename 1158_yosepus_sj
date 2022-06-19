#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int N, K;
    queue<int> circle;
    cin>>N>>K;
    
    for(int i = 1; i <= N; i++) {
        circle.push(i);
    }
    
    int count = 0;
    cout << "<";
    while(circle.size() > 1) {
        count++;
        if(count % K == 0) {
            cout << circle.front() << ", ";
        } else {
            circle.push(circle.front());
        }
        circle.pop();
        
    }
    
    cout<<circle.front()<<">";

    return 0;
}
