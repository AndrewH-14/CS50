from sys import argv, exit
import csv

if len(argv) != 3:
    print("Usage: python dna.py data.csv sequence.txt")
    exit(1)

file = open(argv[2], "r")
sequence = file.readline()
listSeq = list(sequence)
file.close()

maxAGATC = 0
maxAATG = 0
maxTATC = 0
maxTTTTTTCT = 0
maxTCTAG = 0
maxGATA = 0
maxGAAA = 0
maxTCTG = 0

for i in range(len(listSeq) - 5):
    numAGATC = 0
    if listSeq[i] == "A" and listSeq[i + 1] == "G" and listSeq[i + 2] == "A" and listSeq[i + 3] == "T" and listSeq[i + 4] == "C":
        iterAGATC = 0
        while listSeq[i + iterAGATC] == "A" and listSeq[i + 1 + iterAGATC] == "G" and listSeq[i + 2 + iterAGATC] == "A" and listSeq[i + 3 + iterAGATC] == "T" and listSeq[i + 4 + iterAGATC] == "C":
            numAGATC += 1
            iterAGATC += 5
        if numAGATC > maxAGATC:
            maxAGATC = numAGATC
    numAGATC = 0
# print(maxAGATC)

for i in range(len(listSeq) - 4):
    numAATG = 0
    if listSeq[i] == "A" and listSeq[i + 1] == "A" and listSeq[i + 2] == "T" and listSeq[i + 3] == "G":
        iterAATG = 0
        while listSeq[i + iterAATG] == "A" and listSeq[i + 1 + iterAATG] == "A" and listSeq[i + 2 + iterAATG] == "T" and listSeq[i + 3 + iterAATG] == "G":
            numAATG += 1
            iterAATG += 4
            if (iterAATG + i) > len(listSeq) - 1:
                break
        if numAATG > maxAATG:
            maxAATG = numAATG
    numAATG = 0
# print(maxAATG)

for i in range(len(listSeq) - 4):
    numTATC = 0
    if listSeq[i] == "T" and listSeq[i + 1] == "A" and listSeq[i + 2] == "T" and listSeq[i + 3] == "C":
        iterTATC = 0
        while listSeq[i + iterTATC] == "T" and listSeq[i + 1 + iterTATC] == "A" and listSeq[i + 2 + iterTATC] == "T" and listSeq[i + 3 + iterTATC] == "C":
            numTATC += 1
            iterTATC += 4
        if numTATC > maxTATC:
            maxTATC = numTATC
    numTATC = 0
# print(maxTATC)

for i in range(len(listSeq) - 8):
    numTTTTTTCT = 0
    if listSeq[i] == "T" and listSeq[i + 1] == "T" and listSeq[i + 2] == "T" and listSeq[i + 3] == "T" and listSeq[i + 4] == "T" and listSeq[i + 5] == 'T' and listSeq[i + 6] == 'C' and listSeq[i + 7] == 'T':
        iterTTTTTTCT = 0
        while listSeq[i + iterTTTTTTCT] == "T" and listSeq[i + 1 + iterTTTTTTCT] == "T" and listSeq[i + 2 + iterTTTTTTCT] == "T" and listSeq[i + 3 + iterTTTTTTCT] == "T" and listSeq[i + 4 + iterTTTTTTCT] == "T" and listSeq[i + 5 + iterTTTTTTCT] =="T" and listSeq[i + 6 + iterTTTTTTCT] =="C" and listSeq[i + 7 + iterTTTTTTCT] =="T":
            #print(f"{listSeq[i]}{listSeq[i + 1]}{listSeq[i + 2]}{listSeq[i + 3]}{listSeq[i + 4]}{listSeq[i + 5]}{listSeq[i + 6]}{listSeq[i + 7]}")
            numTTTTTTCT += 1
            iterTTTTTTCT += 8
        if numTTTTTTCT > maxTTTTTTCT:
            maxTTTTTTCT = numTTTTTTCT
    numTTTTTTCT = 0
# print(maxTTTTTTCT)

for i in range(len(listSeq) - 5):
    numTCTAG = 0
    if listSeq[i] == "T" and listSeq[i + 1] == "C" and listSeq[i + 2] == "T" and listSeq[i + 3] == "A" and listSeq[i + 4] == "G":
        iterTCTAG = 0
        while listSeq[i + iterTCTAG] == "T" and listSeq[i + 1 + iterTCTAG] == "C" and listSeq[i + 2 + iterTCTAG] == "T" and listSeq[i + 3 + iterTCTAG] == "A" and listSeq[i + 4 + iterTCTAG] == "G":
            numTCTAG += 1
            iterTCTAG += 5
        if numTCTAG > maxTCTAG:
            maxTCTAG = numTCTAG
    numTCTAG = 0
# print(maxTCTAG)

for i in range(len(listSeq) - 4):
    numGATA = 0
    if listSeq[i] == "G" and listSeq[i + 1] == "A" and listSeq[i + 2] == "T" and listSeq[i + 3] == "A":
        iterGATA = 0
        while listSeq[i + iterGATA] == "G" and listSeq[i + 1 + iterGATA] == "A" and listSeq[i + 2 + iterGATA] == "T" and listSeq[i + 3 + iterGATA] == "A":
            numGATA += 1
            iterGATA += 4
        if numGATA > maxGATA:
            maxGATA = numGATA
    numGATA = 0
# print(maxGATA)

for i in range(len(listSeq) - 4):
    numGAAA = 0
    if listSeq[i] == "G" and listSeq[i + 1] == "A" and listSeq[i + 2] == "A" and listSeq[i + 3] == "A":
        iterGAAA = 0
        while listSeq[i + iterGAAA] == "G" and listSeq[i + 1 + iterGAAA] == "A" and listSeq[i + 2 + iterGAAA] == "A" and listSeq[i + 3 + iterGAAA] == "A":
            numGAAA += 1
            iterGAAA += 4
        if numGAAA > maxGAAA:
            maxGAAA = numGAAA
    numGAAA = 0
# print(maxGAAA)

for i in range(len(listSeq) - 4):
    numTCTG = 0
    if listSeq[i] == "T" and listSeq[i + 1] == "C" and listSeq[i + 2] == "T" and listSeq[i + 3] == "G":
        iterTCTG = 0
        while listSeq[i + iterTCTG] == "T" and listSeq[i + 1 + iterTCTG] == "C" and listSeq[i + 2 + iterTCTG] == "T" and listSeq[i + 3 + iterTCTG] == "G":
            numTCTG += 1
            iterTCTG += 4
        if numTCTG > maxTCTG:
            maxTCTG = numTCTG
    numTCTG = 0
# print(maxTCTG)

with open(argv[1], newline="") as csvfile:
    database = csv.DictReader(csvfile)
    for row in database:
        if len(row) == 4 and int(row['AGATC']) == maxAGATC and int(row['AATG']) == maxAATG and int(row['TATC']) == maxTATC:
            print(row['name'])
            exit(0)
        elif int(row['AGATC']) == maxAGATC and int(row['AATG']) == maxAATG and int(row['TATC']) == maxTATC and int(row['TTTTTTCT']) == maxTTTTTTCT and int(row['TCTAG']) == maxTCTAG and int(row['GATA']) == maxGATA and int(row['GAAA']) == maxGAAA and int(row['TCTG']) == maxTCTG:
            print(row['name'])
            exit(0)

print("No match")
exit(0)