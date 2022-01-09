#include <iostream>
#include <unordered_map>

struct LinkNode
{
    int key, value;
    LinkNode *prev;
    LinkNode *next;
    LinkNode() : key(0), value(0), prev(nullptr), next(nullptr) {}
    LinkNode(int _key, int _value) : key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class LRUCache
{
public:
    LRUCache() : LRUCache(10) {}
    LRUCache(int capacity) : _capacity(capacity), _size(0)
    {
        _head = new LinkNode();
        _tail = new LinkNode();
        _head->next = _tail;
        _tail->prev = _head;
    }

    int get(int key)
    {
        if (_cache.count(key) == 0)
        {
            return -1;
        }
        LinkNode *node = _cache[key];
        moveToHead(node);

        return node->value;
    }

    void put(int key, int value)
    {
        /**
         * 无此key则新增节点至头部，超限则移除尾部节点
         * 有key则更新值并移动至头部
         */
        if (_cache.count(key) == 0)
        {
            LinkNode *node = new LinkNode(key, value);
            _cache[key] = node;
            addToHead(node);
            ++_size;

            if (_size > _capacity)
            {
                LinkNode *lastNode = removeTail();
                _cache.erase(lastNode->key);
                delete lastNode;
                --_size;
            }
        }
        else
        {
            LinkNode *node = _cache[key];
            node->value = value;
            moveToHead(node);
        }
    }

private:
    /**
     * @brief 将节点添加至头部
     *
     * @param node
     */
    void addToHead(LinkNode *node)
    {
        node->prev = _head;
        _head->next->prev = node;
        node->next = _head->next;
        _head->next = node;
    }

    /**
     * @brief 将节点移动至头部
     *
     * @param node
     */
    void moveToHead(LinkNode *node)
    {
        removeNode(node);
        addToHead(node);
    }

    /**
     * @brief 返回待删除的尾部节点
     *
     * @return LinkNode*
     */
    LinkNode *removeTail()
    {
        LinkNode *tmp = _tail->prev;
        removeNode(tmp);
        return tmp;
    }

    /**
     * @brief 移除节点
     *
     * @param node
     */
    void removeNode(LinkNode *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

private:
    std::unordered_map<int, LinkNode *> _cache;     // 缓存key -> node
    LinkNode *_head;        // 记录node访问时间顺序
    LinkNode *_tail;
    int _capacity;
    int _size;
};

int main()
{
    LRUCache cache;
    for (int i = 0; i < 10; i++)
    {
        cache.put(i, i * i);
    }

    /**
     * => 0
     * => 4
     * => 16
     * => 36
     * => 64
     */
    for (int i = 0; i < 10; i += 2)
    {
        std::cout << cache.get(i) << std::endl;
    }

    return 0;
}
