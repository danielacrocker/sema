#####################################################################
# find.py
# 	parse and implement find parameters:
#	-print
#	--exec
#
# 	use subprocess and glob
#
#####################################################################

import sys
import os
from pathlib import Path
import glob

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
	for root, dirs, files in os.walk(dirpath,topdown=True):
		for name in files:
			aFile = os.path.join(dirpath, name)
			theFiles.append(aFile)
	
	return theFiles 


theLen = len(sys.argv)

if theLen  <= 1:
	print("usage: find / -name x.y -print")

pgm = sys.argv[0]


if theLen >= 2:

	root = sys.argv[1]
	print("root: ", root)

	os.chdir(root) # switch to find dir

	if theLen >= 3:
		name_operation = sys.argv[2]
		print("name_operation: ", name_operation)

		if name_operation == '-type':
			dir_file = sys.argv[3]
			print("dir_file: ", dir_file)

			if theLen >= 5:
				operation = sys.argv[4]
				print("operation: ", operation)

			else:

				if dir_file == 'd':
					print("find only directories")
					for f in listdir_r(root):
						print("\n",f) 

				elif dir_file == 'f':
					print("find only files") 
					for f in listfiles_r(root):
						print("\n",f) 
				else:
					print("\nUnknown operation on type")

		elif name_operation == '-name':

			print("pattern: " , sys.argv[3])

			#files = [f for f in os.listdir('.') if os.path.isfile(f)]

			# for f in files:
				# do something

			files = glob.glob(sys.argv[3])		

			for f in files:
				print(f)

