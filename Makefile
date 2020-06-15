FLAGS = -std=gnu99 -Wall -Wextra -Wno-unused-parameter -Wno-deprecated-declarations -lalut -lopenal -lm
GTKFLAGS=`pkg-config gtk+-3.0 --cflags` `pkg-config gtk+-3.0 --libs`
CPP = gcc
SRCS = piano.c keyboard.c sounds.c recorder.c player.c writer.c
OBJS = $(SRCS:.c=.o)

all: piano recordingHelper project

project: piano recordingHelper
	$(CPP) project.c -o project $(FLAGS) $(GTKFLAGS)

piano: $(OBJS)
	$(CPP) -o piano $(OBJS) $(FLAGS) $(GTKFLAGS)

piano.o: piano.c keyboard.o
	$(CPP) piano.c $(FLAGS) $(GTKFLAGS) -c

keyboard.o: keyboard.c keyboard.h sounds.o
	$(CPP) keyboard.c $(FLAGS) $(GTKFLAGS) -c

sounds.o: sounds.c sounds.h
	$(CPP) sounds.c $(FLAGS) $(GTKFLAGS) -c

recorder.o: recorder.c recorder.h
	$(CPP) recorder.c $(FLAGS) $(GTKFLAGS) -c

player.o: player.c player.h
	$(CPP) player.c $(FLAGS) $(GTKFLAGS) -c

writer.o: writer.c writer.h
	$(CPP) writer.c $(FLAGS) $(GTKFLAGS) -c

recordingHelper: sounds.o
	$(CPP) recordingHelper.c -o recordingHelper sounds.o $(FLAGS) $(GTKFLAGS)

clean:
	$(RM) piano *.o *~ recordingHelper project
