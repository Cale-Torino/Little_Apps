using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MusicIntense.Classes
{
    internal class PositionFlagsClass
    {
        //
        // Summary:
        //     Channel Position Mode flags to be used with e.g. ManagedBass.Bass.ChannelGetLength(System.Int32,ManagedBass.PositionFlags),
        //     ManagedBass.Bass.ChannelGetPosition(System.Int32,ManagedBass.PositionFlags),
        //     ManagedBass.Bass.ChannelSetPosition(System.Int32,System.Int64,ManagedBass.PositionFlags)
        //     or ManagedBass.Bass.StreamGetFilePosition(System.Int32,ManagedBass.FileStreamPosition).
        [Flags]
        public enum PositionFlags
        {
            //
            // Summary:
            //     Byte position.
            Bytes = 0x0,
            //
            // Summary:
            //     Order.Row position (HMUSIC only). LoWord = order, HiWord = row * scaler (ManagedBass.ChannelAttribute.MusicPositionScaler).
            MusicOrders = 0x1,
            //
            // Summary:
            //     Tick position (MIDI streams only).
            MIDITick = 0x2,
            //
            // Summary:
            //     OGG bitstream number.
            OGG = 0x3,
            //
            // Summary:
            //     CD Add-On: the track number.
            CDTrack = 0x4,
            //
            // Summary:
            //     ZXTune Sub Count.
            ZXTuneSubCount = 0xF10000,
            //
            // Summary:
            //     ZXTune Sub Length.
            ZXTuneSubLength = 0xF20000,
            //
            // Summary:
            //     Midi Add-On: Let the old sound decay naturally (including reverb) when changing
            //     the position, including looping and such can also be used in ManagedBass.Bass.ChannelSetPosition(System.Int32,System.Int64,ManagedBass.PositionFlags)
            //     calls to have it apply to particular position changes.
            MIDIDecaySeek = 0x4000,
            //
            // Summary:
            //     Mixer playback buffering when seeking.
            MixerReset = 0x10000,
            //
            // Summary:
            //     MOD Music Flag: Stop all notes when moving position.
            MusicPositionReset = 0x8000,
            //
            // Summary:
            //     MOD Music Flag: Stop all notes and reset bmp/etc when moving position.
            MusicPositionResetEx = 0x400000,
            //
            // Summary:
            //     Mixer Flag: Don't ramp-in the start after seeking.
            MixerNoRampIn = 0x800000,
            //
            // Summary:
            //     Flag: Allow inexact seeking. For speed, seeking may stop at the beginning of
            //     a block rather than partially processing the block to reach the requested position.
            Inexact = 0x8000000,
            //
            // Summary:
            //     Flag: The requested position is relative to the current position. pos is treated
            //     as signed in this case and can be negative. Unless the ManagedBass.PositionFlags.MixerReset
            //     flag is also used, this is relative to the current decoding/processing position,
            //     which will be ahead of the currently heard position if the mixer output is buffered.
            Relative = 0x4000000,
            //
            // Summary:
            //     Get the decoding (not playing) position.
            Decode = 0x10000000,
            //
            // Summary:
            //     Flag: decode to the position instead of seeking.
            DecodeTo = 0x20000000,
            //
            // Summary:
            //     Scan the file to build a seek table up to the position, if it has not already
            //     been scanned. Scanning will continue from where it left off previously rather
            //     than restarting from the beginning of the file each time. This flag only applies
            //     to MP3/MP2/MP1 files and will be ignored with other file formats.
            Scan = 0x40000000,
            //
            // Summary:
            //     HLS Segment sequence number.
            HlsSegment = 0x10000
        }
    }
}
