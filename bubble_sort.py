import random
import time
import matplotlib.pyplot as plt

# Bubble Sort
def bubble_sort(arr):
    n = len(arr)

    for i in range(n):
        for j in range(n-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]

# Different array sizes
sizes = [100, 500, 1000, 2000, 5000]

# Array to store execution times
time_array = []

print("Array Size\tTime (seconds)")
print("-------------------------------")

for size in sizes:

    # Generate random array
    arr = [random.randint(1, 10000) for _ in range(size)]

    start = time.perf_counter()

    bubble_sort(arr)

    end = time.perf_counter()

    elapsed = end - start

    # Store time in array
    time_array.append(elapsed)

    print(size, "\t\t", round(elapsed, 6))

# Plot graph using arrays
plt.plot(sizes, time_array, marker='o')
plt.title("Bubble Sort Time Analysis")
plt.xlabel("Array Size")
plt.ylabel("Execution Time (seconds)")
plt.grid(True)
plt.show()