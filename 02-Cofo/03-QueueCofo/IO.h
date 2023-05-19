#ifndef _IO_H_
#define _IO_H_

#define TRUE 1
#define FALSE 0

#define BLACK "\033[0;30m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define PURPLE "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE  "\033[0;37m"

#define BOLD_BLACK "\033[1;30m"
#define BOLD_RED "\033[1;31m"
#define BOLD_GREEN "\033[1;32m"
#define BOLD_YELLOW "\033[1;33m"
#define BOLD_BLUE "\033[1;34m"
#define BOLD_PURPLE "\033[1;35m"
#define BOLD_CYAN "\033[1;36m"
#define BOLD_WHITE  "\033[1;37m"

#define COLOR_RESET "\033[0m"

#define ROW_LEN 80
#define MARGIN_CHAR '-'
#define SPACE ' '

#ifdef _IO_C_

typedef struct _line_{
    int rowLength;

    int contentLength;
    int mainLength;
    int leftMargin;
    int rightMargin;

    char *content;
    char *main;
    char marginChar;
} Line;

void printNTimes( char c, int n, int jump );
void colorPrintNTimes( char c, int n, int jump, char color[] );
int fcprint( char string[], int alignment, char color[], int jump, int sizeTxt );
//char *toColorString( char content[], char color[] );

#else

extern void printNTimes( char c, int n, int jump );
extern void colorPrintNTimes( char c, int n, int jump, char color[] );
extern int fcprint( char string[], int alignment, char color[], int jump, int sizeTxt );

#endif
#endif