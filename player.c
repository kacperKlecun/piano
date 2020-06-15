#include <gtk/gtk.h>

#include <stdlib.h>
#include <string.h>
/*
Module which purpose is to play given file (button "Play" on keyboard).
*/
GtkWidget *window;

static void music(GtkWidget *widget, GtkWidget *data){
    const char *entry;
    char sum[50];
    entry = gtk_entry_get_text (GTK_ENTRY (data));
    strcpy(sum, "play ");
    strcat(sum, entry);
    system(sum);
    gtk_widget_destroy(window);
}
void play(GtkWidget *widget, gpointer data){
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);//declare toplevel window

    gtk_window_set_title(GTK_WINDOW(window),"player");//set title of window
    gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);//set position of window
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);//set border width of window
    gtk_window_set_default_size (GTK_WINDOW(window), 200,50);

    g_signal_connect(G_OBJECT(window), "destroy",G_CALLBACK(gtk_widget_destroy), NULL);//connect signal of X in window to quiting the program

    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);//declare vertical box

    gtk_container_add(GTK_CONTAINER(window), box);//add box to window container

    GtkWidget *text;
    text = gtk_entry_new();
    g_signal_connect(G_OBJECT(text), "activate", G_CALLBACK(music), (gpointer) text);

    gtk_box_pack_start(GTK_BOX(box), text, TRUE, TRUE, 0);

    gtk_widget_show_all(window);//show all widgets under window
}
