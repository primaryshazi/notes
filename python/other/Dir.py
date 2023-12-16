import os

DIR_PATH = (os.getcwd() + "/sz_dir").replace("\\", "/")


# 递归获取所有文件和文件夹
def listFullPathRecursion(path: str) -> list[str]:
    if not os.path.exists(path):
        return []

    fullpaths: list[str] = []
    if os.path.isdir(path):
        dirs = os.listdir(path)
        for dirPath in dirs:
            fullpaths += listFullPathRecursion("{}/{}".format(path, dirPath))
        fullpaths.append(path)
    else:
        fullpaths.append(path)

    return fullpaths


# 递归删除所有文件和文件夹
def removeRecursion(path: str):
    if not os.path.exists(path):
        return

    fullpaths = listFullPathRecursion(path)
    for fp in fullpaths:
        if os.path.isdir(fp):
            os.rmdir(fp)
            print("remove dir:%s" % fp)
        else:
            os.remove(fp)
            print("remove file:%s" % fp)


# 递归创建路径
def createRecursion(path: str):
    if os.path.exists(path):
        return
    os.makedirs(path)


removeRecursion(DIR_PATH)
createRecursion(DIR_PATH + "/1/2/3/4/5/6")
print(listFullPathRecursion(DIR_PATH))
