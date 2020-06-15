#include <gtk/gtk.h>

#include "keyboard.h"
/*
Program for initialization of gtk and making keyboard.
*/
int main(int argc,char *argv[]){
    gtk_init(&argc, &argv);//initialize gtk

    make_keyboard();

    gtk_main();//start the main loop
    return 0;
}
