#ifndef SOUNDS_H
#define SOUNDS_H

void KillALData();// cleans all buffers and sources
void make_sound(GtkWidget *widget, gpointer key);// plays sound which is specified by "key"

#endif
