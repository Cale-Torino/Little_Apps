using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MusicIntense
{
    internal class ChannelAttributeClass
    {
        //
        // Summary:
        //     Channel attribute options used by ManagedBass.Bass.ChannelSetAttribute(System.Int32,ManagedBass.ChannelAttribute,System.Single)
        //     and ManagedBass.Bass.ChannelGetAttribute(System.Int32,ManagedBass.ChannelAttribute,System.Single@).
        public enum ChannelAttribute
        {
            //
            // Summary:
            //     The sample rate of a channel... 0 = original rate (when the channel was created).
            //     This attribute applies to playback of the channel, and does not affect the channel's
            //     sample data, so has no real effect on decoding channels. It is still adjustable
            //     though, so that it can be used by the BassMix add-on, and anything else that
            //     wants to use it.
            //     It is not possible to change the sample rate of a channel if the "with FX flag"
            //     DX8 effect implementation enabled on it, unless DirectX 9 or above is installed.
            //     Increasing the sample rate of a stream or MOD music increases its CPU usage,
            //     and reduces the Length of its playback Buffer in terms of time. If you intend
            //     to raise the sample rate above the original rate, then you may also need to increase
            //     the Buffer Length via the ManagedBass.Bass.PlaybackBufferLength config option
            //     to avoid break-ups in the sound.
            //     Platform-specific
            //     On Windows, the sample rate will get rounded down to a whole number during playback.
            Frequency = 1,
            //
            // Summary:
            //     The volume level of a channel... 0 (silent) to 1 (full).
            //     This can go above 1.0 on decoding channels.
            //     This attribute applies to playback of the channel, and does not affect the channel's
            //     sample data, so has no real effect on decoding channels. It is still adjustable
            //     though, so that it can be used by the BassMix add-on, and anything else that
            //     wants to use it.
            //     When using ManagedBass.Bass.ChannelSlideAttribute(System.Int32,ManagedBass.ChannelAttribute,System.Single,System.Int32,System.Boolean)
            //     to slide this attribute, a negative volume value can be used to fade-out and
            //     then stop the channel.
            Volume = 2,
            //
            // Summary:
            //     The panning/balance position of a channel... -1 (Full Left) to +1 (Full Right),
            //     0 = Centre.
            //     This attribute applies to playback of the channel, and does not affect the channel's
            //     sample data, so has no real effect on decoding channels. It is still adjustable
            //     though, so that it can be used by the BassMix add-on, and anything else that
            //     wants to use it.
            //     It is not possible to set the pan position of a 3D channel. It is also not possible
            //     to set the pan position when using speaker assignment, but if needed, it can
            //     be done via a ManagedBass.DSPProcedure instead (not on mono channels).
            //     Platform-specific
            //     On Windows, this attribute has no effect when speaker assignment is used, except
            //     on Windows Vista and newer with the Bass.VistaSpeakerAssignment config option
            //     enabled. Balance control could be implemented via a ManagedBass.DSPProcedure
            //     instead
            Pan = 3,
            //
            // Summary:
            //     The wet (reverb) / dry (no reverb) mix ratio... 0 (full dry) to 1 (full wet),
            //     -1 = automatically calculate the mix based on the distance (the default).
            //     For a sample, stream, or MOD music channel with 3D functionality.
            //     Obviously, EAX functions have no effect if the output device does not support
            //     EAX. ManagedBass.Bass.GetInfo(ManagedBass.BassInfo@) can be used to check that.
            //     EAX only affects 3D channels, but EAX functions do not require ManagedBass.Bass.Apply3D
            //     to apply the changes. LastError.NoEAX: The channel does not have EAX support.
            //     EAX only applies to 3D channels that are mixed by the hardware/drivers. ManagedBass.Bass.ChannelGetInfo(System.Int32,ManagedBass.ChannelInfo@)
            //     can be used to check if a channel is being mixed by the hardware. EAX is only
            //     supported on Windows.
            EaxMix = 4,
            //
            // Summary:
            //     Non-Windows: Disable playback buffering?... 0 = no, else yes..
            //     A playing channel is normally asked to render data to its playback Buffer in
            //     advance, via automatic Buffer updates or the ManagedBass.Bass.Update(System.Int32)
            //     and ManagedBass.Bass.ChannelUpdate(System.Int32,System.Int32) functions, ready
            //     for mixing with other channels to produce the final mix that is given to the
            //     output device.
            //     When this attribute is switched on (the default is off), that buffering is skipped
            //     and the channel will only be asked to produce data as it is needed during the
            //     generation of the final mix. This allows the lowest latency to be achieved, but
            //     also imposes tighter timing requirements on the channel to produce its data and
            //     apply any DSP/FX (and run mixtime syncs) that are set on it; if too long is taken,
            //     there will be a break in the output, affecting all channels that are playing
            //     on the same device.
            //     The channel's data is still placed in its playback Buffer when this attribute
            //     is on, which allows ManagedBass.Bass.ChannelGetData(System.Int32,System.IntPtr,System.Int32)
            //     and ManagedBass.Bass.ChannelGetLevel(System.Int32) to be used, although there
            //     is likely to be less data available to them due to the Buffer being less full.
            //     This attribute can be changed mid-playback.
            //     If switched on, any already buffered data will still be played, so that there
            //     is no break in sound.
            //     This attribute is not available on Windows, as BASS does not generate the final
            //     mix.
            NoBuffer = 5,
            //
            // Summary:
            //     The CPU usage of a channel. (in percentage).
            //     This attribute gives the percentage of CPU that the channel is using, including
            //     the time taken by decoding and DSP processing, and any FX that are not using
            //     the "with FX flag" DX8 effect implementation. It does not include the time taken
            //     to add the channel's data to the final output mix during playback. The processing
            //     of some add-on stream formats may also not be entirely included, if they use
            //     additional decoding threads; see the add-on documentation for details.
            //     Like ManagedBass.Bass.CPUUsage, this function does not strictly tell the CPU
            //     usage, but rather how timely the processing is. For example, if it takes 10ms
            //     to generate 100ms of data, that would be 10%.
            //     If the reported usage exceeds 100%, that means the channel's data is taking longer
            //     to generate than to play. The duration of the data is based on the channel's
            //     current sample rate (ManagedBass.ChannelAttribute.Frequency). A channel's CPU
            //     usage is updated whenever it generates data. That could be during a playback
            //     Buffer update cycle, or a ManagedBass.Bass.Update(System.Int32) call, or a ManagedBass.Bass.ChannelUpdate(System.Int32,System.Int32)
            //     call. For a decoding channel, it would be in a ManagedBass.Bass.ChannelGetData(System.Int32,System.IntPtr,System.Int32)
            //     or ManagedBass.Bass.ChannelGetLevel(System.Int32) call.
            //     This attribute is read-only, so cannot be modified via ManagedBass.Bass.ChannelSetAttribute(System.Int32,ManagedBass.ChannelAttribute,System.Single).
            CPUUsage = 7,
            //
            // Summary:
            //     The sample rate conversion quality of a channel
            //     0 = linear interpolation, 1 = 8 point sinc interpolation, 2 = 16 point sinc interpolation,
            //     3 = 32 point sinc interpolation. Other values are also accepted but will be interpreted
            //     as 0 or 3, depending on whether they are lower or higher.
            //     When a channel has a different sample rate to what the output device is using,
            //     the channel's sample data will need to be converted to match the output device's
            //     rate during playback. This attribute determines how that is done. The linear
            //     interpolation option uses less CPU, but the sinc interpolation gives better sound
            //     quality (less aliasing), with the quality and CPU usage increasing with the number
            //     of points. A good compromise for lower spec systems could be to use sinc interpolation
            //     for music playback and linear interpolation for sound effects.
            //     Whenever possible, a channel's sample rate should match the output device's rate
            //     to avoid the need for any sample rate conversion. The device's sample rate could
            //     be used in ManagedBass.Bass.CreateStream(System.Int32,System.Int32,ManagedBass.BassFlags,ManagedBass.StreamProcedure,System.IntPtr)
            //     or ManagedBass.Bass.MusicLoad(System.String,System.Int64,System.Int32,ManagedBass.BassFlags,System.Int32)
            //     or BassMidi stream creation calls, for example.
            //     The sample rate conversion occurs (when required) during playback, after the
            //     sample data has left the channel's playback Buffer, so it does not affect the
            //     data delivered by ManagedBass.Bass.ChannelGetData(System.Int32,System.IntPtr,System.Int32).
            //     Although this attribute has no direct effect on decoding channels, it is still
            //     available so that it can be used by the BassMix add-on and anything else that
            //     wants to use it.
            //     This attribute can be set at any time, and changes take immediate effect. A channel's
            //     initial setting is determined by the ManagedBass.Bass.SRCQuality config option,
            //     or ManagedBass.Bass.SampleSRCQuality in the case of a sample channel.
            //     Platform-specific
            //     On Windows, sample rate conversion is handled by Windows or the output device/driver
            //     rather than BASS, so this setting has no effect on playback there.
            SampleRateConversion = 8,
            //
            // Summary:
            //     The download Buffer level required to resume stalled playback in percent... 0
            //     - 100 (the default is 50%).
            //     This attribute determines what percentage of the download Buffer (ManagedBass.Bass.NetBufferLength)
            //     needs to be filled before playback of a stalled internet stream will resume.
            //     It also applies to 'buffered' User file streams created with ManagedBass.Bass.CreateStream(ManagedBass.StreamSystem,ManagedBass.BassFlags,ManagedBass.FileProcedures,System.IntPtr).
            NetworkResumeBufferLevel = 9,
            //
            // Summary:
            //     The scanned info of a channel.
            ScannedInfo = 10,
            //
            // Summary:
            //     Disable playback ramping?
            NoRamp = 11,
            //
            // Summary:
            //     The average bitrate of a file stream.
            Bitrate = 12,
            //
            // Summary:
            //     Playback buffering length.
            Buffer = 13,
            //
            // Summary:
            //     Processing granularity. (HMUSIC/HSTREAM/HRECORD)
            Granule = 14,
            //
            // Summary:
            //     The amplification level of a MOD music... 0 (min) to 100 (max).
            //     This will be rounded down to a whole number.
            //     As the amplification level get's higher, the sample data's range increases, and
            //     therefore, the resolution increases. But if the level is set too high, then clipping
            //     can occur, which can result in distortion of the sound. You can check the current
            //     level of a MOD music at any time by ManagedBass.Bass.ChannelGetLevel(System.Int32).
            //     By doing so, you can decide if a MOD music's amplification level needs adjusting.
            //     The default amplification level is 50.
            //     During playback, the effect of changes to this attribute are not heard instantaneously,
            //     due to buffering. To reduce the delay, use the ManagedBass.Bass.PlaybackBufferLength
            //     config option to reduce the Buffer Length.
            MusicAmplify = 0x100,
            //
            // Summary:
            //     The pan separation level of a MOD music... 0 (min) to 100 (max), 50 = linear.
            //     This will be rounded down to a whole number. By default BASS uses a linear panning
            //     "curve". If you want to use the panning of FT2, use a pan separation setting
            //     of around 35. To use the Amiga panning (ie. full left and right) set it to 100.
            MusicPanSeparation = 257,
            //
            // Summary:
            //     The position scaler of a MOD music... 1 (min) to 256 (max).
            //     This will be rounded down to a whole number. When calling ManagedBass.Bass.ChannelGetPosition(System.Int32,ManagedBass.PositionFlags),
            //     the row (HIWORD) will be scaled by this value. By using a higher scaler, you
            //     can get a more precise position indication. The default scaler is 1.
            MusicPositionScaler = 258,
            //
            // Summary:
            //     The BPM of a MOD music... 1 (min) to 255 (max).
            //     This will be rounded down to a whole number. This attribute is a direct mapping
            //     of the MOD's BPM, so the value can be changed via effects in the MOD itself.
            //     Note that by changing this attribute, you are changing the playback Length. During
            //     playback, the effect of changes to this attribute are not heard instantaneously,
            //     due to buffering. To reduce the delay, use the ManagedBass.Bass.PlaybackBufferLength
            //     config option to reduce the Buffer Length.
            MusicBPM = 259,
            //
            // Summary:
            //     The speed of a MOD music... 0 (min) to 255 (max).
            //     This will be rounded down to a whole number. This attribute is a direct mapping
            //     of the MOD's speed, so the value can be changed via effects in the MOD itself.
            //     The "speed" is the number of ticks per row. Setting it to 0, stops and ends the
            //     music. Note that by changing this attribute, you are changing the playback Length.
            //     During playback, the effect of changes to this attribute are not heard instantaneously,
            //     due to buffering. To reduce the delay, use the ManagedBass.Bass.PlaybackBufferLength
            //     config option to reduce the Buffer Length.
            MusicSpeed = 260,
            //
            // Summary:
            //     The global volume level of a MOD music... 0 (min) to 64 (max, 128 for IT format).
            //     This will be rounded down to a whole number. This attribute is a direct mapping
            //     of the MOD's global volume, so the value can be changed via effects in the MOD
            //     itself. The "speed" is the number of ticks per row. Setting it to 0, stops and
            //     ends the music. Note that by changing this attribute, you are changing the playback
            //     Length. During playback, the effect of changes to this attribute are not heard
            //     instantaneously, due to buffering. To reduce the delay, use the ManagedBass.Bass.PlaybackBufferLength
            //     config option to reduce the Buffer Length.
            MusicVolumeGlobal = 261,
            //
            // Summary:
            //     The number of active channels in a MOD music.
            //     This attribute gives the number of channels (including virtual) that are currently
            //     active in the decoder, which may not match what is being heard during playback
            //     due to buffering. To reduce the time difference, use the ManagedBass.Bass.PlaybackBufferLength
            //     config option to reduce the Buffer Length. This attribute is read-only, so cannot
            //     be modified via ManagedBass.Bass.ChannelSetAttribute(System.Int32,ManagedBass.ChannelAttribute,System.Single).
            MusicActiveChannelCount = 262,
            //
            // Summary:
            //     The volume level... 0 (silent) to 1 (full) of a channel in a MOD music + channel#.
            //     channel: The channel to set the volume of... 0 = 1st channel.
            //     The volume curve used by this attribute is always linear, eg. 0.5 = 50%. The
            //     ManagedBass.Bass.LogarithmicVolumeCurve config option setting has no effect on
            //     this. The volume level of all channels is initially 1 (full). This attribute
            //     can also be used to count the number of channels in a MOD Music. During playback,
            //     the effect of changes to this attribute are not heard instantaneously, due to
            //     buffering. To reduce the delay, use the ManagedBass.Bass.PlaybackBufferLength
            //     config option to reduce the Buffer Length.
            MusicVolumeChannel = 0x200,
            //
            // Summary:
            //     The volume level... 0 (silent) to 1 (full) of an instrument in a MOD music +
            //     inst#.
            //     inst: The instrument to set the volume of... 0 = 1st instrument.
            //     The volume curve used by this attribute is always linear, eg. 0.5 = 50%. The
            //     ManagedBass.Bass.LogarithmicVolumeCurve config option setting has no effect on
            //     this. The volume level of all instruments is initially 1 (full). For MOD formats
            //     that do not use instruments, read "sample" for "instrument". This attribute can
            //     also be used to count the number of instruments in a MOD music. During playback,
            //     the effect of changes to this attribute are not heard instantaneously, due to
            //     buffering. To reduce the delay, use the ManagedBass.Bass.PlaybackBufferLength
            //     config option to reduce the Buffer Length.
            MusicVolumeInstrument = 768,
            //
            // Summary:
            //     BassFx Tempo: The Tempo in percents (-95%..0..+5000%).
            Tempo = 0x10000,
            //
            // Summary:
            //     BassFx Tempo: The Pitch in semitones (-60..0..+60).
            Pitch = 65537,
            //
            // Summary:
            //     BassFx Tempo: The Samplerate in Hz, but calculates by the same % as ManagedBass.ChannelAttribute.Tempo.
            TempoFrequency = 65538,
            //
            // Summary:
            //     BassFx Tempo Option: Use FIR low-pass (anti-alias) filter (gain speed, lose quality)?
            //     true=1 (default), false=0.
            //     See BassFx.TempoCreate for details.
            //     On iOS, Android, WinCE and Linux ARM platforms this is by default disabled for
            //     lower CPU usage.
            TempoUseAAFilter = 65552,
            //
            // Summary:
            //     BassFx Tempo Option: FIR low-pass (anti-alias) filter Length in taps (8 .. 128
            //     taps, default = 32, should be %4).
            //     See BassFx.TempoCreate for details.
            TempoAAFilterLength = 65553,
            //
            // Summary:
            //     BassFx Tempo Option: Use quicker tempo change algorithm (gain speed, lose quality)?
            //     true=1, false=0 (default).
            //     See BassFx.TempoCreate for details.
            TempoUseQuickAlgorithm = 65554,
            //
            // Summary:
            //     BassFx Tempo Option: Tempo Sequence in milliseconds (default = 82).
            //     See BassFx.TempoCreate for details.
            TempoSequenceMilliseconds = 65555,
            //
            // Summary:
            //     BassFx Tempo Option: SeekWindow in milliseconds (default = 14).
            //     See BassFx.TempoCreate for details.
            TempoSeekWindowMilliseconds = 65556,
            //
            // Summary:
            //     BassFx Tempo Option: Tempo Overlap in milliseconds (default = 12).
            //     See BassFx.TempoCreate for details.
            TempoOverlapMilliseconds = 65557,
            //
            // Summary:
            //     BassFx Tempo Option: Prevents clicks with tempo changes (default = FALSE).
            //     See BassFx.TempoCreate for details.
            TempoPreventClick = 65558,
            //
            // Summary:
            //     Playback direction (-1 = Reverse or 1 = Forward).
            ReverseDirection = 69632,
            //
            // Summary:
            //     BASSMIDI: Gets the Pulses Per Quarter Note (or ticks per beat) value of the MIDI
            //     file.
            //     This attribute is the number of ticks per beat as defined by the MIDI file; it
            //     will be 0 for MIDI streams created via BassMidi.CreateStream(int,BassFlags,int),
            //     It is read-only, so can't be modified via ManagedBass.Bass.ChannelSetAttribute(System.Int32,ManagedBass.ChannelAttribute,System.Single).
            MidiPPQN = 73728,
            //
            // Summary:
            //     BASSMIDI: The maximum percentage of CPU time that a MIDI stream can use... 0
            //     to 100, 0 = unlimited.
            //     It is not strictly the CPU usage that is measured, but rather how timely the
            //     stream is able to render data. For example, a limit of 50% would mean that the
            //     rendering would need to be at least 2x real-time speed. When the limit is exceeded,
            //     BassMidi will begin killing voices, starting with the most quiet. When the CPU
            //     usage is limited, the stream's samples are loaded asynchronously so that any
            //     loading delays (eg. due to slow disk) do not hold up the stream for too long.
            //     If a sample cannot be loaded in time, then it will be silenced until it is available
            //     and the stream will continue playing other samples as normal in the meantime.
            //     This does not affect sample loading via BassMidi.StreamLoadSamples, which always
            //     operates synchronously. By default, a MIDI stream will have no CPU limit.
            MidiCPU = 73729,
            //
            // Summary:
            //     BASSMIDI: The number of MIDI channels in a MIDI stream... 1 (min) - 128 (max).
            //     For a MIDI file stream, the minimum is 16. New channels are melodic by default.
            //     Any notes playing on a removed channel are immediately stopped.
            MidiChannels = 73730,
            //
            // Summary:
            //     BASSMIDI: The maximum number of samples to play at a time (polyphony) in a MIDI
            //     stream... 1 (min) - 1000 (max).
            //     If there are currently more voices active than the new limit, then some voices
            //     will be killed to meet the limit. The number of voices currently active is available
            //     via the Voices attribute. A MIDI stream will initially have a default number
            //     of voices as determined by the Voices config option.
            MidiVoices = 73731,
            //
            // Summary:
            //     BASSMIDI: The number of samples (voices) currently playing in a MIDI stream.
            //     This attribute is read-only, so cannot be modified via ManagedBass.Bass.ChannelSetAttribute(System.Int32,ManagedBass.ChannelAttribute,System.Single).
            MidiVoicesActive = 73732,
            //
            // Summary:
            //     BASSMIDI: The current state of a MIDI stream.
            MidiState = 73733,
            //
            // Summary:
            //     BASSMIDI: The sample rate conversion quality of a MIDI stream's samples.
            MidiSRC = 73734,
            MidiKill = 73735,
            //
            // Summary:
            //     BASSMIDI: The volume level (0.0=silent, 1.0=normal/default) of a track in a MIDI
            //     file stream + track#.
            //     track#: The track to set the volume of... 0 = first track.
            //     The volume curve used by this attribute is always linear, eg. 0.5 = 50%. The
            //     ManagedBass.Bass.LogarithmicVolumeCurve config option setting has no effect on
            //     this. During playback, the effect of changes to this attribute are not heard
            //     instantaneously, due to buffering. To reduce the delay, use the ManagedBass.Bass.PlaybackBufferLength
            //     config option to reduce the Buffer Length. This attribute can also be used to
            //     count the number of tracks in a MIDI file stream. MIDI streams created via BassMidi.CreateStream(int,BassFlags,int)
            //     do not have any tracks.
            MidiTrackVolume = 73984,
            //
            // Summary:
            //     BassOpus: The sample rate of an Opus stream's source material.
            //     Opus streams always have a sample rate of 48000 Hz, and an Opus encoder will
            //     resample the source material to that if necessary. This attribute presents the
            //     original sample rate, which may be stored in the Opus file header. This attribute
            //     is read-only, so cannot be modified via ManagedBass.Bass.ChannelSetAttribute(System.Int32,ManagedBass.ChannelAttribute,System.Single).
            OpusOriginalFrequency = 77824,
            //
            // Summary:
            //     BassDSD: The gain (in decibels) applied when converting to PCM.
            //
            // Remarks:
            //     This attribute is only applicable when converting to PCM, and is unavailable
            //     when producing DSD-over-PCM or raw DSD data. The default setting is determined
            //     by the ManagedBass.ChannelAttribute.DSDGain config option
            DSDGain = 81920,
            //
            // Summary:
            //     BassDSD: The DSD sample rate.
            //
            // Remarks:
            //     This attribute is read-only, so cannot be modified via ManagedBass.Bass.ChannelSetAttribute(System.Int32,ManagedBass.ChannelAttribute,System.Single).
            DSDRate = 81921,
            //
            // Summary:
            //     BassMix: Custom output latency in seconds... default = 0 (no accounting for latency).
            //     Changes take immediate effect.
            //
            // Remarks:
            //     When a mixer is played by BASS, the BassMix.ChannelGetData(int,IntPtr,int), BassMix.ChannelGetLevel(int),
            //     BassMix.ChannelGetLevel(int,float[],float,LevelRetrievalFlags)", and BassMix.ChannelGetPosition(int,PositionFlags)
            //     functions will get the output latency and account for that so that they reflect
            //     what is currently being heard, but that cannot be done when a different output
            //     system is used, eg. ASIO or WASAPI. In that case, this attribute can be used
            //     to tell the mixer what the output latency is, so that those functions can still
            //     account for it. The mixer needs to have the ManagedBass.BassFlags.Decode and
            //     ManagedBass.BassFlags.MixerPositionEx flags set to use this attribute.
            MixerLatency = 86016,
            //
            // Summary:
            //     Amount of data to asynchronously buffer from a splitter's source. 0 = disable
            //     asynchronous buffering. The asynchronous buffering will be limited to the splitter's
            //     buffer length.
            SplitAsyncBuffer = 86032,
            //
            // Summary:
            //     Maximum amount of data to asynchronously buffer at a time from a splitter's source.
            //     0 = as much as possible.
            SplitAsyncPeriod = 86033
        }
    }
}
