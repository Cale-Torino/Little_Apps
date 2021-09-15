import glob
import hashlib

filenames = glob.glob("*.*")

for filename in filenames:
    with open(filename, 'rb') as inputfile:
        data = inputfile.read()
        print filename, hashlib.md5(data).hexdigest()

with open('filelist.md5.txt', 'w') as f:
    print >> f, 'Filename:', filename, hashlib.md5(data).hexdigest()  # Python 2.x
f.close()