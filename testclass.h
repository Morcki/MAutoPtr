#include<stdio.h>
#include<iostream>
using namespace std;
class Test{
    public:
        Test(char *arr);

        ~Test();

        static Test* m_getInstance(char *arr){
            if (mInstance == NULL){
                mInstance = new Test(arr);
            }
            return mInstance;
        }
        static Test* m_getInstance(){
            if (mInstance == NULL){
                cerr << "Error!Test is not initialized." << endl;
            }
            return mInstance;
        }

        static Test* mInstance;

    protected:
        char fpath[128] = {0};
};