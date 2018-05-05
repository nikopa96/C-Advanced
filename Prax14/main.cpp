#include <iostream>
#include <future>
#include "ThreadPool.h"

std::future<int> my_work() {
    auto promise = std::make_shared<std::promise<int>>();
    auto lambda = [promise]{ promise->set_value(42); };
    std::thread t(lambda);
    t.detach();
    return promise->get_future();
}

int slow_operation(int x) {
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    return x;
}

int exception_operation(int x) {
    throw std::runtime_error("Asynchronous exception");
}

void f() {
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    std::cout << "f() exited" << std::endl;
}

void g() {
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    std::cout << "g() exited" << std::endl;
}

void task_lambda() {
    auto lambda = [](int a,int b){ return a+b; };
    std::packaged_task<int(int,int)> task(lambda);
    auto future = task.get_future();
    task(2,9);
    std::cout << "task_lambda: " << future.get() << std::endl;
}

void task_thread() {
    auto lambda = [](int a,int b){ return a+b; };
    std::packaged_task<int(int,int)> task(lambda);
    auto future = task.get_future();
    std::thread t(std::move(task), 2, 9);
    t.join();
    std::cout << "task_thread: " << future.get() << std::endl;
}

int main() {

    auto future1 = my_work();  // std::future<int>
    std::cout << "future 1: " << future1.get() << std::endl;

    auto future2 = std::async(std::launch::async, slow_operation, 10);
    auto future3 = std::async(std::launch::deferred, slow_operation, 10);
    auto future4 = std::async(std::launch::async, exception_operation, 10);
    try {
        std::cout << "future 2 + future 3: " << future2.get() + future3.get() << std::endl;
        future4.get();
    } catch (const std::exception &e) {
        std::cout << "Exception " << e.what() << std::endl;
    }

    // f() and g() are not executed in parallel, because futures we get from async have
    // blocking destructors. This code will not run g() until f() has completely finished.
    // current status: submitted defect report to the standards committee
    std::async(std::launch::async, []{ f(); });
    std::async(std::launch::async, []{ g(); });

    task_lambda();
    task_thread();

    // create a thread pool of 5 worker threads
    ThreadPool pool(5);

    // queue a bunch of "work items"
    for(auto i=0; i<8; i++) {
        auto lambda = [i] {
            std::cout << "hello " << i << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(125));
            std::cout << "World " << i << std::endl;
        };
        pool.enqueue(lambda);
        pool.enqueue(lambda);
        pool.enqueue(lambda);
        pool.enqueue(lambda);
        pool.enqueue(lambda);
    }



    return 0;
}