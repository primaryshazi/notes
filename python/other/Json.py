import json

map = {'name': 'ShaZi', 'age': 1, 'height': '***', 'hobby': ['yuri', 'yuri', 'yuri'], 'man': True, 'secret': None, 'other': {'education': 'undergraduate', 'profession': '***'}}

# python结构转换为json
# => {"name": "ShaZi", "age": 1, "height": "***", "hobby": ["yuri", "yuri", "yuri"], "man": true, "secret": null, "other": {"education": "undergraduate", "profession": "***"}}
jsonStruct = json.dumps(map)
print(jsonStruct)

# json结构转换为python
# {'name': 'ShaZi', 'age': 1, 'height': '***', 'hobby': ['yuri', 'yuri', 'yuri'], 'man': True, 'secret': None, 'other': {'education': 'undergraduate', 'profession': '***'}}
data = json.loads(jsonStruct)
print(data)

# 写入json
with open('temp.json', 'w+') as file:
    json.dump(map, file)

# 读取json
# {'name': 'ShaZi', 'age': 1, 'height': '***', 'hobby': ['yuri', 'yuri', 'yuri'], 'man': True, 'secret': None, 'other': {'education': 'undergraduate', 'profession': '***'}}
with open('temp.json', 'r') as file:
    data = json.load(file)
    print(data)
