#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include "messages.pb.h"

//using namespace std;

int main(int argc, char *argv[]){
    // Verify the version of the library
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    swarm::Data data;


    /*
    if (!data.ParseFromIstream(&input)) {
      cerr << "Failed to parse address book." << endl;
      return -1;
    }
	*/

    std::fstream input(argv[1], std::ios::in | std::ios::binary);


    if (!data.ParseFromIstream(&input)) {
      std::cerr << "Failed to parse address book." << std::endl;
      return -1;
    }


    std::cout<<"x = "<<data.x()<<std::endl;
    std::cout<<"y = "<<data.y()<<std::endl;
    std::cout<<"vel_x = "<<data.vel_x()<<std::endl;
    std::cout<<"vel_y = "<<data.vel_y()<<std::endl;

    google::protobuf::ShutdownProtobufLibrary();

    return 0;
}

