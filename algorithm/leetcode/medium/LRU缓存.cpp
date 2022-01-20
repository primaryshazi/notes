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
    LRUCache(int capacity) : capacity_(capacity), size_(0)
    {
        head_ = new LinkNode();
        tail_ = new LinkNode();
        head_->next = tail_;
        tail_->prev = head_;
    }

    int get(int key)
    {
        if (cache_.count(key) == 0)
        {
            return -1;
        }
        LinkNode *node = cache_[key];
        moveToHead(node);

        return node->value;
    }

    void put(int key, int value)
    {
        /**
         * 无此key则新增节点至头部，超限则移除尾部节点
         * 有key则更新值并移动至头部
         */
        if (cache_.count(key) == 0)
        {
            LinkNode *node = new LinkNode(key, value);
            cache_[key] = node;
            addToHead(node);
            ++size_;

            if (size_ > capacity_)
            {
                LinkNode *lastNode = removeTail();
                cache_.erase(lastNode->key);
                delete lastNode;
                --size_;
            }
        }
        else
        {
            LinkNode *node = cache_[key];
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
        node->prev = head_;
        head_->next->prev = node;
        node->next = head_->next;
        head_->next = node;
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
        LinkNode *tmp = tail_->prev;
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
    std::unordered_map<int, LinkNode *> cache_; // 缓存key -> node
    LinkNode *head_;                            // 记录node访问时间顺序
    LinkNode *tail_;
    int capacity_;
    int size_;
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
