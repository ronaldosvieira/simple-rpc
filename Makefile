all:
	rpcgen date.x
	gcc -c date_clnt.c
	gcc -c date_svc.c
	gcc -c dateproc.c
	gcc -c rdate.c
	gcc -o client date_clnt.o rdate.o
	gcc -o server date_svc.o dateproc.o
	
clean:
	rm *.o -f
	rm date.h -f
	rm date_clnt.c -f
	rm date_svc.c -f
	rm client -f
	rm server -f