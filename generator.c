#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <ctype.h>

#define dolna_hranica 10
#define EXPEC_NUMBER_OF_ARGUMENTS 3

int main(int argc, char const *argv[]){
    
    unsigned char l;
    int f,i,j,n;
    float number;
    
    if ( argc > EXPEC_NUMBER_OF_ARGUMENTS ){
        printf("Too much arguments.\n");
        return 1;
    }

    if ( argc < EXPEC_NUMBER_OF_ARGUMENTS ){
    	printf("Not enough arguments.\n");
    	return 2;
    }
    
    f = open ( argv[1], O_WRONLY | O_CREAT, 0660 );
    if ( f < 0 ){
        return 3;
    }

    n = atoi ( argv[2] );
    printf( " n = %d\n", n );
    
    srand ( time( NULL ) );
    
    for (i = 0; i < n; i++){
        l = rand() % 10 + ( dolna_hranica + 1 );
        printf("%d\n", l);
        write ( f, &l, sizeof(char) * 1 );
        for (j = 0; j < l; j++){
            number = (float) rand() / (float) RAND_MAX;
            printf("%f\n",number);
            write ( f, &number, sizeof(float) * 1 );
        }
    }
    
    if ( close (f) != 0) {
    	printf("FAILED\n");
    	return 4;
    }

    return 0;
}
