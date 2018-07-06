#beam_search的瞎写

本质：是对广度优先搜索的一个改进，对搜索空间进行了优化（类似于剪枝），减少了内存消耗的目的。

概念：
1、  引入启发式函数的概念  h  目的是 来估计当前节点到目标节点的损失。
2、beam width B ：每一层 （each level）广度优先搜索算法保存的节点数目；
    可以防止程序内存溢出，加快搜索速度；

3、BEAM的作用类似于 open list，用于保存下一轮扩展的节点；
4、SET保存 BEAM中所有的后续节点，是启发函数的输入空间；
5、a hash table 类似于 closed list，用于保存所有已经访问过的节点。

算法流程：
1、将开始节点 start 加入到 BEAM 和 a hash table ；
2、循环遍历 BEAM的所有后续节点，加入到SET中，并清空 BEAM；
3、从SET中选取 B 个启发函数值最优的节点加入到 BEAM 和 hash table中，（已经在hash table里的不能再增加）；
4、以上循环进行，直到找到目标节点或hash table满了，或主循环结束后 BEAM为空（没找到解）

/* initialization */
g = 0;
hash_table = { start };
BEAM = { start };

/* main loop */
while(BEAM ≠ ∅){                             // loop until the BEAM contains no nodes
  SET = ∅;                                   // the empty set /* generate the SET nodes */ 
  for(each state in BEAM){ 
    for(each successor of state){ 
        if(successor == goal) 
            return g + 1;
        SET = SET ∪ { successor };             // add successor to SET 
    } 
    } 
    BEAM = ∅;                                  // the empty set g = g + 1;

  /* fill the BEAM for the next loop */
  while((SET ≠ ∅) AND (B > |BEAM|)){ 
  // set is not empty and the number of nodes in BEAM is less than B state = successor in SET with smallest h value;
    SET = SET \ { state };                   // remove state from SET 
    if(state ∉ hash_table){ // state is not in the hash_table 
        if(hash_table is full) return ∞;
        hash_table = hash_table ∪ { state };   // add state to hash_table
        BEAM = BEAM ∪ { state };               // add state to BEAM
    }
  }
}

// goal was not found, and BEAM is empty - Beam Search failed to find the goal
return ∞;


