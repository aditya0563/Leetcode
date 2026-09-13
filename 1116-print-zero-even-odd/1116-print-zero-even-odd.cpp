class ZeroEvenOdd {
private:
    int n;
    mutex mtx;
    condition_variable cv;
    int state;
    int i;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        state = 0;
        i = 1;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for (int k = 0; k < n; ++k) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this]() { return state == 0; });
            
            printNumber(0);
            
            if (i % 2 == 1) {
                state = 1;
            } else {
                state = 2;
            }
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        for (int k = 2; k <= n; k += 2) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this]() { return state == 2; });
            
            printNumber(i);
            i++;
            
            state = 0;
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        for (int k = 1; k <= n; k += 2) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this]() { return state == 1; });
            
            printNumber(i);
            i++;
            
            state = 0;
            cv.notify_all();
        }
    }
};