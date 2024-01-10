import threading
from threading import Semaphore
from typing import Callable


def printNumber(number: int) -> None:
    print(number)


class ZeroEvenOdd:
    current_num: int

    sem_zero: Semaphore
    sem_even: Semaphore
    sem_odd: Semaphore

    def __init__(self, n):
        self.n = n
        self.current_num = 1

        self.sem_zero = Semaphore()
        self.sem_even = Semaphore()
        self.sem_odd = Semaphore()

        self.sem_even.acquire()
        self.sem_odd.acquire()

    # printNumber(x) outputs "x", where x is an integer.
    def zero(self, printNumber: "Callable[[int], None]") -> None:
        while self.n >= self.current_num:
            self.sem_zero.acquire()
            if self.n < self.current_num:
                # print(f"Abording 0 {self.current_num}")
                self.sem_even.release()
                self.sem_odd.release()
                return
            printNumber(0)

            if (self.current_num + 1) % 2 == 0:
                self.sem_odd.release()
            else:
                self.sem_even.release()

    def even(self, printNumber: "Callable[[int], None]") -> None:
        while self.n >= self.current_num:
            self.sem_even.acquire()
            # print("Executing even")
            if self.current_num > self.n:
                # print(f"Abording even {self.current_num}")
                return
            printNumber(self.current_num)
            self.current_num += 1

            self.sem_even.release()
            # if self.current_num + 1 <= self.n:
            self.sem_even.acquire()
            self.sem_zero.release()

    def odd(self, printNumber: "Callable[[int], None]") -> None:
        while self.n >= self.current_num:
            self.sem_odd.acquire()
            # print("Executing odd")
            if self.current_num > self.n:
                # print(f"Abording odd {self.current_num}")
                return
            printNumber(self.current_num)
            self.current_num += 1

            self.sem_odd.release()
            # if self.current_num + 1 <= self.n:
            self.sem_odd.acquire()
            self.sem_zero.release()


if __name__ == "__main__":
    s = ZeroEvenOdd(5)

    th1 = threading.Thread(target=s.zero, args=(printNumber,))
    th2 = threading.Thread(target=s.even, args=(printNumber,))
    th3 = threading.Thread(target=s.odd, args=(printNumber,))
    th1.start()
    th2.start()
    th3.start()

    th1.join()
    th2.join()
    th3.join()
    # 1 2 1 2 1
