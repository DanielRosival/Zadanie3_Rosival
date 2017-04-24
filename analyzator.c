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
    int f,counter = 0,i,j;
    float **pointer = NULL, average = 0, averageBIG = 0;
    unsigned char n, *dlzky = NULL;
    off_t end_position;
    
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
        printf("Open failed\n");
        return 1;
    }

    pointer = malloc ( sizeof ( pointer ) );
    dlzky = malloc ( sizeof ( char ) );

    end_position = lseek ( f, 0, SEEK_END );
    lseek ( f, 0, SEEK_SET );
 

    while ( (lseek( f, 0, SEEK_CUR )) != end_position ){
        pointer = realloc ( pointer, 4 * ( counter + 1 ) );
        dlzky = realloc ( dlzky, sizeof ( unsigned char ) * ( counter + 1 ) );
        
        read ( f, &dlzky[counter], sizeof ( unsigned char ) );

        pointer[counter] = malloc ( sizeof ( float ) * dlzky[counter] );

        n = dlzky[counter];
        printf("%d\n",n );
        for (i = 0; i < n; i++){
            read ( f, &pointer[i], sizeof(float));  
        }
        average = average / n;
        counter++;  
    }

    if ( close (f) == -1){
        printf("Closing failed\n");
        return 3;
    }

    printf("Pocet postupnosti je: %d\n", counter);
    printf("Aritmeticky priemer priemerov je:%f\n", averageBIG);
    for (i = 0; i < counter; i++){
        printf("test\n");
        printf("%d\n", i);
        printf("%d. postupnost ma %d clenov", i+1, dlzky[i]);

        for ( j = 0; j < dlzky[i]; j++ ){
            printf("%f ", pointer[i][j] );
        }
        printf("\n");
    }

    free(pointer);
    free(dlzky);
    
    
    
    return 0;
}
