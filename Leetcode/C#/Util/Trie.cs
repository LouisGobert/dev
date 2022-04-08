using System;
using System.Collections.Generic;
using System.Text;

namespace LeetCode.Trie
{
    public class Trie
    {
        private TrieNode _root;

        /** Initialize your data structure here. */
        public Trie()
        {
            _root = new TrieNode();
        }

        /** Inserts a word into the trie. */
        public void Insert(string word)
        {

            TrieNode temp = _root;
            for (int i = 0; i < word.Length; i++)
            {

                if (!temp.Contains(word[i]))
                {
                    temp.Add(word[i]);
                } 

                temp = temp.get(word[i]);
            }

            temp.isEnd = true;
        }

        /** Returns if the word is in the trie. */
        //public bool Search(string word)
        //{

        //}

        /** Returns if there is any word in the trie that starts with the given prefix. */
        //public bool StartsWith(string prefix)
        //{

        //}
    }

    public class TrieNode
    {
        private TrieNode[] childs;
        private const int MAX_CHILD = 26;

        public bool isEnd { get; set; }
        public int nbChild { get; set; }


        public TrieNode()
        {
            childs = new TrieNode[MAX_CHILD];
       
        }

        public TrieNode get(char child)
        {
            return childs[child - 'a'];
        }

        public bool Contains(char child)
        {
            return childs[child - 'a'] != null;
        }

        public void Add(char child)
        {
            if (childs[child - 'a'] == null)
                nbChild++;
            childs[child - 'a'] = new TrieNode();
        }
    }

    /**
     * Your Trie object will be instantiated and called as such:
     * Trie obj = new Trie();
     * obj.Insert(word);
     * bool param_2 = obj.Search(word);
     * bool param_3 = obj.StartsWith(prefix);
     */
}
