//使用哈希表
//时间复杂度O(N) 空间复杂度O(N)
class Trie
{
private:
    unordered_set<string> hash;
public:
    Trie()
    {}

    void insert(string word)
    {
        hash.insert(word);
    }

    bool search(string word)
    {
        if (hash.count(word)) return true;
        return false;
    }

    bool startsWith(string prefix)
    {
        for (auto str : hash)
        {
            if (strstr(str.c_str(), prefix.c_str()) == str.c_str()) return true; 
        }
        return false;
    }
};


//使用字典树
//时间复杂度O(S)S为插入字符串的长度 空间复杂度O(26N)N为所有插入字符串的长度之和
class Trie 
{
private:
    vector<Trie*> child;
    bool is_end;
public:
    Trie():child(26), is_end(false) 
    {}
    
    void insert(string word) 
    {

        Trie* cur = this;
        //遍历该字符串
        for (char ch : word)
        {
            //该字符在字典树中不存在则创建
            if (cur->child[ch - 'a'] == nullptr) cur->child[ch - 'a'] = new Trie();
            //cur指向下个位置
            cur = cur->child[ch - 'a'];
        }   
        //在该字符串结尾设置为true
        cur->is_end = true;
    }
    
    bool search(string word) 
    {
        Trie* cur = this;
        for (char ch : word)
        {
            if (cur->child[ch - 'a'] == nullptr) return false;
            cur = cur->child[ch - 'a'];
        }
        return cur->is_end;
    }
    
    bool startsWith(string prefix)  
    {
        Trie* cur = this;
        for (char ch : prefix)
        {
            if (cur->child[ch - 'a'] == nullptr) return false;
            cur = cur->child[ch - 'a'];
        }
        return true;
    }
};