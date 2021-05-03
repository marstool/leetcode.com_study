#include "h00.h"

#define _DP if(0)
//#define _DP if(1)

TreeNode _treeNodeArr[ _max_treeAmount ] ;
TreeNode * _treeNode_top ;
char _str_null[] = "null" ;

TreeNode * _searchNode( TreeNode * ___topNode , int ___idx ) {
    int __upIdx ;
    int __upL0R1 ;

    if ( NULL == ___topNode ) return NULL ;
    if ( 0 >= ___idx ) return NULL ;

    if ( 1 == ___idx ) return ___topNode ;

    __upL0R1 = (___idx & 1);
    __upIdx = ( ___idx >> 1) ;

    _DP printf ( " 83819191 ___idx %d , __upIdx %d , __upL0R1 %d  \n" , ___idx , __upIdx , __upL0R1 );

    if ( 0 != __upIdx ) {
        ___topNode = _searchNode( ___topNode , __upIdx ) ;
        if ( NULL == ___topNode ) {
            printf ( " 83819197 unexpect rt NULL\n" );
            return NULL ;
        }
    }

    if ( 0 == __upL0R1 ) {
        return ___topNode -> left ;
    }
    return ___topNode -> right ;

} // _searchNode

TreeNode * _treeNodeCreateOneX( TreeNode * ___topNode , char *___sbuf , int ___idx ) {
    int __cn02 ;
    int __upIdx ;
    int __upL0R1 ;
    int __v01 ;
    TreeNode * __rtNode ;
    TreeNode * __tmpNode ;

    __rtNode = NULL ;

    if ( 1 == ___idx ) { _DP printf("\n"); } 
    _DP printf("8381911 [%d]<%s>\n", ___idx , ___sbuf);

    if ( NULL == ___sbuf  ) {
        printf( "8381913 error _treeNodeCreateOneX : %d : %s\n", ___idx , (NULL==___sbuf)?"null":"notNull" ); 
        return NULL ;
    }

    __cn02 = strlen( ___sbuf )  ;
    if ( __cn02 == 4 
            && ___sbuf[0] == 'n' 
            && ___sbuf[1] == 'u' 
            && ___sbuf[2] == 'l' 
            && ___sbuf[3] == 'l' 
       ) 
    {
        _DP printf("8381915 null found\n");
        return NULL ;
    }

    __v01 = atoi( ___sbuf ) ;
    __rtNode = _newBST( __v01 ) ;

    if ( 1 == ___idx ) {
        _DP printf("8381917 first.\n");
        return __rtNode ;
    }

    __upL0R1 = (___idx & 1);
    __upIdx = ( ___idx >> 1) ;
    __tmpNode = _searchNode( ___topNode , __upIdx ) ;

    if ( NULL == __tmpNode ) {
        _DP printf("8381919 rt NULL! why ?. free %d nodeS. \n", _treeNodeFree( __rtNode ) );
        return NULL ;
    }

    if ( 0 == __upL0R1 ) {
        __tmpNode -> left  = __rtNode ; 
    } else {
        __tmpNode -> right = __rtNode ; 
    }

    return __rtNode ;
} // _treeNodeCreateOneX

