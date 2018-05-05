#include "ThreadPool.h"

void Worker::operator()() {
    std::function<void()> task;
    while (true) {
        {
            // acquire a lock
            std::unique_lock<std::mutex> lock(pool.queue_mutex);

            // look for a task to process
            while (!pool.stop && pool.tasks.empty()) {
                // if no tasks is present
                pool.condition.wait(lock);
            }

            // exit if the pool is stopped
            if (pool.stop) {
                return;
            }

            // fetch the next task from the queue
            task = pool.tasks.front();
            pool.tasks.pop_front();
        } // release the lock

        // execute task
        task();
    }
}

ThreadPool::ThreadPool(size_t numThreads) : stop(false) {
    for(auto i=0; i<numThreads; i++) {
        workers.emplace_back(Worker(*this));
    }
}

void ThreadPool::enqueue(std::function<void()> f) {
    {
        // acquire a lock
        std::unique_lock<std::mutex> lock(queue_mutex);

        // register the task
        tasks.push_back(f);
    } // release the lock

    // wake up one worker thread
    condition.notify_one();
}

ThreadPool::~ThreadPool() {
    stop = true;
    condition.notify_all();

    // join the threads
    for(auto &t : workers) {
        if (t.joinable()) {
            t.join();
        }
    }
}
