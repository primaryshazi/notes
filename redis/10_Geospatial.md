# Geospatial

## 添加多个地点经纬度至Citys

    GEOADD Citys Longitude_1 Latitude_1 Member_1 ...

## 获取多个地点的经纬度

    GEOPOS Citys Member_1 ...

## 获取两个地点之间的距离

    GEODIST Citys Member_1 Member_2
    GEODIST Citys Member_1 Member_2 m
    GEODIST Citys Member_1 Member_2 km
    GEODIST Citys Member_1 Member_2 ft
    GEODIST Citys Member_1 Member_2 mi

## 依据经纬度获取范围内的地点

    GEORADIUS Citys Longitude Latitude Radius km
    显示坐标
    GEORADIUS Citys Longitude Latitude Radius km WITHCOORD
    显示距离
    GEORADIUS Citys Longitude Latitude Radius km WITHDIST
    显示hash值
    GEORADIUS Citys Longitude Latitude Radius km WITHHASH
    只显示前N个
    GEORADIUS Citys Longitude Latitude Radius km COUNT N
    按距离升序排序
    GEORADIUS Citys Longitude Latitude Radius km ASC

## 依据地点获取范围内的地点

    GEORADIUSBYMEMBER Citys Member Radius km
    显示坐标
    GEORADIUSBYMEMBER Citys Member Radius km WITHCOORD
    显示距离
    GEORADIUSBYMEMBER Citys Member Radius km WITHDIST
    显示hash值
    GEORADIUSBYMEMBER Citys Member Radius km WITHHASH
    只显示前N个
    GEORADIUSBYMEMBER Citys Member Radius km COUNT N
    按距离升序排序
    GEORADIUSBYMEMBER Citys Member Radius km ASC

## 获取地点的hash值

    GEOHASH Citys Member_1 ...
