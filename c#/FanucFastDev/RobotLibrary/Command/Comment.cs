using System;
using RobotLibrary.Global;

namespace RobotLibrary.Command
{

    public static class Comment
    {
        public static void comment(string comment)
        {

            Utils.StringUtils.TextVerify(ref comment, Const.COMMENT_MAX_CHAR);
            //Comment.checkLenght(comment);

            #if debug
            Console.WriteLine($"!{comment}");
            #endif

            Generation.appendLine(String.Format("  !{0} ;", comment));

        }

        public static string ToString(string comment) {
            return "Comment.comment(\"" + 
            comment.Substring(comment.IndexOf('!') + 1).TrimStart(' ').TrimEnd() + 
            "\");";
        }   

    }
}
