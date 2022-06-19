#include <iostream>
#include <stack>	// ����
using namespace std;

int main() {
	int X;
	cin >> X;	// �ܾ� ����

	int count;	// �����ܾ� ����

	for (int i = 0; i < X; i++) {
		string word;
		cin >> word;

		stack<char> stack;

		for (int i = 0; i < word.length(); i++) {
			// ������ ������� �ʰ�, ������ ���ڰ� ���� ���ڿ� ���ٸ� pop
			if (!stack.empty() && stack.top() == word[i]) {
				stack.pop();
			}
			// ������ ����ְų�, ������ ���ڰ� ���� ���ڿ� �ٸ��ٸ� push (���� �߻�)
			else {
				stack.push(word[i]);
			}
		}

		// ������ ����ִٸ� ���� �߻� ���� ����� (=�����ܾ�)
		if (stack.empty()) {
			count++;
		}

	}

	cout << count;
}