#define GLOBAL_VECTOR_LENGTH 8192
#define INPUT_VECTOR_LENGTH 2000
#define INPUT_CHANNEL_COUNT 64

void load_data(MATFile*, const char*, double**, int*);
void get_dimensions(MATFile*, const char*, int*);

MATFile* open_data_file(const char*);

