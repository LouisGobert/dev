using System;

public class concatenation_of_consecuting_binary_number
{
    public int ConcatenatedBinary(int n)
    {
        ulong res;
        int decalage = 0;
        int temp;

        for (res = 0; n > 0; n--)
        {        
            decalage += countDigit(n);
            Console.WriteLine($"dec tot = {decalage}");
        }

        return (int)res % ((int)Math.Pow(10, 9) + 7);
    }


    private int countDigit(int n)
    {
        int digit = 0;
        while (n != 0)
        {
            n = n >> 1;
            digit++;
        }
        return digit;
    }
}
