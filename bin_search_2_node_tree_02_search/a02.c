#include "h00.h"


struct TreeNode * _treeNodeCreate( char *___sbuf ) {
    int __cn01 ;
    char *__ch01 ;
    int __cn02 ;
    printf( "trying to create for <%s>, get < " , ___sbuf?___sbuf:"(null)" );
    if ( NULL == ___sbuf ) { return NULL ; }

    for ( __cn01 = 10 ; __cn01 > 0 ; __cn01 -- ){
        __ch01 = index(___sbuf , ',');
        if ( NULL == __ch01 ) {
            printf("(null)\n");
        } else {
            __cn02 = __ch01 - ___sbuf ;
            printf("(%d, %d)\n", __ch01, __cn02 );
        }

        if ( NULL == __ch01 ) { break ; }
        ___sbuf += __cn02 + 1 ;
    }

    return NULL ;
}
int               _treeNodeFree( struct TreeNode * ___treeNodeTop){
    return 0 ;
}
