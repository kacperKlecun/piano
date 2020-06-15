#include <stdlib.h>
#include <stdio.h>
/*
Main program which manages piano and recordingHelper
*/
int main(){
    FILE *wasRecorded;
    int q;
    while(1){
        system("./piano");
        wasRecorded=fopen("was recorded","rb");
        q=fgetc(wasRecorded);
        fclose(wasRecorded);
        if(q=='y'){
            wasRecorded=fopen("was recorded","wb");
            fprintf(wasRecorded, "n");
            fclose(wasRecorded);
            system("./recordingHelper");
            continue;
        }
        break;
    }
    return 0;
}
