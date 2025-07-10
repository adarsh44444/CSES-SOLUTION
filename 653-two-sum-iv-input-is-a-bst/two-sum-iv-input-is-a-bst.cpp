class Solution {
public:
    class BSTIterator {
    public:
        stack<TreeNode*> s;
        bool reverse;

        BSTIterator(TreeNode* root, bool isReverse) {
            reverse = isReverse;
            pushAll(root);
        }

        int next() {
            TreeNode* node = s.top(); s.pop();
            if (!reverse)
                pushAll(node->right);
            else
                pushAll(node->left);
            return node->val;
        }

        void pushAll(TreeNode* node) {
            while (node != nullptr) {
                s.push(node);
                node = reverse ? node->right : node->left;
            }
        }

        bool hasNext() {
            return !s.empty();
        }
    };

    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;

        BSTIterator l(root, false); // in-order
        BSTIterator r(root, true);  // reverse in-order

        int i = l.next();
        int j = r.next();

        while (i < j) {
            int sum = i + j;
            if (sum == k) return true;
            else if (sum < k) i = l.next();
            else j = r.next();
        }
        return false;
    }
};