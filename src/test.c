#include <stdio.h>
#include <stdlib.h>

void testFct(int* test)
{
	*test++;
}

int main(int argc, char const *argv[])
{
	int test = 1;
	int* testPt = &test;
	printf("%d %d\n",test, *testPt);
	*testPt +=1;
	printf("%d %d\n",test, *testPt);
	*testPt =152;
	printf("%d %d\n",test, *testPt);
	testFct(&test);
	printf("%d %d\n",test, *testPt);
	printf("%d\n",+-1);

	/* code */
	return 0;
}
