//106. Construct Binary Tree from Inorder and Postorder Traversal



class Solution {
public:
    void createMap(vector<int>& inorder, map<int, int>& mpp, int n) {
        for (int i = 0; i < n; i++) {
            mpp[inorder[i]] = i;
        }
    }
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int& index,
                    int inStart, int inEnd, int n, map<int, int>& mpp) {
        // base case
        if (index < 0 || inStart > inEnd) {
            return NULL;
        }
        int element = postorder[index--];
        TreeNode* root = new TreeNode(element);

        int position = mpp[element];

        root->right =solve(inorder, postorder, index, position + 1,       inEnd,  n, mpp);
        root->left = solve(inorder, postorder, index, inStart,       position - 1,     n,  mpp);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int postIndex = n-1;
        map<int, int> mpp;
        createMap(inorder, mpp, n);
        TreeNode* ans = solve(inorder, postorder, postIndex, 0, n - 1, n, mpp);
        return ans;
    }
};