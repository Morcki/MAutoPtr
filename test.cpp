#include <stdio.h>
#include "testclass.h"

int main(){
  char fp[128] = "./config.txt";
  Test *m_test = new Test(fp);
  return 0;
}