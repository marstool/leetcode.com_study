#include "h00.h"


//#define _max_treeAmount    32    // moust be 2 ^^ 1,2,3,4,5.... 2, 4, 8 , 16 , 32
#define _max_treeAmount    16    // moust be 2 ^^ 1,2,3,4,5.... 2, 4, 8 , 16 , 32
TreeNode _treeNodeArr[ _max_treeAmount ] ;
TreeNode * _treeNode_top ;
char _str_null[] = "null" ;

void _treeNodeCreateOne( char *___sbuf , int ___idx ) {
    if ( 1 == ___idx ) { printf("\n"); } ; printf("[%d]<%s>\n", ___idx , ___sbuf);
    /*
       if ( __cn02 == 4 
       && ___sbuf[0] == 'n' 
       && ___sbuf[1] == 'u' 
       && ___sbuf[2] == 'l' 
       && ___sbuf[3] == 'l' 
       ) {
       } else {
       }
       */
} // _treeNodeCreateOne

TreeNode * _treeNodeCreate( char *___sbuf ) {
    int __cn01 ;
    int __cn02 ;
    char *__cp01 ;
    char __buf[256] ;

    _treeNode_top = NULL ;

    printf( "trying to create for <%s>, get < " , ___sbuf?___sbuf:"(null)" );
    if ( NULL == ___sbuf ) {  // EOF met
        return NULL ; 
    }

    for ( __cn01 = 1 ; __cn01 < _max_treeAmount ; __cn01 ++ ){
        __cp01 = index(___sbuf , ',');
        if ( NULL == __cp01 ) {
            __cn02 = strlen( ___sbuf )  ;
        } else {
            __cn02 = __cp01 - ___sbuf ;
        }

        strncpy( __buf , ___sbuf , __cn02 );
        __buf[__cn02] = 0 ;
        _treeNodeCreateOne( __buf , __cn01 ) ;

        if ( 1 == __cn01 ) {
            _treeNode_top = _treeNodeArr ;
        }

        if ( NULL == __cp01 ) {
            __cn01 ++ ;
            while ( __cn01 < _max_treeAmount ) { // set NULL to the remain
                _treeNodeCreateOne( _str_null , __cn01 ) ;
                __cn01 ++ ;
            }
            break ;
        }

        ___sbuf += __cn02 + 1 ;
    }

    return _treeNode_top ;
}
int               _treeNodeFree( TreeNode * ___treeNodeTop){
    return 0 ;
}
