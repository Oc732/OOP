EXPERIMENT NO.7- Write a python program to store first year percentage of student in array write a function for
sorting array of floating point number in ascending order using selection sort and bubble sort
and display top five scores.





def selection_sort(arr):
    n = len(arr)
    for i in range(n):
        min_index = i
        for j in range(i + 1, n):
            if arr[j] < arr[min_index]:
                min_index = j
        # Swap the found minimum element with the first element
        arr[i], arr[min_index] = arr[min_index], arr[i]
    return arr

def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        # Last i elements are already sorted
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                # Swap if the element is greater than the next element
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
    return arr

def display_top_scores(arr, n=5):
    print(f"Top {n} scores:")
    # Check if there are fewer than 5 students
    if len(arr) < n:
        n = len(arr)
    for i in range(n):
        print(f"{i+1}. {arr[-(i+1)]}%")  # Print the top scores in descending order

def main():
    # Step 1: Accept the first-year percentage of students
    n = int(input("Enter the number of students: "))
    percentages = []
    for i in range(n):
        score = float(input(f"Enter percentage of student {i + 1}: "))
        percentages.append(score)
    
    # Step 2: Choose sorting method
    print("\nChoose sorting method:")
    print("1. Selection Sort")
    print("2. Bubble Sort")
    choice = int(input("Enter your choice (1 or 2): "))
    
    # Step 3: Sort the percentages and display top 5 scores
    if choice == 1:
        selection_sort(percentages)
        print("\nSorted scores using Selection Sort:")
        display_top_scores(percentages)
    elif choice == 2:
        bubble_sort(percentages)
        print("\nSorted scores using Bubble Sort:")
        display_top_scores(percentages)
    else:
        print("Invalid choice! Please select either 1 or 2.")
        
# Run the program
main()
