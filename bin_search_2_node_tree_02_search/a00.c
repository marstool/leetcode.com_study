#include "h00.h"

bool isValidBST(struct TreeNode* root);

#ifdef kk
// [5,1,4,null,null,3,6]
//
struct TreeNode a22 = { 3, NULL , NULL };
struct TreeNode a23 = { 6, NULL , NULL };
struct TreeNode a10 = { 1, NULL , NULL };
struct TreeNode a11 = { 4, &a22 , &a23 };
struct TreeNode a00 = { 5, &a10 , &a11 };
#endif

// [[[7,3,15,null,null,9,20]],[],[],[],[],[],[],[],[],[]]
struct TreeNode a22 = { 9, NULL , NULL };
struct TreeNode a23 = { 20, NULL , NULL };
struct TreeNode a10 = { 3, NULL , NULL };
struct TreeNode a11 = { 15, &a22 , &a23 };
struct TreeNode a00 = { 7, &a10 , &a11 };

int main( int ___argc , char **___argv ){
    bool __rt ;
    BSTIterator *__st01 ;

    __rt = isValidBST( &a00 );
    printf ( "\n\n" );
    printf ( "true is :%s\n" , true?"true":"false" );
    printf ( "false is :%s\n" , false?"true":"false" );
    printf ( "result is :%d\n" , __rt );
    printf ( "result is :========= %s\n" , __rt?"true":"false" );
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


    return 0 ;
}
