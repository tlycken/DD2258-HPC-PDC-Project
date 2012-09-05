#include <stdlib.h>
#include <stdio.h>
#include <mat.h>
#include <matrix.h>

#include "dataloader.h"

using namespace std;


int main(int argc, char *argv[]) {

    data_item toroidal_field;
    data_item input;
    data_item plasma_current;

    toroidal_field = load_from_file("data/shot_21970.mat", "toroidal_field");
    input = load_from_file("data/shot_21970.mat", "input");
    plasma_current = load_from_file("data/shot_21970.mat", "plasma_current");

    for(int t = 0; t < input.Nt; t++) {
        printf("Channel 1 at %f: %f", input.times[t], input.data[0][t]);
    }

    return 0;
}
