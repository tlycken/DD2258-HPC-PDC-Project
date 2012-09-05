#include <string>

struct data_item {
    double** data;
    double* times;
    int M;
    int N;
    int Nt;
};


data_item load_from_file(std::string, std::string);
