
                ---------------------------
                ModPlug Player User's Guide
                ---------------------------


-----------------------------------------------------------------
                 HOW TO USE MODPLUG PLAYER ?
-----------------------------------------------------------------
[SOFTWARE INFORMATION]
ModPlug Player is intended for public domain distribution only.
I am not responsible for any problems that could be caused by
the usage of this program.

[SYSTEM REQUIREMENTS]
- 486DX2-66 minimum (Pentium 100MHz highly recommended).
- Windows 95, Windows 98 or Windows NT 3.51 or higher.
- A soundcard with 32-bit drivers.

[CONTACT]
The best place to get the latest news for ModPlug Player is at
ModPlug Central: "http://www.modplug.com".
For any technical questions, or bug report, you can contact me at
"olivier@modplug.com" (I speak both French and English), or even
better, post your questions in the Modplug Central forums.

[TECHNICAL INFORMATION]
ModPlug Player is a 32-bit Windows 95/NT4 application, currently
not using any hardware acceleration, but featuring a lot of options
to create the best possible output (Up to 48KHz, 16-bit, stereo):
- 32-bit internal precision for mixing, dithered to 16-bit.
- High quality resampling filter.
- Automatic click removal.
- Digital Bass Expansion digital low-pass filter (filter range and depth
  customizable in Advanced Player Options)
- Dolby Pro-Logic Surround support (and it's not only negating the right
  channel) with custom delay and 100Hz-7KHz filter depth.
- Reverb Option (not echo), much better since v1.41.01
- Noise Reduction: attenuation of the very high requencies in the sound.
- Stereo Separation option (25%-400%), useful for headphones.
- 40-bands (Or 2x 19-bands) fourier spectrum analyzer, and VU-Meter.

=============================================================================

