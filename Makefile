all: httpd

httpd: httpd.c
	gcc -g -W -Wall -lsocket -o httpd httpd.c -lpthread 

simpleclient: simpleclient.c
	gcc -g simpleclient.c -o simpleclient
clean:
	rm httpd
