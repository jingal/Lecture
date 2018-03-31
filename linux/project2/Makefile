#make
.SUFFIXES : .c .o

TARGET = project2
SRC = main.c msglib.c shmlib.c parent.c child.c
OBJS   = $(SRC:%.c=%.o)

CC = gcc
CFLAGS = -I../inc -g

all : $(TARGET)
	
$(TARGET) : $(OBJS)
		$(CC) -o $(TARGET) $(OBJS)

%.o:src/%.c 
	$(CC) $(CFLAGS) -c $< -o $@
		
clean :
	rm -f $(OBJS) $(TARGET)
