import csv

FIELD_NAME = ["name", "score"]

FILE_NAME = "temp.csv"

CSV_LIST = [("a", 8.0), ("b", 9.5)]

CSV_DICT = [{"name": "a", "score": 8.0}, {"name": "b", "score": 9.5}]

with open(FILE_NAME, "w", newline="") as file:
    csvWriter = csv.writer(file)
    for item in CSV_LIST:
        csvWriter.writerow(item)

# => ['a', '8.0']
# => ['b', '9.5']
with open(FILE_NAME, "r") as file:
    csvReader = csv.reader(file)
    for row in csvReader:
        print(row)

with open(FILE_NAME, "w", newline="") as file:
    csvWriter = csv.DictWriter(file, fieldnames=FIELD_NAME)
    csvWriter.writeheader()
    csvWriter.writerows(CSV_DICT)

# => {'name': 'name', 'score': 'score'}
# => {'name': 'a', 'score': '8.0'}
# => {'name': 'b', 'score': '9.5'}
with open(FILE_NAME, "r") as file:
    csvReader = csv.DictReader(file, fieldnames=FIELD_NAME)
    for item in csvReader:
        print(item)
