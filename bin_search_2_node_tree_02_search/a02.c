#include "h00.h"


struct TreeNode * _treeNodeCreate( char *___sbuf ) {
    printf( "trying to create for <%s>, get < " , ___sbuf?___sbuf:"(null)" );
    return NULL ;
}
int               _treeNodeFree( struct TreeNode * ___treeNodeTop){
    return 0 ;
}