SETUP:
------

  Clicking on the Setup button will bring a 4 property pages
  dialog:

  - Soundcard Setup / Soundcard Advanced Setup:
  ---------------------------------------------
    * Mixing quality:
      Select the output quality (A CD-ROM is 44.1KHz).
      If you don't want to take too much CPU, 32KHz is a good
      compromise between CPU and audio quality.
      A 32-channels IT module played at 48KHz,stereo can take up
      to 100% of the CPU on a DX2-66 (Especially with Spectrum Analyzer).
      Note: I noticed that 48KHz output can create noise on some
      sound cards, because the hardware is downsampling it to 44.1KHz.
      In this case 44.1KHz is much better (Come on, it's only 4KHz
      difference, you don't need to upgrade your sound card).

    * Stereo:
      This will create a stereo output.
      Playing in mono takes slightly less CPU than in stereo.
      You need to have the stereo option enabled to hear panning
      effects and surround sound.

    * 16-Bit:
      You are strongly advised to use this option, unless your
      soundcard doesn't support stereo playback.
      Playing in 8-bit mode doesn't decrease the CPU usage.

    * Sound buffer length and Number of buffers:
      This option configure the size of the buffer sent to the soundcard.
      (Total length = SoundBufferLength*NumberOfBuffers milliseconds)
      If you are using a small buffer, the player will respond faster
      when you change the player options or move the Pre-Amp slider.
      At the same time, if the PC is very busy in a multitasking
      environment, the sound may get cut from time to time.
      The buffer length must be between 50ms and 250ms.
      The bigger the buffer length, the slower the spectrum analyzer will
      be updated.
      The default settings should work fine, but you may want to increase
      it if you are using CPU-intensive applications, or decrease it if
      you have a very fast PC.

    * Stereo Separation:
      This allows you to control the stereo separation between right and
      left channel. You may want to decrease it with headphones, or increase
      it to feel a stronger stereo. This works only in stereo mode.

    * Maximum Mixing Channels:
      This allows you to control the CPU usage of ModPlug, by limiting the
      number of channels simultaneously playing. It can make a big difference
      in CPU with IT modules using NNA effects. Typically, most modules
      (MOD/S3M and XM) don't go over 16 simultaneous channels, and IT modules
      usually don't go over 32 simultaneous channels. But mixing 32
      simultaneous channels can take 100% of the CPU on a 486DX4-100,
      especially if you're using MultiPoint oversampling, or other DSP
      effects. This option will automatically take care of this problem.

    * Use Function Callback:
      Some drivers (and most Windows NT drivers) don't support the thread
      callback option: in this case, you will hear about half a second of
      sound and it will stop. If this happens, check this box.
      (ModPlug auto-detect NT, and check it under Windows NT)

    * Real-Time Priority:
      This option enables you to control if ModPlug uses a real-time thread
      or a regular high-priority thread. Depending on your sound driver, it
      may improve the response of the player when running in the background.
      Since, v1.25, it also changes the priority of the ModPlug Player process,
      and it should not drop sound anymore with this option enabled.
      I recommend using this option. If you don't have at least a Pentium 133MHz,
      you should use the "Limit CPU usage" combined with this option, or else
      ModPlug could slow down the computer so that it's almost impossible to
      stop the player.

    * Use MMX acceleration:
      This checkbox is grayed if your processor doesn't support the Intel MMX
      instruction set. Note that the player may not take a lot less CPU with
      this option enabled on Pentium II processors, because the multipoint
      resampling will be used more often for slightly better quality, and P2
      have a very fast non-MMX integer multiply. Also, MMX doesn't accelerate
      32-bit operations very well, so the difference in speed may be very small
      for high quality sound mixing. This will also enable SSE/3DNow optimizations
      for P3 and AMD processors.

    * Use DirectSound Secondary buffers:
      This mode is only intended for compatibility problems. If directsound
      doesn't work, you can try to enable this option to see if it's better.
      But if you're using a non-accelerated sound card, directsound is likely
      to output everything at 22KHz using a crappy resampling :(

    Note: If you choose a setting that your soundcard doesn't support,
      the player will ignore it.

  - Player Setup:
  ---------------

    * Spectrum analyzer:
      When this option is checked, ModPlug Player will display the frequency
      spectrum of the sound (using Fourier analyzis). This takes more CPU and
      doesn't affect the quality of the sound. When the player window is behind
      another window or is minimized, the spectrum is not calculated and doesn't
      take any CPU. The frequencies in the spectrum display range from 86Hz
      to 11KHz (There is up to 40-bands). It takes about 15-20% of the CPU on
      a fast Pentium machine, so you shouln't use it with a 486.

    * Stereo Spectrum:
      When this option is checked, together with the Spectrum Analyzer, the
      player will display one spectrum for the left and right channels.
      (In this case, there is 2x19 bands in the spectrum, and the range
      for each channel is from 86Hz to 8KHz). It doesn't take more CPU than
      the mono spectrum analyzer. (You need to play in stereo mode to use this
      option, or else you'll see the same on each channels, duh!)

    * Reverb:
      This will create a reveration effect on the sound.
      You can change the reverb preset, and the reverb level (actually more
      of a Dry/Wet mix depending on the preset).
      Note that the reverberation engine has been completely redesigned
      in v1.45, and it now works only on MMX processors.

    * Pro-Logic Delayed Surround:
      This options sends part of the the sound to the Dolby Pro-Logic
      Surround channel (center + rear speakers) with a delay of about 5
      to 50ms, filtering frequencies from 100Hz to 7KHz. This option works
      only with Stereo enabled. You can change the surround depth and delay
      in the Advanced Player Setup.

    * Noise Reduction:
      Use this option only at 44.1KHz or 48KHz, or else it will filter
      all the high frequencies. It's basically a -3dB lowpass filter running
      at Fs/4 (Fc=11kHz at 44kHz). I really don't recommend using this, but
      it seems some people like it, so that's the only reason why it's still
      here.

    * Bass Expansion:
      This option will make the player doing up to 20dB bass amplification.
      It takes a little bit more CPU, but not that much.
      If you like low frequencies, or just want to upset your neighbour,
      that's the option you'll need. You can change the XBass level and
      range in the Player Setup.

    * Disable Resampling:
      I don't recommend using this option, but I had request from people to
      put it back. The player will be much faster, but no resampling is
      performed, so the quality is pretty bad, creating very high frequencies
      in the signal.

    * Use high-quality resampling:
      You shouldn't use this option on a slow CPU if you're working on other
      applications in the background, because it takes much more CPU.
      On the other hand, using the high quality resampling filter improves a lot
      the quality of the sound. (Useful when recording WAV files).
      By default , the player is using a 256x linear interpolation to create
      a smooth sound. At the same time, linear interpolation decreases
      a the magnitude of the high frequencies, and creates high-frequency
      aliasing.

    * Use Volume Ramping:
      This option doesn't take much more CPU, and instead of jumping from one
      volume to the other, the player will use a volume ramping at the start
      and end of a note, which will remove most of pops and clicks in the sound.
      It will also ramp all volume changes (including volume envelopes), for a
      delay of about 2 milliseconds (very fast), so that no clicks can be created,
      but without slowing down the volume changes.
      NOTE: This is no more an option since v1.36.03: it is always ON.

    * Graphic Equalizer:
      This option is available only on Pentium-Class CPUs, since it uses
      floating-point arithmetic, and I recommend it only for Pentium-II owners.
      I personally always use the 'Clear' preset, since it improves a lot the
      quality of higher frequencies, usually attenuated by the resampler.
      It uses 6 different bandpass filters. Note that you can select the
      senter frequency for each band by right-clicking on the slider.

    * Automatic Gain Control:
      When you open a module with this option enabled, the player will adjust
      the global volume so that there is no clipping, even when the pre-amp
      slider is to the maximum. It can give a better Signal/Noise ratio (SNR).

    * Limit Play Time:
      Enter the maximum playing time of a song (in seconds) before the
      player jumps to the next song. You can also enable/disable the 
      Intro (or Time Limit) mode by the right-click menu.


  - Directories:
  --------------

      * Songs Directory:
        You can enter the path where your mods are located, and the
        player will automatically go to this directory when running.

      * Register Extensions:
        This makes Windows use ModPlug player as the default player
        for all the modules recognized. After clicking this button,
        you can open a song just by double-clicking it in the Windows
        Explorer. If "Use DDE" is selected, each time you open a mod
        it will stay in the same window, or else Windows will open
        another ModPlug Player Window.

      * Clear PlayList When...
        The playlist can be automatically cleared each time you Drag&Drop
        Files in the player window, or when you use the open button.
        (It's always cleared if you open a .MOL file)


  - Plug-ins:
  -----------

      This option allows you to use plug-ins originally made for WinAmp
      (MPEG layer3 Player) with ModPlug Player.
      You have to manually locate one of more plugin libraries.
      The priority option allows you to control the priority of the plugin
      (So it doesn't take too much CPU)
      WARNING:
      * Some plug-ins using DirectDraw won't work while the player is
      using DirectSound, in this case, use a regular Wave Device.
      * Some plug-ins require to be installed in the same directory than
      the player (modplug.exe), so you can either copy modplug.exe in your
      winamp directory, or install a second copy of the plugin in the same
      directory than the player (This is necessary for the Cthugha Plug-in).


  - Packing (now in the Details window):
  --------------------------------------

      The slider allows you to control the quality of packing for the
      Pack As command, and give you information about which samples
      would be packed in the current song. The compression used to pack
      the samples is ADPCM, which can make the file size twice smaller.
      If the compression quality is low, more samples will be packed,
      but you may lose quality. If the compression quality is high, you
      probably won't lose any quality, but less samples will be packed.
      Only use this option if you want to reduce download time for the
      Mod-plugin on a web page, where download time is more important than
      quality (like for a preview of a song).

OPEN:
-----
  Opens a file or a module list.
  The following file types are supported in the current version:
    - *.669: UNIS 669, 669 Composer modules.
    - *.AMS: Velvet Studio AMS 1.x modules.
    - *.AMF: Asylum / DSMI modules.
    - *.DBM: DigiBooster Pro modules.
    - *.DMF: X-Tracker modules.
    - *.DSM: DSIK internal format modules.
    - *.FAR: Farandole Composer modules (beta).
    - *.IT:  Impulse Tracker modules.
    - *.MED: OctaMed modules.
    - *.MDL: DigiTracker 1.x modules.
    - *.MOD: ProTracker modules (4-32 channels, 15/31 samples).
    - *.MOL: Module lists, compatible with MOD4WIN.
    - *.MTM: MultiTracker modules.
    - *.NST: NoiseTracker modules.
    - *.OKT: OktaLyser modules.
    - *.PSM: ProTracker Studio modules.
    - *.PTM: PolyTracker modules.
    - *.S3M: ScreamTracker III modules.
    - *.STM: ScreamTracker II modules.
    - *.ULT: UltraTracker modules.
    - *.UMX: Musics from Unreal and Unreal Tournament
    - *.WOW: Grave Composer modules.
    - *.XM:  FastTracker modules.
    - *.WAV: Wave Files (smaller than 16MB).
    - All the above when zipped (*.MDZ, *.S3Z, *.XMZ, *.ITZ, *.ZIP).
    - All of the above then compressed with RAR (*.MDR, *.RAR)
    - All of the above when compressed with LHA (Amiga archives)

INFO:
-----
  This button will make the song information (comments and sample names)
  scroll in the LCD display.

ABOUT:
------
  Shows the current version of ModPlug Player.

REPEAT:
-------
  This button will cause the song to play again. If you click 4 times
  on this button, the song will be repeated indefinitely.
  The repeat count is displayed in the LCD screen.

SHUFFLE:
--------
  This button will cause a random song to be played after the current one.

EDIT:
-----
  This button will bring a dialog allowing you to edit the playing list.
  You can double-click in the list to activate a song.

SAVE AS:
--------
  This button will save the current song under a new name. You can use it
  to unpack/unzip a module, or to convert to a new format.

SAVE WAV:
---------
  This button will create a .WAV file using the current song, and all the
  current player settings.

PACK AS:
--------
  This button allows to save a module and pack the samples with ADPCM
  compression. Most players won't recognize the song anymore, but you
  can use it as a module in a Web page: it will be faster to download it.
  You can also ZIP the saved file to make it even smaller.
  If you want to unpack a previously packed module, just use the regular
  Save As button.

DETAILS:
--------
  This will bring a window displaying more details about the song being
  played. Note that if the song changes while this window is open, you will
  have the information of the current song and the information of the new
  song mixed up (Sorry about that).

SAVE LIST:
----------
  This button saves the current playing list, as a .MOL file.

CLR LIST:
---------
  This button is clearing the current playing list.

REMOVE:
-------
  This button removes the current song from the list. The file is not erased
  from the disk. You should use Ctrl+D if you want to remove the file from
  the disk.

-----------------------------------------------------------------
                       SHORTCUT KEYS
-----------------------------------------------------------------

A:         AGC On/Off
E:         EQ On/Off
I:         Scroll Song Info
M:         Switch between Mono/Stereo
P:         Play/Pause
R:         Reverb On/Off
S:         Surround On/Off
X:         Bass Expansion On/Off
Ctrl+D:    Delete the current file (useful to remove crappy mods)
Ctrl+K:    Start/Stop plugin.
Ctrl+L:    Show Playlist Window
Ctrl+M:    Show ModPlug Mixer Window
Ctrl+O:    Open a file
Ctrl+S:    Save the current file
Ctrl+W:    Save as Wave
Del:       Remove the current file from the playing list
Shift+Del: Clear the playing list
Space:     Jump to next song
ESC:       Stop/Exit
F1:        About
<-         Previous Pattern
->         Next Pattern
Ctrl + ->  Next Song
Ctrl + <-  Prev Song
Ctrl+N     Next Song

-----------------------------------------------------------------
                 FREQUENTLY ASKED QUESTIONS
     (I'm tired of answering the same emails over and over)
-----------------------------------------------------------------

Q: The channel display is buggy: sometimes it writes 05/04 channels!
A: This is not a bug. The internal click-removal never cuts channels
   but fade them down for 2 milliseconds, so this adds channels to be
   mixed. Also, with IT NNA effects, you can mix a lot more channels.
   The first number is the current average polyphony (on 1 sec). The
   second number is the number of channels in the song.

Q: Sometimes, the Details window displays something like 100 patterns,
   and says than 150 are different!
A: This isn't a bug either (I should amke this text more clear): it means
   that there is 100 patterns (music blocks) played in the song, but 150
   are saved in the file: i.e. 100 of them are not used (hidden patterns?).

Q: How do I uninstall Modplug Player, or the Mod-Plugin ?
A: Find the file "modplug.exe" and drag it to the recycle bin.
   Remove also this file: readme.txt, that should be in the same folder.
   Modplug saves its settings in the registry, under the following key:
   "HKEY_CURRENT_USER\Software\Olivier Lapicque\Modplug Player"
   For the plugin, find the file "NPMOD32.DLL", and send it to the
   recycle bin.

Q: What language did you use to program ModPlug Player ?
A: C++, and a little bit of inline assembly (asm for MMX, EQ and the C parts
   where the compiler really sucked).

Q: I have a non-MMX Cyrix P166, how come the Equalizer is disabled ?
A: Like 486s, most Cyrix processors do not have a good enough floating point
   performance to perform the EQ (Come on! time to get a K6-2 or P2).
   (You should be able to test it by selecting an EQ preset, and then use the
   'E' shortcut, but it will be disabled each time you go back to the setup
   screen - but believe me, you'll quickly turn it back off when you'll see
   your CPU usage jump to 95%)

Q: Do you speak french ?
A: Yes. I am originally from France, but I'm now living in the SF Bay area in
   California.

Q: When I save a file under a different format, it sounds really different.
A: Don't convert between different file formats using Modplug Player: it is
   much better done using Modplug Tracker. Also: don't convert anything recent
   to a MOD, since you'll lose most of the effects, instrument envelopes, and
   all samples will be converted to 8-bit and truncated to 64KB.

Q: I can't get the player to pan 100% left or 100% right
A: Reverb, Surround and Bass Expansion create feedback from one channel to
   the other.

-----------------------------------------------------------------
                       VERSION HISTORY

   Get the latest version at "http://www.modplug.com"
-----------------------------------------------------------------
1.46.02:
--------
- Fixed DX Media Audio Effects support on Windows XP
- Fixed loading of stereo samples in XM files.

1.46:
-----
- Updated sound device handling (less chance of dropping audio)
- Support modules with up to 1000 samples.
- EQ optimizations for 3DNow! and SSE.
- Increase max mixing channels from 128 to 200.

1.45:
-----
- Improved MMX processing for resonant filters
- Added MDL v0.0 loader (previously supported only v1.0+)
- MMX HQ mixer slightly faster (about 10%)
- New improved reverb engine, more presets, but MMX only (sorry for 486 owners).
- Show full path option in playlist window
- Support for underscores in email addresses
- Another XPK fix
- New extended filter mode for MPT v1.13+
- Fix for XPK-packed mods possible crash
- Fixed Save As Wave

1.44:
-----
- Minor IT chiptunes portamento accuracy fixes
- Added support for mod files packed with SQSH or PP20
- Added EMail artist feature
- Added no mouse wheel option
- Bass Expansion now includes automatic DC removal
- Fixed IT retrig+portamento combination
- Added support for filters with stereo samples

1.43:
-----
- New high quality resampling mode
- Improved AMF and DMF loaders
- New higher quality bass expansion
- Added support for stereo samples
- Minor sound engine enhancements and compatibility fixes

1.42:
-----
- Fixed IT filter cutoff range compatibility
- Fixed DMF loader
- Fixed effect bug in MED:MMD0 playback
- Added headphones option (softer panning)
- Fixed tuning of very small bidirectional loops
- Added PSM loader
- All new much improved high quality resampler
- Fixed possible GPF with extremely high pitch on very large samples
- Improved surround
- Fixed UMX loader (Unreal and Unreal Tournament music)
- Made playlist looping optional
- Added directory context menu option
- Fixed possible crash when loading modules (due to the new LHA loader)
- Added support for LHA-compressed modules (Aminet anyone?)
- Completely new, improved reverb (a bit slower: 3-4% on a P2-333)
- Fixed pan/volume random variation (pan/vol swing)

1.41:
-----
- Added customizable EQ presets
- Added an extra EQ band
- Fixed HUGE bidirectional loop bug of 1.40.04
- Fixed IT compatibility problem with sample vibrato
- Fixed FT2 compatibility problem with effect 9xx (Offset)
- Added AMF loader
- Accepts UNC network file names in playlist
- Added 96 channels max. polyphony option for MMX CPUs
- Improved MED support

1.40:
-----
- New improved setup screen (MPT-like).
- Added support for IT "Carry Envelope" flag.
- Added "Add to playlist" shell command.
- Added AGC indicator
- More optimizations for resonant filters.
- Details window can be closed by pressing <ESC>
- Zxx macro bugfix for better IT compatibility.
- Fixed bug with some visualization plugins (plugin would sometimes stop)
- Improved a lot handling of IT filter envelopes.
- Fixed UMX loader for IT modules.
- Loads mod4win playlists with multiple directories.
- Snap to viewport doesn't hide the player under the taskbar anymore.
- Fixed setup dialog: wasn't showing with Win95 versions older than OSR1 or NT 3.51
- Fixed channels VU-Meters in the mixer window
- Added beta AMS 2.2 loader
- Fixed some special cases where pattern loops were ignored in the initial 1.39

1.39:
-----
- Mostly a compilation of all patches for 1.38.0x, including, minor FT2/IT
  compatibility improvements.
- Added pattern position display.
- Fixed repeat bug (wasn't always repeating in the initial 1.38.03).
- Improved memory management so there is less memory fragmentation after
  playing for long hours in Win95 (Win98 and NT have a much better memory
  manager).
- Fixed most FT2 compatibility problems.
- Fixed playlist not saved when exiting windows (that's about time, I know)
- Added check for valid backward jumps in a same pattern (allow playing backwards)
- Fixed special case of the pattern loop for FT2 compatibility.
- Fixed WAV writer when normalizing - this was broken in 1.38.01
- Fixed lost of audio when switching apps with secondary buffers.
- Added Open and PlayList in the contextual menu when in titlebar mode.
- Playlist bug fix: files in the root directory where ignored.
- Added support for Mouse Wheel (as a volume control)
- Fixed mouse problem when dragging position slider
- Added DSM Loader

1.38:
-----
- Show the correct text in the info scroller for XM modules.
- Fixed IT panning slide effect (left/right were reversed)
- Fixed possible GPF when loading files in the second player window (mixer)
- Fixed wrong behavior of S3M/IT retrig continue Q00 in some cases.
- Improved interpolation accuracy of pitch envelopes.
- Added the mini-titlebar mode (button between minimize and close).
- Improved ULT loader.
- Fixed XM Set Envelope Position when used past the volume sustain point.
- Fixed IT Instrument Pitch/Pan Separation.
- Fixed possible noise in the MMX resampler in some rare cases.
- Improved a lot the IT resonant filters.
- Added Delete shortcut in the playlist editor (to remove songs from the list)
- Tremor Fix: ontime and offtime were reversed in 1.37
- Fixed XM/MOD Amiga Retrig (E9x) effect.
- Added loader for DigiBooster Pro (DBM) modules.
- Fixed tempo bug in 669/MTM/FAR modules.
- Improved the resampler by using a different algorithm in the range
  [Fs/2, Fs*2], so that less low-pass filtering occurs.

1.37:
-----
- Loads STM modules converted from MODs by the bmod2stm utility
- Removed the 'Volume Ramping' option (now always enabled).
- Added 5-bands Graphic Equalizer (pentium minimum, since it uses floating point)
  (The 'Clear' preset is probably the best one)
- You can now select the file extensions registered by Modplug Player.
- Added beta AMS 1.x support
- Fixed Tremor and Retrig (they behave differently for XM and IT modules)
- Fixed envelope-reset problem in FT2 modules
- Fixed Tremor bug when ontime+offtime is bigger than the number of frames/row
- Changed the system tray icons, so that only one click is needed for action
- Fixed tone-portamento (partially broken since 1.36 in XM/IT)
- Fixed problem loading some S3M modules (channels muted)
- Added double-click on XBass/Surround/Reverb for easy switch

1.36:
-----
- Fixed volume slides in S3M/IT (D0F & DF0 commands)
- Added IT filter envelope support
- Fixed panning/pitch envelope loop bug
- Added support for IT Resonant Filters (Zxx)
- Improved MDL support (more effects & support for envelopes).
- Fixed sample change bug in some MOD modules
- Fixed panning bug when playing WAV files
- Improved conversion between XM/IT and MOD/S3M.
- Fixed bug with tiny bidirectional loops played at very high frequencies
- Added DirectSound Secondary Buffers mode (only to solve problems with
  some soundcards - like Ensoniq) Using this option might reduce the quality
  of the sound (see the SETUP section above for more details).
- More accuracy when playing WAV files (were a little bit out of tune,
  causing the resampler to go on, and filter the WAV)
- Finer control for the Surround depth (might take a little bit more CPU).
- Added smart sample remapping when loading XMs with more than 200 samples.
  (I saw this problem with the excellent Synthetica (Generica part three)
   from martyn  / Onyx:Trance 98: 10MB XM with almost 250 samples)
- Fixed memory leaks with RAR files
- Fixed VU-Meters in ModPlug Mixer (they were always on)

1.35:
-----
- Added RAR compression support (I recommend renaming the RAR extension to MDR)
- Fixed Pattern Loop when used with a Pattern Break on the same row
- Added support for IPC_XXXX calls from WinAmp plugins.
- Increased max # of directories in a playlist
- Fixed Tone portamento (was reseting envelopes positions)
- Fixed High Offset SAx (with memory)
- Added beta PTM support (PolyTracker Modules)
- Increased maximum reverb depth
- Lowered the depth of the reverb low-pass filter
- Added beta support for MMCMP-packed modules, thanks to
  Zirconia, aka Emmanuel Giasson, the author of MMCMP.
- Added Snap to Viewport option.
- Added IT commands S77, S78, S79, S7A, S7B, S7C (enable/disable envelopes)
- Slightly faster stereo mixing for non-MMX processors.
- Much better AGC: it is now a true dynamic AGC.
- Improved reverb (4-delay lines with early reflections + cross feedback)
- Added scan of sub-directories when dropping files

1.34:
-----
- Added more shortcut to navigate between songs
- Support for Song Title in some WinAmp Plug-Ins.
- Fixed some bugs with IT sustain sample loops.
- Added custom colors for the titlebar font.
- Added Full Drag option (Move window content while dragging).
- The spectrum analyzer take a little bit more CPU, but it's done only
  when the processor is idle (It's updated much more often).
- WinAmp Visualization Plug-ins (cool!)
- Some minor adjustments
- Fixed IT volume column portamento
- Fixed IT pitch envelopes loops
- Fixed Instrument Default Pan
- Fixed S3M loader

1.33:
-----
- Changed player interface
- Fixed S3M bug with the pattern break to row command
- Implemented some IT bugs for better compatibility
- Fixed bug with IT S91 (Surround) command
- Fixed XM keyoff/fadeout bug
- Added DirectSound support (The REC button doesn't work yet with DirectSound).
- Fixed rare spline oversampling bug with MMX enabled.
- Increase Instrument/Sample limit to 199 (was 99).
- Added support for XM with more than 200 patterns.

1.32:
-----
- Fixed IT period tuning problem
- Fixed bug in some XM modules (a 0 was inserted in the order table)
- Added More Keyboard Shortcuts (see "SHORTCUT KEYS" section above)
- Added 24-bit WAV writer, and Normalize 24-bit to 8/16 bit
- Added IT Pitch Envelopes
- PlayLists are no longer dependent of the list drive (useful for CDROM musicdisks)<BR>
- Added the REC button in the ModPlug Mixer (you need a Full-Duplex soundcard
  for this to work).
- Added Sort/Shuffle buttons in the playlist editor.
- Implemented the IT panbrello effect
- Improved the oversampling for non-MMX processors (already in 1.31patch#2)
- Increased size of the Details window
- Added ESC shortcut (Stop/Exit)
- Changed buttons

1.31:
-----
- Fixed XM fadeout/key off bugs.
- The player now base the quality of multipoint resampling depending on
  the speed of your processor.
- Improved the Pro-Logic and Reverb high-pass filters
- Improved the spline oversampling (but also slower)
- Added MMX support! (Only used for stereo mixing - Up to 100% faster)
- Added option to auto-save the module list to modplug.mol
- Fixed Bidi Loop bug with LoopStart=0
- Fixed bugs in S3M modules with more than 16 channels
- The player can now be started minimized
- Improved ULT loader
- The computer doesn't go in suspend mode if ModPlug is playing

1.30:
-----
- Fixed bug with Note Fade + Zero FadeOut Volume.
- Fixed crash with some Bidi Loops.
- Fixed hang when loading XM modules with more than 100 samples.
- Improved XM volume column tone-portamento


