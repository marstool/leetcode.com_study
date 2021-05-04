#ifndef H01
#define H01

typedef struct {

} KthLargest;

void kthLargestFree(KthLargest* obj) ;
int kthLargestAdd(KthLargest* obj, int val) ;
KthLargest* kthLargestCreate(int k, int* nums, int numsSize) ;

#endif
