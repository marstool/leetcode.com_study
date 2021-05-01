#include "h00.h"

char _buf[256] ;
char * _dumpT1( struct TreeNode*  ___d ){
    _buf[0] = 0 ;
    char __buf2[256] ;
    if ( ___d == NULL ) {
        sprintf( _buf, "(null)");
    } else {
        sprintf( _buf, "%d:" , ___d -> val );

        if ( ___d -> left == NULL ) {
            strcat( _buf, "<null1>" );
        } else {
            sprintf(__buf2, "%d" , ___d -> left -> val );
            strcat( _buf, __buf2);
        }

        if ( ___d -> right == NULL ) {
            strcat( _buf, ",<null2>" );
        } else {
            sprintf(__buf2, ",%d" , ___d -> right -> val );
            strcat( _buf, __buf2);
        }
    }
    return _buf ;
}

bool valid2_debug = false ;
bool valid2(struct TreeNode* ___L, struct TreeNode* root, struct TreeNode* ___R){
    //bool __rtLeft ;
    //bool __rtRight ;

    if ( valid2_debug ) {
        printf( "%s" , _dumpT1( ___L ));
        printf( "--" );
        printf( "%s", _dumpT1( root ));
        printf( "--" );
        printf( "%s" , _dumpT1( ___R ));
        printf( "\n\n" );
    }

    if ( root == NULL ) return true ;

    if ( ___L != NULL ) {
        if ( ___L -> val >= root->val ) return false;
    }
    if ( ___R != NULL ) {
        if ( ___R -> val <= root->val ) return false;
    }

    if ( false == valid2( ___L , root -> left , root )) return false ; 
    if ( false == valid2( root , root -> right , ___R)) return false ; 

    return true;
}

bool isValidBST(TreeNode* root){
    //return valid2( root, NULL, NULL );
    //return valid2( root, root->left, root->right );
    return valid2( NULL , root, NULL );
}
