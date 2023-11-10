// #include <stdio.h>
// #include <string.h>

// void Banner();
// void Encryption();
// void Decryption();

// int main(int argc, char *argv[]){
//     int input;
//     //Banner();
//     // printf("what option did you want?\n");
//     // printf("1. Encryption\n");
//     // printf("2. Decryption\n");
//     // printf("Input your choice : ");
//     // scanf("%d", &input);
    
//     Encryption();
//     // if(input == 1){
//     //     Encryption();
//     // } else if(input == 2){
//     //     Decryption();
//     // } else {
//     //     printf("What else??");
//     // }
//     // if(argv[1] != NULL){
//     //     FILE *file = fopen(argv[1], "r");
//     //     //printf("%s", argv[1]);
//     // } else {
//     //     printf("nothing");
//     // }
//     return 0;
// }

// void Banner(){

// }

// void Encryption(){
//     char filename[50];
//     FILE *file;

//     printf("Input your file name : ");
//     scanf("%s", &filename);
//     file = fopen(&filename, "r");
//     printf("%s", file);
// }

// void Decryption(){

// }

#include <stdio.h>
#include <string.h>

#define MAXC 1024       /* if you need a constant, #define on (or more) */

int main (void) {
    
    char fname[MAXC], line[MAXC];                   /* storage for filename & line */
    FILE *fp = NULL;                                /* FILE pointer */
    
    fputs ("enter filename: ", stdout);                     /* prompt */
    
    if (!fgets (fname, MAXC, stdin) || *fname == '\n') {    /* check EOF or empty line */
        puts ("(user canceled input)");
        return 1;
    }
    fname[strcspn (fname, "\n")] = 0;                       /* trim \n from end */
    
    if (!(fp = fopen (fname, "r"))) {               /* validate file open succeeds */
        perror ("fopen-fname");                     /* fopen sets errno on failure */
        return 1;
    }
    
    putchar ('\n');                                 /* provide space before output */
    while (fgets (line, MAXC, fp)) {                /* read each line from file */
        line[strcspn (line, "\n")] = 0;             /* trim \n from end */
        puts (line);                                /* output line */
    }
    
    fclose (fp);                                    /* close file when done */
}