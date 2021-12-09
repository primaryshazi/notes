# 抛出异常
# => <class 'Exception'>
# => ('exception',)
# => exception
try:
    raise Exception('exception')
except Exception as e:
    print(type(e))
    print(e.args)
    print(e)

# 发生异常则进入except，无异常则进入else
# => begin
# => right
try:
    print('begin')
except Exception:
    print('wrong')
else:
    print('right')

# 无论是否有异常都会执行finally
# => begin
# => wrong
# => end
try:
    print('begin')
    raise Exception('exception')
except Exception:
    print('wrong')
else:
    print('right')
finally:
    print('end')
