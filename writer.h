#ifndef WRITER_H
#define WRITER_H

int canWrite; //variable for checking if program can write music
void notes(GtkWidget *widget, gpointer data); //function which starts writing of music
void writeNote(GtkWidget *widget, gpointer data); //function which adds single note to sheet

#endif