/*
   void _treeNodeCreateOne( char *___sbuf , int ___idx ) {
   int __cn02 ;
   int __upIdx ;
   int __upL0R1 ;
   int __v01 ;

   if ( 1 == ___idx ) { _DP printf("\n"); } ; _DP printf("[%d]<%s>\n", ___idx , ___sbuf);
   if ( NULL == ___sbuf 
   || 0 >= ___idx 
   || _max_treeAmount <= ___idx ) {
   fprintf( stderr , "error _treeNodeCreateOne : %d : %s\n", ___idx , (NULL==___sbuf)?"null":"notNull" ); 
   return ;
   }
   __cn02 = strlen( ___sbuf )  ;

   _treeNodeArr[___idx] . left  = NULL ;
   _treeNodeArr[___idx] . right = NULL ;

   __upIdx = (___idx >> 1) ;
   __upL0R1 = (___idx & 1);

   if ( __cn02 == 4 
   && ___sbuf[0] == 'n' 
   && ___sbuf[1] == 'u' 
   && ___sbuf[2] == 'l' 
   && ___sbuf[3] == 'l' 
   ) {
   __v01 = 0 ;
   if ( 1 == __upL0R1 ) {  _treeNodeArr[__upIdx] . right = NULL ; }
   else                 {  _treeNodeArr[__upIdx] . left  = NULL ; }
   } else {
   __v01 = atoi( ___sbuf ) ;
   if ( 1 == __upL0R1 ) {  _treeNodeArr[__upIdx] . right = _treeNodeArr + ___idx ; }
   else                 {  _treeNodeArr[__upIdx] . left  = _treeNodeArr + ___idx ; }
   }

   _treeNodeArr[___idx] . val = __v01 ;

   } // _treeNodeCreateOne
   */

TreeNode * _treeNodeCreateX( char *___sbuf ) {
    int __cn01 ;
    int __cn02 ;
    int __cn09 ;
    char *__cp01 ;
    char __buf[256] ;
    TreeNode * __tmpNode ;

    _treeNode_top = NULL ;

    _DP printf( "trying to create for <%s>, get < " , ___sbuf?___sbuf:"(null)" );
    if ( NULL == ___sbuf ) {  // EOF met
        return NULL ; 
    }

    __cn09 = 0 ;
    for ( __cn01 = 1 ; __cn01 < _max_treeAmount ; __cn01 ++ ){
        __cp01 = index(___sbuf , ',');
        if ( NULL == __cp01 ) {
            __cn02 = strlen( ___sbuf )  ;
        } else {
            __cn02 = __cp01 - ___sbuf ;
        }

        strncpy( __buf , ___sbuf , __cn02 );
        __buf[__cn02] = 0 ;
        __tmpNode = _treeNodeCreateOneX( _treeNode_top , __buf , __cn01 ) ;

        if ( NULL != __tmpNode ) {
            __cn09 ++ ;
        }

        if ( 1 == __cn01 ) {
            _treeNode_top = __tmpNode ;
        }

        if ( NULL == __cp01 ) {
            break ;
        }

        ___sbuf += __cn02 + 1 ;
    }

    if ( __cn01 == _max_treeAmount ) {
        printf( "81838181 create nodeTree reach Max ( %d ) , why ?\n", _max_treeAmount ) ;
    } else {
        printf( "81838182 create nodeTree amount ( %d ) , correct ?\n", __cn09 ) ;
    }

    return _treeNode_top ;
} // _treeNodeCreateX
/*
   TreeNode * _treeNodeCreateBAK( char *___sbuf ) {
   int __cn01 ;
   int __cn02 ;
   char *__cp01 ;
   char __buf[256] ;

   _treeNode_top = NULL ;

   _DP printf( "trying to create for <%s>, get < " , ___sbuf?___sbuf:"(null)" );
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
   _treeNode_top = _treeNodeArr + 1 ;
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
   } // _treeNodeCreateBAK
   */

void _freeOneNode( TreeNode * ___treeNodeTop){
    // create by _newBST
    if ( NULL == ___treeNodeTop ) return ;
    free( ___treeNodeTop ) ;
} // _freeOneNode

int               _treeNodeFree( TreeNode * ___treeNodeTop){
    int __cnt01 ;

    if ( NULL == ___treeNodeTop ) {
        return 0 ;
    }

    __cnt01 = 1 ;
    __cnt01 += _treeNodeFree( ___treeNodeTop -> left ) ;
    __cnt01 += _treeNodeFree( ___treeNodeTop -> right ) ;

    _freeOneNode( ___treeNodeTop ) ;

    return __cnt01 ;
} // _treeNodeFree
