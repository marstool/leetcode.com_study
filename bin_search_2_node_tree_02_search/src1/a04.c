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

const char * _dumpOneTreeNode(TreeNode* ___tn){
    static char __dBuf[256] ;
    char __dBuf2[256] ;

    if ( NULL == ___tn ) return "L(*) ** R(*)" ;

    if (NULL == ___tn -> left) strcpy( __dBuf , "L(*)" );
    else                      sprintf( __dBuf , "L(%d)", ___tn -> left -> val );

    sprintf( __dBuf2 , " %d ", ___tn -> val );
    strcat( __dBuf , __dBuf2 );


    if (NULL == ___tn -> right) sprintf( __dBuf2 , "L(*)" );
    else                        sprintf( __dBuf2 , "L(%d)", ___tn -> right -> val );
    strcat( __dBuf , __dBuf2 );

    return __dBuf ;
} // _dumpOneTreeNode

void _dumpBSTsort( BSTIterator * ___iter ) {
    bool __rt ;
    //TreeNode * __treeNode01;
    //TreeNode * __treeNode02;

    if ( NULL == ___iter ) { printf( "===== NULL BSTIterator MET ! 81839111 =====\n\n" ); return ; }

    printf ( " the BSTiter is : nodeRoot : %s,  first : %s, current : %s \n" , 
            _dumpOneTreeNode( ___iter -> nodeRoot ),
            _dumpOneTreeNode( ___iter -> firstNode ),
            _dumpOneTreeNode( ___iter -> curNode )
           );


    __rt = isValidBST( ___iter -> nodeRoot );
    if ( false == __rt ) {
        printf( "===== inValid BSTIterator Found ! 81839112 =====\n" ); 
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
