#include <iostream>
#include <stack>	// 스택
using namespace std;

int main() {
	int X;
	cin >> X;	// 단어 개수

	int count;	// 좋은단어 개수

	for (int i = 0; i < X; i++) {
		string word;
		cin >> word;

		stack<char> stack;

		for (int i = 0; i < word.length(); i++) {
			// 스택이 비어있지 않고, 마지막 문자가 현재 문자와 같다면 pop
			if (!stack.empty() && stack.top() == word[i]) {
				stack.pop();
			}
			// 스택이 비어있거나, 마지막 문자가 현재 문자와 다르다면 push (교차 발생)
			else {
				stack.push(word[i]);
			}
		}

		// 스택이 비어있다면 교차 발생 안한 경우임 (=좋은단어)
		if (stack.empty()) {
			count++;
		}

	}

	cout << count;
}