from sys import argv, exit
import csv
import cs50

if len(argv) != 2:
    print("Usage: python import.py characters.csv")
    exit(1)

# open(f"students.db", "w").close()
db = cs50.SQL("sqlite:///students.db")

#db.execute("CREATE TABLE students (first TEXT, middle TEXT, last TEXT, house TEXT, birth NUMERIC)")

with open(argv[1], "r") as characters:

    reader = csv.DictReader(characters)

    for row in reader:

        name = row['name']

        numWords = len(name.split())

        if numWords == 3:

            lst = name.split()
            firstName = lst[0]
            middleName = lst[1]
            lastName = lst[2]

        elif numWords == 2:

            lst = name.split()
            firstName = lst[0]
            middleName = None
            lastName = lst[1]

        db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)", firstName, middleName, lastName, row['house'], row['birth'])

