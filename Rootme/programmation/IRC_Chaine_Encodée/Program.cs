using System;
using System.Net.Sockets;
using System.Threading;
using System.Net;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Globalization;

namespace IRC_Chaine_Encodee
{
    class Program
    {
        public static string SERVER = "irc.root-me.org";
        public static int PORT = 6667;
        public static string USER = "/USER LouisGobert|79443 0 * :LouisGobert|79443";
        public static string NICK = "Louis";
        public static string CHANNEL = "#root-me_challenge";
        public static string JOIN = "JOIN ";

        static void Main(string[] args)
        {

            string res = decode64("Um9vdE1l");

            NetworkStream stream;
            TcpClient irc;
            string inputLine;
            StreamReader reader;
            StreamWriter writer;
            string[] splitInput;
            int msgRecNumber = 1;
            bool respond = false;

            try
            {
                irc = new TcpClient(SERVER, PORT);
                stream = irc.GetStream();
                reader = new StreamReader(stream);
                writer = new StreamWriter(stream);
                writer.WriteLine("NICK Louis");
                writer.Flush();
                writer.WriteLine("USER Louis 0 * :test");
                writer.Flush();
                writer.WriteLine("msg NickServ IDENTIFY mdp1234#");
                writer.Flush();
                writer.WriteLine("JOIN " + CHANNEL);
                writer.Flush();

                while ((inputLine = reader.ReadLine()) != null)
                {
                    splitInput = inputLine.Split(new char[] { ' ' });

                    Console.Write($"Message N{msgRecNumber++}:");
                    foreach (string s in splitInput)
                        Console.Write($"{s} ");
                    Console.WriteLine();

                    if (msgRecNumber == 1)
                    {
                        // writer.WriteLine("/MSG !ep1 coucou");
                        // writer.Flush();
                    }
                    else if (msgRecNumber == 63)
                    {
                        writer.WriteLine("JOIN " + CHANNEL);
                        writer.Flush();

                    }
                    else if (msgRecNumber == 67)
                    {
                        // writer.WriteLine("helpop cuser");
                        writer.WriteLine("privmsg Candy !ep2");
                        writer.Flush();
                        respond = true;
                    }
                    else if (inputLine.Contains("PRIVMSG Louis") && respond)
                    {
                        respond = false;
                        string encrypted = splitInput[3].Substring(1);
                        

                        

                        writer.WriteLine("privmsg Candy !ep2 -rep " + decode64(encrypted));
                        writer.Flush();

                    }
                }

                writer.Close();
                reader.Close();
                irc.Close();

            }
            catch (Exception e)
            {
                Console.WriteLine($"Erreur : {e}");
            }
        }

        public static string decode64(string encrypted)
        {
            return System.Text.Encoding.UTF8.GetString(Convert.FromBase64String(encrypted));
        }
    }
}
