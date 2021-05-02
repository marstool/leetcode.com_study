#include "h00.h"


BSTIterator _ST01 = { NULL };

struct TreeNode* _findFirst( struct TreeNode* root ) {
    struct TreeNode* __tmpNode ;
    if ( NULL == root ) return NULL ;

    while ( NULL != root ) {
        // printf( "%d " , root -> val );

        __tmpNode = root -> left ;
        if ( NULL == __tmpNode ) {
            // printf( " rt(%d).\n" , root -> val );
            return root ;
        }
        root = __tmpNode ;
    }
    return NULL ;
}

struct TreeNode* _findPrev( struct TreeNode* root ) {
    struct TreeNode* __tmpNode ;
    if ( NULL == root ) return NULL ;

    while ( NULL != root ) {
        __tmpNode = _findPrev( root -> left ) ;
        if ( NULL == __tmpNode ) {
            return root ;
        }
        root = __tmpNode ;
    }
    return NULL ;
}

struct TreeNode* _findNext( struct TreeNode* root , struct TreeNode* ___now) {
    //struct TreeNode* __tmpNode ;

    if ( NULL == root ) return NULL ;
    if ( NULL == ___now ) return NULL ;


    if ( root == ___now ) {
        if ( NULL == ___now -> right ) {
            return NULL ; 
        }
        return _findFirst( ___now -> right ) ;
    }

    if ( root -> val < ___now -> val ) { // root < now
        return _findNext( root -> right , ___now ) ;
    }

    // root -> val > ___now -> val 
    if ( ___now == root-> left ) {
        return root ;
    }

    if ( NULL != ___now -> right ) {
        return _findFirst( ___now -> right ) ;
    }

    // NULL == ___now -> right // so , between root and now
    
    while ( root -> left != ___now ) {
        root = root -> left ;
    }
    
    return root ;
}


