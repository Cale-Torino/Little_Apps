using SpaceStars;
using System;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Windows.Forms;

namespace SpaceExample
{
    public partial class MainForm : Form
    {
        //the graphics object
        Graphics _p = new PictureBox().CreateGraphics();
        //represents the starfield object
        StarField _s;
        public MainForm()
        {
            InitializeComponent();
        }

        private void MainForm_Load(object sender, EventArgs e)
        {
            //Console.Beep();
            Init();
            label.Parent = pictureBox1;
            label.BackColor = Color.Transparent;
            label.Text = $"Version: {_s.Elac_Version()}";
            timer1.Start();
        }
        public void EnableDoubleBuffering()
        {
            SetStyle(ControlStyles.OptimizedDoubleBuffer | ControlStyles.AllPaintingInWmPaint | ControlStyles.UserPaint, true);
            UpdateStyles();
        }
        private void Init()
        {
            //use double buffer for smooth animation
            EnableDoubleBuffering();
            BackColor = Color.Black;
            _s = new StarField(Width, Height, 300);
        }
        private void timer1_Tick(object sender, EventArgs e)
        {
            //move the stars 
            _s.MoveStars(2, 0, 0);
            //invalidate AFTER all the movement has been done.  
            pictureBox1.Invalidate();
        }

        private void pictureBox1_Paint(object sender, PaintEventArgs e)
        {
            _p = e.Graphics;
            _p.SmoothingMode = SmoothingMode.AntiAlias;
            _s.DrawStars(_p);
        }
    }
}
