#include "h00.h"

BSTIterator* bSTIteratorCreate(struct TreeNode* root) {
    _ST01 . nodeRoot = root ;
    _ST01 . firstNode  = _findFirst( root ) ;
    _ST01 . curNode  = _ST01 . firstNode  ;
    return &_ST01 ;
}

int bSTIteratorNext(BSTIterator* obj) {
    int __rt ; 
    if ( false == bSTIteratorHasNext( obj ) ) return -1 ;
    __rt = obj -> curNode -> val ; 
    obj -> curNode = _findNext( obj -> nodeRoot , obj -> curNode ) ;
    return __rt ;
}

bool bSTIteratorHasNext(BSTIterator* obj) {
    if ( NULL == obj  ) return false ;
    if ( NULL == obj -> curNode ) return false ;
    return true ;
}


void bSTIteratorFree(BSTIterator* obj) {
    
}

