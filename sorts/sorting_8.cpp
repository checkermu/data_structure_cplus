#include <iostream>
#include <string>
#include <stack>
#include <vector>

/*
线性排序算法
 */

/*
计数排序，Counting sort

待排序的整数序列，最小值不小于0，最大值不大于K。

建立一个长度大小为 K 的线性表 C ，用来记录不大于每个值元素的个数。

计数排序的本质是通过计算无序集合中 整数出现的次数，来决定集合如何排序。

一直失败的一点：从0开始，则集合出现的次数-1 才是真正最终存储的下标。
 */

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
using namespace std;

/*
A-待排序的，B额外空间，Order-额外空间，N-待排序数目，K-最大的数
 */
void CountingSort(int *A,int *B,int *Order,int N,int K)
{
    int *C=new int[K];
    int i;
    memset(C,0,sizeof(int)*(K));
    for (i=0;i<N;i++) //把A中的每个元素分配
        C[A[i]]++;
    printf("after asign A to C\n");
    for (i=0;i<K;i++)
        printf("%d ",C[i]);
    for (i=1;i<K;i++) //统计不大于i的元素的个数
        C[i]+=C[i-1];
    printf("after statics C it self\n");
    for (i=0;i<K;i++)
        printf("%d ",C[i]);
    printf("A");
    for (i=N-1;i>=0;i--)
    {
        B[C[A[i]]-1]=A[i]; //按照统计的位置，将值输出到B中，将顺序输出到Order中
        Order[C[A[i]]-1]=i;
        C[A[i]]--;
    }
}
int main()
{
    int *A,*B,*Order,N=15,K=10,i;
    A=new int[N];
    B=new int[N];
    Order=new int[N];
    for (i=0; i<N; i++)
    	A[i] = rand()%K;
    // for (i=1;i<=N;i++)
    //     A[i]=rand()%K+1; //生成1..K的随机数
    printf("Before CS:\n");
    for (i=0;i<N;i++)
        printf("%d ",A[i]);
    CountingSort(A,B,Order,N,K);
    printf("\nAfter CS:\n");
    for (i=0;i<N;i++)
        printf("%d ",B[i]);
    printf("\nOrder:\n");
    for (i=0;i<N;i++)
        printf("%d ",Order[i]);
    return 0;
}



void BucketSort(int *A,int *B,int N,int K)
{
    int *C=new int[K+1];
    int i,j,k;
    memset(C,0,sizeof(int)*(K+1));
    for (i=1;i<=N;i++) //把A中的每个元素按照值放入桶中
        C[A[i]]++;
    for (i=j=1;i<=K;i++,j=k) //统计每个桶元素的个数，并输出到B
        for (k=j;k<j+C[i];k++)
            B[k]=i;
}
int main_buck()
{
    int *A,*B,N=1000,K=1000,i;
    A=new int[N+1];
    B=new int[N+1];
    for (i=1;i<=N;i++)
        A[i]=rand()%K+1; //生成1..K的随机数
    BucketSort(A,B,N,K);
    for (i=1;i<=N;i++)
        printf("%d ",B[i]);
    return 0;
}
