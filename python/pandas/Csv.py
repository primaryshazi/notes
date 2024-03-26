import pandas

FILE_NAME = "temp.csv"
CSV_DICT = {"name": ["a", "b"], "score": [8.0, 9.5]}

frame = pandas.DataFrame(CSV_DICT)
frame.to_csv(FILE_NAME, index=False)

data = pandas.read_csv(FILE_NAME)

# => ['name', 'score', 'comment']
# => (3, 3)
# => 3
# => [['a' 8.0 'NULL']
# =>  ['b' 9.5 'NULL']
# =>  ['c' 9.0 'NULL']]
data["comment"] = ["NULL", "NULL"]
data.loc[3] = ["c", 9.0, "NULL"]
pandas.DataFrame(data).to_csv(FILE_NAME, index=False)
print(list(data.columns))  # 列头
print(data.shape)  # 行列
print(len(data))  # 行数
print(data.values)  # 数据

# => ['name', 'score']
# => (2, 2)
# => 2
# => [['a' 8.0]
# =>  ['b' 9.5]]
data = data.drop(3, axis=0)  # 删除行
data = data.drop("comment", axis=1)  # 删除列
pandas.DataFrame(data).to_csv(FILE_NAME, index=False)
print(list(data.columns))  # 列头
print(data.shape)  # 行列
print(len(data))  # 行数
print(data.values)  # 数据
