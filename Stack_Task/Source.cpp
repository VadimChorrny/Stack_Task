#include <iostream>
#include <stack>
#include <ctime>


using namespace std;

int main()
{
	stack<int> st;

	int rand_num = 30;
	for (size_t i = 0; i < rand_num; i++)
	{
		int number = rand() % 29 + 1;
		cout << "Push " << number << endl;
		st.push(number);
	}
	cout << "Size: " << st.size() << endl;
	cout << "Empty: " << st.empty() << endl;
	cout << "Top: " << st.top() << endl;

	return 0;
}