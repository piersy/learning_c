#include <stdlib.h>
#include <stdio.h>


struct test_struct {
	int i;
};

void fillStruct3(struct test_struct **t, int val){
	 struct test_struct *retStruct = (struct test_struct*)malloc(sizeof(struct test_struct));
	 retStruct->i = val;
	 printf("filling\n");
	 *t = retStruct;
	 printf("filled\n");
}

int main(){
	struct test_struct **t;
	printf("about to fill\n");
	*t = NULL;
	fillStruct3(t, 5);
//	printf("filled\n");
	if ((*t)->i != 5){
		printf("fail\n");
	}
	return 0;
}
