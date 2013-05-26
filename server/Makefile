all: ldb_server

main.o: main.cc
	g++ -c main.cc -o main.o -I /usr/local/msgpack-rpc/include -I /usr/local/msgpack/include -I /usr/local/mpio/include -I ../client -static

server.o: server.cc server.h
	g++ -c server.cc -o server.o -I /usr/local/msgpack-rpc/include -I /usr/local/msgpack/include -I /usr/local/mpio/include -static

client.o: ../client/client.cc ../client/client.h
	g++ -c ../client/client.cc -o client.o -I /usr/local/msgpack-rpc/include -I /usr/local/msgpack/include -I /usr/local/mpio/include -I ../client -static

ldb_server: main.o server.o client.o
	g++ main.o server.o client.o -o ldb_server -L /usr/local/mpio/lib -L /usr/local/msgpack/lib -L /usr/local/msgpack-rpc/lib -lmsgpack-rpc -lmpio -lmsgpack -static -lpthread

clean:
	rm -f *.o
	rm -f ldb_server
