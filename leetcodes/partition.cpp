#include <iostream>
using namespace std;
/*
无需数组的中位数

O(n)时间复杂度，借鉴快排的分割函数！
 */

int partition(int a[], int left, int right){
	int pivot = a[left], i=left+1, j=right, tmp;
	while(i<=j){
		while(i<=j && a[i] <= pivot){
			++i;
		}
		while(i<=j && a[j] >= pivot){
			--j;
		}
		if(i < j){
			tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
			++i;
			--j;
		}
	}
	a[left] = a[j];
	a[j] = pivot;
	return j;
}
//http://www.cnblogs.com/hellogiser/p/kmin-of-array.html
int Kmin(int a[], int left, int right, int k){
	if (left <= right){
		int p = partition(a, left, right);
		int pk = p-left+1;//+1是为了index边个数，减去left是为了避免不是从0开始
		if  (k < pk){
			return Kmin(a, left, p-1, k);//左边查找
		}else if(k > pk){
			return Kmin(a, p+1, right, k-pk);//右边查找
		}else{
			return a[p];
		}
	}
	return -1;
}


int main(){
	int a[] = {4, 2, 8, 3, 1, 6};
	// int p = partition(a, 0, 5);
	// int lent = sizeof(a)/sizeof(a[0]);
	// for (int i=0; i<lent; i++){
	// 	cout<<a[i]<<'\t';
	// }
	// cout<<endl;
	// cout<<p<<endl;

	int p = Kmin(a, 0, 5, 5);
	cout<<p<<endl;

}


