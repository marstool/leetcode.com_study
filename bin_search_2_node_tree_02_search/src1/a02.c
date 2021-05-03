#include "h00.h"

#define _dbtc if(1)
//#define _dbtc 

TreeNode _treeNodeArr[ _max_treeAmount ] ;
TreeNode * _treeNode_top ;
char _str_null[] = "null" ;

TreeNode * _treeNodeCreateOneX( TreeNode * ___topNode , char *___sbuf , int ___idx ) {
    int __cn02 ;
    int __upIdx ;
    int __upL0R1 ;
    int __v01 ;
    TreeNode * __rtNode ;

    __rtNode = NULL ;
    if ( 1 == ___idx ) { _dbtc printf("\n"); } ; _dbtc printf("[%d]<%s>\n", ___idx , ___sbuf);
    if ( NULL == ___sbuf  ) {
        printf( "8381911 error _treeNodeCreateOneX : %d : %s\n", ___idx , (NULL==___sbuf)?"null":"notNull" ); 
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
        return NULL ;
    }

    __v01 = atoi( ___sbuf ) ;
    __rtNode = _newBST( __v01 ) ;

    __upIdx = ___idx ;
    while ( 1 ) {
        __upIdx = (__upIdx >> 1) ;
        if ( 0 == __upIdx ) {
            __upL0R1 = (___idx & 1);
            break ; 
        }
    }

    return __rtNode ;
} // _treeNodeCreateOneX

/*
   void _treeNodeCreateOne( char *___sbuf , int ___idx ) {
   int __cn02 ;
   int __upIdx ;
   int __upL0R1 ;
   int __v01 ;

   if ( 1 == ___idx ) { _dbtc printf("\n"); } ; _dbtc printf("[%d]<%s>\n", ___idx , ___sbuf);
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

    _dbtc printf( "trying to create for <%s>, get < " , ___sbuf?___sbuf:"(null)" );
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

        if ( NULL == __tmpNode ) {
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
        printf( " 81838181 create nodeTree reach Max ( %d ) , why ?\n", _max_treeAmount ) ;
    } else {
        printf( " 81838182 create nodeTree amount ( %d ) , why ?\n", __cn09 ) ;
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

   _dbtc printf( "trying to create for <%s>, get < " , ___sbuf?___sbuf:"(null)" );
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

int               _treeNodeFree( TreeNode * ___treeNodeTop){
    return 0 ;
}
