#include <stdlib.h>
#include <string.h>

#include <gtk/gtk.h>

#include "sounds.h"
/*
Program for converting text file into music.
*/
int main(){
    char *buffer=malloc(20);

    FILE *recordFile=fopen("recorded music","rb");
    fgets(buffer , 15, recordFile);
    int presentSeconds, prevSeconds=atoi(buffer);

    while(!feof(recordFile)){
        if (fgets(buffer , 14, recordFile) == NULL )
            break;
        if(buffer[0]=='S'){
            int c=fgetc(recordFile);
            if(c==EOF)
                break;
            if(c=='v')
                strcat(buffer, "v");
            make_sound(NULL, (gpointer) buffer);
        }
        else if(buffer[0] != '\n'){
            presentSeconds=atoi(buffer);
            int delaySeconds=presentSeconds-prevSeconds;
            if(delaySeconds<0) delaySeconds+=60;
            sleep(delaySeconds);
            if(delaySeconds==0)
                sleep(1);
            prevSeconds=presentSeconds;
        }
    }
    fclose(recordFile);

    FILE *alsoftFile=fopen("/home/kacper/.alsoftrc","wb");
    fprintf(alsoftFile, "sources=1024\ndrivers=pulse");
    fclose(alsoftFile);
   
    return 0;
}
