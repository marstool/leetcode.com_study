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
    TreeNode* __tmpTN  ;
    TreeNode* __tmpTN2 ;
    //bool __replace_root ;

    if ( NULL == ___tn ) return NULL ;

    printf( "1838181 : trying delete %d\n" , key ) ;

    if ( key == ___tn -> val ) { // try delete the root
        printf( "1838183 : found and delete %d\n" , key ) ;
        if ( NULL == ___tn -> left ) { // delete the root while no left-child
            __tmpTN = ___tn -> right ;
            _freeOneNode( ___tn ) ;
            return __tmpTN ;
        }
        if ( NULL == ___tn -> right ) { // delete the root while no right-child
            __tmpTN = ___tn -> left ;
            _freeOneNode( ___tn ) ;
            return __tmpTN ;
        }

        // both left and right exist, delete root.
        __tmpTN = ___tn -> right ;
        __tmpTN2 = __tmpTN -> left ;
        if ( NULL == __tmpTN2 ){
            __tmpTN -> left = ___tn -> left ;
            _freeOneNode( ___tn ) ;
            return __tmpTN ;
        }

        while ( NULL != __tmpTN2 -> left ) {
            __tmpTN2 = __tmpTN2 -> left ;
        }

        __tmpTN2 -> left = ___tn -> left ;
        _freeOneNode( ___tn ) ;
        return __tmpTN ;
    }

    if ( key > ___tn -> val ) { // try delete the root-right-child
        ___tn -> right = deleteNode( ___tn -> right , key);
    } else { // try delete the root-left-child
        ___tn -> left  = deleteNode( ___tn -> left  , key);
    }

    return ___tn ; // keep the origin root
} // deleteNode

