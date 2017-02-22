CFLAGS = -g
LIBS = -L/usr/local/lib -lprotobuf -pthread  -lpthread
CC = g++

.PHONY: all protoc_middleman read

all: protoc_middleman read

protoc_middleman: messages.proto
	protoc --cpp_out=. messages.proto
	@touch protoc_middleman

read: read.cc messages.pb.cc
	$(CC) $(CFLAGS) read.cc messages.pb.cc -o read $(LIBS)

clean:
	rm -f protoc_middleman
	rm -f messages.pb.cc
	rm -f messages.pb.h
	rm -f read
