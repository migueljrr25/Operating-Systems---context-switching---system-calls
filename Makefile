make: runsc runcs
	gcc system_call.o -o runsc
	gcc context_switch.o -o runcs
runsc: system_call.c
	gcc -c system_call.c
runcs: context_switch.c
	gcc -c context_switch.c
clean:	
	rm *.o runcs runsc 