import time
from threading import Semaphore, Thread
from typing import Callable


def printBuzz():
    print("buzz")


def printFizz():
    print("fizz")


def printFizzBuzz():
    print("fizzbuzz")


def printNumber(x):
    print(x)


class FizzBuzz:
    """
    "fizzbuzz" if i is divisible by 3 and 5,
    "fizz" if i is divisible by 3 and not 5,
    "buzz" if i is divisible by 5 and not 3, or
    i if i is not divisible by 3 or 5
    """

    n: int
    current_n: int
    sem_fizz: Semaphore
    sem_fizzbuzz: Semaphore
    sem_buzz: Semaphore
    sem_number: Semaphore

    def __init__(self, n: int):
        self.n = n
        self.current_n = 1
        self.sem_buzz = Semaphore()
        self.sem_fizz = Semaphore()
        self.sem_fizzbuzz = Semaphore()
        self.sem_number = Semaphore()

        self.sem_buzz.acquire()
        self.sem_fizz.acquire()
        self.sem_fizzbuzz.acquire()

    def fizz(self, printFizz: "Callable[[], None]") -> None:
        self.sem_fizz.acquire()
        while self.n >= self.current_n:
            printFizz()
            self._realse_corresponding()
            self.sem_fizz.acquire()
        self._realse_corresponding()

    # printBuzz() outputs "buzz"
    def buzz(self, printBuzz: "Callable[[], None]") -> None:
        self.sem_buzz.acquire()
        while self.n >= self.current_n:
            printBuzz()
            self._realse_corresponding()
            self.sem_buzz.acquire()
        self._realse_corresponding()

    # printFizzBuzz() outputs "fizzbuzz"
    def fizzbuzz(self, printFizzBuzz: "Callable[[], None]") -> None:
        self.sem_fizzbuzz.acquire()
        while self.n >= self.current_n:
            printFizzBuzz()
            self._realse_corresponding()
            self.sem_fizzbuzz.acquire()

        self._realse_corresponding()

    def number(self, printNumber: "Callable[[int], None]") -> None:
        self.sem_number.acquire()
        while self.n >= self.current_n:
            # print(f"Printing number ({self.current_n})")
            printNumber(self.current_n)
            self._realse_corresponding()
            self.sem_number.acquire()

        self._realse_corresponding()

    def _realse_corresponding(self) -> None:
        # Based on the current_n, relase the good next function$
        self.current_n += 1
        # time.sleep(0.1)
        num = self.current_n
        if num > self.n:
            self.sem_fizzbuzz.release()
            self.sem_buzz.release()
            self.sem_fizz.release()
            self.sem_number.release()

            return

        if num % 3 == 0 and num % 5 == 0:
            self.sem_fizzbuzz.release()
        elif num % 3 == 0:
            self.sem_fizz.release()
        elif num % 5 == 0:
            self.sem_buzz.release()
        else:
            # print(f"num % 5 == {num%5}")
            self.sem_number.release()


if __name__ == "__main__":
    s = FizzBuzz(30)

    th1 = Thread(target=s.fizz, args=(printFizz,))
    th2 = Thread(target=s.buzz, args=(printBuzz,))
    th3 = Thread(target=s.fizzbuzz, args=(printFizzBuzz,))
    th4 = Thread(target=s.number, args=(printNumber,))
    th1.start()
    th2.start()
    th3.start()
    th4.start()

    th1.join()
    th2.join()
    th3.join()
    th4.join()
