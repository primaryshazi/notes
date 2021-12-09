# Stream

## 添加消息队列

    # Stream：消息队列名称；Id：消息ID，一般采用*表示自动生成；Field：消息字段；Message：消息内容
    XADD Stream Id Field_1 Message_1 Field_2 Message_2

## 裁剪消息队列长度

    # 最少不得小于Count
    XTRIM Stream MAXLEN ~ Count

    # 限制最大长度为Count
    XTRIM Stream MAXLEN Count

## 删除消息

    XDEL Id_1 Id_2

## 获取消息队列长度

    XLEN Stream

## 获取消息列表

    # 从Start_ID开始到End_ID读取Count条消息
    XRANGE Stream Start_ID End_ID COUNT Count

    # 从头开始读取Count条数据
    XRANGE Stream - + COUNT Count

    # 从End_ID开始到Start_ID读取Count条消息
    XREVRANGE Stream End_ID Start_ID COUNT Count

    # 从尾开始读取Count条数据
    XRANGE Stream + - COUNT Count

## 读取消息

    # 从消息队列读取指定ID起Count条消息；ID：0-0表示从第一条数据开始，$表示最新的数据
    XREAD COUNT Count STREAMS Stream ID Id

    # 阻塞Block毫秒从消息队列读取指定ID起Count条消息
    XREAD COUNT Count BLOCK Block STREAMS Stream ID Id

## 创建消费者组

    # 流不存在则创建流，从头开始消费
    XGROUP CREATE Stream Group 0-0

    # 流不存在则创建流，从尾开始消费
    XGROUP CREATE Stream Group $

## 创建消费者

    XGROUP CREATECONSUMER Stream Group Consumer

## 消费者读取

    # 读取还没有被读过的消息
    XREADGROUP GROUP Group Consumer STREAMS Stream >

    # 读取从来没有被确认的consumer的消息
    XREADGROUP GROUP Group Consumer STREAMS Stream 0

## 删除消费者

    XGROUP DELCONSUMER Stream Gourp Comsumer

## 删除消费者组

    XGROUP DESTROY Stream Group

## 确认消息

    XACK Stream Group Id_1 Id_2

## 查看待处理消息相关信息

    # 从头显示Count数据
    XPENDING Stream Group - + Count

    # 从Start_ID开始到End_ID读取Count条消息
    XPENDING Stream Group Start_ID End_ID Count

## 转移消息的归属权

    # 直到超过Min_Time毫秒该消息未被处理，则会将所有权赋予Consumer
    XCLAIM Stream Group Consumer Min_Time ID Id

## 查看消费者消息

    XINFO GOURPS Stream

## 查看流信息

    XINFO STREAM Stream

## 查看消费者信息

    XINFO CONSUMER Stream Group
