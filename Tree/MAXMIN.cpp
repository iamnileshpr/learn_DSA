/*
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
  public:
 
    int findMax(Node *root) {
        // code here
        int sum=INT_MIN;
        if(root==NULL) return 0;
        int lh=findMax(root->left);
        int rh=findMax(root->right);
        return max(root->data,max(lh,rh));
    }

    int findMin(Node *root) {
        
        // code here
        int sum1=INT_MAX;
        if(root==NULL) return INT_MAX;
        int lh=findMin(root->left);
        int rh=findMin(root->right);
        return min(root->data,min(lh,rh));    }
};