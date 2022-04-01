using System;
using System.Collections.Generic;
using System.Text;

namespace LeetCode.String
{
    class check_record
    {
        public bool CheckRecord(string s)
        {
            int L_count = 0;
            bool a = false;

            for (int i = 0; i < s.Length; i++)
            {
                if (s[i] == 'A')
                {
                    if (a)
                        return false;
                    a = true;
                }

                if (s[i] == 'L')
                {
                    L_count++;
                    if (L_count == 3)
                        return false;
                }
                else
                    L_count = 0;
            }

            return true;
        }
    }
}
