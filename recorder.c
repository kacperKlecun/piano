#include <gtk/gtk.h>

#include <time.h>
#include <stdlib.h>

#include "recorder.h"
#include "keyboard.h"
/*
Module which purpose is to record music (button "Record" on keyboard).
*/
static FILE *recordFile, *wasRecorded, *alsoftFile;

static time_t presentTime;

static int canRecord;

static GtkWidget *popup;

static void save_recording(GtkWidget *widget, GtkWidget *data){
    const char *entry;
    entry = gtk_entry_get_text (GTK_ENTRY (data));

    alsoftFile=fopen("/home/kacper/.alsoftrc","wb");
    fprintf(alsoftFile, "sources=1024\ndrivers=wave\n[wave]\nfile=%s", entry);
    fclose(alsoftFile);

    gtk_widget_destroy(popup);

    gtk_main_quit();
}

static void stop_recording(){
    char seconds[3];
    time(&presentTime);
    struct tm * timeinfo;
    timeinfo = localtime (&presentTime);
    strftime(seconds, 3, "%S",timeinfo);
    fprintf(recordFile, "%s\n", seconds);
    fclose(recordFile);

    popup = gtk_window_new(GTK_WINDOW_TOPLEVEL);//declare toplevel window

    gtk_window_set_title(GTK_WINDOW(popup),"save recording");//set title of window
    gtk_window_set_position(GTK_WINDOW(popup),GTK_WIN_POS_CENTER);//set position of window
    gtk_container_set_border_width(GTK_CONTAINER(popup), 10);//set border width of window
    gtk_window_set_default_size (GTK_WINDOW(popup), 200,50);
    gtk_window_set_resizable (GTK_WINDOW(popup), FALSE);

    g_signal_connect(G_OBJECT(popup), "destroy",G_CALLBACK(gtk_widget_destroy), NULL);//connect signal of X in window to quiting the program

    GtkWidget *text;
    text = gtk_entry_new();
    g_signal_connect(G_OBJECT(text), "activate", G_CALLBACK(save_recording), (gpointer) text);

    gtk_container_add(GTK_CONTAINER(popup), text);

    gtk_widget_show_all(popup);//show all widgets under window
}

void add_music(GtkWidget *widget, gpointer data){
    if(canRecord==0) return;
    char seconds[3];
    time(&presentTime);
    struct tm * timeinfo;
    timeinfo = localtime (&presentTime);
    strftime(seconds, 3, "%S",timeinfo);
    fprintf(recordFile, "%s\n%s\n", seconds, (char*) data);
}
void record(GtkWidget *widget, gpointer data){
    if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget))){

        wasRecorded=fopen("was recorded","wb");
        if (wasRecorded == NULL ) return;
        fprintf(wasRecorded, "y");
        fclose(wasRecorded);

        recordFile=fopen("recorded music","wb");
        if (recordFile == NULL ) return;
        char seconds[3];
        time(&presentTime);
        struct tm * timeinfo;
        timeinfo = localtime (&presentTime);
        strftime(seconds, 3, "%S",timeinfo);
        fprintf(recordFile, "%s\n", seconds);
        canRecord=1;
    }
    else{
        canRecord=0;
        stop_recording();
    }
}
