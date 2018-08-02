#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

/*
two sum问题，
无外乎三种解决方案：
1、二分查找（先排好序）
2、用hash表，以空间换时间；
3、双指针法（针对有序的）
 */

vector<int> find_two(vector<int> &arr, int target){
	unordered_map<int, int> map;
	vector<int> res;
	for (int i=0; i<arr.size(); i++){
		map[arr[i]] = i;
	}
	for (int j=0; j < arr.size(); j++){
		int t = target - arr[j];
		if (map.count(t) && map[t] != j){
			res.push_back(j);
			res.push_back(map[t]);
			// break;
			res.push_back(-100);
		}
	}
	return res;
}


/*
链接：http://fisherlei.blogspot.com/2013/03/leetcode-two-sum-solution.html还不错，结构体保存index；
一个循环搞定这个hash_map的存储和查找过程！
优点，即便是多个，也不会出现 （0，1）， （1，0）这样重复出现的Pair对。

 */
vector<int> find_two_2(vector<int> &arr, int target){
	vector<int> res;
	if (arr.size() <= 1){
		cout<<"the vector is two small!";
		return res;
	}
	unordered_map<int, int> map;
	for (int i=0; i<arr.size(); i++){
		int t = target - arr[i];
		if (map.count(t)){
			
			res.push_back(map[t]);
			res.push_back(i);
			res.push_back(-100);
		}else{
			map[arr[i]] = i;
		}
	}
	return res;
}


int main(){
	int a[7] = {14, 1, 6, 8, 9, 11, 10};
	vector<int> arr(a, a+7);
	vector<int>::iterator it;
	// for (it = arr.begin(); it != arr.end(); it++){
	// 	cout << *it <<endl;
	// }
	vector<int> res;
	res = find_two_2(arr, 15);

	
	for (it = res.begin(); it != res.end(); it++){
		cout << *it <<endl;
	}

}





//每个单词的能量分布表，table在负采样中用到
void InitUnigramTable() {

  int a, i;
  double train_words_pow = 0;
  double d1, power = 0.75;
  table = (int *)malloc(table_size * sizeof(int));//分配空间
  //遍历词汇表，统计词的能量总值train_words_pow 
  for (a = 0; a < vocab_size; a++) 
    train_words_pow += pow(vocab[a].cn, power);


  i = 0;
  //表示已遍历词的能量值占总能量的比 
  d1 = pow(vocab[i].cn, power) / train_words_pow;
  //a - table表的索引
  //i - 词汇表的索引
  for (a = 0; a < table_size; a++) {
    table[a] = i;//单词i占用table的a位置 
                 //table反映的是一个单词能量的分布，一个单词能量越大，所占用的table的位置越多 
    if (a / (double)table_size > d1) {
      i++;       //移到下个词
      d1 += pow(vocab[i].cn, power) / train_words_pow;
    }
    // put everthing else in the end of the unigram table??？
    if (i >= vocab_size) i = vocab_size - 1;
  }
}
