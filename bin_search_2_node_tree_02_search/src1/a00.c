#include "h00.h"

bool isValidBST(TreeNode* root);

//#ifdef kk
// [5,1,4,null,null,3,6]
//
TreeNode a22 = { 3, NULL , NULL };
TreeNode a23 = { 6, NULL , NULL };
TreeNode a10 = { 1, NULL , NULL };
TreeNode a11 = { 4, &a22 , &a23 };
TreeNode a00 = { 5, &a10 , &a11 };
//#endif

// [[[7,3,15,null,null,9,20]],[],[],[],[],[],[],[],[],[]]
TreeNode d22 = { 9, NULL , NULL };
TreeNode d23 = { 20, NULL , NULL };
TreeNode d11 = { 3, NULL , NULL };
TreeNode d10 = { 15, &d22 , &d23 };
TreeNode d00 = { 7, &d10 , &d11 };

// [3,1,4,null,2]
TreeNode b22 = { 2, NULL , NULL };
TreeNode b10 = { 4, NULL , NULL };
TreeNode b11 = { 1, NULL , &b22 };
TreeNode b00 = { 3, &b10 , &b11 };

int main( int ___argc , char **___argv ){
    bool __rt ;
    BSTIterator *__st01 ;
    TreeNode * __treeNode01;

    printf ( "\n\n" );
    //printf ( "true is :%s\n" , true?"true":"false" );
    //printf ( "false is :%s\n" , false?"true":"false" );
    //printf ( "result is :%d\n" , __rt );
    printf ( "\n\n" );
    __rt = isValidBST( &a00 );
    printf ( "result is :========= a00 : %s\n" , __rt?"true":"false" );
    printf ( "\n\n" );
    __rt = isValidBST( &b00 );
    printf ( "result is :========= b00 : %s\n" , __rt?"true":"false" );
    printf ( "\n\n" );
    __rt = isValidBST( &d00 );
    printf ( "result is :========= d00 : %s\n" , __rt?"true":"false" );
    printf ( "\n\n" );

    __st01 = bSTIteratorCreate( &a00 ) ;

//     bSTIterator.next();    // return 3
//     bSTIterator.next();    // return 7
//     bSTIterator.hasNext(); // return True
//     bSTIterator.next();    // return 9
//     bSTIterator.hasNext(); // return True
//     bSTIterator.next();    // return 15
//     bSTIterator.hasNext(); // return True
//     bSTIterator.next();    // return 20
//     bSTIterator.hasNext(); // return False
    printf( "next get : %d\n" , bSTIteratorNext( __st01 ) );    // return 3
    printf( "next get : %d\n" , bSTIteratorNext( __st01 ) );    // return 7
    printf( "Has next ? %s\n" , bSTIteratorHasNext( __st01 ) ? "true" : "false" ); // return True
    printf( "next get : %d\n" , bSTIteratorNext( __st01 ) );    // return 9
    printf( "Has next ? %s\n" , bSTIteratorHasNext( __st01 ) ? "true" : "false" ); // return True
    printf( "next get : %d\n" , bSTIteratorNext( __st01 ) );    // return 15
    printf( "Has next ? %s\n" , bSTIteratorHasNext( __st01 ) ? "true" : "false" ); // return True
    printf( "next get : %d\n" , bSTIteratorNext( __st01 ) );    // return 20
    printf( "Has next ? %s\n" , bSTIteratorHasNext( __st01 ) ? "true" : "false" ); // return False
    printf( " expect --- 7,3,15,null,null,9,20    , 3 7 9 15 20 \n\n" );

    __st01 = bSTIteratorCreate( &b00 ) ;
    printf( "next get : %d\n" , bSTIteratorNext( __st01 ) );    // return 3
    printf( "next get : %d\n" , bSTIteratorNext( __st01 ) );    // return 7
    printf( "Has next ? %s\n" , bSTIteratorHasNext( __st01 ) ? "true" : "false" ); // return True
    printf( "next get : %d\n" , bSTIteratorNext( __st01 ) );    // return 9
    printf( "Has next ? %s\n" , bSTIteratorHasNext( __st01 ) ? "true" : "false" ); // return True
    printf( "next get : %d\n" , bSTIteratorNext( __st01 ) );    // return 15
    printf( "Has next ? %s\n" , bSTIteratorHasNext( __st01 ) ? "true" : "false" ); // return True
    printf( "next get : %d\n" , bSTIteratorNext( __st01 ) );    // return 20
    printf( "Has next ? %s\n" , bSTIteratorHasNext( __st01 ) ? "true" : "false" ); // return False
    printf( " expect --- 3,1,4,null,2        1 2 3 4 \n\n" );

    __treeNode01 = _treeNodeCreate("5,1,4,null,null,3,6");
    __rt = isValidBST( __treeNode01 );
    printf ( "create result is :========= %s\n" , __rt?"true":"false" );

    printf( "\n\n" ) ;
    return 0 ;
}
