#include "h00.h"

struct TreeNode* searchBST(struct TreeNode* root, int val){

    if ( NULL == root ) return NULL ;

    if ( val == root -> val ) return root ;

    if ( val > root -> val ) {
        return searchBST( root -> right , val ) ;
    }

    return searchBST( root -> left , val ) ;
} // searchBST

struct TreeNode* insertIntoBST(struct TreeNode* root, int val){
    if ( NULL == root ) {
        printf( "========== 1:%d\n", val );
        root = malloc( sizeof (struct TreeNode ));
        root -> val = val ;
        root -> left = NULL ;
        root -> right = NULL ;
        printf( "========== 2: %p\n", root );
        return root ;
    }

    printf( "========== 9: \n");
    return NULL ;
} // insertIntoBST
