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

计数排序的本质是**通过计算无序集合中 整数出现的次数，来决定集合如何排序**。

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
int main_counting()
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


/*
基数排序
其用到了Counting 计数排序：Counting是用无序整数出现的次数来决定如何排序，是稳定的排序；

基数排序 将数据按照 位 分开，并从数据的最低有效位到最高有效位依次排序，进而得到有序数据集合。

因为在进行高位排序的时候，低位已经有序了，因此高位不能破坏低位原有的顺序——》必须是稳定排序才可用！

基数排序会用到 计数排序。

不局限于整数， 只要能把元素分割为整数，就能用基数排序。

由于基数排序对每个p位置的位数值使用计数排序，因此基数排序消耗的运行时间是计数排序的p倍，即O（pn+pk）

其对空间的要求与计数排序一样：两个大小为n的数组，一个大小为k的数组。

https://www.cnblogs.com/idreamo/p/8978469.html
https://www.byvoid.com/zhs/blog/sort-radix
 */

#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int rxsort(int *data, int size, int p, int k)
{
    int *counts, *temp;
    int index, pval, i, j, n;

    /*给计数器数组分配空间*/


}



int quicksort_partition(int a[], int low, int high){
    int tmp = a[low];

    int lindex = low+1;
    int hindex = high;
    int exchange;
    while(lindex <= hindex){
        while (lindex <= hindex && a[lindex] <= tmp){
            ++lindex;
        }
        while (lindex <= hindex && a[hindex] >= tmp){
            --hindex;
        }
        if (lindex < hindex){
            exchange = a[lindex];
            a[lindex] = a[hindex];
            a[hindex] = exchange;
            --hindex;
            ++lindex;
        }
    }
    a[low] = a[hindex];
    a[hindex] = tmp;

    return hindex;
}

/*
快速排序 分治法：
 */
void quicksort(int a[], int low, int high){
    if (low >= high){
        return;
    }
    int pivot = quicksort_partition(a, low, high);
    quicksort(a, low, pivot-1);
    quicksort(a, pivot+1, high);
}

int main(){
    int a[] = {3,5,7,9,2,3,1,0,7,5,4};
    quicksort(a, 0, 10);
    for (int i=0; i<11; i++){
        cout<<a[i]<<'\t';
    }
}




int partition(int a[], int low, int high){
    int tmp = a[low];
    int lowindex = low+1;
    int highindex = high;
    int exchange;

    while(lowindex <= highindex){
        while(lowindex <= highindex && a[lowindex] <= tmp){
            lowindex++;
        }
        while(lowindex <= highindex && a[highindex] >= tmp){
            highindex--;
        }
        if(lowindex < highindex){
            exchange = a[lowindex];
            a[lowindex] = a[highindex];
            a[highindex] = exchange;
            ++lowindex;
            --highindex;
        }
    }
    a[low] = a[highindex];
    a[highindex] = tmp;
    return highindex;
}



/*
桶排序：
一、http://www.voidcn.com/article/p-xbzmlplt-bee.html
二、https://blog.csdn.net/u012243115/article/details/47172787
三、https://www.byvoid.com/zhs/blog/sort-radix
将长度为N的待排序序列，划分为M个子空间（桶）；基于映射函数，将待排序的元素映射到不同的桶中；

桶排序利用函数的映射关系，减少了几乎所有的比较工作；
思考：桶排序映射函数 f(k)计算，相当于快排中的划分，已经把大量的数据分割成了基本有序的数据块（桶），然后在每个桶内进行比较排序。

时间复杂度：
一、映射到桶，为O(N)
二、桶内比较排序， 复杂度为  ∑O(Ni * log Ni )
因此：
1、映射函数尽量平均分到M个桶内；
2、尽量增大桶的数量；

——
思考一下 Hash表的思想 和桶排序的思想；
 */
