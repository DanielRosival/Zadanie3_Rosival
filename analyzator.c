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

#define EXPEC_NUMBER_OF_ARGUMENTS 2


int main(int argc, char const *argv[]){
    int f,counter = 0,i;
    float **pointer = NULL, *bufF = NULL, average = 0,averageBIG = 0;
    unsigned char n, *bufC = NULL;
    
    if ( argc > EXPEC_NUMBER_OF_ARGUMENTS ) {
        printf("Too many arguments!\n");
        return 1;
    }
    
    if ( argc < EXPEC_NUMBER_OF_ARGUMENTS ) {
        printf("Not enough arguments\n");
        return 2;
    }
    
    f = open ( argv[1] , O_RDONLY);
    if ( f < 0 ){
        return 1;
    }
    
    while ( lseek( f, 0, SEEK_CUR ) != EOF){
        read ( f,  bufC, 1 * sizeof(char));
        n = *bufC;
        pointer = realloc ( pointer, (4 * ( counter + 1 ) ) );
        *pointer =  malloc ( sizeof(float) * n );
        for (i = 0; i < n; ++i){
            read ( f, bufF, 1 * sizeof(float));
            *pointer[i] = *bufF;
            average += *bufF;
        }
        counter++;
        averageBIG += average; 
        printf("Arim. priemer postupnosti %d = %f\n", counter, average / (float) n);    
    }
    
    printf("Priemer aritmetickych priemerov = %f\n", averageBIG/counter);
    
    
    return 0;
}
