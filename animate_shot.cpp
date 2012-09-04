#include <stdlib.h>
#include <stdio.h>
#include <mat.h>
#include <matrix.h>

#include "dataloader.h"

using namespace std;

int main(int argc, char *argv[]) {
    MATFile *datafile = open_data_file("data/shot_21970.mat");

    double **toroidal_field;
    double **input_signal;

    int dimens[2];
    
    get_dimensions(datafile, "toroidal_field_signal", dimens);
    
    int M = dimens[0];
    int N = dimens[1];
    
    toroidal_field = new double*[N];
    
    for (int n = 0; n < N; n++) {
        toroidal_field[n] = new double[M];
    }    
    
    load_data(datafile, "toroidal_field_signal", toroidal_field, dimens);
    
    printf("Data dimensions: (M,N) = (%d,%d)\n", M, N);
    fflush(stdout);
  
    double mean_field;
  
    for (int n = 0; n < N; n++) {
        for (int m = 0; m < M; m++) {
            mean_field += toroidal_field[n][m];
        }
    }
    
    printf("Mean field: %f\n", mean_field/GLOBAL_VECTOR_LENGTH);

    load_data(datafile, "input_signal", input_signal, dimens);
  
    matClose(datafile);

    return 0;
}
