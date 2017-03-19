#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include "messages.pb.h"


int main(int argc, char *argv[]){
    // Verify the version of the library
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    int x, y, vel_x, vel_y;
    FILE *fout;
    std::string output;

    if (argc != 2) {
       std::cerr << "Usage: " << argv[0] << " file_to_store" <<std::endl;
        return -1;
    }

    swarm::Data data;

    std::cout << "Enter x: ";
    std::cin >> x;
    data.set_x(x);
    std::cout << "Enter y: ";
    std::cin >> y;
    data.set_y(y);
    std::cout << "Enter vel_x: ";
    std::cin >> vel_x;
    data.set_vel_x(vel_x);
    std::cout << "Enter vel_y: ";
    std::cin >> vel_y;
    data.set_vel_y(vel_y);

  if (!data.SerializeToString(&output)) {
        std::cerr << "Failed to write to the address book." <<std::endl;
        return -1;
    }

    fout = fopen(argv[1], "w");
if (fout==NULL) {
        std::cerr << "Failed to write." <<std::endl;
        return -1;
    }

    fprintf(fout, "%s", output.c_str());



    /*
     * This isn't actually needed because the program dies after this but
     * it is a good practise to do this because then if we extend this
     * code to do some other thing so we should shutdown the protobuf
     * library which frees up the memory
     */
    google::protobuf::ShutdownProtobufLibrary();

    return 0;
}
