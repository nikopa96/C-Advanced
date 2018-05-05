#ifndef PRAX14_THREADPOOL_H
#define PRAX14_THREADPOOL_H

#include <cstddef>
#include <thread>
#include <vector>
#include <deque>
#include <mutex>

// forward declaration
class ThreadPool;

class Worker {
public:
    explicit Worker(ThreadPool &s) : pool(s) { }
    void operator()();
private:
    ThreadPool &pool;
};

class ThreadPool {
    friend class Worker;
public:
    explicit ThreadPool(size_t numThreads);
    void enqueue(std::function<void()> f);
    ~ThreadPool();
private:
    // need to keep track of threads so we can join them
    std::vector<std::thread> workers;
    // a queue of tasks
    std::deque<std::function<void()>> tasks;
    // synchronization
    std::mutex queue_mutex;
    std::condition_variable condition;
    bool stop;
};

#endif //PRAX14_THREADPOOL_H
