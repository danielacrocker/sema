# find.py
# 	parse and implement find parameters:
#	-print
#	--exec
#
# 	use subprocess and glob
#
import sys
import os
from pathlib import Path

# list only dirs
def listdir_r(dirpath):
	"""lists directories and sub-directories recursively
	"""
	
	paths = []
	paths.append(dirpath)
	for path in os.listdir(dirpath):
		rpath = os.path.join(dirpath, path)
		if os.path.isdir(rpath):
			subdirs = listdir_r(rpath)
			if not subdirs == []:
				paths.extend(subdirs)
	return paths

# list only files
def listfiles_r(dirpath):
	"""lists files recursively
	"""
	
	theFiles = []
	for files in os.walk(dirpath,topdown=False):
		for fileName in files:
			theFiles.append(fileName)
		
	return theFiles 


theLen = len(sys.argv)

if theLen  <= 1:
	print("usage: find / -name x.y -print")

pgm = sys.argv[0]

if theLen >= 2:
	root = sys.argv[1]
	print("root: ", root)

if theLen >= 3:
	name_operation = sys.argv[2]
	print("name_operation: ", name_operation)

if theLen >= 4:
	dir_file = sys.argv[3]
	print("dir_file: ", dir_file)

if theLen >= 5:
	operation = sys.argv[4]
	print("opertion: ", operation)

os.chdir(dir)

print("cwd is: ", os.getcwd())

if name_operation == '-type':

	if dir_file is 'd':
		print("find only directories")
		for f in listdir_r(dir):
			print("\n",f) 

	if dir_file is 'f':
		print("find only files") 
		for f in listfiles_r(dir):
			print("\n",f) 

