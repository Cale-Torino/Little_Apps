using System;
using System.Windows.Forms;

namespace Logs4NetExample
{
    public partial class MainForm : Form
    {
        private static readonly log4net.ILog log = log4net.LogManager.GetLogger(System.Reflection.MethodBase.GetCurrentMethod().DeclaringType);
        public MainForm()
        {
            InitializeComponent();
        }

        private void MainForm_Load(object sender, EventArgs e)
        {
            log.Info("**APPLICATION START**");
            //log.Debug("Hello Debug world!");
            //log.Error("Hello Error world!");
            //log.Fatal("Hello Fatal world!");
            //log.Warn("Hello Warn world!");
            StatusLabel.Text = "Ready";

        }

        private void button1_Click(object sender, EventArgs e)
        {
            log.Info("** Button1 Clicked **");
            StatusLabel.Text = $"[{DateTime.Now}] Button1 Clicked";
        }

        private void button1_MouseEnter(object sender, EventArgs e)
        {
            log.Info("** Button1 MouseEnter **");
            StatusLabel.Text = $"[{DateTime.Now}] Button1 MouseEnter";
        }

        private void button1_MouseLeave(object sender, EventArgs e)
        {
            log.Info("** Button1 MouseLeave **");
            StatusLabel.Text = $"[{DateTime.Now}] Button1 MouseLeave";
        }

        private void button2_Click(object sender, EventArgs e)
        {
            log.Info("** Button2 Clicked **");
            StatusLabel.Text = $"[{DateTime.Now}] Button2 Clicked";
        }

        private void button2_MouseEnter(object sender, EventArgs e)
        {
            log.Info("** Button2 MouseEnter **");
            StatusLabel.Text = $"[{DateTime.Now}] Button2 MouseEnter";
        }

        private void button2_MouseLeave(object sender, EventArgs e)
        {
            log.Info("** Button2 MouseLeave **");
            StatusLabel.Text = $"[{DateTime.Now}] Button2 MouseLeave";
        }
    }
}
