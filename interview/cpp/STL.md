# STL

---

## STL容器

容器|说明|类别|标准
-|-|-|-
array|静态连续数组|顺序容器|C++11
vector|动态连续数组|顺序容器|
deque|双端队列|顺序容器|
forward_list|单链表|顺序容器|C++11
list|双链表|顺序容器|
set|唯一键集合|关联容器|
map|唯一键值对应集合|关联容器|
multiset|可重复键集合|关联容器|
multimap|可重复键值对集合|关联容器|
unorderd_set|散列储存唯一键集合|无序关联容器|C++11
unorderd_map|散列储存唯一键值集合|无序关联容器|C++11
unorderd_multiset|散列储存可重复键集合|无序关联容器|C++11
unorderd_multimap|散列储存可重复键值集合|无序关联容器|C++11
stack|栈|容器适配器|
queue|队列|容器适配器|
priority_queue|优先队列|容器适配器|

---

## 迭代器失效

### vector

1. 当执行erase()方法时，指向删除节点的迭代器全部失效，指向删除节点之后的全部迭代器也失效
2. 当进行push_back()方法时，end()操作返回的迭代器失效
3. 当插入一个元素后，capacity()返回值与没有插入元素之前相比有改变，则需要重新加载整个容器，此时first()和end()操作返回的迭代器都会失效
4. 当插入一个元素后，如果空间未重新分配，指向插入位置之前的元素的迭代器仍然有效，但指向插入位置之后元素的迭代器全部失效

### deque

1. 插入到除首尾位置之外的任何位置都会导致迭代器、指针和引用都会失效
2. 在首尾位置添加元素，迭代器会失效，但是指针和引用不会失效
3. 在首尾之外的任何位置删除元素，那么指向被删除元素外其他元素的迭代器全部失效
4. 在其首部或尾部删除元素则只会使指向被删除元素的迭代器失效

### set map multimap multiset

1. 删除当前的iterator，仅仅会使当前的iterator失效，只要在erase时，递增当前iterator即可

---