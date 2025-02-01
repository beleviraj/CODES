#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

#define N 5
#define THINKING 2
#define HUNGRY 1
#define EATING 0
#define LEFT (phnum + 4) % N
#define RIGHT (phnum + 1) % N

int state[N];
int phil[N] = {0, 1, 2, 3, 4};
mutex mtx;
condition_variable S[N];
void test(int phnum) {
    if (state[phnum] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING) {
        state[phnum] = EATING;
        this_thread::sleep_for(chrono::milliseconds(2000));
        cout << "Philosopher " << phnum + 1 << " takes fork " << LEFT + 1 << " and " << phnum + 1 << endl;
        cout << "Philosopher " << phnum + 1 << " is Eating" << endl;
        S[phnum].notify_one();
    }
}
void take_fork(int phnum) {
    unique_lock<mutex> lock(mtx);
    state[phnum] = HUNGRY;
    cout << "Philosopher " << phnum + 1 << " is Hungry" << endl;
    test(phnum);
    S[phnum].wait(lock, [&] { return state[phnum] == EATING; });
    this_thread::sleep_for(chrono::milliseconds(1000));
}
void put_fork(int phnum) {
    unique_lock<mutex> lock(mtx);
    state[phnum] = THINKING;
    cout << "Philosopher " << phnum + 1 << " putting fork " << LEFT + 1 << " and " << phnum + 1 << " down" << endl;
    cout << "Philosopher " << phnum + 1 << " is thinking" << endl;
    test(LEFT);
    test(RIGHT);
}
void philosopher(int num) {
    while (true) {
        take_fork(num);
        put_fork(num);
    }
}
int main() {
    thread threads[N];
    for (int i = 0; i < N; i++) {
        threads[i] = thread(philosopher, i);
        cout << "Philosopher " << i + 1 << " is thinking" << endl;
    }
    for (int i = 0; i < N; i++)
        threads[i].join();
    return 0;
}
