#include <stdio.h>
#include <assert.h>
#include "assignment1.h"

int main(){
	ArrayUtil util,utilNew;
	util = create(4,5);
	utilNew = create(4,5);
	resize(util,5);
	printf("%d\n",areEqual(util,utilNew));
	dispose(util);
	return 0;
};