using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MusicIntense
{
    internal class FileStreamPositionClass
    {
        //
        // Summary:
        //     Stream File Position modes to be used with ManagedBass.Bass.StreamGetFilePosition(System.Int32,ManagedBass.FileStreamPosition)
        public enum FileStreamPosition
        {
            //
            // Summary:
            //     Position that is to be decoded for playback next. This will be a bit ahead of
            //     the position actually being heard due to buffering.
            Current = 0,
            //
            // Summary:
            //     Download progress of an internet file stream or "buffered" User file stream.
            Download = 1,
            //
            // Summary:
            //     End of the file, in other words the file Length. When streaming in blocks, the
            //     file Length is unknown, so the download Buffer Length is returned instead.
            End = 2,
            //
            // Summary:
            //     Start of stream data in the file.
            Start = 3,
            //
            // Summary:
            //     Internet file stream or "buffered" User file stream is still connected? 0 = no,
            //     1 = yes.
            Connected = 4,
            //
            // Summary:
            //     The amount of data in the Buffer of an internet file stream or "buffered" User
            //     file stream. Unless streaming in blocks, this is the same as ManagedBass.FileStreamPosition.Download.
            Buffer = 5,
            //
            // Summary:
            //     Returns the socket hanlde used for streaming.
            Socket = 6,
            //
            // Summary:
            //     The amount of data in the asynchronous file reading Buffer. This requires that
            //     the ManagedBass.BassFlags.AsyncFile flag was used at the stream's creation.
            AsyncBuffer = 7,
            //
            // Summary:
            //     WMA add-on: internet buffering progress (0-100%)
            WmaBuffer = 1000,
            //
            // Summary:
            //     Segment Sequence number.
            HlsSegment = 0x10000
        }
    }
}
