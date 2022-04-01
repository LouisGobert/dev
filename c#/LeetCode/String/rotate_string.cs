using System;
using System.Collections.Generic;
using System.Text;

namespace LeetCode
{
    public class rotate_string
    {
        public static bool RotateString(string A, string B)
        {

            //int lenA = A.Length;
            //int lenB = B.Length;
            //if (lenA == 0 && lenB == 0) return true;
           // else if (lenB != lenA) return false;
            int lenA, iATemp;
            if ((lenA = A.Length) != B.Length) return false;
            if (lenA == 0) return true;

            for (int iA = 0, iB; iA < lenA; iA++)
            {
                if (A[iA] == B[0])
                {
                    for (iB = 0, iATemp = iA; iB < lenA; iB++)
                    {
                        if (A[iA++] != B[iB]) iB = lenA;
                        else if (iA == lenA) iA = 0;

                        if (iA == iATemp) return true;
                    }

                    iA = iATemp;
                    
                }
            }
            return false;

        }
    }
}

