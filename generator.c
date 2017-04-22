#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <ctype.h>

#define dolna_hranica 10

int main(int argc, char const *argv[])
{
    char n;
    unsigned char l;
    int f,i,j;
    float *number = NULL;
    
    if ( argc > 3 ){
        printf("Too much arguments.\n");
        return 1;
    }
    
    n = argv[2];
    
    f = open ( argv[1], O_WRONLY | O_CREAT, 0660 );
    if ( f < 0 ){
        return 1;
    }
    
    srand ( time( NULL ) );
    
    for (i = 0; i <= n; ++i){
        l = rand() % 10 + ( dolna_hranica + 1 );
        write ( f, n, sizeof(char) * 1 );
        for (j = 0; i <= l; ++j){
            *number = (float) rand() / (float) RAND_MAX;
            write ( f, number, sizeof(float) * 1 );
        }
    }
    
    close ( f );
    
    
    
    
    return 0;
}
