import glob
import hashlib
import time
#import os

#my_dir = r("*.*")
#for f in os.listdir(my_dir):
 #   path = os.path.join(my_dir, f)
  #  if os.path.isfile(path):
   #     print os.path.getsize(path)


filenames = glob.glob("*.*")

for filename in filenames:
	with open(filename, 'rb') as inputfile:
		data = inputfile.read()
		print '. -- ',filename, hashlib.md5(data).hexdigest()

for filename in filenames:
	with open('filelist.md5.txt', 'w') as f:
		print >> f,''
		print >> f,'#'
		print >> f,'#  GENERATE_FILELIST'
		print >> f,'#  MADE BY C.A.TORINO FOR TRUCK ASSIST PTY LTD'
		print >> f,'#  PYTHON 2.7 GENERATED'
		print >> f,'#  (filename)    (filesize)    (flags)    md5    (major_version)    (minor_version)'
		print >> f,'#'
		print >> f,''
		#f.write('\n'.join(filename))
		#f.writelines(i + '\n' for i in filename)
		print >> f, filename,'        filesize     ','0       ', hashlib.md5(data).hexdigest(),'    ----','         ----\n'
		print ''
		print 'generate filelist.md5.txt successfully'
time.sleep(3) 
#f.close()