class ZeroEvenOdd {
private:
    int n;
    counting_semaphore<1> zero_sem{1};
    counting_semaphore<1> odd_sem{0};
    counting_semaphore<1> even_sem{0};

public:
    ZeroEvenOdd(int n) {
        this->n = n;
    }

    void zero(function<void(int)> printNumber) {
        for (int i = 1; i <= n; ++i) {
            zero_sem.acquire();
            
            printNumber(0);
            
            if (i % 2 == 1) {
                odd_sem.release();
            } else {
                even_sem.release();
            }
        }
    }

    void even(function<void(int)> printNumber) {
        for (int i = 2; i <= n; i += 2) {
            even_sem.acquire();
            
            printNumber(i);
            
            zero_sem.release();
        }
    }

    void odd(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i += 2) {
            odd_sem.acquire();
            
            printNumber(i);
            
            zero_sem.release();
        }
    }
};