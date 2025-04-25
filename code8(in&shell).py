Practical 08:  write a python program to store second year percentage of student in array of floating point number in ascending order using a)insertion sort b)shell sort and display top five score





def insertion_sort(arr):
    n = len(arr)
    for i in range(1, n):
        key = arr[i]
        j = i - 1
        # Move elements of arr[0..i-1] that are greater than key
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key
    return arr

def shell_sort(arr):
    n = len(arr)
    gap = n // 2
    while gap > 0:
        # Perform a gapped insertion sort for this gap size
        for i in range(gap, n):
            key = arr[i]
            j = i
            while j >= gap and arr[j - gap] > key:
                arr[j] = arr[j - gap]
                j -= gap
            arr[j] = key
        gap //= 2
    return arr

def display_top_scores(arr, n=5):
    print(f"\nTop {n} scores:")
    # If there are fewer than 5 students, display all of them
    if len(arr) < n:
        n = len(arr)
    for i in range(n):
        print(f"{i+1}. {arr[-(i+1)]}%")  # Print the top scores in descending order

def main():
    # Step 1: Accept the second-year percentage of students
    n = int(input("Enter the number of students: "))
    percentages = []
    for i in range(n):
        score = float(input(f"Enter percentage of student {i + 1}: "))
        percentages.append(score)
    
    # Step 2: Choose sorting method
    print("\nChoose sorting method:")
    print("1. Insertion Sort")
    print("2. Shell Sort")
    choice = int(input("Enter your choice (1 or 2): "))
    
    # Step 3: Sort the percentages and display top 5 scores
    if choice == 1:
        insertion_sort(percentages)
        print("\nSorted scores using Insertion Sort:")
        display_top_scores(percentages)
    elif choice == 2:
        shell_sort(percentages)
        print("\nSorted scores using Shell Sort:")
        display_top_scores(percentages)
    else:
        print("Invalid choice! Please select either 1 or 2.")
        
# Run the program
main()
