import glob
import hashlib
import sys
import os

filenames = glob.glob("*.*")
		# truncate the file to zero length before opening
f1 = open(os.path.expanduser(sys.path[0]) + '\\filelist.md5.txt', 'w')
for filename in filenames:
	with open(filename, 'rb') as inputfile:
		data = inputfile.read()
		#'a' will append the file, rather than write over whatever else you put in it like 'w' 
		#sys.stdout = open('filelist.md5.txt', 'a')
		with open('filelist.md5.txt', 'a') as f:
			print >> f, '. -- ', filename, '-----', hashlib.md5(data).hexdigest()

f.close()