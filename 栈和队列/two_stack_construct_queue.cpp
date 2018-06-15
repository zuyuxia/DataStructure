// 问题的描述：双栈实现队列
//		使用两个栈实现一个队列，支持push和pop的操作
// 一个栈用来push，一个栈用来pop

#include <iostream>
#include <stack>

using namespace std;

class NewQueue {
public:
	void push(int number) {
		stack_push_.push(number);
	}
	int pop() {
		if (stack_pop_.empty()){
			// 将stack_push_中的数据全部压入空的stack_pop_中
			int length = stack_push_.size();
			for (int i = 0; i < length; ++i) {
				stack_pop_.push(stack_push_.top());
				stack_push_.pop();
			}
		}
		int result = stack_pop_.top();
		stack_pop_.pop();
		return result;
	}

private:
	stack<int> stack_push_, stack_pop_;
};

int main() {
	NewQueue nq;
	nq.push(2);
	nq.push(5);
	nq.push(6);

	cout << nq.pop() << endl;

	nq.push(3);

	cout << nq.pop() << endl;

	nq.push(4);

	system("pause");
	return 0;
}