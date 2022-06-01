using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Playing_MP3
{
    public class BassFlagsClass
    {
        //
        // Summary:
        //     Stream/Sample/Music/Recording/AddOn create flags to be used with Stream Creation
        //     functions.
        [Flags]
        public enum BassFlags : uint
        {
            //
            // Summary:
            //     0 = default create stream: 16 Bit, stereo, no Float, hardware mixing, no Loop,
            //     no 3D, no speaker assignments...
            Default = 0x0u,
            //
            // Summary:
            //     Use 8-bit resolution. If neither this or the ManagedBass.BassFlags.Float flags
            //     are specified, then the stream is 16-bit.
            Byte = 0x1u,
            //
            // Summary:
            //     Decode/play the stream (MP3/MP2/MP1 only) in mono, reducing the CPU usage (if
            //     it was originally stereo). This flag is automatically applied if ManagedBass.DeviceInitFlags.Mono
            //     was specified when calling ManagedBass.Bass.Init(System.Int32,System.Int32,ManagedBass.DeviceInitFlags,System.IntPtr,System.IntPtr).
            Mono = 0x2u,
            //
            // Summary:
            //     Loop the file. This flag can be toggled at any time using ManagedBass.Bass.ChannelFlags(System.Int32,ManagedBass.BassFlags,ManagedBass.BassFlags).
            Loop = 0x4u,
            //
            // Summary:
            //     Use 3D functionality. This is ignored if ManagedBass.DeviceInitFlags.Device3D
            //     wasn't specified when calling ManagedBass.Bass.Init(System.Int32,System.Int32,ManagedBass.DeviceInitFlags,System.IntPtr,System.IntPtr).
            //     3D streams must be mono (chans=1). The Speaker flags can not be used together
            //     with this flag.
            Bass3D = 0x8u,
            //
            // Summary:
            //     Force the stream to not use hardware mixing (Windows Only).
            SoftwareMixing = 0x10u,
            //
            // Summary:
            //     Enable the old implementation of DirectX 8 effects (Windows Only). Use ManagedBass.Bass.ChannelSetFX(System.Int32,ManagedBass.EffectType,System.Int32)
            //     to add effects to the stream. Requires DirectX 8 or above.
            FX = 0x80u,
            //
            // Summary:
            //     Use 32-bit floating-point sample data (see Floating-Point Channels for details).
            //     WDM drivers or the ManagedBass.BassFlags.Decode flag are required to use this
            //     flag.
            Float = 0x100u,
            //
            // Summary:
            //     Enable pin-point accurate seeking (to the exact byte) on the MP3/MP2/MP1 stream
            //     or MOD music. This also increases the time taken to create the stream, due to
            //     the entire file being pre-scanned for the seek points. Note: This flag is ONLY
            //     needed for files with a VBR, files with a CBR are always accurate.
            Prescan = 0x20000u,
            //
            // Summary:
            //     Automatically free the music or stream's resources when it has reached the end,
            //     or when ManagedBass.Bass.ChannelStop(System.Int32) or ManagedBass.Bass.Stop is
            //     called. This flag can be toggled at any time using ManagedBass.Bass.ChannelFlags(System.Int32,ManagedBass.BassFlags,ManagedBass.BassFlags).
            AutoFree = 0x40000u,
            //
            // Summary:
            //     Restrict the download rate of the file to the rate required to sustain playback.
            //     If this flag is not used, then the file will be downloaded as quickly as possible.
            //     This flag has no effect on "unbuffered" streams (Buffer=false). This flag can
            //     be toggled at any time using ManagedBass.Bass.ChannelFlags(System.Int32,ManagedBass.BassFlags,ManagedBass.BassFlags).
            RestrictDownloadRate = 0x80000u,
            //
            // Summary:
            //     Download and play the file in smaller chunks. Uses a lot less memory than otherwise,
            //     but it's not possible to seek or loop the stream - once it's ended, the file
            //     must be opened again to play it again. This flag will automatically be applied
            //     when the file Length is unknown. This flag also has the effect of resticting
            //     the download rate. This flag has no effect on "unbuffered" streams (Buffer=false).
            StreamDownloadBlocks = 0x100000u,
            //
            // Summary:
            //     Decode the sample data, without outputting it. Use ManagedBass.Bass.ChannelGetData(System.Int32,System.IntPtr,System.Int32)
            //     to retrieve decoded sample data. Bass.SoftwareMixing/ManagedBass.BassFlags.Bass3D/BassFlags.FX/ManagedBass.BassFlags.AutoFree
            //     are all ignored when using this flag, as are the Speaker flags.
            Decode = 0x200000u,
            //
            // Summary:
            //     Pass status info (HTTP/ICY tags) from the server to the ManagedBass.DownloadProcedure
            //     callback during connection. This can be useful to determine the reason for a
            //     failure.
            StreamStatus = 0x800000u,
            //
            // Summary:
            //     Use an async look-ahead cache.
            AsyncFile = 0x40000000u,
            //
            // Summary:
            //     File is a Unicode (16-bit characters) filename
            Unicode = 0x80000000u,
            //
            // Summary:
            //     BassFx add-on: If in use, then you can do other stuff while detection's in process.
            FxBpmBackground = 0x1u,
            //
            // Summary:
            //     BassFx add-on: If in use, then will auto multiply bpm by 2 (if BPM < MinBPM*2)
            FXBpmMult2 = 0x2u,
            //
            // Summary:
            //     BassFx add-on (BassFx.TempoCreate): Uses a linear interpolation mode (simple).
            FxTempoAlgorithmLinear = 0x200u,
            //
            // Summary:
            //     BassFx add-on (BassFx.TempoCreate): Uses a cubic interpolation mode (recommended,
            //     default).
            FxTempoAlgorithmCubic = 0x400u,
            //
            // Summary:
            //     BassFx add-on (BassFx.TempoCreate): Uses a 8-tap band-limited Shannon interpolation
            //     (complex, but not much better than cubic).
            FxTempoAlgorithmShannon = 0x800u,
            //
            // Summary:
            //     BassFx add-on: Free the source Handle as well?
            FxFreeSource = 0x10000u,
            //
            // Summary:
            //     BASSMIDI add-on: Don't send a WAVE header to the encoder. If this flag is used
            //     then the sample format (mono 16-bit) must be passed to the encoder some other
            //     way, eg. via the command-line.
            MidiNoHeader = 0x1u,
            //
            // Summary:
            //     BASSMIDI add-on: Reduce 24-bit sample data to 16-bit before encoding.
            Midi16Bit = 0x2u,
            //
            // Summary:
            //     BASSMIDI add-on: Ignore system reset events (MidiEventType.System) when the system
            //     mode is unchanged. This flag can be toggled at any time using ManagedBass.Bass.ChannelFlags(System.Int32,ManagedBass.BassFlags,ManagedBass.BassFlags).
            MidiNoSystemReset = 0x800u,
            //
            // Summary:
            //     BASSMIDI add-on: Let the sound decay naturally (including reverb) instead of
            //     stopping it abruptly at the end of the file. This flag can be toggled at any
            //     time using ManagedBass.Bass.ChannelFlags(System.Int32,ManagedBass.BassFlags,ManagedBass.BassFlags)
            //     methods.
            MidiDecayEnd = 0x1000u,
            //
            // Summary:
            //     BASSMIDI add-on: Disable the MIDI reverb/chorus processing. This flag can be
            //     toggled at any time using ManagedBass.Bass.ChannelFlags(System.Int32,ManagedBass.BassFlags,ManagedBass.BassFlags).
            MidiNoFx = 0x2000u,
            //
            // Summary:
            //     BASSMIDI add-on: Let the old sound decay naturally (including reverb) when changing
            //     the position, including looping. This flag can be toggled at any time using ManagedBass.Bass.ChannelFlags(System.Int32,ManagedBass.BassFlags,ManagedBass.BassFlags),
            //     and can also be used in ManagedBass.Bass.ChannelSetPosition(System.Int32,System.Int64,ManagedBass.PositionFlags)
            //     calls to have it apply to particular position changes.
            MidiDecaySeek = 0x4000u,
            //
            // Summary:
            //     BASSMIDI add-on: Do not remove empty space (containing no events) from the end
            //     of the file.
            MidiNoCrop = 0x8000u,
            //
            // Summary:
            //     BASSMIDI add-on: Only release the oldest instance upon a note off event (MidiEventType.Note
            //     with velocity=0) when there are overlapping instances of the note. Otherwise
            //     all instances are released. This flag can be toggled at any time using ManagedBass.Bass.ChannelFlags(System.Int32,ManagedBass.BassFlags,ManagedBass.BassFlags).
            MidiNoteOff1 = 0x10000u,
            //
            // Summary:
            //     BASSMIDI add-on: Map the file into memory. This flag is ignored if the soundfont
            //     is packed as the sample data cannot be played directly from a mapping; it needs
            //     to be decoded. This flag is also ignored if the file is too large to be mapped
            //     into memory.
            MidiFontMemoryMap = 0x20000u,
            //
            // Summary:
            //     Use bank 127 in the soundfont for XG drum kits. When an XG drum kit is needed,
            //     bank 127 in soundfonts that have this flag set will be checked first, before
            //     falling back to bank 128 (the standard SF2 drum kit bank) if it is not available
            //     there.
            MidiFontXGDRUMS = 0x40000u,
            //
            // Summary:
            //     Music and BASSMIDI add-on: Use sinc interpolated sample mixing. This increases
            //     the sound quality, but also requires more CPU. Otherwise linear interpolation
            //     is used. Music: If neither this or the ManagedBass.BassFlags.MusicNonInterpolated
            //     flag is specified, linear interpolation is used. This flag can be toggled at
            //     any time using ManagedBass.Bass.ChannelFlags(System.Int32,ManagedBass.BassFlags,ManagedBass.BassFlags).
            SincInterpolation = 0x800000u,
            //
            // Summary:
            //     Music: Use "normal" ramping (as used in FastTracker 2). This flag can be toggled
            //     at any time using ManagedBass.Bass.ChannelFlags(System.Int32,ManagedBass.BassFlags,ManagedBass.BassFlags).
            MusicRamp = 0x200u,
            //
            // Summary:
            //     Music: Use "sensitive" ramping. This flag can be toggled at any time using ManagedBass.Bass.ChannelFlags(System.Int32,ManagedBass.BassFlags,ManagedBass.BassFlags).
            MusicSensitiveRamping = 0x400u,
            //
            // Summary:
            //     Music: Apply XMPlay's surround sound to the music (ignored in mono). This flag
            //     can be toggled at any time using ManagedBass.Bass.ChannelFlags(System.Int32,ManagedBass.BassFlags,ManagedBass.BassFlags).
            MusicSurround = 0x800u,
            //
            // Summary:
            //     Music: Apply XMPlay's surround sound mode 2 to the music (ignored in mono). This
            //     flag can be toggled at any time using ManagedBass.Bass.ChannelFlags(System.Int32,ManagedBass.BassFlags,ManagedBass.BassFlags).
            MusicSurround2 = 0x1000u,
            //
            // Summary:
            //     Music: Play .MOD file as FastTracker 2 would. This flag can be toggled at any
            //     time using ManagedBass.Bass.ChannelFlags(System.Int32,ManagedBass.BassFlags,ManagedBass.BassFlags).
            MusicFT2Mod = 0x2000u,
            //
            // Summary:
            //     Apply FastTracker 2 panning to XM files.
            MusicFT2PAN = 0x2000u,
            //
            // Summary:
            //     Music: Play .MOD file as ProTracker 1 would. This flag can be toggled at any
            //     time using ManagedBass.Bass.ChannelFlags(System.Int32,ManagedBass.BassFlags,ManagedBass.BassFlags).
            MusicPT1Mod = 0x4000u,
            //
            // Summary:
            //     Music: Stop all notes when seeking (using ManagedBass.Bass.ChannelSetPosition(System.Int32,System.Int64,ManagedBass.PositionFlags)).
            //     This flag can be toggled at any time using ManagedBass.Bass.ChannelFlags(System.Int32,ManagedBass.BassFlags,ManagedBass.BassFlags).
            MusicPositionReset = 0x8000u,
            //
            // Summary:
            //     Music: Use non-interpolated mixing. This generally reduces the sound quality,
            //     but can be good for chip-tunes. This flag can be toggled at any time using ManagedBass.Bass.ChannelFlags(System.Int32,ManagedBass.BassFlags,ManagedBass.BassFlags).
            MusicNonInterpolated = 0x10000u,
            //
            // Summary:
            //     Music: Stop the music when a backward jump effect is played. This stops musics
            //     that never reach the end from going into endless loops. Some MOD musics are designed
            //     to jump all over the place, so this flag would cause those to be stopped prematurely.
            //     If this flag is used together with the ManagedBass.BassFlags.Loop flag, then
            //     the music would not be stopped but any ManagedBass.SyncFlags.End sync would be
            //     triggered. This flag can be toggled at any time using ManagedBass.Bass.ChannelFlags(System.Int32,ManagedBass.BassFlags,ManagedBass.BassFlags).
            MusicStopBack = 0x80000u,
            //
            // Summary:
            //     Music: Don't load the samples. This reduces the time taken to load the music,
            //     notably with MO3 files, which is useful if you just want to get the name and
            //     Length of the music without playing it.
            MusicNoSample = 0x100000u,
            //
            // Summary:
            //     Music: Stop all notes and reset bpm/etc when seeking. This flag can be toggled
            //     at any time using ManagedBass.Bass.ChannelFlags(System.Int32,ManagedBass.BassFlags,ManagedBass.BassFlags).
            MusicPositionResetEx = 0x400000u,
            //
            // Summary:
            //     Sample: muted at max distance (3D only)
            MuteMax = 0x20u,
            //
            // Summary:
            //     Sample: uses the DX7 voice allocation and management
            VAM = 0x40u,
            //
            // Summary:
            //     Sample: override lowest volume
            SampleOverrideLowestVolume = 0x10000u,
            //
            // Summary:
            //     Sample: override longest playing
            SampleOverrideLongestPlaying = 0x20000u,
            //
            // Summary:
            //     Sample: override furthest from listener (3D only)
            SampleOverrideDistance = 0x30000u,
            //
            // Summary:
            //     Sample: Do not recycle/override one of the sample's existing channels. This should
            //     be used as an argument to ManagedBass.Bass.SampleGetChannel(System.Int32,System.Boolean).
            SampleChannelNew = 0x1u,
            //
            // Summary:
            //     Sample: Create a stream rather than a sample channel. This should be used as
            //     an argument to ManagedBass.Bass.SampleGetChannel(System.Int32,System.Boolean).
            SampleChannelStream = 0x2u,
            //
            // Summary:
            //     BASSCD add-on: Read sub-channel data. 96 bytes of de-interleaved sub-channel
            //     data will be returned after each 2352 bytes of audio. This flag can not be used
            //     with the ManagedBass.BassFlags.Float flag, and is ignored if the ManagedBass.BassFlags.Decode
            //     flag is not used.
            CDSubChannel = 0x200u,
            //
            // Summary:
            //     BASSCD add-on: Read sub-channel data, without using any hardware de-interleaving.
            //     This is identical to the ManagedBass.BassFlags.CDSubChannel flag, except that
            //     the de-interleaving is always performed by BASSCD even if the drive is apparently
            //     capable of de-interleaving itself.
            CDSubchannelNoHW = 0x400u,
            //
            // Summary:
            //     BASSCD add-on: Include C2 error info. 296 bytes of C2 error info is returned
            //     after each 2352 bytes of audio (and optionally 96 bytes of sub-channel data).
            //     This flag cannot be used with the ManagedBass.BassFlags.Float flag, and is ignored
            //     if the ManagedBass.BassFlags.Decode flag is not used. The first 294 bytes contain
            //     the C2 error bits (one bit for each byte of audio), followed by a byte containing
            //     the logical OR of all 294 bytes, which can be used to quickly check if there
            //     were any C2 errors. The final byte is just padding. Note that if you request
            //     both sub-channel data and C2 error info, the C2 info will come before the sub-channel
            //     data!
            CdC2Errors = 0x800u,
            //
            // Summary:
            //     Only relevant for StreamAddChannelEx(): Start is an absolute position in the
            //     mixer output rather than relative to the mixer's current position. If the position
            //     has already passed then the source will start immediately.
            MixerChanAbsolute = 0x1000u,
            //
            // Summary:
            //     BASSmix add-on: only read buffered data.
            SplitSlave = 0x1000u,
            //
            // Summary:
            //     BASSmix add-on: The splitter's length and position is based on the splitter's
            //     (rather than the source's) channel count.
            SplitPosition = 0x2000u,
            //
            // Summary:
            //     BASSmix add-on: resume a stalled mixer immediately upon new/unpaused source
            MixerResume = 0x1000u,
            //
            // Summary:
            //     BASSmix add-on: enable BassMix.ChannelGetPosition(int,PositionFlags,int) support.
            MixerPositionEx = 0x2000u,
            //
            // Summary:
            //     BASSmix add-on: Buffer source data for BassMix.ChannelGetData(int,IntPtr,int)
            //     and BassMix.ChannelGetLevel(int).
            MixerChanBuffer = 0x2000u,
            //
            // Summary:
            //     BASSmix add-on: Buffer source data for BassMix.ChannelGetData(int,IntPtr,int)
            //     and BassMix.ChannelGetLevel(int).
            [Obsolete("Renamed to MixerChanBuffer for clarity.")]
            MixerBuffer = 0x2000u,
            //
            // Summary:
            //     BASSmix add-on: Limit mixer processing to the amount available from this source.
            MixerChanLimit = 0x4000u,
            //
            // Summary:
            //     BASSmix add-on: Limit mixer processing to the amount available from this source.
            [Obsolete("Renamed to MixerChanLimit for clarity.")]
            MixerLimit = 0x4000u,
            //
            // Summary:
            //     BASSmix add-on: end the stream when there are no sources
            MixerEnd = 0x10000u,
            //
            // Summary:
            //     BASSmix add-on: Matrix mixing
            MixerChanMatrix = 0x10000u,
            //
            // Summary:
            //     BASSmix add-on: Matrix mixing
            [Obsolete("Renamed to MixerChanMatrix for clarity.")]
            MixerMatrix = 0x10000u,
            //
            // Summary:
            //     BASSmix add-on: don't stall when there are no sources
            MixerNonStop = 0x20000u,
            //
            // Summary:
            //     BASSmix add-on: don't process the source
            MixerChanPause = 0x20000u,
            //
            // Summary:
            //     BASSmix add-on: don't process the source
            [Obsolete("Renamed to MixerChanPause for clarity.")]
            MixerPause = 0x20000u,
            //
            // Summary:
            //     BASSmix add-on: downmix to stereo (or mono if mixer is mono)
            MixerChanDownMix = 0x400000u,
            //
            // Summary:
            //     BASSmix add-on: downmix to stereo (or mono if mixer is mono)
            [Obsolete("Renamed to MixerChanDownMix for clarity.")]
            MixerDownMix = 0x400000u,
            //
            // Summary:
            //     BASSmix add-on: don't ramp-in the start
            MixerChanNoRampin = 0x800000u,
            //
            // Summary:
            //     BASSmix add-on: don't ramp-in the start
            [Obsolete("Renamed to MixerChanNoRampin for clarity.")]
            MixerNoRampin = 0x800000u,
            //
            // Summary:
            //     Recording: Start the recording paused. Use ManagedBass.Bass.ChannelPlay(System.Int32,System.Boolean)
            //     to start it.
            RecordPause = 0x8000u,
            //
            // Summary:
            //     Recording: Enable Echo Cancellation (only available on certain devices, like
            //     iOS).
            RecordEchoCancel = 0x2000u,
            //
            // Summary:
            //     Recording: Enable Automatic Gain Control (only available on certain devices,
            //     like iOS).
            RecordAGC = 0x4000u,
            //
            // Summary:
            //     Front speakers (channel 1/2)
            SpeakerFront = 0x1000000u,
            //
            // Summary:
            //     Rear/Side speakers (channel 3/4)
            SpeakerRear = 0x2000000u,
            //
            // Summary:
            //     Center and LFE speakers (5.1, channel 5/6)
            SpeakerCenterLFE = 0x3000000u,
            //
            // Summary:
            //     Rear Center speakers (7.1, channel 7/8)
            SpeakerRearCenter = 0x4000000u,
            //
            // Summary:
            //     Speakers Pair 1
            SpeakerPair1 = 0x1000000u,
            //
            // Summary:
            //     Speakers Pair 2
            SpeakerPair2 = 0x2000000u,
            //
            // Summary:
            //     Speakers Pair 3
            SpeakerPair3 = 0x3000000u,
            //
            // Summary:
            //     Speakers Pair 4
            SpeakerPair4 = 0x4000000u,
            //
            // Summary:
            //     Speakers Pair 5
            SpeakerPair5 = 0x5000000u,
            //
            // Summary:
            //     Speakers Pair 6
            SpeakerPair6 = 0x6000000u,
            //
            // Summary:
            //     Speakers Pair 7
            SpeakerPair7 = 0x7000000u,
            //
            // Summary:
            //     Speakers Pair 8
            SpeakerPair8 = 0x8000000u,
            //
            // Summary:
            //     Speakers Pair 9
            SpeakerPair9 = 0x9000000u,
            //
            // Summary:
            //     Speakers Pair 10
            SpeakerPair10 = 0xA000000u,
            //
            // Summary:
            //     Speakers Pair 11
            SpeakerPair11 = 0xB000000u,
            //
            // Summary:
            //     Speakers Pair 12
            SpeakerPair12 = 0xC000000u,
            //
            // Summary:
            //     Speakers Pair 13
            SpeakerPair13 = 0xD000000u,
            //
            // Summary:
            //     Speakers Pair 14
            SpeakerPair14 = 0xE000000u,
            //
            // Summary:
            //     Speakers Pair 15
            SpeakerPair15 = 0xF000000u,
            //
            // Summary:
            //     Speaker Modifier: left channel only
            SpeakerLeft = 0x10000000u,
            //
            // Summary:
            //     Speaker Modifier: right channel only
            SpeakerRight = 0x20000000u,
            //
            // Summary:
            //     Front Left speaker only (channel 1)
            SpeakerFrontLeft = 0x11000000u,
            //
            // Summary:
            //     Rear/Side Left speaker only (channel 3)
            SpeakerRearLeft = 0x12000000u,
            //
            // Summary:
            //     Center speaker only (5.1, channel 5)
            SpeakerCenter = 0x13000000u,
            //
            // Summary:
            //     Rear Center Left speaker only (7.1, channel 7)
            SpeakerRearCenterLeft = 0x14000000u,
            //
            // Summary:
            //     Front Right speaker only (channel 2)
            SpeakerFrontRight = 0x21000000u,
            //
            // Summary:
            //     Rear/Side Right speaker only (channel 4)
            SpeakerRearRight = 0x22000000u,
            //
            // Summary:
            //     LFE speaker only (5.1, channel 6)
            SpeakerLFE = 0x23000000u,
            //
            // Summary:
            //     Rear Center Right speaker only (7.1, channel 8)
            SpeakerRearCenterRight = 0x24000000u,
            //
            // Summary:
            //     BassAac add-on: use 960 samples per frame
            AacFrame960 = 0x1000u,
            //
            // Summary:
            //     BassAac add-on: Downmatrix to Stereo
            AacStereo = 0x400000u,
            //
            // Summary:
            //     BassDSD add-on: Produce DSD-over-PCM data (with 0x05/0xFA markers). DSD-over-PCM
            //     data is 24-bit, so the ManagedBass.BassFlags.Float flag is required.
            DSDOverPCM = 0x400u,
            //
            // Summary:
            //     BassDSD add-on: Produce raw DSD data instead of PCM. The DSD data is in blocks
            //     of 8 bits (1 byte) per-channel with the MSB being first/oldest. DSD data is not
            //     playable by BASS, so the ManagedBass.BassFlags.Decode flag is required.
            DSDRaw = 0x200u,
            //
            // Summary:
            //     BassAC3 add-on: downmix to stereo
            Ac3DownmixStereo = 0x200u,
            //
            // Summary:
            //     BASS_AC3 add-on: downmix to quad
            Ac3DownmixQuad = 0x400u,
            //
            // Summary:
            //     BASS_AC3 add-on: downmix to dolby
            Ac3DownmixDolby = 0x600u,
            //
            // Summary:
            //     BASS_AC3 add-on: enable dynamic range compression
            Ac3DRC = 0x800u,
            //
            // Summary:
            //     DSHOW add-on: Use this flag to disable audio processing.
            DShowNoAudioProcessing = 0x80000u,
            //
            // Summary:
            //     DSHOW add-on: Use this flag to enable mixing video on a channel.
            DShowStreamMix = 0x1000000u,
            //
            // Summary:
            //     DSHOW add-on: Use this flag to enable auto dvd functions(on mouse down, keys
            //     etc).
            DShowAutoDVD = 0x4000000u,
            //
            // Summary:
            //     DSHOW add-on: Use this flag to restart the stream when it's finished.
            DShowLoop = 0x8000000u,
            //
            // Summary:
            //     DSHOW add-on: Use this to enable video processing.
            DShowVideoProcessing = 0x20000u,
            //
            // Summary:
            //     BassWV add-on: Limit to stereo
            WVStereo = 0x400000u
        }
    }
}
