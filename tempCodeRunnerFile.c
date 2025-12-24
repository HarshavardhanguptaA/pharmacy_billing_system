#include <stdio.h>
#include <time.h>
int main() {
    time_t t;
    time(&t);
    printf("=================================\n");
    printf("        WELCOME SCREEN\n");
    printf("=================================\n");
    printf("Name        : Abinavani T C\n");
    printf("Register No : 711525BCS002\n");
    printf("Department  : AIDS\n");
    printf("---------------------------------\n");
    printf("Date & Time : %s", ctime(&t));
    return 0;
}
