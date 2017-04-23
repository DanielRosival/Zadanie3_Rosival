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

int main(int argc, char const *argv[]){
    int f;

    f = open ( argv[1] , O_RDONLY);
    if ( f < 0 ){
        return 1;
    }
    

    return 0;
}
