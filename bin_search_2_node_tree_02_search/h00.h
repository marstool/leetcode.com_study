#include <stdbool.h>
#include <stdio.h>
#include <string.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct {
    struct TreeNode *nodeRoot ;
    struct TreeNode *curNode ;
    
} BSTIterator;

BSTIterator* bSTIteratorCreate(struct TreeNode* root) ;
int bSTIteratorNext(BSTIterator* obj) ;
bool bSTIteratorHasNext(BSTIterator* obj) ;
void bSTIteratorFree(BSTIterator* obj) ;

struct TreeNode * _treeNodeCreate( char *___sbuf ) ;
int               _treeNodeFree( struct TreeNode * ___treeNodeTop);

