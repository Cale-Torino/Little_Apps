using System.Runtime.InteropServices;

namespace MusicIntense.Classes
{
    /// <summary>
    ///     Wraps bass.dll.
    ///     Supports: .mp3, .ogg, .wav, .mp2, .mp1, .aiff, .m2a, .mpa, .m1a, .mpg, .mpeg,
    ///     .aif, .mp3pro, .bwf, .mus, .mod, .mo3, .s3m, .xm, .it, .mtm, .umx, .mdz, .s3z,
    ///    .itz, .xmz
    /// </summary>
    /// <Remarks>
    ///     BASS is a multiplatform audio library. It's purpose is to provide the most powerful
    ///     and efficient (yet easy to use), sample, stream, MOD music, and recording functions.
    ///     All in a tiny DLL, under 100KB in size.
    /// </Remarks>
    ///
    internal class BassClass : IDisposable
    {
        private const string BASS_lib = @"Libs\bass.dll";
        //https://stackoverflow.com/questions/529677/how-to-have-comments-in-intellisense-for-function-in-visual-studio
        /// <summary>
        ///     Initializes an output device.
        /// </summary>
        /// <param name="Device">
        ///    The device to use... -1 = default device, 0 = no sound, 1 = first real output
        ///    device. ManagedBass.Bass.GetDeviceInfo(System.Int32,ManagedBass.DeviceInfo@)
        ///    or ManagedBass.Bass.DeviceCount can be used to get the total number of devices.
        /// </param>
        /// <param name="Frequency">Output sample rate.</param>
        /// <param name="Win">
        ///     The application's main window... System.IntPtr.Zero = the desktop window (use
        ///     this for console applications).
        /// </param>
        /// <param name="ClsID">
        ///Class identifier of the object to create, that will be used to initialize DirectSound...
        ///null = use default
        /// </param>
        ///<returns>
        ///If the device was successfully initialized, true is returned, else false is returned.
        ///Use ManagedBass.Bass.LastError to get the error code.
        ///</returns>
        ///
        ///<exception cref="Exceptions">
        ///   F:ManagedBass.Errors.Device:
        ///     The device number specified is invalid.
        ///
        ///   F:ManagedBass.Errors.Already:
        ///     The device has already been initialized. You must call ManagedBass.Bass.Free
        ///     before you can initialize it again.
        ///
        ///   F:ManagedBass.Errors.Driver:
        ///     There is no available device driver... the device may already be in use.
        ///
        ///   F:ManagedBass.Errors.SampleFormat:
        ///     The specified format is not supported by the device. Try changing the Frequency
        ///     and Flags parameters.
        ///
        ///   F:ManagedBass.Errors.Memory:
        ///    There is insufficient memory.
        ///
        ///   F:ManagedBass.Errors.No3D:
        ///     The device has no 3D support.
        ///
        ///   F:ManagedBass.Errors.Unknown:
        ///     Some other mystery problem!
        /// </exception>
        /// 
        /// <param name="Flags">
        ///     Any combination of ManagedBass.DeviceInitFlags.
        /// </param>
        ///<remarks>
        ///     This function must be successfully called before using any sample, stream or
        ///     MOD music functions. The recording functions may be used without having called
        ///    this function.
        ///     Playback is not possible with the ManagedBass.Bass.NoSoundDevice device, but
        ///     it does allow the use of "decoding channels", eg. to decode files.
        ///     When specifying a class identifier (ClsID), after successful initialization,
        ///     you can use GetDSoundObject(DSInterface) to retrieve the DirectSound object,
        ///     and through that access any special interfaces that the object may provide.
        ///     Simultaneously using multiple devices is supported in the BASS API via a context
        ///     switching system - instead of there being an extra "device" parameter in the
        ///     function calls, the device to be used is set prior to calling the functions.
        ///     ManagedBass.Bass.CurrentDevice is used to switch the current device. When successful,
        ///     ManagedBass.Bass.Init(System.Int32,System.Int32,ManagedBass.DeviceInitFlags,System.IntPtr,System.IntPtr)
        ///     automatically sets the current thread's device to the one that was just initialized.
        ///     When using the default device (device = -1), ManagedBass.Bass.CurrentDevice can
        ///     be used to find out which device it was mapped to. On Windows, it'll always be
        ///     the first device.
        ///     Platform-specific
        ///     On Linux, a 'Default' device is hardcoded to device number 1, which uses the
        ///     default output set in the ALSA config; that could map directly to one of the
        ///     other devices or it could use ALSA plugins. If the IncludeDefaultDevice config
        ///     option has been enbled, a "Default" device is also available on Windows, who's
        ///     output will follow default device changes on Windows 7. In both cases, the "Default"
        ///     device will also be the default device (device = -1).
        ///     The sample format specified in the Frequency and Flags parameters has no effect
        ///     on the device output on iOS or OSX, and not on Windows unless VxD drivers are
        ///     used (on Windows 98/95); with WDM drivers (on Windows XP/2000/Me/98SE), the output
        ///     format is automatically set depending on the format of what is played and what
        ///     the device supports, while on Vista and above, the output format is determined
        ///     by the user's choice in the Sound control panel. On Linux the output device will
        ///     use the specified format if possible, but will otherwise use a format as close
        ///     to it as possible. If the ManagedBass.DeviceInitFlags.Frequency flag is specified
        ///     on iOS or OSX, then the device's output rate will be set to the freq parameter
        ///     (if possible). The ManagedBass.DeviceInitFlags.Frequency flag has no effect on
        ///     other platforms. ManagedBass.Bass.GetInfo(ManagedBass.BassInfo@) can be used
        ///     to check what the output format actually is.
        ///     The Win and ClsID parameters are only used on Windows and are ignored on other
        ///     platforms. That applies to the ManagedBass.DeviceInitFlags.CPSpeakers and ManagedBass.DeviceInitFlags.ForcedSpeakerAssignment
        ///     flags too, as the number of available speakers is always accurately detected
        ///     on the other platforms. The ManagedBass.DeviceInitFlags.Latency flag is also
        ///     ignored on Linux/OSX/Android/Windows CE, as latency information is available
        ///     without it. The latency is also available without it on iOS, but not immediately
        ///     following this function call unless the flag is used.
        ///     The DeviceInitFlags.DMix flag is only available on Linux, and allows multiple
        ///     applications to share the device (if they all use 'dmix'). It may also be possible
        ///     for multiple applications to use exclusive access if the device is capable of
        ///     hardware mixing. If exclusive access initialization fails, the DeviceInitFlags.DMix
        ///     flag will automatically be tried; if that happens, it can be detected via ManagedBass.Bass.GetInfo(ManagedBass.BassInfo@)
        ///     and the ManagedBass.BassInfo.InitFlags.
        ///     On Linux and Windows CE, the length of the device's buffer can be set via the
        ///     ManagedBass.Bass.PlaybackBufferLength config option.
        ///</remarks>    
        [DllImport(BASS_lib, CallingConvention = CallingConvention.StdCall)]
        internal static extern bool BASS_Init(int Device = -1, int Frequency = 44100, DeviceInitFlagsClass.DeviceInitFlags Flags = DeviceInitFlagsClass.DeviceInitFlags.Default, IntPtr Win = default, IntPtr ClsID = default);
        [DllImport(BASS_lib, CallingConvention = CallingConvention.StdCall, CharSet = CharSet.Ansi)]
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
        internal static extern int BASS_StreamCreateFile(bool mem, string File, long Offset, long Length, BassFlagsClass.BassFlags Flags = BassFlagsClass.BassFlags.Unicode);
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
        internal static extern bool BASS_ChannelPlay(int Handle, bool Restart = false);
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
        internal static extern bool BASS_StreamFree(int Handle);
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
        internal static extern bool BASS_Free();
        [DllImport(BASS_lib, CallingConvention = CallingConvention.StdCall)]
        //
        // Summary:
        //     Translates a time (seconds) position into bytes, based on a channel's format.
        //
        // Parameters:
        //   Handle:
        //     The channel Handle... a HCHANNEL, HMUSIC, HSTREAM, or HRECORD. HSAMPLE handles
        //     may also be used.
        //
        //   Position:
        //     The position to translate (in seconds, e.g. 0.03 = 30ms).
        //
        // Returns:
        //     If successful, then the translated Length in Bytes is returned, else -1 is returned.
        //     Use ManagedBass.Bass.LastError to get the error code.
        //
        // Exceptions:
        //   F:ManagedBass.Errors.Handle:
        //     Handle is not a valid channel.
        //
        // Remarks:
        //     The translation is based on the channel's initial sample rate, when it was created.
        //     The return value is rounded down to the position of the nearest sample.
        internal static extern long BASS_ChannelSeconds2Bytes(int Handle, double Position);
        [DllImport(BASS_lib, CallingConvention = CallingConvention.StdCall)]
        //
        // Summary:
        //     Retrieves the decoding/download/end position of a file stream.
        //
        // Parameters:
        //   Handle:
        //     The stream's handle.
        //
        //   Mode:
        //     The file position to retrieve. One of ManagedBass.FileStreamPosition values.
        //
        // Returns:
        //     If succesful, then the requested file position is returned, else -1 is returned.
        //     Use ManagedBass.Bass.LastError to get the error code.
        //
        // Exceptions:
        //   F:ManagedBass.Errors.Handle:
        //     Handle is not valid.
        //
        //   F:ManagedBass.Errors.NotFile:
        //     The stream is not a file stream.
        //
        //   F:ManagedBass.Errors.NotAvailable:
        //     The requested file position/status is not available.
        //
        // Remarks:
        //     ID3 tags (both v1 and v2) and WAVE headers, as well as any other rubbish at the
        //     start of the file, are excluded from the calculations of this function.
        //     This is useful for average bitrate calculations, but it means that the ManagedBass.FileStreamPosition.Current
        //     position may not be the actual file position - the ManagedBass.FileStreamPosition.Start
        //     position can be added to it to get the actual file position.
        //     When streaming a file from the internet or a "buffered" user file stream, the
        //     entire file is downloaded even if the audio data ends before that, in case there
        //     are tags to be read. This means that the ManagedBass.FileStreamPosition.Download
        //     position may go beyond the ManagedBass.FileStreamPosition.End position.
        //     It's unwise to use this function (with mode = ManagedBass.FileStreamPosition.Current)
        //     for syncing purposes because it returns the position that's being decoded, not
        //     the position that's being heard. Use ManagedBass.Bass.ChannelGetPosition(System.Int32,ManagedBass.PositionFlags)
        //     for syncing instead.
        internal static extern long BASS_StreamGetFilePosition(int Handle, FileStreamPositionClass.FileStreamPosition Mode = FileStreamPositionClass.FileStreamPosition.Current);
        [DllImport(BASS_lib, CallingConvention = CallingConvention.StdCall)]
        //
        // Summary:
        //     Retrieves the playback position of a sample, stream, or MOD music. Can also be
        //     used with a recording channel.
        //
        // Parameters:
        //   Handle:
        //     The channel Handle... a HCHANNEL, HMUSIC, HSTREAM, or HRECORD.
        //
        //   Mode:
        //     How to retrieve the position
        //
        // Returns:
        //     If an error occurs, -1 is returned, use ManagedBass.Bass.LastError to get the
        //     error code. If successful, the position is returned.
        //
        // Exceptions:
        //   F:ManagedBass.Errors.Handle:
        //     Handle is not a valid channel.
        //
        //   F:ManagedBass.Errors.NotAvailable:
        //     The requested position is not available.
        //
        //   F:ManagedBass.Errors.Unknown:
        //     Some other mystery problem!
        //
        // Remarks:
        //     With MOD music you might use the ManagedBass.BitHelper.LoWord(System.Int32) and
        //     ManagedBass.BitHelper.HiWord(System.Int32) methods to retrieve the order and
        //     the row values respectively.
        internal static extern long BASS_ChannelGetPosition(int Handle, PositionFlagsClass.PositionFlags Mode = PositionFlagsClass.PositionFlags.Bytes);
        [DllImport(BASS_lib, CallingConvention = CallingConvention.StdCall)]
        //
        // Summary:
        //     Gets or sets the current output master volume level... 0 (silent) to 1 (max).
        //
        // Exceptions:
        //   F:ManagedBass.Errors.Init:
        //     ManagedBass.Bass.Init(System.Int32,System.Int32,ManagedBass.DeviceInitFlags,System.IntPtr,System.IntPtr)
        //     has not been successfully called.
        //
        //   F:ManagedBass.Errors.NotAvailable:
        //     There is no volume control when using the No Sound Device.
        //
        //   F:ManagedBass.Errors.Parameter:
        //     Invalid volume.
        //
        //   F:ManagedBass.Errors.Unknown:
        //     Some other mystery problem!
        //
        // Remarks:
        //     When using multiple devices, the current thread's device setting (as set with
        //     ManagedBass.Bass.CurrentDevice) determines which device this function call applies
        //     to.
        //     A return value of -1 indicates error. Use ManagedBass.Bass.LastError to get the
        //     error code. Throws ManagedBass.BassException on Error while setting value.
        //     The actual volume level may not be exactly the same as set, due to underlying
        //     precision differences.
        //     This function affects the volume level of all applications using the same output
        //     device. If you wish to only affect the level of your app's sounds, ManagedBass.Bass.ChannelSetAttribute(System.Int32,ManagedBass.ChannelAttribute,System.Single)
        //     and/or the ManagedBass.Bass.GlobalMusicVolume, ManagedBass.Bass.GlobalSampleVolume
        //     and ManagedBass.Bass.GlobalStreamVolume config options should be used instead.
        internal static extern double BASS_SetVolume(float value);
        [DllImport(BASS_lib, CallingConvention = CallingConvention.StdCall)]
        //
        // Summary:
        //     Gets or sets the current output master volume level... 0 (silent) to 1 (max).
        //
        // Exceptions:
        //   F:ManagedBass.Errors.Init:
        //     ManagedBass.Bass.Init(System.Int32,System.Int32,ManagedBass.DeviceInitFlags,System.IntPtr,System.IntPtr)
        //     has not been successfully called.
        //
        //   F:ManagedBass.Errors.NotAvailable:
        //     There is no volume control when using the No Sound Device.
        //
        //   F:ManagedBass.Errors.Parameter:
        //     Invalid volume.
        //
        //   F:ManagedBass.Errors.Unknown:
        //     Some other mystery problem!
        //
        // Remarks:
        //     When using multiple devices, the current thread's device setting (as set with
        //     ManagedBass.Bass.CurrentDevice) determines which device this function call applies
        //     to.
        //     A return value of -1 indicates error. Use ManagedBass.Bass.LastError to get the
        //     error code. Throws ManagedBass.BassException on Error while setting value.
        //     The actual volume level may not be exactly the same as set, due to underlying
        //     precision differences.
        //     This function affects the volume level of all applications using the same output
        //     device. If you wish to only affect the level of your app's sounds, ManagedBass.Bass.ChannelSetAttribute(System.Int32,ManagedBass.ChannelAttribute,System.Single)
        //     and/or the ManagedBass.Bass.GlobalMusicVolume, ManagedBass.Bass.GlobalSampleVolume
        //     and ManagedBass.Bass.GlobalStreamVolume config options should be used instead.
        internal static extern double BASS_GetVolume();//can be used to confirm what the value is.
        [DllImport(BASS_lib, CallingConvention = CallingConvention.StdCall)]
        //
        // Summary:
        //     Sets the value of an attribute of a sample, stream or MOD music.
        //
        // Parameters:
        //   Handle:
        //     The channel handle... a HCHANNEL, HMUSIC, HSTREAM or HRECORD.
        //
        //   Attribute:
        //     The attribute to set the value of.
        //
        //   Value:
        //     The new attribute value. See the attribute's documentation for details on the
        //     possible values.
        //
        // Returns:
        //     If successful, true is returned, else false is returned. Use ManagedBass.Bass.LastError
        //     to get the error code.
        //
        // Exceptions:
        //   F:ManagedBass.Errors.Handle:
        //     Handle is not a valid channel.
        //
        //   F:ManagedBass.Errors.Type:
        //     Attribute is not valid.
        //
        //   F:ManagedBass.Errors.Parameter:
        //     Value is not valid. See the attribute's documentation for the valid range of
        //     values.
        //
        // Remarks:
        //     The actual attribute value may not be exactly the same as requested, due to precision
        //     differences. For example, an attribute might only allow whole number values.
        //     ManagedBass.Bass.ChannelGetAttribute(System.Int32,ManagedBass.ChannelAttribute,System.Single@)
        internal static extern bool BASS_ChannelSetAttribute(int Handle, ChannelAttributeClass.ChannelAttribute Attribute, float Value);
        [DllImport(BASS_lib, CallingConvention = CallingConvention.StdCall)]
        //
        // Summary:
        //     Translates a byte position into time (seconds), based on a channel's format.
        //
        // Parameters:
        //   Handle:
        //     The channel Handle... a HCHANNEL, HMUSIC, HSTREAM, or HRECORD. HSAMPLE handles
        //     may also be used.
        //
        //   Position:
        //     The position in Bytes to translate.
        //
        // Returns:
        //     If successful, then the translated Length in seconds is returned, else a negative
        //     value is returned. Use ManagedBass.Bass.LastError to get the error code.
        //
        // Exceptions:
        //   F:ManagedBass.Errors.Handle:
        //     Handle is not a valid channel.
        //
        // Remarks:
        //     The translation is based on the channel's initial sample rate, when it was created.
        internal static extern double BASS_ChannelBytes2Seconds(int Handle, long Position);
        [DllImport(BASS_lib, CallingConvention = CallingConvention.StdCall)]
        //
        // Summary:
        //     Retrieves the playback Length of a channel.
        //
        // Parameters:
        //   Handle:
        //     The channel Handle... a HCHANNEL, HMUSIC, HSTREAM. HSAMPLE handles may also be
        //     used.
        //
        //   Mode:
        //     How to retrieve the Length (one of the ManagedBass.PositionFlags flags).
        //
        // Returns:
        //     If succesful, then the channel's Length is returned, else -1 is returned. Use
        //     ManagedBass.Bass.LastError to get the error code.
        //
        // Exceptions:
        //   F:ManagedBass.Errors.Handle:
        //     Handle is not a valid channel.
        //
        //   F:ManagedBass.Errors.NotAvailable:
        //     The Length is not available.
        //
        // Remarks:
        //     The exact Length of a stream will be returned once the whole file has been streamed,
        //     but until then it is not always possible to 100% accurately estimate the Length.
        //     The Length is always exact for MP3/MP2/MP1 files when the ManagedBass.BassFlags.Prescan
        //     flag is used in the ManagedBass.Bass.CreateStream(System.String,System.Int64,System.Int64,ManagedBass.BassFlags)
        //     call, otherwise it is an (usually accurate) estimation based on the file size.
        //     The Length returned for OGG files will usually be exact (assuming the file is
        //     not corrupt), but when streaming from the internet (or "buffered" User file),
        //     it can be a very rough estimation until the whole file has been downloaded. It
        //     will also be an estimate for chained OGG files that are not pre-scanned.
        //     Unless an OGG file contains a single bitstream, the number of bitstreams it contains
        //     will only be available if it was pre-scanned at the stream's creation.
        //     Retrieving the Length of a MOD music requires that the ManagedBass.BassFlags.Prescan
        //     flag was used in the ManagedBass.Bass.MusicLoad(System.String,System.Int64,System.Int32,ManagedBass.BassFlags,System.Int32)
        //     call.
        internal static extern long BASS_ChannelGetLength(int Handle, PositionFlagsClass.PositionFlags Mode = PositionFlagsClass.PositionFlags.Bytes);
        [DllImport(BASS_lib, CallingConvention = CallingConvention.StdCall)]
        //
        // Summary:
        //     Sets the playback position of a sample, MOD music, or stream.
        //
        // Parameters:
        //   Handle:
        //     The channel Handle... a HCHANNEL, HSTREAM or HMUSIC.
        //
        //   Position:
        //     The position, in units determined by the Mode.
        //
        //   Mode:
        //     How to set the position.
        //
        // Returns:
        //     If succesful, then true is returned, else false is returned. Use ManagedBass.Bass.LastError
        //     to get the error code.
        //
        // Exceptions:
        //   F:ManagedBass.Errors.Handle:
        //     Handle is not a valid channel.
        //
        //   F:ManagedBass.Errors.NotFile:
        //     The stream is not a file stream.
        //
        //   F:ManagedBass.Errors.Position:
        //     The requested position is invalid, eg. beyond the end.
        //
        //   F:ManagedBass.Errors.NotAvailable:
        //     The download has not yet reached the requested position.
        //
        //   F:ManagedBass.Errors.Unknown:
        //     Some other mystery problem!
        //
        // Remarks:
        //     Setting the position of a MOD music in bytes (other than 0) requires that the
        //     ManagedBass.BassFlags.Prescan flag was used in the ManagedBass.Bass.MusicLoad(System.String,System.Int64,System.Int32,ManagedBass.BassFlags,System.Int32)
        //     call. When setting the position in orders/rows, the channel's byte position (as
        //     reported by ManagedBass.Bass.ChannelGetPosition(System.Int32,ManagedBass.PositionFlags))
        //     is reset to 0. This is because it's not possible to get the byte position of
        //     an order/row position - it's possible that a position may never be played in
        //     the normal cause of events, or it may be played multiple times.
        //     When changing the position of a MOD music, and the ManagedBass.BassFlags.MusicPositionReset
        //     flag is active on the channel, all notes that were playing before the position
        //     changed will be stopped. Otherwise, the notes will continue playing until they
        //     are stopped in the MOD music. When setting the position in bytes, the BPM, "speed"
        //     and "global volume" are updated to what they would normally be at the new position.
        //     Otherwise they are left as they were prior to the postion change, unless the
        //     seek position is 0 (the start), in which case they are also reset to the starting
        //     values (when using the ManagedBass.BassFlags.MusicPositionReset flag). When the
        //     ManagedBass.BassFlags.MusicPositionResetEx flag is active, the BPM, speed and
        //     global volume are reset with every seek.
        //     For MP3/MP2/MP1 streams, unless the file is scanned via the ManagedBass.PositionFlags.Scan
        //     or the ManagedBass.BassFlags.Prescan flag at stream creation, seeking will be
        //     approximate but generally still quite accurate. Besides scanning, exact seeking
        //     can also be achieved with the ManagedBass.PositionFlags.DecodeTo flag.
        //     Seeking in internet file (and "buffered" User file) streams is possible once
        //     the download has reached the requested position, so long as the file is not being
        //     streamed in blocks ManagedBass.BassFlags.StreamDownloadBlocks.
        //     User streams (created with ManagedBass.Bass.CreateStream(System.Int32,System.Int32,ManagedBass.BassFlags,ManagedBass.StreamProcedure,System.IntPtr))
        //     are not seekable, but it is possible to reset a User stream (including its Buffer
        //     contents) by setting its position to byte 0.
        //     The ManagedBass.PositionFlags.DecodeTo flag can be used to seek forwards in streams
        //     that are not normally seekable, like custom streams or internet streams that
        //     are using the ManagedBass.BassFlags.StreamDownloadBlocks flag, but it will only
        //     go as far as what is currently available; it will not wait for more data to be
        //     downloaded, for example. ManagedBass.Bass.ChannelGetPosition(System.Int32,ManagedBass.PositionFlags)
        //     can be used to confirm what the new position actually is.
        //     In some cases, particularly when the ManagedBass.PositionFlags.Inexact flag is
        //     used, the new position may not be what was requested. ManagedBass.Bass.ChannelGetPosition(System.Int32,ManagedBass.PositionFlags)
        //     can be used to confirm what the new position actually is.
        //     The ManagedBass.PositionFlags.Scan flag works the same way as the ManagedBass.Bass.CreateStream(System.String,System.Int64,System.Int64,ManagedBass.BassFlags)
        //     ManagedBass.BassFlags.Prescan flag, and can be used to delay the scanning until
        //     after the stream has been created. When a position beyond the end is requested,
        //     the call will fail (ManagedBass.Errors.Position error code) but the seek table
        //     and exact Length will have been scanned. When a file has been scanned, all seeking
        //     (even without the ManagedBass.PositionFlags.Scan flag) within the scanned part
        //     of it will use the scanned infomation.
        internal static extern bool BASS_ChannelSetPosition(int Handle, long Position, PositionFlagsClass.PositionFlags Mode = PositionFlagsClass.PositionFlags.Bytes); // seek to start position
        public void Dispose()
        {
            throw new NotImplementedException();
        }
    }
}
