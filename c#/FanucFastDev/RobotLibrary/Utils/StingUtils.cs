﻿using System;
using System.Linq;
using RobotLibrary.Global;

namespace RobotLibrary.Utils
{
    public class StringUtils
    {
        public static void TextVerify(ref string s, int maxLength)
        {

            if (s.Length > maxLength)
            {
                Console.Write($"La phrase : \"{s}\" ne peux contenir que {maxLength} caractères.\n" +
                                         $"Veuillez introduire une phrase plus courte : ");

                s = Console.ReadLine();
                TextVerify(ref s, maxLength);
                return;
            }
                

            for (int i = 0; i < s.Length; i++)
            {
                if (Const.ACCENT.Contains(s[i]))
                {
                    Console.Write(  $"La phrase : \"{s}\" ne peux pas contenir des accents.\n" +
                                         $"Veuillez introduire une nouvelle phrase : ");

                    s = Console.ReadLine();

                    // Vérification de la nouvelle phrase
                    TextVerify(ref s, maxLength);
                    return;

                }
            }
        }
    }
}
