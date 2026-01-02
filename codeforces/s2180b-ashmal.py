n_test_cases = int(input())

for _ in range(n_test_cases):
    n_words = int(input())
    all_words = input()
    words = all_words.split(" ")
    result = ""

    for word in words:
        if word + result <= result + word:
            result = word + result
        else:
            result = result + word

    print(result)






