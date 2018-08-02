#include <iostream>

using namespace std;

/*
l连续子数组的最大值

关键是最优子结构

sub[i]表示包含i这个元素，前i个元素的最大连续子数组；result 为找到的子数组中和最大的；
第 i+1 个元素，两种选择：一：作为新子数组的第一个元素，二：放入到前面的子数组；
sum[i+1] = max {a[i+1], sum[i]+a[i+1]}
result = max(result, sum[i])
 */

int findMax(const int a[], const int size){
	int currSum = 0;
	int maxSum = 0;
	for (int i =0; i < size; i++){
		currSum += a[i];
		if(currSum < 0){
			currSum = 0;
		}
		if (currSum > maxSum){
			maxSum = currSum;
		}
	}
	//全是负数
	if (maxSum == 0){
		maxSum = a[0];
		for (int i=1; i<size; i++){
			if (maxSum < a[i]){
				maxSum = a[i];
			}
		}
	}
	return maxSum;
}


int main(){
	// int a[] = {1,  3, -2, 7, -6, 2, 1};
	int a[] = {1, -2, 3, 10, -4, 7, 2, -5};
	int length = sizeof(a)/sizeof(a[0]);
	cout <<"length:"<<length<<endl;
	int max = findMax(a, length);
	cout<<"max:"<<max<<endl;
	return 0;
}
