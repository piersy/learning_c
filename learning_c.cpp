#include "gtest/gtest.h"
#include <stdlib.h>


struct test_struct {
	int i;
};

void fillStruct(test_struct *t, int val){
	test_struct *retStruct = (test_struct*)malloc(sizeof(test_struct));
	retStruct->i = val;
	*t =  *retStruct;
}

void fillStruct2(test_struct *t, int val){
	 t = (test_struct*)malloc(sizeof(test_struct));
	 t->i = val;
}

void fillStruct3(test_struct **t, int val){
	 test_struct *retStruct = (test_struct*)malloc(sizeof(test_struct));
	 retStruct->i = val;
	 printf("filling\n");
	 *t = retStruct;
	 printf("filled\n");
}

void fillStruct4(test_struct *t, int val){
	//make our struct pointer point to their struct
	 test_struct *retStruct = t;
	 retStruct->i = val;
}

TEST(learning_c, DISABLED_return_struct)
{
	test_struct *t = (test_struct*)malloc(sizeof(test_struct));
	fillStruct(t, 5);
	EXPECT_EQ(t->i, 5);
}

TEST(learning_c, DISABLED_return_struct2)
{
	test_struct *t;
	fillStruct2(t, 5);
	EXPECT_EQ(t->i, 5);
}

// This is ok even though the pointer has not been set to
// any value.
TEST(learning_c, dereference_uninitialised_primitive_pointer) {
	int **x;
	int y = 4;
	*x = &y;
}

TEST(learning_c, dereference_uninitialised_struct_pointer)
{
	test_struct **t;
	*t = NULL;
	test_struct h;
	*t = &h;
	//printf("about to fill\n");
	//fillStruct3(t, 5);
	//printf("filled\n");
	//EXPECT_EQ((*t)->i, 5);
}

TEST(learning_c, return_struct3)
{
	test_struct **t;
	*t = NULL;
	printf("about to fill\n");
	fillStruct3(t, 5);
	printf("filled\n");
	EXPECT_EQ((*t)->i, 5);
}


TEST(learning_c, DISABLED_return_struct4)
{
	test_struct *t = (test_struct*)malloc(sizeof(test_struct));
	fillStruct4(t, 5);
	EXPECT_EQ(t->i, 5);
}
