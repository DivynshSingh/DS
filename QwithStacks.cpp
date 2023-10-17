#include <bits/stdc++.h>
using namespace std;

struct Queue {
	stack<int> s1, s2;

	void enQ(int x)
	{
		while (!s1.empty()) {
			s2.push(s1.top());
			s1.pop();
		}

		s1.push(x);

		while (!s2.empty()) {
			s1.push(s2.top());
			s2.pop();
		}
	}

	int deQ()
	{
		if (s1.empty()) {
			return -1;
		}

		int x = s1.top();
		s1.pop();
		return x;
	}
};


int main()
{
	Queue q;
	q.enQ(1);
	q.enQ(2);
	q.enQ(3);

	cout << q.deQ() << endl;
	cout << q.deQ() << endl;
	cout << q.deQ() << endl;

	return 0;
}
