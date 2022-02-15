using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Http;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Maths_Testing_Application
{
    /// <summary>
    /// sends data such as time and completed test, module etc.
    /// sends this remotely so that everyting can be checked
    ///
    /// checks that no cheating, checks time start and time complete
    /// checks questions answered, checks correct/incorrect answers
    /// </summary>
    internal class SendDataClass
    {
        public class HTTPRequest
        {

            public async void send(string httpurl) 
            {
                //Memo_richTextBox.Clear();
                using (HttpClient client = new HttpClient())
                {
                    //Add Default Request Headers
                    //client.DefaultRequestHeaders.Add("Authorization", "Bearer token");
                    try
                    {
                        using (HttpResponseMessage response = await client.GetAsync(new Uri(httpurl)))
                        {
                            using (HttpContent content = response.Content)
                            {
                                //Read the result and display in Textbox
                                string result = await content.ReadAsStringAsync();//Result string JSON
                                string reasonPhrase = response.ReasonPhrase;//Reason OK, FAIL etc.
                                //Memo_richTextBox.AppendText(result + Environment.NewLine);
                                //Memo_richTextBox.AppendText(reasonPhrase + Environment.NewLine);
                            }
                        }
                    }
                    catch (Exception ex)
                    {
                        MessageBox.Show(ex.Message, "Could not test Telegram API", MessageBoxButtons.OK, MessageBoxIcon.Error);
                        Logger.LoggerClass.Logger.WriteLine(" *** Error:" + ex.Message + " [TelegramAPIForm] ***");
                        return;
                    }
                }
            }




        }
    }
}
