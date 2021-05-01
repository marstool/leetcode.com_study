#include "h00.h"

void _dumpTreeNode(TreeNode* root){
    int __i01 ; 
    TreeNode* __tp ;

    if ( NULL == root ) { printf( "===== NULL treeNodeArr MET ! =====\n" ); return ; }

    for ( __i01 = 0 ; __i01 < _max_treeAmount ; __i01 ++ ) {
        __tp = root + __i01 ;

        if (NULL == __tp -> left) printf( "L(*)" );
        else                      printf( "L(%d)", __tp -> left -> val );

        printf( " %d ", __tp -> val );

        if (NULL == __tp -> right) printf( "R(*)" );
        else                       printf( "R(%d)", __tp -> right -> val );
        
        if ( 3 == __i01 % 4 ) {
            printf( "\n" ) ;
        } else {
            printf( "\t" ) ;
        }
    }
} // _dumpTreeNode

void _dumpBSTsort( BSTIterator * ___iter ) {
} // _dumpBSTsort
