using System;
using System.Collections.Generic;
using System.Text;


namespace LeetCode.Trie
{
    class short_encoding_of_word
    {
        public int MinimumLengthEncoding(string[] words)
        {
            TrieNode node = new TrieNode();

            int minLenght = 0;

            for (int i = 0; i < words.Length; i++)
            {
                addIntelligent(words[i], node, ref minLenght);

            }
            return minLenght;
        }

        public void addIntelligent(string word, TrieNode node, ref int minLenght)
        {
            for (int i = word.Length-1, wLen = 1; i >=0; i--, wLen++)
            {

                if (!node.Contains(word[i]))
                    node.Add(word[i]);

                node = node.get(word[i]);

                if (node.isEnd)
                {
                    minLenght -= (wLen + 1);
                    node.isEnd = false;
                }
            }


            if (node.nbChild == 0)
            {
                minLenght += word.Length + 1;
                node.isEnd = true;
            }
        }


        // TIME EXED
        //public int MinimumLengthEncoding(string[] words)
        //{
        //    int lenWord = words.Length;
        //    string winner = string.Empty;
        //    string res = string.Empty;

        //    for (int i = 0; i < lenWord; i++)
        //    {

        //        winner = words[i];
        //        words[i] = "0";
        //        if (winner != "0")
        //        {



        //            for (int y = i + 1; y < lenWord; y++)
        //            {

        //                if (winner.EndsWith(words[y]))
        //                {
        //                    words[y] = "0";
        //                }
        //                else if (words[y].EndsWith(winner))
        //                {
        //                    winner = words[y];
        //                    words[y] = "0";
        //                }

        //            }

        //            res += winner + "#";
        //        }


        //    }

        //    return res.Length;
        //}
    }
}
