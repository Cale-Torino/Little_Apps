using MusicIntense.Classes;
using System.Diagnostics;
using System.Runtime.InteropServices;

namespace MusicIntense
{
    public partial class MainForm : Form
    {
        private int _handel;
        public MainForm()
        {
            InitializeComponent();
        }
        private void StopSound()
        {
            try
            {
                //BASSMODClass.BASSMOD_Free();
                // free the stream 
                BassClass.BASS_StreamFree(_handel);
                // free BASS 
                BassClass.BASS_Free();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
                return;
            }
        }
            private void PlaySound()
            {
                try
                {
                    BassClass.BASS_Init(-1, 44100, DeviceInitFlagsClass.DeviceInitFlags.Default, IntPtr.Zero);
                    _handel = BassClass.BASS_StreamCreateFile(false, @"Music\legion.mp3", 0L, 0L, BassFlagsClass.BassFlags.Default);
                    BassClass.BASS_ChannelPlay(_handel, false);
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message);
                    return;
                }
            }

        private void groupBox5_Enter(object sender, EventArgs e)
        {

        }

        private void groupBox6_Enter(object sender, EventArgs e)
        {

        }

        private void groupBox7_Enter(object sender, EventArgs e)
        {

        }

        private void groupBox8_Enter(object sender, EventArgs e)
        {

        }

        private void MainForm_Load_1(object sender, EventArgs e)
        {
            //https://stackoverflow.com/questions/529677/how-to-have-comments-in-intellisense-for-function-in-visual-studio
            PlaySound();
            //ManagedBass.Bass.ChannelSetPosition
            //ManagedBass.Bass.ChannelGetLength
            //https://docs.microsoft.com/en-us/dotnet/api/system.diagnostics.process.getcurrentprocess?view=net-6.0
        }

       


        private void MainForm_FormClosing_1(object sender, FormClosingEventArgs e)
        {
            TimeSpan a = DateTime.UtcNow - Process.GetCurrentProcess().StartTime.ToUniversalTime();
            MessageBox.Show($"{a}");
            StopSound();
        }

        private void groupBox5_MouseHover(object sender, EventArgs e)
        {
            long pos = BassClass.BASS_ChannelSeconds2Bytes(_handel, 0001);//176400
            BassClass.BASS_ChannelSetPosition(_handel, pos);
            //getPos();
        }

        private void groupBox6_MouseHover(object sender, EventArgs e)
        {
            long pos = BassClass.BASS_ChannelSeconds2Bytes(_handel, 0057);//10054800
            BassClass.BASS_ChannelSetPosition(_handel, pos);
            //getPos();
        }

        private void groupBox7_MouseHover(object sender, EventArgs e)
        {
            long pos = BassClass.BASS_ChannelSeconds2Bytes(_handel, 0154);//27165600
            BassClass.BASS_ChannelSetPosition(_handel, pos);
            //getPos();
        }

        private void groupBox8_MouseHover(object sender, EventArgs e)
        {
            long pos = BassClass.BASS_ChannelSeconds2Bytes(_handel, 0252);//44452800
            BassClass.BASS_ChannelSetPosition(_handel, pos);
            //getPos();
        }

        private void funnySongArpToolStripMenuItem_Click(object sender, EventArgs e)
        {
            long pos = BassClass.BASS_StreamGetFilePosition(_handel);
            MessageBox.Show($"{pos}");
        }

        private void getPos()
        {
            long FilePosition = BassClass.BASS_StreamGetFilePosition(_handel);
            long ChannelPosition = BassClass.BASS_ChannelGetPosition(_handel);
            MessageBox.Show($"FilePosition: {FilePosition} \n ChannelPosition: {ChannelPosition}");
        }

        private void funnySongArpbackToolStripMenuItem_Click(object sender, EventArgs e)
        {
            long FilePosition = BassClass.BASS_StreamGetFilePosition(_handel);
            //BassClass.BASS_ChannelPlay(_handel, false);
            

            long ChannelPosition = BassClass.BASS_ChannelGetPosition(_handel);
            //BassClass.BASS_ChannelSetPosition(_handel, BassClass.BASS_ChannelSeconds2Bytes(_handel, ChannelPosition));
            MessageBox.Show($"FilePosition: {FilePosition} \n ChannelPosition: {ChannelPosition}");
            //BASS_ChannelGetPosition
            //c
        }

        private void volumeToolStripMenuItem_Click(object sender, EventArgs e)
        {
            //long ChannelPosition = BassClass.BASS_ChannelGetPosition(_handel);
            //BassClass.BASS_SetVolume(30);
            //bool SetAttribute = BassClass.BASS_ChannelSetAttribute(_handel, ChannelAttributeClass.ChannelAttribute.Volume, 0.1f);
            double TotalTimeString = BassClass.BASS_ChannelBytes2Seconds(_handel, BassClass.BASS_ChannelGetLength(_handel));
            double CurrentTimeString = BassClass.BASS_ChannelBytes2Seconds(_handel, BassClass.BASS_ChannelGetPosition(_handel));
            MessageBox.Show($"TotalTimeString: {TotalTimeString} \n CurrentTimeString: {CurrentTimeString}");
        }
    }
}