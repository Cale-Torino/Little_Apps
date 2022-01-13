import glob
import hashlib
import sys
import os


filenames = glob.glob("*.*")
		# truncate the file to zero length before opening
f1 = open(os.path.expanduser(sys.path[0]) + '\\filelist.md5.txt', 'w')
#'a' will append the file, rather than write over whatever else you put in it like 'w' 
with open('filelist.md5.txt', 'a') as f:
		print >> f,''
		print >> f,'#'
		print >> f,'#  GENERATE_FILELIST'
		print >> f,'#  MADE BY C.A.TORINO FOR TRUCK ASSIST PTY LTD'
		print >> f,'#  PYTHON 2.7 GENERATED'
		print >> f,'#  (filename)    (filesize)    (flags)    md5    (major_version)    (minor_version)'
		print >> f,'#'
		print >> f,''
f.close()
for filename in filenames:
	with open(filename, 'rb') as inputfile:
		data = inputfile.read()
		print '. -- ',filename, hashlib.md5(data).hexdigest()

for filename in filenames:
	#'a' will append the file, rather than write over whatever else you put in it like 'w' 
	with open('filelist.md5.txt', 'a') as f:
		print >> f, filename,'        filesize     ','0       ', hashlib.md5(data).hexdigest(),'    ----','         ----'
f.close()