#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include "messages.pb.h"

using namespace std;

int main(int argc, char *argv[]){
    // Verify the version of the library
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    int x, y, vel_x, vel_y;
    FILE *fout;
    string output;

    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " file_to_store" << endl;
        return -1;
    }

    swarm::Data data;

    cout << "Enter x: ";
    cin >> x;
    data.set_x(x);
    cout << "Enter y: ";
    cin >> y;
    data.set_y(y);
    cout << "Enter vel_x: ";
    cin >> vel_x;
    data.set_vel_x(vel_x);
    cout << "Enter vel_y: ";
    cin >> vel_y;
    data.set_vel_y(vel_y);

    if (!data.SerializeToString(&output)) {
        cerr << "Failed to write to the address book." << endl;
        return -1;
    }

    fout = fopen(argv[1], "w");
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
