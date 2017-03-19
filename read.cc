#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include "messages.pb.h"


int main(int argc,char *argv[])
{
GOOGLE_PROTOBUF_VERIFY_VERSION;

 int x, y, vel_in_x, vel_in_y;
 


if (argc != 2) {
       std::cerr << "Usage: " << argv[0] << " file_to_store" << std::endl;
        return -1;
    }

swarm::Data data;

std::fstream input(argv[1], std::ios::in | std::ios::binary);



if (!data.ParseFromIstream(&input)) {
       std:: cerr << "Failed to write to the address book." << std::endl;
        return -1;
    }


x=data.x();
y=data.y();
vel_in_x=data.vel_x();
vel_in_y=data.vel_y();

std::cout<<"The x coordinate is:"<<x<<std::endl;
std::cout<<"The y coordinate is:"<<y<<std::endl;
std::cout<<"The velocity along x direction is:"<<vel_in_x<<std::endl;
std::cout<<"The velocity along y direction is:"<<vel_in_y<<std::endl;

google::protobuf::ShutdownProtobufLibrary();


}
