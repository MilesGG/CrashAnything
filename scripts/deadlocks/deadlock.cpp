#include <mutex>
#include <iostream>
#include <cstdio>
#include <thread>
#include <future>
#include <chrono>

using namespace std;
mutex _m1;
mutex _m2;

void func12(){
    unique_lock<mutex> l1(_m1);
    this_thread::yield();
    this_thread::sleep_for( chrono::seconds(1) );
    unique_lock<mutex> l2(_m2 );
}

void func21(){
    unique_lock<mutex> l2(_m2);
    this_thread::yield();
    this_thread::sleep_for( chrono::seconds(1) );
    unique_lock<mutex> l1(_m1);
}

int main( int argc, char* argv[] ){
    async(func12);
    func21();
    cout << "All done!";
    getchar();
}
