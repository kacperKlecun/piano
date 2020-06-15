#include <gtk/gtk.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#include "writer.h"
/*
Program for writing sheet music.
*/
GtkWidget *image, *grid, *window;

static int i, j, barsNumber;

time_t presentTime, previousTime;

static void stop_writing(GtkWidget *widget, gpointer data){
    canWrite=0;
    gtk_widget_destroy(widget);
}

static void save(GtkWidget *widget, GtkWidget *data){
    const char *entry;
    entry = gtk_entry_get_text (GTK_ENTRY (data));

    char command[]="gnome-screenshot -w -B --file=\"My Sheets\"/\"";
    strcat(command, entry);
    strcat(command, "\"");
    system(command);
}

void writeNote(GtkWidget *widget, gpointer data){
    if(canWrite==0) return;

    time(&presentTime);

    if(i==0 && j>0){
        image=gtk_image_new_from_file("Notes/space.png");
        gtk_grid_attach(GTK_GRID(grid), image, 0, j, 1, 1);
        i++;
    }

    if(difftime(presentTime,previousTime)>1.5){
        image=gtk_image_new_from_file("Notes/rest.png");
        gtk_grid_attach(GTK_GRID(grid), image, i, j, 1, 1);
        i++;

        if(i%5==0){
            image=gtk_image_new_from_file("Notes/bar.png");
            gtk_grid_attach(GTK_GRID(grid), image, i, j, 1, 1);
            i++;
            if(barsNumber==15){
                notes(NULL, NULL);
                return;
            }
            barsNumber++;
        }
        if(i%16==0){
            i=0;
            j++;
        }

    }

    image=gtk_image_new_from_file(data);
    gtk_grid_attach(GTK_GRID(grid), image, i, j, 1, 1);

    i++;

    if(i%5==0){
        image=gtk_image_new_from_file("Notes/bar.png");
        gtk_grid_attach(GTK_GRID(grid), image, i, j, 1, 1);
        i++;
        if(barsNumber==14){
            gtk_widget_show_all(grid);
            notes(NULL, NULL);
            return;
        }
        barsNumber++;
    }
    if(i%16==0){
        i=0;
        j++;
    }

    gtk_widget_show_all(grid);

    time(&previousTime);
}
void notes(GtkWidget *widget, gpointer data){
    canWrite=1;
    i=1;
    j=0;
    barsNumber=0;
    time(&previousTime);

    GtkWidget *box;
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);//declare toplevel window

    gtk_window_set_title(GTK_WINDOW(window),"writer");//set title of window
    gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);//set position of window
    gtk_container_set_border_width(GTK_CONTAINER(window), 0);//set border width of window
    gtk_window_set_default_size (GTK_WINDOW(window), 1060,0);

    g_signal_connect(G_OBJECT(window), "destroy",G_CALLBACK(stop_writing), NULL);//connect signal of X in window to quiting the program
    
    static GdkColor colorBlack;
    gdk_color_parse("black", &colorBlack);
    gtk_widget_modify_bg(window, GTK_STATE_NORMAL, &colorBlack);

    box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);

    GtkWidget *text;
    text = gtk_entry_new();
    g_signal_connect(G_OBJECT(text), "activate", G_CALLBACK(save), (gpointer) text);
    gtk_box_pack_start(GTK_BOX(box), text, TRUE, TRUE, 0);

    grid = gtk_grid_new();
    gtk_grid_set_row_homogeneous(GTK_GRID(grid), TRUE);

    image=gtk_image_new_from_file("Notes/begin.png");
    gtk_grid_attach(GTK_GRID(grid), image, 0, 0, 1, 1);

    gtk_box_pack_start(GTK_BOX(box), grid, TRUE, TRUE, 0);

    gtk_container_add(GTK_CONTAINER(window), box);

    gtk_widget_show_all(window);//show all widgets under window
}
