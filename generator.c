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

int main(int argc, char const *argv[]){
    
    unsigned char l;
    int f,i,j;
    float number;
    
    if ( argc > 3 ){
        printf("Too much arguments.\n");
        return 1;
    }

    if ( argc < 3 ){
    	printf("Not enough arguments.\n");
    	return 2;
    }
    
    f = open ( argv[1], O_WRONLY | O_CREAT, 0660 );
    if ( f < 0 ){
        return 3;
    }
    
    srand ( time( NULL ) );
    
    for (i = 0; i < (*argv[2]); ++i){
        l = rand() % 10 + ( dolna_hranica + 1 );
        printf("%c\n", l);
        write ( f, &l, sizeof(char) * 1 );
        for (j = 0; j < l; ++j){
            number = (float) rand() / (float) RAND_MAX;
            printf("number\n");
            write ( f, &number, sizeof(float) * 1 );
        }
    }
    
    if ( close (f) != 0) {
    	printf("FAILED\n");
    	printf("%s\n", strerror(errno));
    }

    return 0;
}
