CFLAGS = -g
LIBS = -L/usr/local/lib -lprotobuf -pthread  -lpthread
CC = g++

.PHONY: all protoc_middleman read write

all: protoc_middleman read write

protoc_middleman: messages.proto
	protoc --cpp_out=. messages.proto
	@touch protoc_middleman

read: read.cc messages.pb.cc
	$(CC) $(CFLAGS) read.cc messages.pb.cc -o read $(LIBS)

write: write.cc messages.pb.cc
	$(CC) $(CFLAGS) write.cc messages.pb.cc -o write $(LIBS)

clean:
	rm -f protoc_middleman
	rm -f messages.pb.cc
	rm -f messages.pb.h
	rm -f read
