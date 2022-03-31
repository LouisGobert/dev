﻿//#define debug
using System;
using System.IO;
using System.Text;
using RobotLibrary.Local;
using RobotLibrary.Command;

namespace RobotLibrary.Global
{
    public static class Generation
    {
        //public static string generatePath; // Le chemin du fichier .LS en cours de modification

        private static int _indexLsLine;
        private static string _BUILD_PATH;
        private static string progInstru;

        public static string setupInfo()
        {

            string progInfo =    $"/PROG  {ProgramInfo.Name}\n" 
                                + "/ATTR\n"
                                + "OWNER       = MNEDITOR;\n"
                                + $"COMMENT     = \"{ProgramInfo.Desc}\";\n"
                                + "PROG_SIZE   = 1382;\n"
                                + "CREATE      = DATE 20-10-15  TIME 15:42:30;\n"
                                + "MODIFIED    = DATE 20-10-15  TIME 16:10:46;\n"
                                + "FILE_NAME   = ;\n"
                                + "VERSION     = 0;\n"
                                + $"LINE_COUNT  = {_indexLsLine-1};\n"
                                + "MEMORY_SIZE = 1662;\n"
                                + "PROTECT     = READ_WRITE;\n"
                                + "TCD:  STACK_SIZE        = 0,\n"
                                + "      TASK_PRIORITY     = 50,\n"
                                + "      TIME_SLICE        = 0,\n"
                                + "      BUSY_LAMP_OFF     = 0,\n"
                                + "      ABORT_REQUEST     = 0,\n"
                                + "      PAUSE_REQUEST     = 0;\n"
                                + $"DEFAULT_GROUP   = {ProgramInfo.GroupMask};\n"
                                + "CONTROL_CODE    = 00000000 00000000;\n"
                                + "/APPL\n"
                                + "/MN\n";


            return progInfo;
        }


        public static void setup(string programName, string BUILD_PATH)
        {

            // Supression des point déjà existant
            Pos.DeleteAllPos();
            _BUILD_PATH = Path.Combine(BUILD_PATH, programName.ToUpper() + ".LS");
            _indexLsLine = 1;
            progInstru = string.Empty;
            ProgramInfo.Reset();

            ProgramInfo.Name = programName;
        }


        public static void appendLine(string line)
        {
            progInstru += string.Format("{0, 4}:{1}\n", _indexLsLine++, line);
        }


        public static void appendXBlankLine(int x)
        {
            if (ProgramInfo.KeepBlankLine)
                for (int i = 0; i < x; i++)
                    appendLine("   ;");
                    
        }


        /// <summary>
        ///     Fonction qui pest appelée lorsque qu'un programme .ls est fini.
        ///     C'est ici que l'on va assemblé le string final qui contiendra tout
        ///     le programme .ls. 
        ///     
        ///     On enregistrera le tout dans le fichier pointé par BUILD_PATH
        /// </summary>
        public static void Save()
        {

            string progFinal = setupInfo() + progInstru + "/POS\n" + Pos.generateAllPoint() + "/END\n";

            #if debug
            Console.WriteLine("\n\n########################################\nProgramme généré :\n");
            Console.WriteLine(progFinal);
            #endif           

            // Création du fichier final
            try
            {
                if (File.Exists(_BUILD_PATH))
                    File.Delete(_BUILD_PATH);
                FileStream fs = File.Create(_BUILD_PATH);

                using (StreamWriter sw = new StreamWriter(fs, Encoding.ASCII))
                {
                    sw.Write(progFinal);
                }
            } catch (Exception ex)
            {
                Console.WriteLine($"Erreur = {ex}");
            }

            Console.WriteLine("Fichier créer dans : " + Path.GetRelativePath(Directory.GetCurrentDirectory(), _BUILD_PATH));
        }
    }
}
