#include "h00.h"

bool isValidBST(struct TreeNode* root);

// [5,1,4,null,null,3,6]
//
struct TreeNode a22 = { 3, NULL , NULL };
struct TreeNode a23 = { 6, NULL , NULL };
struct TreeNode a10 = { 1, NULL , NULL };
struct TreeNode a11 = { 4, &a22 , &a23 };
struct TreeNode a00 = { 5, &a10 , &a11 };

int main( int ___argc , char **___argv ){
    bool __rt ;
    __rt = isValidBST( &a00 );
    printf ( "true is :%s\n" , true?"true":"false" );
    printf ( "false is :%s\n" , false?"true":"false" );
    printf ( "result is :%d\n" , __rt );
    printf ( "result is :%s\n" , __rt?"true":"false" );
    return 0 ;
}
