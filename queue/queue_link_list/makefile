CC:=gcc
exe:=test
obj:=main.o queue_linked_list.o

all:$(obj)
	$(CC) -o $(exe) $(obj)  
%.o:%.c
	$(CC) -g -c $^ -o $@

.PHONY:clean
clean:
	rm -rf $(obj) $(exe)
