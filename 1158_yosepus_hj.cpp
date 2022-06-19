#include<iostream>
#include <queue>
using namespace std;
 
int main() {
	int N; // 4
	cin >> N; 
 
	int K; // 2
	cin >> K;
 
	queue<int> q;
 
	for (int i = 1; i <= N; i++)
	{
		q.push(i);
	}
 ////////////////////////////////////////////////////////////
	int cnt = N - 1;
 
	cout << "<";
 
	while (cnt--)
	{ // [1,2,3,4,5,6] -> [2,3,4,5,6,1] -> [4,5,6,1,2] -> [5,6,1,2,4]
		for (int i = 0; i < K-1; i++)
		{
			q.push(q.front());
			q.pop();
		}
		cout<< q.front() << ", ";
		q.pop();
	}
 
	cout << q.front() << ">";
	q.pop();
 
	return 0;
}
