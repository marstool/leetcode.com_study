#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//#define _max_treeAmount    32    // moust be 2 ^^ 1,2,3,4,5.... 2, 4, 8 , 16 , 32
//#define _max_treeAmount    16    // moust be 2 ^^ 1,2,3,4,5.... 2, 4, 8 , 16 , 32
#define _max_treeAmount    128    // moust be 2 ^^ 1,2,3,4,5.... 2, 4, 8 , 16 , 32

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    bool isNull ;
} ;
typedef struct TreeNode TreeNode ;

typedef struct {
    TreeNode *nodeRoot ; // topRoot
    TreeNode *firstNode ; // firstRoot
    TreeNode *curNode ;
    
} BSTIterator;

BSTIterator* bSTIteratorCreate(TreeNode* root) ;
int bSTIteratorNext(BSTIterator* obj) ;
bool bSTIteratorHasNext(BSTIterator* obj) ;
void bSTIteratorFree(BSTIterator* obj) ;

TreeNode * _treeNodeCreate( char *___sbuf ) ;
TreeNode * _treeNodeCreateX( char *___sbuf ) ;
int               _treeNodeFree( TreeNode * ___treeNodeTop);

void _dumpTreeNode(TreeNode* root, char * ___sep);
void _dumpBSTsort( BSTIterator * ___iter ) ;
bool isValidBST(TreeNode* root);

extern BSTIterator _ST01 ;
struct TreeNode* _findNext( struct TreeNode* root , struct TreeNode* ___now) ;
struct TreeNode* _findPrev( struct TreeNode* root ) ;

struct TreeNode* _findFirst( struct TreeNode* root ) ;
struct TreeNode* searchBST(struct TreeNode* root, int val);
struct TreeNode* insertIntoBST(struct TreeNode* root, int val);
struct TreeNode* _newBST(int val);
void _freeOneNode( TreeNode * ___treeNodeTop);
struct TreeNode* deleteNode(struct TreeNode* root, int key);
