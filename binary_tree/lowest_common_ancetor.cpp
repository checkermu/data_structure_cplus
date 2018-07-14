#include <iostream>
#include <vector>

using namespace std;
/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class TreeNode {
public:
	int val;
	TreeNode *left, *right;
	TreeNode(int val) {
		this->val = val;
		this->left = this->right = NULL;
	}
};


class Solution {
public:
    /*
     * @param root: The root of the binary search tree.
     * @param A: A TreeNode in a Binary.
     * @param B: A TreeNode in a Binary.
     * @return: Return the least common ancestor(LCA) of the two nodes.
     */
    TreeNode * lowestCommonAncestor(TreeNode * root, TreeNode * A, TreeNode * B) {
        // write your code here
        if (root == NULL || A == NULL || B ==NULL){
        	return NULL;
        }
        TreeNode * nodes = root;
        vector<TreeNode*> path1;
        vector<TreeNode*> path2;
        cout<<"NOW BEGIN PATH:"<<nodes->val<<endl;
        bool left = this->findPath(nodes, A, path1);
        cout<<"NOW LEFT PATH:"<<path1[0]->val<<endl;
        bool right = this->findPath(nodes, B, path2);

        if (left && right){
        	int lenth = path1.size() > path2.size() ? path2.size() : path1.size();
        	TreeNode * ancestorNode;
        	for (int i=0; i<lenth; i++){
        		if (path1[i]->val == path2[i]->val){
        			ancestorNode = path1[i];
        			continue;
        		}else{
        			break;
        		}
        	}
        	if (ancestorNode != NULL){
        		return ancestorNode;
        	}else{
        		return NULL;
        	}
        }else{
        	return NULL;
        }

    }

    bool findPath(TreeNode* root, TreeNode *A, vector<TreeNode*> &paths){
    	if (root == NULL || A == NULL){
    		return false;
    	}
    	paths.push_back(root);
    	cout<<"FIND:"<<paths[0]->val<<endl;
    	if(root->val == A->val){
    		return true;
    	}
    	bool find = (this->findPath(root->left, A, paths) || this->findPath(root->right, A, paths));
    	if (find){
    		return true;
    	}
    	paths.pop_back();
    	return false;
    }
};

TreeNode * makeTree(){
	TreeNode * t1 = new TreeNode(4);
	TreeNode * t2 = new TreeNode(3);
	TreeNode * t3 = new TreeNode(7);
	TreeNode * t4 = new TreeNode(5);
	TreeNode * t5 = new TreeNode(6);
	t1->left = t2;
	t1->right = t3;
	t3->left = t4;
	t3->right = t5;
	TreeNode * root = t1;
	return root;
}


int main(){
	TreeNode * root = makeTree();
	TreeNode * ta = new TreeNode(3);
	TreeNode * tb = new TreeNode(5);
	Solution* ancestorObj = new Solution();

	cout <<"HERE:"<<root->val<<endl;
	TreeNode * res = ancestorObj->lowestCommonAncestor(root, ta, tb);
	cout<<"THE result:"<<res->val<<endl;
	return 0;
}
