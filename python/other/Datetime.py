import time
import datetime
import calendar


# => Now time : 1617957650.768357
# => Local time :  time.struct_time(tm_year=2021, tm_mon=4, tm_mday=9, tm_hour=16, tm_min=40, tm_sec=50, tm_wday=4, tm_yday=99, tm_isdst=0)
# => Local time :  Fri Apr  9 16:40:50 2021
# => Local time :  2021-04-09 16:40:50
# 当前时间以秒的形式
print('Now time : {:f}'.format(time.time()))
# 本地时间以元组形式
print('Local time : ', time.localtime(time.time()))
# 本地时间
print('Local time : ', time.asctime(time.localtime(time.time())))
# 格式化本地时间
print('Local time : ', time.strftime('%Y-%m-%d %H:%M:%S', time.localtime()))

# => beg : 2021-04-09 16:40:50.769352
# => end : 2021-04-09 16:40:52.769774
# 获取当前日期和时间
beg = datetime.datetime.now()
print('beg : ' + str(beg))
time.sleep(2)
end = datetime.datetime.now()
print('end : ' + str(end))

# datetime转str
strBeg = beg.strftime('%Y-%m-%d %H:%M:%S')
strEnd = end.strftime('%Y-%m-%d %H:%M:%S')
# str转datetime
beg = datetime.datetime.strptime(strBeg, '%Y-%m-%d %H:%M:%S')
end = datetime.datetime.strptime(strEnd, '%Y-%m-%d %H:%M:%S')

# => seconds : 2
# 二者时间间隔，只返回秒部
print('seconds : {:d}'.format(int((end - beg).seconds)))

# 字符串时间转换为秒
secBeg = time.mktime(time.strptime(strBeg, "%Y-%m-%d %H:%M:%S"))
secEnd = time.mktime(time.strptime(strEnd, "%Y-%m-%d %H:%M:%S"))
# => seconds : 2
print('seconds : {:d}'.format(int(secEnd - secBeg)))

# => 2020-1 :
# =>    January 2020
# => Mo Tu We Th Fr Sa Su
# =>        1  2  3  4  5
# =>  6  7  8  9 10 11 12
# => 13 14 15 16 17 18 19
# => 20 21 22 23 24 25 26
# => 27 28 29 30 31
# 获取日历
print('2020-1 :')
print(calendar.month(2020, 1))

# 包含睡眠时间
start = time.perf_counter()
time.sleep(1.5)
end = time.perf_counter()
# => 3.568110 - 2.067574 = 1.500536
print('{:f} - {:f} = {:f}'.format(end, start, end - start))

# 不包含睡眠时间
start = time.process_time()
time.sleep(1.5)
end = time.process_time()
# => 0.093750 - 0.093750 = 0.000000
print('{:f} - {:f} = {:f}'.format(end, start, end - start))
