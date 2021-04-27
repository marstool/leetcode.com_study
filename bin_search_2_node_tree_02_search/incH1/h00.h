#include <stdbool.h>
#include <stdio.h>
#include <string.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} ;
typedef struct TreeNode TreeNode ;

typedef struct {
    TreeNode *nodeRoot ;
    TreeNode *curNode ;
    
} BSTIterator;

BSTIterator* bSTIteratorCreate(TreeNode* root) ;
int bSTIteratorNext(BSTIterator* obj) ;
bool bSTIteratorHasNext(BSTIterator* obj) ;
void bSTIteratorFree(BSTIterator* obj) ;

TreeNode * _treeNodeCreate( char *___sbuf ) ;
int               _treeNodeFree( TreeNode * ___treeNodeTop);

