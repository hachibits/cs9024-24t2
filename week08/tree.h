#ifndef TREE
#define TREE
#include <stdbool.h> 

struct treeNode {
    int value;
    struct treeNode *left;
    struct treeNode *right;
};
typedef struct treeNode TreeNode;

TreeNode *newNode(int value);                             
TreeNode *insert(TreeNode *root, int value);              
void printInOrder(TreeNode *root);                        
void printPreOrder(TreeNode *root);                       
void printPostOrder(TreeNode *root);                      
void printGivenLevel(TreeNode *root, int level);          
bool existsInTree(TreeNode *root, int targetValue);       
int getNumNodes(TreeNode *root);                          
int height(TreeNode *root);
void freeTree(TreeNode *root);                            

#endif
