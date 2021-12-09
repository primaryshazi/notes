import pandas

FILE_NAME = 'temp.csv'
CSV_DICT = {'name': ['citrus', 'yuru yuri'], 'score': [8.0, 9.5]}

frame = pandas.DataFrame(CSV_DICT)
frame.to_csv(FILE_NAME, index=False)

data = pandas.read_csv(FILE_NAME)

# => ['name', 'score', 'comment']
# => (3, 3)
# => 3
# => [['citrus' 8.0 'NULL']
# =>  ['yuru yuri' 9.5 'NULL']
# =>  ['Bloom Into You' 9.0 'NULL']]
data['comment'] = ['NULL', 'NULL']
data.loc[3] = ['Bloom Into You', 9.0, 'NULL']
pandas.DataFrame(data).to_csv(FILE_NAME, index=False)
print(list(data.columns))  # 列头
print(data.shape)  # 行列
print(len(data))  # 行数
print(data.values)  # 数据

# => ['name', 'score']
# => (2, 2)
# => 2
# => [['citrus' 8.0]
# =>  ['yuru yuri' 9.5]]
data = data.drop(3, axis=0)  # 删除行
data = data.drop('comment', axis=1)  # 删除列
pandas.DataFrame(data).to_csv(FILE_NAME, index=False)
print(list(data.columns))  # 列头
print(data.shape)  # 行列
print(len(data))  # 行数
print(data.values)  # 数据
