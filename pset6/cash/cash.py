from cs50 import get_float

numCoins = 0
change = get_float("Change owed: ")

while change < 0:
    change = get_float("Change owed: ")

cents = int(change * 100)

# print(f"{cents}")

numCoins = numCoins + (cents // 25)
cents = cents % 25

# print(f"{numCoins}")

numCoins = numCoins + (cents // 10)
cents = cents % 10

numCoins = numCoins + (cents // 5)
cents = cents % 5

numCoins = numCoins + (cents // 1)

print(f"{numCoins}")