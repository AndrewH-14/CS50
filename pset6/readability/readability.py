from cs50 import get_string

string = get_string("Text: ")

numLetters = 0
numWords = 1
numSent = 0

for i in range(len(string)):
    if string[i].isalpha():
        numLetters += 1
    elif string[i] == " ":
        numWords += 1
    elif string[i] == '.' or string[i] == '?' or string[i] == '!':
        numSent += 1

L = float((numLetters / numWords) * 100.0)
S = float((numSent / numWords) * 100.0)

index = round((0.0588 * L) - (0.296 * S) - 15.8)

if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print(f"Grade {index}")
    
    