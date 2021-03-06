#include "h00.h"

#define DP if(0)

void _dumpOneTreeNode(TreeNode* ___tn){
    if ( NULL == ___tn ) { printf( "L(*) ** R(*)" ); return ; }

    if (NULL == ___tn -> left) printf( "L(*)" );
    else                       printf( "L(%d)", ___tn -> left -> val );

    printf( " %d ", ___tn -> val );


    if (NULL == ___tn -> right) printf( "L(*)" );
    else                        printf( "L(%d)", ___tn -> right -> val );

    return ;
} // _dumpOneTreeNode


void _dumpTreeNode(TreeNode* root, char * ___sep){
    //int __i01 ; 
    //TreeNode* __tp ;

    if ( NULL == root ) { printf( "===== NULL treeNodeArr MET ! 1838191 =====\n" ); return ; }

    {_dumpOneTreeNode( root ) ; printf("%s", ___sep);}

    if ( NULL != root -> left)   _dumpTreeNode(    root -> left  , ___sep) ;

    if ( NULL != root -> right)  _dumpTreeNode(    root -> right , ___sep) ;
} // _dumpTreeNode

/*
void _dumpTreeNodeBAK(TreeNode* root){
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
*/

void _dumpBSTsort( BSTIterator * ___iter ) {
    bool __rt ;
    int __cnt01;
    //TreeNode * __treeNode01;
    //TreeNode * __treeNode02;

    if ( NULL == ___iter ) { printf( "===== NULL BSTIterator MET ! 81839111 =====\n\n" ); return ; }

    if(0) printf ( " 81839112 the BSTiter is : nodeRoot : %d,  first : %d, current : %d \n" 
            , ___iter -> nodeRoot -> val  
            , ___iter -> firstNode -> val 
            , ___iter -> curNode -> val 
            );

    DP printf ( " 81839113 the BSTiter is : nodeRoot : " );
    DP _dumpOneTreeNode( ___iter -> nodeRoot );
    DP printf ( " first : " );
    DP _dumpOneTreeNode( ___iter -> firstNode );
    DP printf ( " current : " );
    DP _dumpOneTreeNode( ___iter -> curNode );
    DP printf ( "\n" );


    __rt = isValidBST( ___iter -> nodeRoot );
    if ( false == __rt ) {
        printf( "===== inValid BSTIterator Found ! 81839115 =====\n\n" ); 
        DP _dumpTreeNode( ___iter -> nodeRoot , " ");
        //printf("\n");
        return ; 
    }
    DP _dumpTreeNode( ___iter -> nodeRoot , " ");

    for ( __cnt01 = 20 ; __cnt01 > 0 ; __cnt01 -- ) {
        if ( true == bSTIteratorHasNext( ___iter ) ) {
            printf( " y:%d " , bSTIteratorNext( ___iter )) ;
        } else {
            printf( " n.\n" );
            break ;
        }
    }

    printf("\n");
} // _dumpBSTsort
