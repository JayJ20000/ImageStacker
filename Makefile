CC = g++
TARGET = main
CFLAGS = -c -Wall -Wextra

all: $(TARGET)

$(TARGET): image_stacker.o main.o
	$(CC) -g -Wextra -Wall -o $(TARGET) main.o image_stacker.o

image_stacker.o: image_stacker.cpp image_stacker.h
	$(CC) $(CFLAGS) image_stacker.cpp

main.o: main.cpp image_stacker.cpp
	$(CC) $(CFLAGS) main.cpp

clean:
	$(RM) $(TARGET) *.o *~
