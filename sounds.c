#include <gtk/gtk.h>

#include "AL/al.h"
#include "AL/alut.h"

#include "sounds.h"
/*
Module for creating sound.
*/
// Buffers hold sound data.
ALuint Buffer;
// Sources are points emitting sound.
ALuint Source;

// Position of the source sound.
ALfloat SourcePos[] = { 0.0, 0.0, 0.0 };
// Velocity of the source sound.
ALfloat SourceVel[] = { 0.0, 0.0, 0.0 };
    
// Position of the listener.
ALfloat ListenerPos[] = { 0.0, 0.0, 0.0 };
    
// Velocity of the listener.
ALfloat ListenerVel[] = { 0.0, 0.0, 0.0 };
    
// Orientation of the listener. (first 3 elements are "at", second 3 are "up")
ALfloat ListenerOri[] = { 0.0, 0.0, -1.0, 0.0, 1.0, 0.0 };

static ALboolean LoadALData(gpointer key){
    // Variables to load into.
    ALenum format;
    ALsizei size;
    ALvoid* data;
    ALsizei freq;
    ALboolean loop;
    // Load wav data into a buffer.
    alGenBuffers(1, &Buffer);
    if (alGetError() != AL_NO_ERROR) return AL_FALSE;
    alutLoadWAVFile(key, &format, &data, &size, &freq, &loop);
    alBufferData(Buffer, format, data, size, freq);
    alutUnloadWAV(format, data, size, freq);
    // Bind buffer with a source.
    alGenSources(1, &Source);
    if(alGetError() != AL_NO_ERROR) AL_FALSE;

    alSourcei (Source, AL_BUFFER,   Buffer   );
    alSourcef (Source, AL_PITCH,    1.0f     );
    alSourcef (Source, AL_GAIN,     1.0f     );
    alSourcefv(Source, AL_POSITION, SourcePos);
    alSourcefv(Source, AL_VELOCITY, SourceVel);
    alSourcei (Source, AL_LOOPING,  loop     );

    // Do another error check and return.
    if (alGetError() == AL_NO_ERROR) return AL_TRUE;
    return AL_FALSE;
}

static void SetListenerValues(){
    alListenerfv(AL_POSITION,    ListenerPos);
    alListenerfv(AL_VELOCITY,    ListenerVel);
    alListenerfv(AL_ORIENTATION, ListenerOri);
}

void KillALData(){
    alDeleteBuffers(1, &Buffer);
    alDeleteSources(1, &Source);
    alutExit();
}

static unsigned int killer=0;

void make_sound(GtkWidget *widget, gpointer key){
    if((++killer)%5==0){
        KillALData();
    }

    // Initialize OpenAL and clear the error bit.
    alutInit(0, NULL);
    alGetError();

    // Load the wav data.
    if (LoadALData(key) == AL_FALSE) return;
    SetListenerValues();

    // Play the wav file.
    alSourcePlay(Source);
}
