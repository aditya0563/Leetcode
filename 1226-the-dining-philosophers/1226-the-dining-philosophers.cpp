class DiningPhilosophers {
private:
    mutex forks[5];

public:
    DiningPhilosophers() {}

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
		int leftFork = philosopher;
        int rightFork = (philosopher + 1) % 5;

        int firstFork = min(leftFork, rightFork);
        int secondFork = max(leftFork, rightFork);
        
        unique_lock<mutex> lock1(forks[firstFork]);
        unique_lock<mutex> lock2(forks[secondFork]);
        
        pickLeftFork();
        pickRightFork();
        
        eat();
        
        putLeftFork();
        putRightFork();
    }
};