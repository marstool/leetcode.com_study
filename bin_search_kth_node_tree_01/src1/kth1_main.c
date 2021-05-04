#include "h01.h"

int main(int ___argc, char ** ___argv ) {
    KthLargest* __kthP ;
    int __i01 ;
    int __iarr[] = {4, 5, 8, 2} ;

    __kthP = kthLargestCreate( 3, __iarr, 4 ) ;

    __i01 = kthLargestAdd( __kthP , 3 );
    __i01 = kthLargestAdd( __kthP , 5 );
    __i01 = kthLargestAdd( __kthP , 10 );
    __i01 = kthLargestAdd( __kthP , 9 );
    __i01 = kthLargestAdd( __kthP , 4 );

    return __i01 ;
} // main
