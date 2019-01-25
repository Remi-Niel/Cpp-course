#include "taskthreads.h"

char *TaskThreads::d_filename;

int main(int argc, char* argv[])
{
    TaskThreads tt{argc, argv};
    tt.run();
    tt.showTime();
}