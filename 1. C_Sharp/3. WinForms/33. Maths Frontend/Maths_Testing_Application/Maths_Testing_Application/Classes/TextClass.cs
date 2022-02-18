using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Maths_Testing_Application
{
    internal class TextClass
    {
        public static class EngLan
        {
            public static void HomeText(Label L)
            {
                try
                {
                    L.Text = "Welcome To The Maths Testing Application";
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message, "Could Not add HomeText", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    return;
                }
            }

            public static void Paragraph1(Label L)
            {
                try
                {
                    L.Text = "Conceptual understanding: Key to place value is being able to work flexibly with composite units – treating 10 as either 'one unit of ten' or 'ten units of one'.";
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message, "Could Not add Paragraph1", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    return;
                }
            }

            public static void Paragraph2(Label L)
            {
                try
                {
                    L.Text = "Procedural fluency: Adding or subtracting 10 to any 2-digit number (without counting in ones), adding a single digit to any two digit number(extending the number bonds). ";
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message, "Could Not add Paragraph2", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    return;
                }
            }

            public static void Paragraph3(Label L)
            {
                try
                {
                    L.Text = "Strategic competence: \n" +
                        "• Using jumps of 10s and units: 63 – 49. 'Start at sixty-three, jump back forty, that gives twenty-three.To jump back nine, jump back three to get to the ten before, which is twenty and then jump back the remaining six to land at 14'.\n" +
                        "• Using compensation: 63 – 49. 'Sixty-three minus fifty is twenty-three.That's subtracting one more than I need to, so I have to add one back.The answer is 14'.\n" +
                        "• Using place value blocks: Make sixty three as '6 tens and 3 units'.We don't have enough units here to take away the nine units in 49, so exchange one of the ten strips for ten units, leaving us with 5 tens and 13 units. We can now subtract 4 tens and 9 units, leaving 1 ten and 4 units = 14'.\n";
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message, "Could Not add Paragraph3", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    return;
                }
            }

            public static void Paragraph4(Label L)
            {
                try
                {
                    L.Text = "Reasoning: Given that 63 – 50 = 13 learners can reason that 63 – 49 must be 14 and explain that 'if you subtract 49 from 63, that is taking away one less than 50 so the answer must be one more. There are various elements of reasoning across the strategies described above. ";
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message, "Could Not add Paragraph4", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    return;
                }
            }

        }

        public static class AfriLan
        {
            public static void HomeText(Label L)
            {
                try
                {
                    L.Text = "Wiskunde Toets Aansoek";
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message, "Could Not add HomeText", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    return;
                }
            }
        }

    }
}
