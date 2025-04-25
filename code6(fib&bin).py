EXPERIMEMT NO.6- Write a python program to store roll no of student in array who attended training program in
sorted order. Write function for searching whether particular student attended training program
or not using binary search and Fibonacci search.





def accept_roll_numbers():
    """Accept roll numbers and return them sorted."""
    n = int(input("Enter the number of students who attended the training program: "))
    roll_numbers = []

    print("Enter the roll numbers:")
    for i in range(n):
        roll_no = int(input(f"Enter roll number of student {i + 1}: "))
        roll_numbers.append(roll_no)

    roll_numbers.sort()
    print("\nRoll numbers sorted successfully!")
    return roll_numbers

def binary_search(arr, x):
    """Perform binary search on a sorted array."""
    low, high = 0, len(arr) - 1
    while low <= high:
        mid = (low + high) // 2
        if arr[mid] == x:
            return mid
        elif arr[mid] < x:
            low = mid + 1
        else:
            high = mid - 1
    return -1

def fibonacci_search(arr, x):
    """Perform Fibonacci search on a sorted array."""
    n = len(arr)
    fib_m_2 = 0
    fib_m_1 = 1
    fib = fib_m_2 + fib_m_1

    while fib < n:
        fib_m_2, fib_m_1 = fib_m_1, fib
        fib = fib_m_2 + fib_m_1

    offset = -1
    while fib > 1:
        i = min(offset + fib_m_2, n - 1)
        
        if arr[i] < x:
            fib, fib_m_1, fib_m_2 = fib_m_1, fib_m_2, fib - fib_m_1
            offset = i
        elif arr[i] > x:
            fib, fib_m_1, fib_m_2 = fib_m_2, fib_m_1 - fib_m_2, fib - fib_m_1
        else:
            return i

    if fib_m_1 and offset + 1 < n and arr[offset + 1] == x:
        return offset + 1

    return -1

def main():
    roll_numbers = accept_roll_numbers()

    while True:
        print("\n--- MENU ---")
        print("1. Search using Binary Search")
        print("2. Search using Fibonacci Search")
        print("3. Exit")

        choice = int(input("Enter your choice: "))

        if choice == 3:
            print("Exiting the program...")
            break

        roll_no = int(input("Enter the roll number to search: "))

        if choice == 1:
            index = binary_search(roll_numbers, roll_no)
            method = "Binary Search"
        elif choice == 2:
            index = fibonacci_search(roll_numbers, roll_no)
            method = "Fibonacci Search"
        else:
            print("Invalid choice, please try again.")
            continue

        if index != -1:
            print(f"Roll number {roll_no} found at index {index} using {method}.")
        else:
            print(f"Roll number {roll_no} not found using {method}.")

# Run the program
if __name__ == "__main__":
    main()
