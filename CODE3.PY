EXPERIMENT NO.3- Write a python program to compute following operations on String:
1. To display word with longest length
2. To determine the freqyency of occurrences of particular character in the string
3. To check whether given string is palindrome or not
4. To display index of first apprearance of the substring
5. To count the occurrences of each word in a given string 



def display_longest_word(s):
    words = s.split()
    longest_word = ""
    for word in words:
        if len(word) > len(longest_word):
            longest_word = word
    return longest_word


def character_frequency(s, char):
    count = 0
    for c in s:
        if c == char:
            count += 1
    return count


def is_palindrome(s):
    start = 0
    end = len(s) - 1
    while start < end:
        if s[start] != s[end]:
            return False
        start += 1
        end -= 1
    return True


def find_substring_index(s, substring):
    index = s.find(substring)
    return index


def count_word_occurrences(s):
    word_count = {}
    words = s.split()
    for word in words:
        if word in word_count:
            word_count[word] += 1
        else:
            word_count[word] = 1
    return word_count


# Main loop
while True:
    string = input("Enter a string: ")
    print("Longest word:", display_longest_word(string))

    char = input("Enter a character to find its frequency: ")
    if len(char) != 1:
        print("Please enter only one character.")
    else:
        print(f"Frequency of '{char}':", character_frequency(string, char))

    print("Is the string a palindrome?", is_palindrome(string))

    substring = input("Enter a substring to find its first appearance index: ")
    index = find_substring_index(string, substring)
    if index == -1:
        print("Substring not found")
    else:
        print(f"Index of first appearance of '{substring}':", index)

    word_occurrences = count_word_occurrences(string)
    print("Word occurrences:", word_occurrences)

    continue_program = input("Do you want to continue? (y/n): ").strip().lower()
    if continue_program != "y":
        break
