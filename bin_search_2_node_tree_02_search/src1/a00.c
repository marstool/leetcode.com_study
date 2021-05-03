#include "h00.h"

#define _DP if(0)

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

void test01(){
    bool __rt ;
    BSTIterator *__st01 ;

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

} // test01

char _str00[] = "2,1,3";
char _str01[] = "5,1,4,null,null,3,6" ;  // false
char _str02[] = "7,3,15,null,null,9,20" ;
char _str03[] = "3,1,4,null,2" ;
char _str04[] = "4,2,7,1,3" ;
char _str05[] = "5,2,6,1,7,4,3" ;
char _str06[] = "5,3,6,2,4,null,7" ;

char _str09[] = "1921,1803,6938,1013,1912,6297,8607,638,1236,null,null,2414,6769,7883,9737,39,925,1137,1384,2257,5154,6620,null,7145,8188,8988,9951,null,145,727,null,null,null,null,null,2041,2338,2899,6006,6322,6706,null,7742,8090,8470,8699,9611,9861,null,null,210,null,770,null,2052,null,null,2875,4577,5291,6281,null,6342,null,null,7478,null,null,8139,8340,8501,null,8703,9270,null,null,null,null,592,null,834,null,null,2510,null,3109,4808,null,5352,6094,null,null,6486,7311,null,null,8142,8242,null,null,null,null,8867,null,null,null,null,null,null,2437,2543,2970,4132,4705,4840,5330,5360,6033,6191,null,null,null,7331,null,null,null,null,null,null,null,2505,null,null,2910,null,3181,4418,null,4735,null,4982,null,null,null,5542,null,null,null,6218,null,null,null,null,null,null,3155,3738,4368,4509,null,null,null,null,null,5548,null,null,null,null,3721,3893,null,null,4508,4555,null,5768,3321,null,3837,null,null,null,null,null,null,null,3303,3607,null,null,null,null,3324,3644,null,3507,null,null,null,null" ;
//10001

void test02(){
    TreeNode * __treeNode01;
    bool __rt ;

    __treeNode01 = _treeNodeCreateX( _str00 );
    __rt = isValidBST( __treeNode01 );
    printf ( "create result is :========= %s : %s \n" , __rt?"true":"false" , _str00 );
    _dumpTreeNode( __treeNode01 );

    __treeNode01 = _treeNodeCreateX( _str01 );
    __rt = isValidBST( __treeNode01 );
    printf ( "create result is :========= %s : %s \n" , __rt?"true":"false" , _str01 );
    _dumpTreeNode( __treeNode01 );

    __treeNode01 = _treeNodeCreateX( _str02 );
    __rt = isValidBST( __treeNode01 );
    printf ( "create result is :========= %s : %s \n" , __rt?"true":"false" , _str02 );
    _dumpTreeNode( __treeNode01 );

    __treeNode01 = _treeNodeCreateX( _str03 );
    __rt = isValidBST( __treeNode01 );
    printf ( "create result is :========= %s : %s \n" , __rt?"true":"false" , _str03 );
    _dumpTreeNode( __treeNode01 );

    printf( "\n\n" ) ;
} // test02

void test03(){
    BSTIterator * __tmpIter ;
    TreeNode * __treeNode01;
    //bool __rt ;

    printf ( "create --- %s \n" , _str00 );
    __treeNode01 = _treeNodeCreateX( _str00 );
    __tmpIter = bSTIteratorCreate( __treeNode01 ) ;
    _dumpBSTsort( __tmpIter ) ;
    // return ;

    printf ( "create --- %s \n" , _str01 );
    __treeNode01 = _treeNodeCreateX( _str01 );
    __tmpIter = bSTIteratorCreate( __treeNode01 ) ;
    _dumpBSTsort( __tmpIter ) ;

    printf ( "create --- %s \n" , _str02 );
    __treeNode01 = _treeNodeCreateX( _str02 );
    __tmpIter = bSTIteratorCreate( __treeNode01 ) ;
    _dumpBSTsort( __tmpIter ) ;

    printf ( "create --- %s \n" , _str03 );
    __treeNode01 = _treeNodeCreateX( _str03 );
    __tmpIter = bSTIteratorCreate( __treeNode01 ) ;
    _dumpBSTsort( __tmpIter ) ;

} // test03

void test04(){
    TreeNode * __tmpNode;
    BSTIterator * __tmpIter ;

    __tmpNode = NULL;

    // "5,2,6,1,7,4,3" ;
    // struct TreeNode* insertIntoBST(struct TreeNode* root, int val){
    __tmpNode = insertIntoBST( __tmpNode , 5 );
    __tmpNode = insertIntoBST( __tmpNode , 2 );
    __tmpNode = insertIntoBST( __tmpNode , 6 );
    __tmpNode = insertIntoBST( __tmpNode , 1 );
    __tmpNode = insertIntoBST( __tmpNode , 7 );
    __tmpNode = insertIntoBST( __tmpNode , 4 );
    __tmpNode = insertIntoBST( __tmpNode , 3 );
    _DP _dumpTreeNode( __tmpNode );

    __tmpIter = bSTIteratorCreate( __tmpNode ) ;
    printf ( "create result is :========= %s\n" , (isValidBST( __tmpNode ))?"true":"false" );
    _dumpBSTsort( __tmpIter ) ;

    printf("\n");

} // test04

void test05(){
    BSTIterator * __tmpIter ;
    TreeNode * __treeNode01;
    int __rt ;

    __treeNode01 = _treeNodeCreateX( _str06 ); // "5,3,6,2,4,null,7" 
    __rt = isValidBST( __treeNode01 );
    printf ( "create result is :========= %s : %s \n" , __rt?"true":"false" , _str03 );
    //_dumpTreeNode( __treeNode01 );

    __tmpIter = bSTIteratorCreate( __treeNode01 ) ;
    _dumpBSTsort( __tmpIter ) ;

    __treeNode01 = deleteNode( __treeNode01 , 0 ) ;
    __tmpIter = bSTIteratorCreate( __treeNode01 ) ;
    _dumpBSTsort( __tmpIter ) ;

    __treeNode01 = deleteNode( __treeNode01 , 3 ) ;
    __tmpIter = bSTIteratorCreate( __treeNode01 ) ;
    _dumpBSTsort( __tmpIter ) ;

} // test05


int main( int ___argc , char **___argv ){
    //test01();
    //test02();
    //test03();
    //test04();
    test05();
    return 0 ;
} // main
