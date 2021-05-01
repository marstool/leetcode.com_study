#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//#define _max_treeAmount    32    // moust be 2 ^^ 1,2,3,4,5.... 2, 4, 8 , 16 , 32
#define _max_treeAmount    16    // moust be 2 ^^ 1,2,3,4,5.... 2, 4, 8 , 16 , 32

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    bool isNull ;
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

void _dumpTreeNode(TreeNode* root);
bool isValidBST(TreeNode* root);

extern BSTIterator _ST01 ;
struct TreeNode* _findNext( struct TreeNode* root , struct TreeNode* ___now) ;
struct TreeNode* _findPrev( struct TreeNode* root ) ;
