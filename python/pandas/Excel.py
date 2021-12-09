import pandas

FILE_NAME = 'temp.xlsx'
EXCEL_DICT = {'name': ['citrus', 'yuru yuri'], 'score': [8.0, 9.5]}

frame = pandas.DataFrame(EXCEL_DICT)
# 写在yuri页，不添加行名
frame.to_excel(FILE_NAME, sheet_name='yuri', index=False)

data = pandas.read_excel(FILE_NAME, sheet_name='yuri')

# => ['name', 'score', 'comment']
# => (3, 3)
# => [['citrus' 8.0 'NULL']
# =>  ['yuru yuri' 9.5 'NULL']
# =>  ['Bloom Into You' 9.0 'NULL']]
data['comment'] = ['NULL', 'NULL']
data.loc[3] = ['Bloom Into You', 9.0, 'NULL']
pandas.DataFrame(data).to_excel(FILE_NAME, sheet_name='yuri', index=False)
print(list(data.columns))  # 获取列名
print(data.shape)  # 获取行列
print(data.values)  # 获取所有值

# => ['name', 'score']
# => (2, 2)
# => [['citrus' 8.0]
# =>  ['yuru yuri' 9.5]]
data = data.drop(3, axis=0)  # 删除行
data = data.drop('comment', axis=1)  # 删除列
pandas.DataFrame(data).to_excel(FILE_NAME, sheet_name='yuri', index=False)
print(list(data.columns))  # 获取列名
print(data.shape)  # 获取行列
print(data.values)  # 获取所有值
