class Foo {

private:
    mutex mtx;
    condition_variable cv;
    int step;
    
public:
    Foo() {
        step = 1;
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();

        unique_lock<mutex> lock(mtx);
        step = 2;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [this]() { return step == 2; });

        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();

        step = 3;
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [this]() { return step == 3; });
        
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};