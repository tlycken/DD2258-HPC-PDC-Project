#include <stdlib.h>
#include <mat.h>
#include <matrix.h>

#include "dataloader.h"

using namespace std;

MATFile* open_data_file(const char* name) {
    return matOpen(name, "r");
}

void get_dimensions(MATFile *datafile, const char* variable_name, int *dimens) {
    mxArray *mxv;
    mxv = matGetVariable(datafile, variable_name);
    
    dimens[0] = (int)mxGetM(mxv);
    dimens[1] = (int)mxGetN(mxv);
    
    mxDestroyArray(mxv);
}

void load_data(MATFile *datafile, const char* name, double **data, int *dimens) {
    mxArray *mxv;
    mxv = matGetVariable(datafile, name);

    const int M = dimens[0];
    const int N = dimens[1];
    
    printf("%s loaded with dimensions %d-by-%d\n", name, (int)M, N);

    printf("\tMemory allocated for %s...\n", name);

    for (int n = 0; n < N; n++) {
        for (int m = 0; m < M; m++) {
            data[n][m] = *mxGetPr(mxv);
        }
    }

    printf("\t%s saved to C++ variable\n", name);
    
    mxDestroyArray(mxv);
    
    printf("\tExiting load_data...\n");
    fflush(stdout);
}
