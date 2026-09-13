class H2O {
public:
    counting_semaphore<1> h_sem{1};
    counting_semaphore<1> o_sem{0};
    bool second_h = false;

    H2O() {

    }

    void hydrogen(function<void()> releaseHydrogen) {
        h_sem.acquire();
        
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        
        if (second_h) {
            second_h = false;
            o_sem.release();
        } else {
            second_h = true;
            h_sem.release();
        }
    }

    void oxygen(function<void()> releaseOxygen) {
        o_sem.acquire();
        
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        
        h_sem.release();
    }
};