#include "h00.h"

void _dumpTreeNode(TreeNode* root){
    int __i01 ; 
    TreeNode* __tp ;

    if ( NULL == root ) { printf( "===== NULL treeNodeArr MET ! 1838191 =====\n" ); return ; }

    for ( __i01 = -1 ; __i01 < _max_treeAmount - 1; __i01 ++ ) {
        __tp = root + __i01 ;

        if (NULL == __tp -> left) printf( "L(*)" );
        else                      printf( "L(%d)", __tp -> left -> val );

        printf( " %d ", __tp -> val );

        if (NULL == __tp -> right) printf( "R(*)" );
        else                       printf( "R(%d)", __tp -> right -> val );

        if ( 2 == __i01 % 4 ) {
            printf( "\n" ) ;
        } else {
            printf( "\t" ) ;
        }
    }
} // _dumpTreeNode

void _dumpOneTreeNode(TreeNode* ___tn){
    if ( NULL == ___tn ) { printf( "L(*) ** R(*)" ); return ; }

    if (NULL == ___tn -> left) printf( "L(*)" );
    else                       printf( "L(%d)", ___tn -> left -> val );

    printf( " %d ", ___tn -> val );


    if (NULL == ___tn -> right) printf( "L(*)" );
    else                        printf( "L(%d)", ___tn -> right -> val );

    return ;
} // _dumpOneTreeNode

void _dumpBSTsort( BSTIterator * ___iter ) {
    bool __rt ;
    //TreeNode * __treeNode01;
    //TreeNode * __treeNode02;

    if ( NULL == ___iter ) { printf( "===== NULL BSTIterator MET ! 81839111 =====\n\n" ); return ; }

    if(0) printf ( " 81839112 the BSTiter is : nodeRoot : %d,  first : %d, current : %d \n" 
            , ___iter -> nodeRoot -> val  
            , ___iter -> firstNode -> val 
            , ___iter -> curNode -> val 
           );

    printf ( " 81839113 the BSTiter is : nodeRoot : " );
    _dumpOneTreeNode( ___iter -> nodeRoot );
    printf ( " first : " );
    _dumpOneTreeNode( ___iter -> firstNode );
    printf ( " current : " );
    _dumpOneTreeNode( ___iter -> curNode );
    printf ( "\n" );


    __rt = isValidBST( ___iter -> nodeRoot );
    if ( false == __rt ) {
        printf( "===== inValid BSTIterator Found ! 81839115 =====\n" ); 
        _dumpTreeNode( ___iter -> nodeRoot );
        printf("\n");
        return ; 
    }

    //__treeNode01 = ___iter -> nodeRoot ;
    //__treeNode02 = ___iter -> firstNode ;
    //TreeNode * __treeNode02;

    // __rt = isValidBST( __treeNode01 );
    printf("\n");
} // _dumpBSTsort
