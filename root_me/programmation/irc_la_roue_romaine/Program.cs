using System;
using System.Net.Sockets;
using System.Threading;
using System.Net;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Globalization;

// /msg nickserv register mdp1233# test@gmail.com
// mdp1234#
/*              writer.WriteLine("NICK " + NICK);
                writer.Flush();
                writer.WriteLine("msg NickServ IDENTIFY mdp1234#");
                writer.Flush();
                writer.WriteLine("JOIN " + CHANNEL);
                writer.Flush();
 */
namespace IRC_Retour_au_collège
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
                    else if (msgRecNumber == 68)
                    {
                        // writer.WriteLine("helpop cuser");
                        writer.WriteLine("privmsg Candy !ep3");
                        writer.Flush();
                        respond = true;
                    }
                    else if (respond)
                    {
                        string crypted = splitInput[3].Substring(1);
                        string res = string.Empty;
                        int temp;
                        for (int i = 0, len = crypted.Length; i < len; i++)
                        {
                            temp = crypted[i];
                            if (Char.IsLower(crypted[i]))
                            {
                                temp -= 'a';
                                temp += 13;
                                temp %= 26;
                                temp += 'a';
                                res += (char)temp;

                            }
                            else if (Char.IsUpper(crypted[i]))
                            {
                                temp -= 'A';
                                temp += 13;
                                temp %= 26;
                                temp += 'A';
                                res += (char)temp;
                            }
                            else
                                res += crypted[i];
                        }

                        writer.WriteLine("privmsg Candy !ep3 -rep " + res);
                        writer.Flush();
                        
                        respond = false;
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
    }
}
