from sys import argv, exit
import cs50

if len(argv) != 2:
    print("Usage: roster.py house")
    exit(1)

#userHouse = argv[1]
db = cs50.SQL("sqlite:///students.db")

dct = db.execute("SELECT * FROM students ORDER BY last")

for row in dct:

    if row['house'] == argv[1]:

        if row['middle'] != None:

            print(f"{row['first']} {row['middle']} {row['last']}, born {row['birth']}")

        else:
            print(f"{row['first']} {row['last']}, born {row['birth']}")
