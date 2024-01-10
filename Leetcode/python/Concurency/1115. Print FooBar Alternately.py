import threading
import time
from typing import Callable


def printBar():
    print("bar")


def printFoo():
    print("foo")


class FooBar:
    sem: threading.Semaphore
    sem_two: threading.Semaphore

    def __init__(self, n):
        self.n = n
        self.sem = threading.Semaphore(1)
        self.sem_two = threading.Semaphore(1)
        self.sem_two.acquire()

    def foo(self, printFoo: "Callable[[], None]") -> None:
        for i in range(self.n):
            self.sem.acquire()
            printFoo()
            self.sem_two.release()
            # time.sleep(0.01)

    def bar(self, printBar: "Callable[[], None]") -> None:
        for i in range(self.n):
            self.sem_two.acquire()
            printBar()
            self.sem.release()


if __name__ == "__main__":
    s = FooBar(1000)

    th1 = threading.Thread(target=s.foo, args=(printFoo,))
    th2 = threading.Thread(target=s.bar, args=(printBar,))
    th1.start()
    th2.start()

    th1.join()
    th2.join()
    # 1 2 1 2 1
