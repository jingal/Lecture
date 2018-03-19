#make
.SUFFIXES : .c .o

TARGET = myls
SRC = main.c dir_traverse.c file_list.c file_mode.c
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
