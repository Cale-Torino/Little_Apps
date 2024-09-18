----------------------------------------------------------------------------
INSTALL:

If you have previously installed an older version of UnCHK, you MUST install 
this version in a different directory -or- delete the older version's 
program and INI file. "Installation" consists of extracting the "UnCHK.exe" 
and putting it wherever you want. If, when you run the program, it says you 
are missing MSVBVM50, You need to download this file from Microsoft:
ftp://ftp.microsoft.com/Softlib/MSLFILES/MSVBVM50.EXE
Save it to a temporary spot and run it. It will install the Visual Basic 5 
run-time files you need. After you've finished the installation, you can delete 
the file you downloaded from Microsoft.

----------------------------------------------------------------------------
QUICK START:

Drop a CHK file on it -or- just run it. 


----------------------------------------------------------------------------
FAQ:

What are the "Scan Depth" settings? 

Whole files - In general, if your recovered CHK files are intact and 
your file system was in good shape (not counting whatever happened to create the 
CHK files!), you can just try to identify the CHK files. The "Whole files" 
scan depth setting is the fastest and generates the fewest false recoveries. 
It also misses the most... because... your file system is NEVER in good shape!

Embedded files - If your file system was so fragmented that you couldn't 
recover any complete files, this might find a few pieces. The "Embedded files" 
option will check every single byte trying to locate little things that might 
have been embedded in other documents. For example, pictures that were part of 
Word documents. You should *NOT* use this scan depth setting unless everything 
else has failed you *AND* you know you have embedded items that are worth 
retrieving. The "Embedded files" scan depth setting is the slowest and generates 
an excessive number of false recoveries. If you really want to use it because 
you are desparate to try to recover something, you should consider blocking all 
file types from being recovered except the file type you are trying to recover. 
See the "What if I only want to recover a single type of file?" FAQ below for 
instructions on how to block unwanted file types from being recovered.

Floppy disk - If the CHK files you are recovering came from a floppy disk (even 
if you've since copied them to your hard drive), this setting might recover 
something that the "Whole files" depth setting would miss. It checks inside the 
recovered CHK files on the 128-byte boundaries looking for cross-linked files. 
Cross-linked files are fairly rare, and with any luck the recovery program that 
created your CHK files made copies of and cross-linked files. If so, this setting 
won't find anything more than the "Whole files" setting. The "Floppy disk" scan 
depth setting is only slightly slower than the "Whole files" setting and will 
generate more false recoveries. 

Hard disk - Same as the above "Floppy disk", except this checks on 512-byte 
boundaries. Your disk may use much larger clusters, so this might be a bit of 
overkill, but at least your cluster size isn't going to be *smaller* than 512 
bytes. 


----------------------------------------------------------------------------
FAQ:

How do I modify the INI file to add more file types?


The easy way is to drop a KNOWN GOOD file onto the UNCHK program. UNCHK will 
automatically add an entry for that file type to the INI file. From then on, 
UNCHK will know how to recover files of that type. More or less.

To manually edit the UNCHK.INI file, look in the same place as the UNCHK.EXE 
program file.

The INI file format is a file extension followed by the hex-encoded file 
header, a space, then some hex-encoded text that should appear in all files 
of that type.

For example, a JPG file has a header that always starts with these bytes:
ÿØÿà
Hex-encoded, it becomes:
FFD8FFE0
However, JPG files also have a plain-text identifier inside them of:
JFIF
When we hex-encode that, it becomes:
4A464946
So the INI file entry becomes:
JPG=FFD8FFE0 4A464946

If you think that's going to be tough to do without a hex encode program, I 
agree! I built an encoder and decoder in. Run them by starting the program 
with either of the following command lines:

UnCHK.exe /encode
UnCHK.exe /decode

You can also use the native "DEBUG" utility to display hex, but 
only if you are prepared to work around it's short file name and small 
file size limitations. 


----------------------------------------------------------------------------
FAQ:

What if I only want to recover a single type of file?

Every time the UnCHK program runs, it makes sure the standard INI entries 
exist and aren't blank. And the program always checks every file type 
listed in the INI file. And that's your clue! Start the program, but don't 
do anything with the first question it asks. Instead, open the INI file 
and delete any entries you don't want to search for. Save the INI file, 
then continue running the program normally. Remember, you have to modify 
the INI file each time you start the program. 

Another approach is to make sure the INI file entries exist and aren't 
blank (which is all it takes to satisfy the startup routines), but put 
bogus data in them. Since you know the data is suposed to be hex-encoded, 
put something that can't be decoded properly! For example:

EXE=ZZZ

Because only 1-9 and A-F are valid hex characters, "ZZZ" will decode out as
an empty string. And empty strings are ignored. So an INI entry like the 
above would permanently stop EXE files from being recovered. Well, not 
PERMANENTLY, because if you just delete the INI file, all the default entries 
are regenerated!


----------------------------------------------------------------------------
FAQ:

Why can't I recover my file?


1 - Your file may not be there. Maybe it was wiped out or key pieces of it were 
wiped out. 

2 - If your file is fragmented, UNCHK will only recover the first fragment. This is 
why you want to defragment your hard drive regularly! After you get the first 
fragment, you have to MANUALLY assemble pieces at random and check to see if you 
improved things. Then you have to hope you have a way to see incremental 
improvements. Even then, your task is one whose complexity is expressed with 
factorials. Two fragments (out of a hundred possible) might take an hour to 
sort through. Three fragments would take four days. Four fragments out of a 
hundred might take over a year. You see how fast this gets out of hand. If you're 
determined to try to reassemble fragmented files, here's how I do it. Use the COPY 
command with the /B (binary) option to concatenate files:

copy /b file0099.jpg + file0001.chk test.jpg

The above would take the partially recovered file0099.jpg file and add the contents of 
file0001.chk to it, storing the result in test.jpg. You'd then have to try opening the 
test.jpg file to see if that helped. For a JPG or GIF picture, this usually means you 
can see more of the picture (assuming, of course, you use a viewer that will tolerate 
broken pictures). If it does help, then you keep the result and start copying other CHK 
files onto it's end to see if you can make your good part bigger. But MOST files won't 
open at all unless they are complete. For example, the slightest error in a Word 
document generates an error. In that case, you're down to trying to open all the CHK 
files in Notepad and looking at them, hoping you can see clues as to where they 
belong. Or you're down to random assembly.


3 - Just because UNCHK says it found a Word document doesn't mean it really is a Word 
document! UNCHK can be faked out by random data that just happens to be in the right 
(or wrong) place. 

4 - Like I said in the first section: Maybe you detected the wrong file type. Maybe you 
are trying to recover a Word document, but it's actually an Excel file. You can try 
forever and never get it to open in Word.

5 - Maybe your office file (Word, Excel, etc.) was recovered complete by UNCHK but 
is corrupted. In this case, I really con't help you. All I can suggest is to try 
the tools you can find at http://www.officerecovery.com



----------------------------------------------------------------------------

http://www.ericphelps.com


