import json

map = {
    "name": "ShaZi",
    "age": 1,
    "height": "***",
    "hobby": ["a", "b", "c"],
    "man": True,
    "secret": None,
    "other": {"x": "y", "z": "***"},
}

# python结构转换为json
# => {"name": "ShaZi", "age": 1, "height": "***", "hobby": ["a", "b", "c"], "man": true, "secret": null, "other": {"x": "y", "z": "***"}}
jsonStruct = json.dumps(map)
print(jsonStruct)

# json结构转换为python
# {'name': 'ShaZi', 'age': 1, 'height': '***', 'hobby': ['a', 'b', 'c'], 'man': True, 'secret': None, 'other': {'x': 'y', 'z': '***'}}
data = json.loads(jsonStruct)
print(data)

# 写入json
with open("temp.json", "w+") as file:
    json.dump(map, file)

# 读取json
# {'name': 'ShaZi', 'age': 1, 'height': '***', 'hobby': ['a', 'b', 'c'], 'man': True, 'secret': None, 'other': {'x': 'y', 'z': '***'}}
with open("temp.json", "r") as file:
    data = json.load(file)
    print(data)
