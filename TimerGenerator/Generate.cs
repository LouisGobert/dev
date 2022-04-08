using System;
using System.Collections.Generic;
using System.Text;

namespace TimerGenerator
{
    public static class Generate
    {
        public static bool GenerateOneLoop(double duree, double freq, int max_nop, out string result, string loopName, string varName, string procedureName)
        {
             int GEN_TIME_LOST_ONE_LOOP = 6;
            result = string.Empty;
            double clock_speed_us = (1 /freq ) * 4;


            // On enlève les temps perdu en générale
            duree -= clock_speed_us * GEN_TIME_LOST_ONE_LOOP;

            int cpt, Y_nop = 0, X_nop = 0;
            
            for (Y_nop = 0; Y_nop <= max_nop; Y_nop++)
            {
                for (cpt = 255; cpt >= 0; cpt--)
                {
                    for (X_nop = 0; X_nop <= max_nop; X_nop++)
                    {
                        if (duree == (Y_nop + ((X_nop + 3) * cpt) -1) * clock_speed_us)
                        {
                            // Le résultat est trouvé
                            result = string.Format("{0}\n    MOVLW D'{1}'\n    MOVWF {2}\n{3}\n",
                                procedureName, cpt, varName, loopName);


                            for (; X_nop > 0; X_nop--)
                                result += "    NOP\n";

                            result += string.Format("    DECFSZ {0}, F\n    GOTO {1}\n", varName, loopName);

                            for (; Y_nop > 0; Y_nop--)
                                result += "    NOP\n";

                            result += "    RETURN";

                            return true;
                        }
                    }
                }
            }

            return false;
        }


        public static bool GenerateTwoLoop(double duree, double freq, int max_nop, out string result, string loopName1, string varName1, string procedureName, string loopName2, string varName2)
        {
            // Déclaration et définition des variables
            int TIME_CALL_RETURN_INIT = 7;
            int MAX_TIME_LP_1 = (max_nop + 3) * 255 - 1;
            int MAX_TIME_LP_2 = (MAX_TIME_LP_1 + max_nop + 4) * 255 - 1;
            int MAX_TIME      = MAX_TIME_LP_2 + TIME_CALL_RETURN_INIT;


            result = string.Empty;
            double clock_speed_us = (1 / freq) * 4;

            // On enlève les temps perdu en générale
            duree -= clock_speed_us * TIME_CALL_RETURN_INIT;
            double dureeTemp = duree;
            int cpt1, cpt2, Z_nop, Y_nop, X_nop;

            /*
                BOUCLE 1 = (X + 3) * cpt1 -1
                BOUCLE 2 = (boucle1 + Y + 4) * cpt2 -1
                TOTAL    = boucle2 + Z + 7

                RES      = Z + 7 - 1 + cpt2*((X+3)*cpt1 - 1 + Y + 4)
            */

            for (Z_nop = 0; Z_nop <= max_nop; Z_nop++)
            {
                for (cpt2 = 255; cpt2 > 0; cpt2--)
                {
                    dureeTemp = duree - Z_nop + 1;
                    ///
                    /// BOUCLE 2
                    /// 
                    if (dureeTemp % cpt2 == 0 && dureeTemp / cpt2 <= (max_nop+3)*255+max_nop+3)
                    {

                        for (Y_nop = 0; Y_nop <= max_nop; Y_nop++)
                        {
                            for (cpt1 = 255; cpt1 > 0; cpt1--)
                            {
                                ///
                                /// BOUCLE 1
                                /// 

                                if (((dureeTemp / cpt2) + 1 - Y_nop - 4) % cpt1 == 0)
                                {
                                    X_nop = (int)(dureeTemp / cpt2 + 1 - Y_nop - 4) / cpt1;

                                    if (X_nop <= max_nop && X_nop >= 3) {
                                        // Le résultat est trouvé
                                        result = string.Format("{0}\n    MOVLW D'{1}'\n    MOVWF {2}\n    MOVLW D'{3}'\n{4}\n    MOVWF {5}\n{6}\n",
                                            procedureName, cpt2, varName2, cpt1, loopName2, varName1, loopName1);


                                        for (X_nop -= 3; X_nop > 0; X_nop--)
                                            result += "    NOP\n";

                                        result += string.Format("    DECFSZ {0}, F\n    GOTO {1}\n", varName1, loopName1);

                                        for (; Y_nop > 0; Y_nop--)
                                            result += "    NOP\n";

                                        result += string.Format("    DECFSZ {0}, F\n    GOTO {1}\n", varName2, loopName2);

                                        for (; Z_nop > 0; Z_nop--)
                                            result += "    NOP\n";

                                        result += "    RETURN";

                                        return true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        
            return false;
        }
    }
}
