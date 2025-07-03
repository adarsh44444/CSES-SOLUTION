class Solution {
public:
    int findleftheight(TreeNode* root){
        int height = 0;
        while(root){
            height++;
            root = root->left;
        }
        return height;
    }

    int findrightheight(TreeNode* root){
        int height = 0;
        while(root){
            height++;
            root = root->right;
        }
        return height;
    }

    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;

        int lh = findleftheight(root);
        int rh = findrightheight(root);

        if (lh == rh)
            return (1 << lh) - 1;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
