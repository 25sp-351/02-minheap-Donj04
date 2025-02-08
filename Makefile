SRCS = $(TARGET).c heap.c
HDRS = heap.h

TARGET = 02-minheap

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ -lm

clean:
	rm -f $(TARGET) $(OBJS) 