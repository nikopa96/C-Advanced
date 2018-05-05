#ifndef PRAX07_BIRD_H
#define PRAX07_BIRD_H

#include <string>

typedef enum {
    t_PIDGEON,
    t_PENGUIN,
    t_DUCK
} BirdType;

class Bird {
public:
    Bird(const std::string &birdName, size_t birdId);
    virtual void run() final;
    virtual void makeNoise() final;
    virtual void flapWings() final;
    virtual void doEverything() = 0;
protected:
    std::string name;
    size_t id;
    std::string displayName;
};

class FlyingBird : public Bird {
public:
    FlyingBird(const std::string &birdName, size_t birdId)
            : Bird(birdName,birdId) {}
    void doEverything() override;
protected:
    virtual void fly() final;
};

class SwimmingBird : public Bird {
public:
    SwimmingBird(const std::string &birdName, size_t birdId)
            : Bird(birdName,birdId) {}
    void doEverything() override;
protected:
    virtual void swim() final;

};

class Pidgeon final : public FlyingBird {
public:
    Pidgeon() : FlyingBird("pidgeon",++counter) {}
private:
    static size_t counter;
};

class Penguin final : public SwimmingBird {
public:
    Penguin() : SwimmingBird("penguin",++counter) {}
private:
    static size_t counter;
};

struct BirdFactory {
    static Bird * makeBird(BirdType type);
};

#endif //PRAX07_BIRD_H
