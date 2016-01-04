ArrayUtil create(int typeSize, int length){
	ArrayUtil *base = (ArrayUtil *)calloc(length,typeSize);
	return *base;
};

ArrayUtil resize(ArrayUtil util, int length){
	ArrayUtil *ptr = realloc(util.base,length*(util.typeSize)); ;
	return *ptr;
};