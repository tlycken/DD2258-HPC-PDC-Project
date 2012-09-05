#include <stdlib.h>
#include <string.h>

#include <mat.h>
#include <matrix.h>

#include "commons.h"
#include "dataloader.h"

using namespace std;

data_item load_from_file(string filename, string variable) {
    MATFile *datafile = matOpen(filename.c_str(), "r");

    double **data;
    
    mxArray *mxv, *mxt;
    mxv = matGetVariable(datafile, (variable + "_signal").c_str());
    mxt = matGetVariable(datafile, (variable + "_t").c_str());

    data_item dataitem = *(new data_item);
    dataitem.M = (int)mxGetM(mxv);
    dataitem.N = (int)mxGetN(mxv);
    dataitem.Nt = MAX((int)mxGetM(mxt), (int)mxGetN(mxt));
    
    dataitem.data = new double*[dataitem.N];
    dataitem.times = new double[dataitem.Nt];
    
    for (int n = 0; n < dataitem.N; n++) {
        dataitem.data[n] = new double[dataitem.M];
        for (int m = 0; m < dataitem.M; m++) {
            dataitem.data[n][m] = *mxGetPr(mxv);
        }
    }    

    dataitem.times = mxGetPr(mxv);
    
    mxDestroyArray(mxv);
    mxDestroyArray(mxt);
    
    matClose(datafile);
    
    return dataitem;
}
