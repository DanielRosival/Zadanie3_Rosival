#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char const *argv[])
{
	if (argc > 3){
		printf("Too much arguments.\n");
		return 1;
	}
	return 0;
}
