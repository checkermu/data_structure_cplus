#include <vector>
using namespace std;

/*
设计包含取出最小值的栈min，要求都是 O(1)的时间复杂度

思路：两个数组，一个存放栈元素，一个存放最小值
 */

class stack_min
{
public:
	stack_min();
	~stack_min();
	vector<int> datas;//保存具体值数据
	vector<int> minStack;//保存最小值在datas里面的下标

	//压栈
	void push(int data){
		datas.push_back(data);
		if (minStack.empty() || data < datas[minStack.back()]){
			minStack.push_back(datas.size()-1);
		}
	}

	void pop(){
		if (!datas.empty() && datas.back() == datas[minStack.back()]){
			minStack.pop_back();
		}
		datas.pop_back();
	}

	int getMin(){
		if (!datas.empty() && !minStack.empty()){
			return datas[minStack.back()];
		}
		else
		{
			cout<<"stack is empty!"<<endl;
			return NULL;
		}
	}

};
