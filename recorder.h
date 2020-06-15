#ifndef RECORDER_H
#define RECORDER_H

void record(GtkWidget *widget, gpointer data); // starts/stops recording depending on button state
void add_music(GtkWidget *widget, gpointer data); // adds name of file (which containes sound) and time to text file

#endif
