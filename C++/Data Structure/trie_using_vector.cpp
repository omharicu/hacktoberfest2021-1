class Trie
{
private:
   struct Node
   {
       vector<int> children;
       int SIZE = 26;
       int isEnd;
 
       Node()
       {
           children.assign(SIZE, -1);
           isEnd = 0;
       }
   };
   vector<Node> trie;
 
public:
   Trie()
   {
       trie.emplace_back();
   }
   void trieAdd(string s)
   {
       int pos = 0;
 
       for (char &ch : s)
       {
           int idx = ch - 'a';
           if (trie[pos].children[idx] == -1)
           {
               trie[pos].children[idx] = trie.size();
               trie.emplace_back();
           }
           pos = trie[pos].children[idx];
       }
 
       trie[pos].isEnd++;
   }
 
   bool trieFind(string s)
   {
       int pos = 0;
 
       for (char &ch : s)
       {
           int idx = ch - 'a';
           if (trie[pos].children[idx] == -1)
           {
               return false;
           }
           pos = trie[pos].children[idx];
       }
       return trie[pos].isEnd > 0;
   }
};
