/*Name: Ahmad Wattad
  Project:avl
  Reviewer:
  Date: 
*/
/****************************** INCLUDES **************************************/
#include <stdio.h>

#include "avl.h"
/******************************************************************************/
static void TestFunc(void);
static void AVLCreateTest(void);
static void AVLInsertTest(void);
static void AVLSizeTest(void);
static void AVLIsEmptyTest(void);
static void AVLHeightTest(void);
static void AVLFindTest(void);
static void AVLRemoveTest(void);
static void AVLForEachTest(void);

/******************************************************************************/
static int CmpFunc(const void *avl_data, const void *data, void *params);
static int PrintTree(void *data, void *params);

/******************************************************************************/
int main()
{
    TestFunc();

    return SUCCESS;
}

/******************************************************************************/

static void TestFunc(void)
{
    AVLCreateTest();
    AVLInsertTest();
    AVLSizeTest();
    AVLIsEmptyTest();
    AVLHeightTest();
    AVLFindTest();
    AVLRemoveTest();
    AVLForEachTest();

}

static void AVLCreateTest(void)
{
    avl_ty *avl = NULL;
    avl = AVLCreate(CmpFunc, NULL);

    if(NULL == avl)
    {
        printf("AVLCreate test failed\n");
        return;
    }
    printf("AVLCreate passed the test successfully\n");

    AVLDestroy(avl);
}

static void AVLInsertTest(void)
{
    avl_ty *avl = NULL;
    avl = AVLCreate(CmpFunc, NULL);

    AVLInsert(avl, (void*)5);
    AVLInsert(avl, (void*)2);
    AVLInsert(avl, (void*)3);
    
    if(AVLIsEmpty(avl) || 3 != AVLSize(avl))
    {
        printf("AVLInsert test failed\n");
        return;
    }


    printf("AVLInsert passed the test successfully\n");

    AVLDestroy(avl);
}

static void AVLSizeTest(void)
{
    avl_ty *avl = NULL;
    size_t size_before_insert = 0;
    size_t size_after_insert = 0;
    avl = AVLCreate(CmpFunc, NULL);

    size_before_insert = AVLSize(avl);
    AVLInsert(avl, (void*)5);
    AVLInsert(avl, (void*)2);
    AVLInsert(avl, (void*)3);
    size_after_insert = AVLSize(avl);
    
    if(0 != size_before_insert || 3 != size_after_insert)
    {
        printf("AVLSize test failed: %d\n", size_after_insert);
        return;
    }


    printf("AVLSize passed the test successfully\n");

    AVLDestroy(avl);
}

static void AVLIsEmptyTest(void)
{
    avl_ty *avl = NULL;
    int status_before_insert = 0;
    int status_after_insert = 0;
    avl = AVLCreate(CmpFunc, NULL);

    status_before_insert = AVLIsEmpty(avl);
    AVLInsert(avl, (void*)5);
    status_after_insert = AVLIsEmpty(avl);
    
    if(TRUE != status_before_insert || FALSE != status_after_insert)
    {
        printf("AVLIsEmpty test failed\n");
        return;
    }


    printf("AVLIsEmpty passed the test successfully\n");

    AVLDestroy(avl);
}

static void AVLHeightTest(void)
{
    avl_ty *avl = NULL;
    size_t height_after_1_insert = 0;
    size_t height_after_2_inserts = 0;
    size_t height_after_3_inserts = 0;
    size_t height_after_4_inserts = 0;

    avl = AVLCreate(CmpFunc, NULL);

    AVLInsert(avl, (void*)5);
    height_after_1_insert = AVLHeight(avl);
    AVLInsert(avl, (void*)2);
    height_after_2_inserts = AVLHeight(avl);
    AVLInsert(avl, (void*)6);
    height_after_3_inserts = AVLHeight(avl);
    AVLInsert(avl, (void*)1);
    height_after_4_inserts = AVLHeight(avl);

    if(0 != height_after_1_insert || 1 != height_after_2_inserts || 
    1 != height_after_3_inserts || 2 != height_after_4_inserts)
    {
        printf("AVLHeight test failed\n");
        return;
    }

    printf("AVLHeight passed the test successfully\n");

    AVLDestroy(avl);
}

static void AVLFindTest(void)
{
    avl_ty *avl = NULL;

    avl = AVLCreate(CmpFunc, NULL);
    AVLInsert(avl, (void*)5);
    AVLInsert(avl, (void*)2);
    AVLInsert(avl, (void*)6);
    AVLInsert(avl, (void*)1);
    

    if(5 != (int)(long)AVLFind(avl, (void*)5) || 2 != (int)(long)AVLFind(avl, (void*)2))
    {
        printf("AVLFind test failed\n");
        return;
    }

    printf("AVLFind passed the test successfully\n");

    AVLDestroy(avl);
}

static void AVLRemoveTest(void)
{
    avl_ty *avl = NULL;
    size_t size_before_remove = 0;
    size_t height_before_remove = 0;
    size_t size_after_1_remove = 0;
    size_t size_after_2_remove = 0;
    size_t height_after_1_remove = 0;
    size_t height_after_2_remove = 0;

    avl = AVLCreate(CmpFunc, NULL);

    AVLInsert(avl, (void*)5);
    AVLInsert(avl, (void*)2);
    AVLInsert(avl, (void*)6);
    AVLInsert(avl, (void*)1);
    size_before_remove = AVLSize(avl);
    height_before_remove = AVLHeight(avl);
    AVLRemove(avl, (void*)6);
    size_after_1_remove = AVLSize(avl);
    height_after_1_remove = AVLHeight(avl);
    AVLRemove(avl, (void*)2);
    size_after_2_remove = AVLSize(avl);
    height_after_2_remove = AVLHeight(avl);

    if(size_after_1_remove + 1 != size_before_remove)
    {
        printf("AVLRemove test failed %d\n", size_before_remove);
        printf("AVLRemove test failed %d\n", size_after_1_remove);
        return;
    }

    printf("AVLRemove passed the test successfully\n");

    AVLDestroy(avl);
}

static void AVLForEachTest()
{
    avl_ty *avl = NULL;
    int preorder_status = 0;
    int inorder_status = 0;
    int postorder_status = 0;

    avl = AVLCreate(CmpFunc, NULL);
    AVLInsert(avl, (void*)5);
    AVLInsert(avl, (void*)2);
    AVLInsert(avl, (void*)6);
    AVLInsert(avl, (void*)1);
    printf("pre order printing\n");
    preorder_status = AVLForEach(avl, PrintTree, NULL, PREORDER);
    printf("\nin order printing\n");
    inorder_status = AVLForEach(avl, PrintTree, NULL, INORDER);
    printf("\npost order printing\n");
    postorder_status = AVLForEach(avl, PrintTree, NULL, POSTORDER);
    
    if((FAILURE == preorder_status) || (FAILURE == inorder_status) 
    || (FAILURE == postorder_status))
    {
        printf("AVLForEach test failed\n");
        return;
    }

    printf("\nAVLForEach passed the test successfully\n");

    AVLDestroy(avl);
}

/******************************************************************************/
static int CmpFunc(const void *avl_data, const void *data, void *params)
{
    (void)params;

    return (int)(long)avl_data - (int)(long)data;
}

static int PrintTree(void *data, void *params)
{
    printf("%d  ",(int)(long)data);
    (void)params;
    return SUCCESS;
}
