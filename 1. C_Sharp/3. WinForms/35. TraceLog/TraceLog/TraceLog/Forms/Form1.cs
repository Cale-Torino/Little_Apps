﻿using System;
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

namespace TraceLog
{
    /// <summary>
    /// Example using the tracelogger
    /// </summary>
    /// <param name="s">data</param>
    /// <param name="c">data</param>
    /// <param name="connected">data</param>
    public partial class MainForm : Form
    {      
        public MainForm()
        {
            InitializeComponent();
        }

        private void InitalizeLog()
        {
            Debug.Listeners.Add(TraceClass.GetTraceListenerh(TraceClass.GetLogPath()));
        }

        private void MainForm_Load(object sender, EventArgs e)
        {
            InitalizeLog();

            TraceClass.LogWrite("This is a log trace :) ", (int)TraceClass.State.Info));//info
            TraceClass.LogWrite("This is a log trace :) ", (int)TraceClass.State.Warning));//warning
            TraceClass.LogWrite("This is a log trace :) ", (int)TraceClass.State.Error));//error
            TraceClass.LogWrite("This is a log trace :) ", (int)TraceClass.State.Debug));//debug
        }

        int i = 0;
        private void Logbutton_Click(object sender, EventArgs e)
        {
            i++;
            TraceClass.LogWrite($"{i} log trace :) ", (int)TraceClass.State.Info));
        }

        private void newFormToolStripMenuItem_Click(object sender, EventArgs e)
        {
            using (var frm = new Form2("testing"))
            {
                frm.ShowDialog();
            }
        }
    }
}
