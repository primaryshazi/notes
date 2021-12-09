var = 5

# => 1
if var % 3 == 2:
    print('1')
elif var % 3 == 1:
    print('2')
else:
    print('3')

# => 5
# => 4
# => 3
# => 2
# => 1
# => 0
while var > 0:
    print(var)
    var -= 1
else:
    print(var)

# => 1
# => 2
# => 3
# => 4
# => 5
# => done
for item in [1, 2, 3, 4, 5]:
    print(item)
else:
    print('done')

# => 1
# => 2
# => 3
# => 4
# => 5
# => done
for item in (1, 2, 3, 4, 5):
    print(item)
else:
    print('done')

# => 0
# => 1
# => 2
# => 3
# => 4
# => done
for item in range(5):
    print(item)
else:
    print('done')

# => 0
# => 2
# => 4
# => 6
# => 8
# => done
for item in range(0, 10, 2):
    print(item)
else:
    print('done')
