CC = g++
TARGET = main
CFLAGS = -c -Wall -Wextra

all: $(TARGET)

$(TARGET): main.o image.o image_stacker.o 
	$(CC) -g -Wextra -Wall -o $(TARGET) main.o image.o image_stacker.o

main.o: main.cpp image_stacker.cpp
	$(CC) -g $(CFLAGS) main.cpp

image.o: image.cpp image_stacker.cpp
	$(CC) -g $(CFLAGS) main.cpp

image_stacker.o: image_stacker.cpp image_stacker.h
	$(CC) -g $(CFLAGS) image_stacker.cpp

clean:
	$(RM) $(TARGET) *.o *~
