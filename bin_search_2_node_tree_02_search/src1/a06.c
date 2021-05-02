#include "h00.h"

struct TreeNode* _newBST(int val){
    struct TreeNode* ___bst ;
    ___bst = malloc( sizeof (struct TreeNode ));
    ___bst -> val = val ;
    ___bst -> left = NULL ;
    ___bst -> right = NULL ;
    return ___bst ;
} // _newBST

struct TreeNode* searchBST(struct TreeNode* root, int val){

    if ( NULL == root ) return NULL ;

    if ( val == root -> val ) return root ;

    if ( val > root -> val ) {
        return searchBST( root -> right , val ) ;
    }

    return searchBST( root -> left , val ) ;
} // searchBST

struct TreeNode* insertIntoBST(struct TreeNode* root, int val){
    struct TreeNode* ___bst ;
    if ( NULL == root ) {
        //printf( "========== 1:%d\n", val );
        root = _newBST( val ) ;
        //printf( "========== 2: %p\n", root );
        return root ;
    }

    ___bst = root ;
    if ( val == ___bst -> val ) { // already in the tree, ignore
        return root ;
    }

    if ( val > ___bst -> val ) { // val > the root's val , insert at right
        if ( NULL == ___bst -> right ) { 
            ___bst -> right = _newBST( val ) ;
            return root ;
        }
        insertIntoBST( ___bst -> right , val ) ;
        return root ;
    }

    // val < the root's val , insert at left

    if ( NULL == ___bst -> left ) { 
        ___bst -> left = _newBST( val ) ;
        return root ;
    }

    insertIntoBST( ___bst -> left , val ) ;
    return root ;

} // insertIntoBST
