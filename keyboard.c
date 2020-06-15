#include <gtk/gtk.h>

#include "key.h"
#include "keyboard.h"
#include "sounds.h"
#include "recorder.h"
#include "player.h"
#include "writer.h"
/*
Module which connects all main functions of the program. It holds all the buttons and keyboard.
*/
char *mnem[]={"_w","_e","_t","_y","_u","_o","_p","_a","_s","_d","_f","_g","_h","_j","_k","_l","_;"};

void make_keyboard(){
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);//declare toplevel window

    gtk_window_set_title(GTK_WINDOW(window),"piano");//set title of window
    gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);//set position of window
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);//set border width of window
    gtk_window_set_default_size (GTK_WINDOW(window), 1200,350);

    g_signal_connect(G_OBJECT(window), "destroy",G_CALLBACK(gtk_main_quit), NULL);//connect signal of X in window to quiting the program
    
    static GdkColor colorBlack;
    gdk_color_parse("black", &colorBlack);
    gtk_widget_modify_bg(window, GTK_STATE_NORMAL, &colorBlack);

    GtkWidget *box1 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);//declare vertical box "box1"

    gtk_container_add(GTK_CONTAINER(window), box1);//add box1 to window container

    GtkWidget *button;

    GtkWidget *box2 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);

    button = gtk_button_new_with_mnemonic("_Quit");//making button, which ends program
    g_signal_connect(G_OBJECT(button), "clicked",G_CALLBACK(gtk_main_quit), NULL);
    gtk_box_pack_start(GTK_BOX(box2), button, TRUE, TRUE, 0);

    button = gtk_button_new_with_mnemonic("_Mute");//declare button which clears data
    g_signal_connect(G_OBJECT(button), "clicked",G_CALLBACK(KillALData), NULL);
    gtk_box_pack_start(GTK_BOX(box2), button, TRUE, TRUE, 0);

    button = gtk_toggle_button_new_with_mnemonic("_Record");//declare button which records music
    g_signal_connect(G_OBJECT(button), "toggled",G_CALLBACK(record), NULL);
    gtk_box_pack_start(GTK_BOX(box2), button, TRUE, TRUE, 0);

    button = gtk_button_new_with_label("Play");//declare button which plays music
    g_signal_connect(G_OBJECT(button), "clicked",G_CALLBACK(play), NULL);
    gtk_box_pack_start(GTK_BOX(box2), button, TRUE, TRUE, 0);

    button = gtk_button_new_with_label("Write");//declare button which writes music
    g_signal_connect(G_OBJECT(button), "clicked",G_CALLBACK(notes), NULL);
    gtk_box_pack_start(GTK_BOX(box2), button, TRUE, TRUE, 0);

    gtk_box_pack_start(GTK_BOX(box1), box2, TRUE, TRUE, 0);
    
    GtkWidget *grid = gtk_grid_new();//declare grid
    gtk_grid_set_row_homogeneous(GTK_GRID(grid), TRUE);
    gtk_grid_set_column_homogeneous(GTK_GRID(grid), TRUE);
    gtk_box_pack_start(GTK_BOX(box1), grid, TRUE, TRUE, 0);

    int j=0;

    for(int i = 0; i < 49; i++) {
        if((i>9 && i<17) || (i>33 && i<45)){
            button = gtk_button_new_with_mnemonic(mnem[j]);
            j++;
        }
        else
            button = gtk_button_new();

        g_signal_connect(G_OBJECT(button), "clicked",G_CALLBACK(make_sound), (gpointer) tab[i].sound);
        g_signal_connect(G_OBJECT(button), "clicked",G_CALLBACK(writeNote), (gpointer) tab[i].note);
        g_signal_connect(G_OBJECT(button), "clicked",G_CALLBACK(add_music), (gpointer) tab[i].sound);

        gtk_grid_attach(GTK_GRID(grid), button, tab[i].posX, tab[i].posY, tab[i].lenX, tab[i].lenY);
    }

    gtk_widget_show_all(window);//show all widgets under window
}
