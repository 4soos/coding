/**
不使用任何内建的哈希表库设计一个哈希集合（HashSet）。

实现 MyHashSet 类：

void add(key) 向哈希集合中插入值 key 。
bool contains(key) 返回哈希集合中是否存在这个值 key 。
void remove(key) 将给定值 key 从哈希集合中删除。如果哈希集合中没有这个值，什么也不做。

*/
#include <vector>
#include <list>

using namespace std;

/**
 * @brief 为了实现哈希集合这一数据结构，有以下几个关键问题需要解决：
 *  哈希函数：能够将集合中任意可能的元素映射到一个固定范围的整数值，并将该元素存储到整数值对应的地址上。
 *
 *  冲突处理：由于不同元素可能映射到相同的整数值，因此需要在整数值出现「冲突」时，需要进行冲突处理。
 * 
 *  总的来说，有以下几种策略解决冲突：
 *      链地址法：为每个哈希值维护一个链表，并将具有相同哈希值的元素都放入这一链表当中。
 *      开放地址法：当发现哈希值 hh 处产生冲突时，根据某种策略，从 hh 出发找到下一个不冲突的位置。
 *          例如，一种最简单的策略是，不断地检查 h+1,h+2,h+3,\ldotsh+1,h+2,h+3,… 这些整数对应的位置。
 *      再哈希法：当发现哈希冲突后，使用另一个哈希函数产生一个新的地址。
 *
 *  扩容：当哈希表元素过多时，冲突的概率将越来越大，而在哈希表中查询一个元素的效率也会越来越低。
 *  因此，需要开辟一块更大的空间，来缓解哈希表中发生的冲突。
 * 
 */

class MyHashSet {
public:
    MyHashSet() : data(base) { }
    
    void add(int key) {
        int h = hash(key);
        for (auto it = data[h].begin(); it != data[h].end(); it++) {
            if ((*it) == key) return;
        }
    }
    
    void remove(int key) {
        int h = hash(key);
        for (auto it = data[h].begin(); it != data[h].end(); ) {
            if ((*it) == key) {
                data[h].erase(it);
                return;
            }
        }
    }
    
    bool contains(int key) {
        int h = hash(key);
        for (auto it = data[h].begin(); it != data[h].end(); it++) {
            if ((*it) == key)
                return true;
        }

    }

private:
    vector<list<int>> data;
    static const int base = 769;
    static int hash(int key) {
        return key;
    }

};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
