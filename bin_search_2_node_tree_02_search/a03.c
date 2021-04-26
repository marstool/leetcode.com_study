#include "h00.h"


BSTIterator _ST01 = { NULL };

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
    struct TreeNode* __tmpNode ;

    if ( NULL == root ) return NULL ;
    if ( NULL == ___now ) return NULL ;


    if ( root == ___now ) {
        return _findPrev( ___now -> right ) ;
    }

    if ( root -> val < ___now -> val ) {
        return _findNext( root -> right , ___now ) ;
    }

    if ( root -> val > ___now -> val ) {
        if ( NULL != ___now -> right ) {
            return _findNext( ___now -> right , ___now ) ;
        }
        return root ;
    }

    if ( NULL != root -> left ) {
        return _findNext( root -> left , ___now ) ;
    }
    return root ;
}

BSTIterator* bSTIteratorCreate(struct TreeNode* root) {
    _ST01 . nodeRoot = root ;
    _ST01 . curNode  = _findPrev( root ) ;
    return &_ST01 ;
}


bool bSTIteratorHasNext(BSTIterator* obj) {
    if ( NULL == obj  ) return false ;
    if ( NULL == obj -> curNode ) return false ;
    return true ;
}


int bSTIteratorNext(BSTIterator* obj) {
    int __rt ; 
    if ( false == bSTIteratorHasNext( obj ) ) return -1 ;
    __rt = obj -> curNode -> val ; 
    obj -> curNode = _findNext( obj -> nodeRoot , obj -> curNode ) ;
    return __rt ;
}

void bSTIteratorFree(BSTIterator* obj) {
    
}

