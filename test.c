#include<stdio.h>
#include<string.h>
char stringBuffer[20];
char* outputStrings[5];
int main(){
    int i;
    int example[]={1,2,3,4,5};
    for (i = 0 ; i < 5 ; ++i)
{
    snprintf(stringBuffer, 20, "%d", example[i]);
    // check for overrun omitted
    outputStrings[i] = strdup(stringBuffer);
    printf("%s",stringBuffer);
}
 
}