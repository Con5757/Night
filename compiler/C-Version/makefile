CC = gcc
CFLAGS = -Wall -Wextra -Iheaders

TARGET = main.exe

SRCS = main.c files/fileRead.c files/tokenizer.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
		$(CC) $(OBJS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	del /f /q $(TARGET) *.o files\*.o 2>nul || rm -f $(TARGET) $(OBJS)