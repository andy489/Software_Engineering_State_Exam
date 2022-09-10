#include <iostream>

class Laptop {
    static int connectedCount;

    bool isConnected;
    int gigaByte;
    int processorsCount;
    float gigaHertz;

public:

    Laptop() {
        isConnected = false;
        gigaByte = 0;
        processorsCount = 0;
        gigaHertz = 0.0f;
    }

    Laptop(bool isConnected, int gigaByte, int processorsCount, float gigaHertz) {
        if (isConnected) {
            connectedCount++;
        }

        this->isConnected = isConnected;
        this->gigaByte = gigaByte;
        this->processorsCount = processorsCount;
        this->gigaHertz = gigaHertz;
    }

    Laptop(Laptop &other) {
        if (other.isConnected) {
            connectedCount++;
        }

        isConnected = other.isConnected;
        gigaByte = other.gigaByte;
        processorsCount = other.processorsCount;
        gigaHertz = other.gigaHertz;
    }

    ~Laptop() {
        if (isConnected) {
            --connectedCount;
        }
    }

    static int getAllConnected() {
        return connectedCount;
    }


    bool getConnected() const {
        return isConnected;
    }

    void setIsConnected(bool isConnected) {
        if (isConnected && !this->isConnected) {
            connectedCount++;
        }
        if (!isConnected && this->isConnected) {
            connectedCount--;
        }
        this->isConnected = isConnected;
    }

    int getGigaByte() const {
        return gigaByte;
    }


    void setGigaByte(int gigaByte) {
        this->gigaByte = gigaByte;
    }


    int getProcessorsCount() const {
        return processorsCount;
    }


    void setProcessorsCount(int processorsCount) {
        this->processorsCount = processorsCount;
    }

    float getGigaHertz() const {
        return gigaHertz;
    }

    void setGigaHertz(float gigaHertz) {
        this->gigaHertz = gigaHertz;
    }
};

int Laptop::connectedCount = 0;

int main() {
    std::cout << Laptop::getAllConnected() << std::endl;

    Laptop *l1 = new Laptop(true, 500, 1, 3.2f);
    Laptop *l2 = new Laptop(false, 1000, 1, 2.8f);

    std::cout << Laptop::getAllConnected() << std::endl;

    l2->setIsConnected(true);
    std::cout << Laptop::getAllConnected() << std::endl;

    l1->setIsConnected(false);
    std::cout << Laptop::getAllConnected() << std::endl;

    delete l2;

    std::cout << Laptop::getAllConnected() << std::endl;

    return 0;
}
