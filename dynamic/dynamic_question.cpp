/*
动态规划的题目汇总
 */

/*
问题一：数字三角形，最大值路径或者最小值路径问题

思考到了 Viterbi算法，算每个节点的最优子结构；

最优子结构+重叠子问题，即可解决。
 */
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;


int backpack_first(int m, vector<int> A){
	int n = A.size(), i=0, j=0;
	vector<int> dp(m+1, 0);
	for (i=0; i<n; i++){
		for (j=m; j >=1; j--){
			if (j > A[i]){
				dp[j] = max(dp[j], dp[j-A[i]] + A[i]);
			}
		}
	}
	for (i=0; i<=m; i++)
		printf("%d\n", dp[i]);
	return dp[m];
}



int backpack_two(int m, vector<int> A){
	        // write your code here
        int size = A.size(), i = 0, j = 0;

        if(size <= 0) {
            return 0;
        }

        // sort(A.begin(), A.end());
        vector< vector<int> > dp(size, vector<int>(m+1, 0) );

        for(i=0; i<size; i++) {
            for(j=1; j<=m; j++) {
                if(i==0 && j>=A[i]) {
                    dp[i][j] = A[i];
                }
                else if(i>0 && j>=A[i]){
                    dp[i][j] = (dp[i-1][j-A[i]] + A[i] > dp[i-1][j]) ? dp[i-1][j-A[i]] + A[i] : dp[i-1][j];
                }
                else if(i>0 && j<A[i]){
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        for (i=0; i<size; i++){
        	for (j=0; j<=m; j++){
        		printf("%d  ", dp[i][j]);
        	}
        	printf("\n");
        }

        return dp[size-1][m];
}

//自己实现一下
int backpack_three(int m, vector<int> &A){
	//最基础的背包，只有物品重量，以及背包大小，目的是 给定背包大小 输出能存储最大的背包容量。
	// 给定背包容量，求其可存储最大重量； dp[i] 怎样与dp[i-1]车上关系呢？
	// 肯定还是得与 物品数组扯上关系，因为背包容量的增大，单个物品最大存放数就会上升；
	// 还是先思考二维的吧
	// 最优子结构，考虑最小，再到逐渐变大；这种都是有至少两个变量；
	// 最基础的 dp[0][j]，只有一个物品，背包逐渐变大的过程；
	// 要求 dp[i][j]最优，则可以从 dp[i-1][XX]而来，这里的XX怎么算呢？
	// 其实就是这个最优子结构的递推公式是怎么样的呢？
	// 物品数为i的时候，(物品数有限)，无论背包容量如何增大，到了后面都一样（物品数有限的瓶颈）
	int size = A.size(), i=0, j=0;
	if (size <= 0){
		return 0;
	}
	vector< vector <int> > dp(size, vector<int>(m+1, 0) ); 
	for (i=0; i<size; i++){
		for (j=0; j<=m; j++){
			if (i==0 && j >= A[i]){
				dp[i][j] = A[i];
			}
			else if (i>0 && j>=A[i]){
				dp[i][j] = max(dp[i-1][j-A[i]] + A[i], dp[i-1][j]);
			}else if (i>0 && j < A[i]){
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	for (i=0; i<size; i++){
		for (j=0; j<=m; j++){
			printf("%d  ", dp[i][j]);
		}
		printf("\n");
	}
	return dp[size-1][m];
}




int main(){
	int m = 14;
	int a[4] = {7, 2, 3, 5};
	vector<int> A(a, a+4);
	// backpack_first(m, A);
	// backpack_two(m, A);
	backpack_three(m, A);
}



/*
问题二：背包问题一，n个物品 放到背包里，如何尽量填满背包，背包容量m，每个物品大小是 A[i]；
 */






