using System;
using System.Collections.Generic;
using System.Text;

namespace LeetCode
{
    class integer_to_roman
    {
        public string IntToRoman(int num)
        {

            string[][] value = new string[4][];
            string[] i_1 = { "","I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };
            string[] i_2 = { "","X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
            string[] i_3 = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
            string[] i_4 = { "", "M", "MM", "MMM" };

            value[0] = i_1;
            value[1] = i_2;
            value[2] = i_3;
            value[3] = i_4;

            string res = string.Empty;

            for (int i = 0; num > 0; i++)
            {
                res = value[i][(num % 10)] + res;
                num /= 10;
            }

            return res;


        }
    }
}
