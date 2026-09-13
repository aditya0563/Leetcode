class H2O {
public:
    mutex mtx;
    condition_variable cv;
    int h_count;

    H2O() {
        h_count = 0;
    }

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [this]() { return h_count < 2; });
        
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        h_count++;
        
        cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [this]() { return h_count == 2; });
        
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        h_count = 0;
        
        cv.notify_all();
    }
};