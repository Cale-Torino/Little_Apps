using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace Playing_MP3
{
    public class BassClass : IDisposable
    {

        private const string BASS_lib = "Libs\\bass.dll";
        [DllImport(BASS_lib, CallingConvention = CallingConvention.StdCall)]
        //
        // Summary:
        //     Initializes an output device.
        //
        // Parameters:
        //   Device:
        //     The device to use... -1 = default device, 0 = no sound, 1 = first real output
        //     device. ManagedBass.Bass.GetDeviceInfo(System.Int32,ManagedBass.DeviceInfo@)
        //     or ManagedBass.Bass.DeviceCount can be used to get the total number of devices.
        //
        //   Frequency:
        //     Output sample rate.
        //
        //   Flags:
        //     Any combination of ManagedBass.DeviceInitFlags.
        //
        //   Win:
        //     The application's main window... System.IntPtr.Zero = the desktop window (use
        //     this for console applications).
        //
        //   ClsID:
        //     Class identifier of the object to create, that will be used to initialize DirectSound...
        //     null = use default
        //
        // Returns:
        //     If the device was successfully initialized, true is returned, else false is returned.
        //     Use ManagedBass.Bass.LastError to get the error code.
        //
        // Exceptions:
        //   F:ManagedBass.Errors.Device:
        //     The device number specified is invalid.
        //
        //   F:ManagedBass.Errors.Already:
        //     The device has already been initialized. You must call ManagedBass.Bass.Free
        //     before you can initialize it again.
        //
        //   F:ManagedBass.Errors.Driver:
        //     There is no available device driver... the device may already be in use.
        //
        //   F:ManagedBass.Errors.SampleFormat:
        //     The specified format is not supported by the device. Try changing the Frequency
        //     and Flags parameters.
        //
        //   F:ManagedBass.Errors.Memory:
        //     There is insufficient memory.
        //
        //   F:ManagedBass.Errors.No3D:
        //     The device has no 3D support.
        //
        //   F:ManagedBass.Errors.Unknown:
        //     Some other mystery problem!
        //
        // Remarks:
        //     This function must be successfully called before using any sample, stream or
        //     MOD music functions. The recording functions may be used without having called
        //     this function.
        //     Playback is not possible with the ManagedBass.Bass.NoSoundDevice device, but
        //     it does allow the use of "decoding channels", eg. to decode files.
        //     When specifying a class identifier (ClsID), after successful initialization,
        //     you can use GetDSoundObject(DSInterface) to retrieve the DirectSound object,
        //     and through that access any special interfaces that the object may provide.
        //     Simultaneously using multiple devices is supported in the BASS API via a context
        //     switching system - instead of there being an extra "device" parameter in the
        //     function calls, the device to be used is set prior to calling the functions.
        //     ManagedBass.Bass.CurrentDevice is used to switch the current device. When successful,
        //     ManagedBass.Bass.Init(System.Int32,System.Int32,ManagedBass.DeviceInitFlags,System.IntPtr,System.IntPtr)
        //     automatically sets the current thread's device to the one that was just initialized.
        //     When using the default device (device = -1), ManagedBass.Bass.CurrentDevice can
        //     be used to find out which device it was mapped to. On Windows, it'll always be
        //     the first device.
        //     Platform-specific
        //     On Linux, a 'Default' device is hardcoded to device number 1, which uses the
        //     default output set in the ALSA config; that could map directly to one of the
        //     other devices or it could use ALSA plugins. If the IncludeDefaultDevice config
        //     option has been enbled, a "Default" device is also available on Windows, who's
        //     output will follow default device changes on Windows 7. In both cases, the "Default"
        //     device will also be the default device (device = -1).
        //     The sample format specified in the Frequency and Flags parameters has no effect
        //     on the device output on iOS or OSX, and not on Windows unless VxD drivers are
        //     used (on Windows 98/95); with WDM drivers (on Windows XP/2000/Me/98SE), the output
        //     format is automatically set depending on the format of what is played and what
        //     the device supports, while on Vista and above, the output format is determined
        //     by the user's choice in the Sound control panel. On Linux the output device will
        //     use the specified format if possible, but will otherwise use a format as close
        //     to it as possible. If the ManagedBass.DeviceInitFlags.Frequency flag is specified
        //     on iOS or OSX, then the device's output rate will be set to the freq parameter
        //     (if possible). The ManagedBass.DeviceInitFlags.Frequency flag has no effect on
        //     other platforms. ManagedBass.Bass.GetInfo(ManagedBass.BassInfo@) can be used
        //     to check what the output format actually is.
        //     The Win and ClsID parameters are only used on Windows and are ignored on other
        //     platforms. That applies to the ManagedBass.DeviceInitFlags.CPSpeakers and ManagedBass.DeviceInitFlags.ForcedSpeakerAssignment
        //     flags too, as the number of available speakers is always accurately detected
        //     on the other platforms. The ManagedBass.DeviceInitFlags.Latency flag is also
        //     ignored on Linux/OSX/Android/Windows CE, as latency information is available
        //     without it. The latency is also available without it on iOS, but not immediately
        //     following this function call unless the flag is used.
        //     The DeviceInitFlags.DMix flag is only available on Linux, and allows multiple
        //     applications to share the device (if they all use 'dmix'). It may also be possible
        //     for multiple applications to use exclusive access if the device is capable of
        //     hardware mixing. If exclusive access initialization fails, the DeviceInitFlags.DMix
        //     flag will automatically be tried; if that happens, it can be detected via ManagedBass.Bass.GetInfo(ManagedBass.BassInfo@)
        //     and the ManagedBass.BassInfo.InitFlags.
        //     On Linux and Windows CE, the length of the device's buffer can be set via the
        //     ManagedBass.Bass.PlaybackBufferLength config option.
        public static extern bool BASS_Init(int Device = -1, int Frequency = 44100, DeviceInitFlagsClass.DeviceInitFlags Flags = DeviceInitFlagsClass.DeviceInitFlags.Default, IntPtr Win = default(IntPtr), IntPtr ClsID = default(IntPtr));
        [DllImport(BASS_lib, CallingConvention = CallingConvention.StdCall)]
        //
        // Summary:
        //     Creates a sample stream from an MP3, MP2, MP1, OGG, WAV, AIFF or plugin supported
        //     file.
        //
        // Parameters:
        //   File:
        //     Filename for which a stream should be created.
        //
        //   Offset:
        //     File Offset to begin streaming from.
        //
        //   Length:
        //     Data length... 0 = use all data up to the end of the file.
        //
        //   Flags:
        //     Any combination of ManagedBass.BassFlags.
        //
        // Returns:
        //     If successful, the new stream's handle is returned, else 0 is returned. Use ManagedBass.Bass.LastError
        //     to get the error code.
        //
        // Exceptions:
        //   F:ManagedBass.Errors.Init:
        //     ManagedBass.Bass.Init(System.Int32,System.Int32,ManagedBass.DeviceInitFlags,System.IntPtr,System.IntPtr)
        //     has not been successfully called.
        //
        //   F:ManagedBass.Errors.NotAvailable:
        //     Only decoding channels (ManagedBass.BassFlags.Decode) are allowed when using
        //     the ManagedBass.Bass.NoSoundDevice device. The ManagedBass.BassFlags.AutoFree
        //     flag is also unavailable to decoding channels.
        //
        //   F:ManagedBass.Errors.Parameter:
        //     The Length must be specified when streaming from memory.
        //
        //   F:ManagedBass.Errors.FileOpen:
        //     The File could not be opened.
        //
        //   F:ManagedBass.Errors.FileFormat:
        //     The file's format is not recognised/supported.
        //
        //   F:ManagedBass.Errors.Codec:
        //     The file uses a codec that's not available/supported. This can apply to WAV and
        //     AIFF files, and also MP3 files when using the "MP3-free" BASS version.
        //
        //   F:ManagedBass.Errors.SampleFormat:
        //     The sample format is not supported by the device/drivers. If the stream is more
        //     than stereo or the ManagedBass.BassFlags.Float flag is used, it could be that
        //     they are not supported.
        //
        //   F:ManagedBass.Errors.Speaker:
        //     The specified SPEAKER flags are invalid. The device/drivers do not support them,
        //     they are attempting to assign a stereo stream to a mono speaker or 3D functionality
        //     is enabled.
        //
        //   F:ManagedBass.Errors.Memory:
        //     There is insufficient memory.
        //
        //   F:ManagedBass.Errors.No3D:
        //     Could not initialize 3D support.
        //
        //   F:ManagedBass.Errors.Unknown:
        //     Some other mystery problem!
        //
        // Remarks:
        //     BASS has built-in support for MPEG, OGG, WAV and AIFF files. Support for additional
        //     formats is available via add-ons, which can be downloaded from the BASS website:
        //     www.un4seen.com.
        //     MPEG 1.0, 2.0 and 2.5 layer 3 (MP3) files are supported, layers 1 (MP1) and 2
        //     (MP2) are also supported. Standard RIFF and RF64 WAV files are supported, with
        //     the sample data in a PCM format or compressed with an ACM codec, but the codec
        //     is required to be installed on the user's system for the WAV to be decoded. So
        //     you should either distribute the codec with your software, or use a codec that
        //     comes with Windows (eg. Microsoft ADPCM). All PCM formats from 8 to 32-bit are
        //     supported in WAV and AIFF files, but the output will be restricted to 16-bit
        //     unless the ManagedBass.BassFlags.Float flag is used. 64-bit floating-point WAV
        //     and AIFF files are also supported, but are rendered in 16-bit or 32-bit floating-point
        //     depending on the flags. The file's original resolution is available via ManagedBass.Bass.ChannelGetInfo(System.Int32,ManagedBass.ChannelInfo@).
        //     Chained OGG files containing multiple logical bitstreams are supported, but seeking
        //     within them is only fully supported if the ManagedBass.BassFlags.Prescan flag
        //     is used (or the ManagedBass.Bass.OggPreScan config option is enabled) to have
        //     them pre-scanned. Without pre-scanning, seeking will only be possible back to
        //     the start. The ManagedBass.PositionFlags.OGG mode can be used with ManagedBass.Bass.ChannelGetLength(System.Int32,ManagedBass.PositionFlags)
        //     to get the number of bitstreams and with ManagedBass.Bass.ChannelSetPosition(System.Int32,System.Int64,ManagedBass.PositionFlags)
        //     to seek to a particular one. A ManagedBass.SyncFlags.OggChange sync can be set
        //     via ManagedBass.Bass.ChannelSetSync(System.Int32,ManagedBass.SyncFlags,System.Int64,ManagedBass.SyncProcedure,System.IntPtr)
        //     to be informed of when a new bitstream begins during decoding/playback.
        //     Multi-channel (ie. more than stereo) OGG, WAV and AIFF files are supported.
        //     Use ManagedBass.Bass.ChannelGetInfo(System.Int32,ManagedBass.ChannelInfo@) to
        //     retrieve information on the format (sample rate, resolution, channels) of the
        //     stream. The playback length of the stream can be retrieved using ManagedBass.Bass.ChannelGetLength(System.Int32,ManagedBass.PositionFlags).
        //     If Length = 0 (use all data up to the end of the file), and the file length increases
        //     after creating the stream (ie. the file is still being written), then BASS will
        //     play the extra data too, but the length returned by ManagedBass.Bass.ChannelGetLength(System.Int32,ManagedBass.PositionFlags)
        //     will not be updated until the end is reached. The ManagedBass.Bass.StreamGetFilePosition(System.Int32,ManagedBass.FileStreamPosition)
        //     return values will be updated during playback of the extra data though.
        //     To stream a file from the internet, use ManagedBass.Bass.CreateStream(System.String,System.Int32,ManagedBass.BassFlags,ManagedBass.DownloadProcedure,System.IntPtr).
        //     To stream from other locations, see ManagedBass.Bass.CreateStream(ManagedBass.StreamSystem,ManagedBass.BassFlags,ManagedBass.FileProcedures,System.IntPtr).
        //     Platform-specific
        //     On Windows and Windows CE, ACM codecs are supported with compressed WAV files.
        //     Media Foundation codecs are also supported on Windows 7 and updated versions
        //     of Vista, including support for AAC/MP4 and WMA. On iOS and OSX, CoreAudio codecs
        //     are supported, adding support for any file formats that have a codec installed.
        //     Media Foundation and CoreAudio codecs are only tried after the built-in decoders
        //     and any plugins have rejected the file.
        public static extern int BASS_StreamCreateFile(bool mem, string File, long Offset, long Length, BassFlagsClass.BassFlags Flags = BassFlagsClass.BassFlags.Unicode);
        [DllImport(BASS_lib, CallingConvention = CallingConvention.StdCall)]
        //
        // Summary:
        //     Starts (or resumes) playback of a sample, stream, MOD music, or recording.
        //
        // Parameters:
        //   Handle:
        //     The channel Handle... a HCHANNEL / HMUSIC / HSTREAM / HRECORD Handle.
        //
        //   Restart:
        //     Restart playback from the beginning? If Handle is a User stream, it's current
        //     Buffer contents are flushed. If it's a MOD music, it's BPM/etc are automatically
        //     reset to their initial values.
        //
        // Returns:
        //     If successful, true is returned, else false is returned. Use ManagedBass.Bass.LastError
        //     to get the error code.
        //
        // Exceptions:
        //   F:ManagedBass.Errors.Handle:
        //     Handle is not a valid channel.
        //
        //   F:ManagedBass.Errors.Start:
        //     The output is paused/stopped, use ManagedBass.Bass.Start to start it.
        //
        //   F:ManagedBass.Errors.Decode:
        //     The channel is not playable, it's a "decoding channel".
        //
        //   F:ManagedBass.Errors.BufferLost:
        //     Should not happen... check that a valid window Handle was used with ManagedBass.Bass.Init(System.Int32,System.Int32,ManagedBass.DeviceInitFlags,System.IntPtr,System.IntPtr).
        //
        //   F:ManagedBass.Errors.NoHW:
        //     No hardware voices are available (HCHANNEL only). This only occurs if the sample
        //     was loaded/created with the ManagedBass.BassFlags.VAM flag, and ManagedBass.VAMMode.Hardware
        //     is set in the sample's VAM mode, and there are no hardware voices available to
        //     play it.
        //
        // Remarks:
        //     When streaming in blocks (ManagedBass.BassFlags.StreamDownloadBlocks), the restart
        //     parameter is ignored as it's not possible to go back to the start. The Restart
        //     parameter is also of no consequence with recording channels.
        public static extern bool BASS_ChannelPlay(int Handle, bool Restart = false);

        [DllImport(BASS_lib, CallingConvention = CallingConvention.StdCall)]

        //
        // Summary:
        //     Frees a sample stream's resources, including any SYNC/DSP/FX it has.
        //
        // Parameters:
        //   Handle:
        //     The stream handle.
        //
        // Returns:
        //     If successful, true is returned, else false is returned. Use ManagedBass.Bass.LastError
        //     to get the error code.
        //
        // Exceptions:
        //   F:ManagedBass.Errors.Init:
        //     Handle is not valid.
        public static extern bool BASS_StreamFree(int Handle);
        [DllImport(BASS_lib, CallingConvention = CallingConvention.StdCall)]
        //
        // Summary:
        //     Frees all resources used by the output device, including all it's samples, streams,
        //     and MOD musics.
        //
        // Returns:
        //     If successful, then true is returned, else false is returned. Use ManagedBass.Bass.LastError
        //     to get the error code.
        //
        // Exceptions:
        //   F:ManagedBass.Errors.Init:
        //     ManagedBass.Bass.Init(System.Int32,System.Int32,ManagedBass.DeviceInitFlags,System.IntPtr,System.IntPtr)
        //     has not been successfully called.
        //
        // Remarks:
        //     This function should be called for all initialized devices before your program
        //     exits. It's not necessary to individually free the samples/streams/musics as
        //     these are all automatically freed by this function.
        //     When using multiple devices, the current thread's device setting (as set with
        //     ManagedBass.Bass.CurrentDevice) determines which device this function call applies
        //     to.
        public static extern bool BASS_Free();

        public void Dispose()
        {
            throw new NotImplementedException();
        }
    }
}
