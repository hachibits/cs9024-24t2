#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

#define MAX(a, b) ((a) > (b) ? (a) : (b))

TreeNode *newNode(int value) {
    TreeNode *newTreeNode = malloc(sizeof(TreeNode));
    newTreeNode->value = value;
    newTreeNode->left = NULL;
    newTreeNode->right = NULL;
    return newTreeNode;
}

TreeNode *insert(TreeNode *root, int value) {
    if (root == NULL) {
        TreeNode *newTreeNode = newNode(value);
        return newTreeNode;
    }

    if (value < root->value) {
        root->left = insert(root->left, value);
    } else if (value > root -> value) {
        root->right = insert(root->right, value);
    } else if  (value == root->value) {
      // do nothing
    }
    return root;
}

void printInOrder(TreeNode *root) {
    if (root == NULL)
        return;
    
    printInOrder(root->left);
    printf("%d ", root->value);
    printInOrder(root->right);
}

void printPreOrder(TreeNode *root) {
    if (root == NULL)
        return;
    
    printf("%d ", root->value);
    printPreOrder(root->left);
    printPreOrder(root->right);
}

void printPostOrder(TreeNode *root) {
    if (root == NULL)
        return;
    
    printPostOrder(root->left);
    printPostOrder(root->right);
    printf("%d ", root->value);
}

bool existsInTree(TreeNode *root, int targetValue) {
    if (root == NULL) {
        return false;
    } else if (root->value == targetValue) {
        return true;
    }
    if (targetValue < root->value) {
        return existsInTree(root->left, targetValue);
    } else if (targetValue > root->value) {
        return existsInTree(root->right, targetValue);
    }
}

int getNumNodes(TreeNode *root) {
    return (root == NULL) ? 0 : 1 + getNumNodes(root->left) + getNumNodes(root->right);
}

int getTreeHeight(TreeNode *root) {
    return (root == NULL) ? 0 : 1 + MAX(getTreeHeight(root->left), getTreeHeight(root->right));
}

void freeTree(TreeNode *root) {
    if (root == NULL)
        return;
    
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}
