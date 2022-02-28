using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace AmmunitionCounter
{
    public partial class MainForm : Form
    {
        // Create the DB with https://sqlitebrowser.org/dl
        public MainForm()
        {
            InitializeComponent();
        }
        private void InitalizeLog()
        {
            Debug.Listeners.Add(TraceClass.GetTraceListenerh(TraceClass.GetLogPath()));
        }

        List<BulletClass> bullet = new List<BulletClass>();

        private void LoadPeopleList()
        {
            bullet = SqliteDataAccessClass.LoadBullets();

            WireUpPeopleList();
        }
        private void WireUpPeopleList()
        {
            listBox1.DataSource = null;
            listBox1.DataSource = bullet;
            listBox1.DisplayMember = "all_data";
        }
        private void MainForm_Load(object sender, EventArgs e)
        {
            InitalizeLog();
            toolStripLabel1.Text = "Ready";
        }

        private void aboutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            using (var frm = new AboutForm("testing"))
            {
                frm.ShowDialog();
            }
        }

        private void Addbutton_Click(object sender, EventArgs e)
        {
            BulletClass b = new BulletClass();

            b.caliber = textBoxCAL.Text;
            b.brand = textBoxBRAND.Text;
            b.grain = textBoxGRAIN.Text;
            b.shot = textBoxSHOT.Text;

            SqliteDataAccessClass.SaveBullet(b);

            textBoxCAL.Text = "";
            textBoxBRAND.Text = "";
            textBoxGRAIN.Text = "";
            textBoxSHOT.Text = "";
            LoadPeopleList();
        }
    }
}
