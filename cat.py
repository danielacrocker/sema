import sys

if len(sys.argv) <= 1:
	print("usage: cat.py file1 file2") 
else:
	for f in sys.argv[1:]:
		handle = open(f,'r')
		rl = handle.readlines()
		for l in rl:
			print(l)
