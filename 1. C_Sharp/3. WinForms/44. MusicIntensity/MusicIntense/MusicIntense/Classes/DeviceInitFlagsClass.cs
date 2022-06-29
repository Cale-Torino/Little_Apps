using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MusicIntense.Classes
{
    public class DeviceInitFlagsClass
    {
        //
        // Summary:
        //     Initialization flags to be used with ManagedBass.Bass.Init(System.Int32,System.Int32,ManagedBass.DeviceInitFlags,System.IntPtr,System.IntPtr)

        public enum DeviceInitFlags
        {
            //
            // Summary:
            //     0 = 16 bit, stereo, no 3D, no Latency calc, no Speaker Assignments
            Default = 0x0,
            //
            // Summary:
            //     Use 8 bit resolution, else 16 bit.
            Byte = 0x1,
            //
            // Summary:
            //     Use mono, else stereo.
            Mono = 0x2,
            //
            // Summary:
            //     Enable 3D functionality. Note: If this is not specified when initilizing BASS,
            //     then the ManagedBass.BassFlags.Bass3D is ignored when loading/creating a sample/stream/music.
            Device3D = 0x4,
            //
            // Summary:
            //     Limit output to 16 bit.
            Bits16 = 0x8,
            //
            // Summary:
            //     Calculate device latency (ManagedBass.BassInfo struct).
            Latency = 0x100,
            //
            // Summary:
            //     Use the Windows control panel setting to detect the number of speakers. Only
            //     use this option if BASS doesn't detect the correct number of supported speakers
            //     automatically and you want to force BASS to use the number of speakers as configured
            //     in the windows control panel.
            CPSpeakers = 0x400,
            //
            // Summary:
            //     Force enabling of speaker assignment (always 8 speakers will be used regardless
            //     if the soundcard supports them). Only use this option if BASS doesn't detect
            //     the correct number of supported speakers automatically and you want to force
            //     BASS to use 8 speakers.
            ForcedSpeakerAssignment = 0x800,
            //
            // Summary:
            //     Ignore speaker arrangement
            NoSpeakerAssignment = 0x1000,
            //
            // Summary:
            //     Linux-only: Initialize the device using the ALSA "dmix" plugin, else initialize
            //     the device for exclusive access.
            DMix = 0x2000,
            //
            // Summary:
            //     Set the device's output rate to freq, otherwise leave it as it is.
            Frequency = 0x4000,
            //
            // Summary:
            //     Limit output to stereo.
            Stereo = 0x8000,
            //
            // Summary:
            //     Hog/Exclusive mode.
            Hog = 0x10000,
            //
            // Summary:
            //     Use AudioTrack output.
            AudioTrack = 0x20000,
            //
            // Summary:
            //     Use DirectSound output.
            DirectSound = 0x40000
        }
    }
}
