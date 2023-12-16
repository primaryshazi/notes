import pandas

FILE_NAME = "temp.xlsx"
EXCEL_DICT = {"name": ["a", "b"], "score": [8.0, 9.5]}

frame = pandas.DataFrame(EXCEL_DICT)
# 写在letter页，不添加行名
frame.to_excel(FILE_NAME, sheet_name="letter", index=False)

data = pandas.read_excel(FILE_NAME, sheet_name="letter")

# => ['name', 'score', 'comment']
# => (3, 3)
# => [['a' 8.0 'NULL']
# =>  ['b' 9.5 'NULL']
# =>  ['c' 9.0 'NULL']]
data["comment"] = ["NULL", "NULL"]
data.loc[3] = ["c", 9.0, "NULL"]
pandas.DataFrame(data).to_excel(FILE_NAME, sheet_name="letter", index=False)
print(list(data.columns))  # 获取列名
print(data.shape)  # 获取行列
print(data.values)  # 获取所有值

# => ['name', 'score']
# => (2, 2)
# => [['a' 8.0]
# =>  ['b' 9.5]]
data = data.drop(3, axis=0)  # 删除行
data = data.drop("comment", axis=1)  # 删除列
pandas.DataFrame(data).to_excel(FILE_NAME, sheet_name="letter", index=False)
print(list(data.columns))  # 获取列名
print(data.shape)  # 获取行列
print(data.values)  # 获取所有值
