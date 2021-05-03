#include "h00.h"

BSTIterator* bSTIteratorCreate(struct TreeNode* root) {
    if ( NULL == root ) return NULL ;

    _ST01 . nodeRoot = root ;
    _ST01 . firstNode  = _findFirst( root ) ;
    _ST01 . curNode  = _ST01 . firstNode  ;

    //printf( "created : %d %d %d.\n" , root -> val , _ST01 . firstNode -> val , _ST01 . curNode -> val);

    return &_ST01 ;
}

int bSTIteratorNext(BSTIterator* obj) {
    int __rt ; 
    if ( NULL == obj ) return -1 ;

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


void bSTIteratorFree(BSTIterator* ___iter) {
    if ( NULL == ___iter ) return ;
    ___iter -> nodeRoot = NULL ;
    ___iter -> firstNode  = NULL ;
    ___iter -> curNode  = NULL ;
}

struct TreeNode* deleteNode(struct TreeNode* ___tn, int key){
    TreeNode* __tmpTN ;
    if ( NULL == ___tn ) return NULL ;

    printf( "1838181 : trying delete %d\n" , key ) ;

    if ( key == ___tn -> val ) {
        if ( NULL == ___tn -> right ) {
            __tmpTN = ___tn -> left ;
            _freeOneNode( ___tn ) ;
            return __tmpTN ;
        }
    }

    return ___tn ;
} // deleteNode

