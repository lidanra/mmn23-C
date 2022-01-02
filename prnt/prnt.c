#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __linux__
#define EXT ""
#elif _WIN32
#define EXT ".exe"
#else
#endif

int main( int argc, char *argv[] ) {
    char ch;
    char end_file []= EXT;
    char *source_file ;
    char end [] = {'.', 'c', '\0'};
    FILE *source;
    source_file = argv[0];
    source_file[strlen(source_file)-strlen(end_file)] ='\0';


    strcat(source_file, end);


    source = fopen(source_file, "r");

    if (source == NULL) {
        printf("Press any key to exit...\n");
        exit(EXIT_FAILURE);
    }

    while ((ch = fgetc(source)) != EOF) {
    printf("%c", ch);
    }

    printf("File copied successfully.\n");

    fclose(source);

    return 0;
}
