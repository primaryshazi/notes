import configparser
import os
import sys
import time

with open('config.ini', 'w') as file:
    file.write('''
[anime]
yuri = best
funny = better
truelove = good
harem = kill
ntr = destroy

[infomation]
name = ShaZi
age = 1
weight = 55.5
''')

config = configparser.ConfigParser()

config.read('config.ini')

# => s -> i : anime -> ('yuri', 'best')
# => s -> i : anime -> ('funny', 'better')
# => s -> i : anime -> ('truelove', 'good')
# => s -> i : anime -> ('harem', 'kill')
# => s -> i : anime -> ('ntr', 'destroy')
# => s -> o : anime -> yuri
# => s -> o -> v : anime -> yuri -> best
# => s -> o : anime -> funny
# => s -> o -> v : anime -> funny -> better
# => s -> o : anime -> truelove
# => s -> o -> v : anime -> truelove -> good
# => s -> o : anime -> harem
# => s -> o -> v : anime -> harem -> kill
# => s -> o : anime -> ntr
# => s -> o -> v : anime -> ntr -> destroy
# => s -> i : infomation -> ('name', 'ShaZi')
# => s -> i : infomation -> ('age', '1')
# => s -> i : infomation -> ('weight', '55.5')
# => s -> o : infomation -> name
# => s -> o -> v : infomation -> name -> ShaZi
# => s -> o : infomation -> age
# => s -> o -> v : infomation -> age -> 1
# => s -> o : infomation -> weight
# => s -> o -> v : infomation -> weight -> 55.5
for section in config.sections():
    for item in config.items(section):
        print('s -> i : {:s} -> {:s}'.format(str(section), str(item)))
    for option in config.options(section):
        print('s -> o : {:s} -> {:s}'.format(str(section), str(option)))
        print('s -> o -> v : {:s} -> {:s} -> {:s}'.format(str(section), str(option), str(config.get(section, option))))

# 获取整形，浮点，布尔值
# config.getint(section, option)
# config.getfloat(section, option)
# config.getboolean(section, option)

config.remove_option('infomation', 'name')
config.remove_section('infomation')

config.add_section('temp')
config.set('temp', 'filename', os.path.basename(sys.argv[0]))
config.set('temp', 'time', str(time.time()))

with open('config.ini', 'w') as file:
    config.write(file)
