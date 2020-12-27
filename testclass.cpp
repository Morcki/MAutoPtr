#include "testclass.h"
#include <string>
using namespace std;
Test::Test(char *fp){
    strcpy_s(fpath ,fp);
    mInstance = this;
}