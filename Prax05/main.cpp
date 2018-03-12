#include <iostream>
#include <cstring>
#include <chrono>
#include <thread>

float add(float a, float b) { return a+b; }
float mul(float a, float b) { return a*b; }

std::string getShorterString(const char* s1, const char* s2,
                             int(*comparator)(const char*, const char*)) {
    return comparator(s1,s2) < 1 ? std::string(s1) : std::string(s2);
}

void successHandler(std::string s) {
    std::cout << "Received a message " << s << std::endl;
}

typedef unsigned char u_char;   // C++98
using byte = unsigned char;     // C++11

typedef void(*TMsg)(std::string);   // C++98
using msg_t = void(*)(std::string); // C++11

class Worker {
public:
    Worker() {
        callback = nullptr;
    }
    void onFinished(msg_t handler) {
        callback = handler;
    }
    void startComputation() {
        std::cout << "Starting fancy computations" << std::endl;

        // simulate complex data processing
        std::this_thread::sleep_for(std::chrono::seconds(3));

        // we are done - notify the teller
        callback("I'm done with the fancy computations.");
    }
private:
    msg_t callback;
};

int lengthComparator(const char* s1, const char* s2) {

    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);

    if ( len1 == len2 ) {
        return 0;
    } else {
        return len1 < len2 ? -1 : 1;
    }

}

int main() {

    // statically allocate 1KB of memory on the stack
    unsigned char buf[1024];

    // allocate 4 bytes in the heap (not initialized)
    int *iptr = new int(); delete iptr;

    // allocate 4 bytes in the heap and copy value 100 into it
    iptr = new int(100);  delete iptr;

    // a (uninitialized) pointer named pBinOp that points to
    // any function with signature float(float,float).
    float(*pBinOp)(float,float);

    // pBinOp now points to the function add
    pBinOp = add;
    std::cout << "5 + 7 = " << pBinOp(5,7) << std::endl;

    pBinOp = mul;
    std::cout << "5 * 7 = " << pBinOp(5,7) << std::endl;

    std::cout << getShorterString("Hello","World!",strcmp) << std::endl;
    std::cout << getShorterString("Hello", "Wor",lengthComparator) << std::endl;

    // create a Worker type object on the stack
    Worker worker1;

    // register the callback
    worker1.onFinished(successHandler);
    worker1.startComputation();

    // allocate a Worker object in the heap
    auto *worker2 = new Worker();

    // register the callback
    worker2->onFinished(successHandler);
    worker2->startComputation();

    delete worker2;

    return 0;
}