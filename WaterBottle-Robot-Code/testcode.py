import threading
import time
import kipr

def task():
    print("test")


thread1 = threading.Thread(target=task, args=())
thread1.start()
print(1)
thread1.join()
print(2)

print("Main thread: All threads finished.")