#!/usr/bin/python3
#
# file: singlelist.py
#

class SingleLinkedListNode(object):
	def __init__(self, value, nxt):
		self.value = value
		self.next = nxt

	def __repr__(self):
		nval = self.next and self.next.value or None
		return f"[{self.value}:{repr(nval)}]"

	def __repr__(self):
		nval = self.next and self.next.value or None
		return f"[{self.value}:{repr(nval)}]"


class SLLController(object):

	def __init__(self, head):	
		self.head = head

	def add(self, node):
		node.next = self.head
		self.head = node

	def print(self):
		n = self.head
		while n is not None:
			print(n.__repr__)
			n = n.next 

	def remove(self, theNode):
		if theNode == self.head:
			print("removing head")
			self.head = self.head.next
		else:
			#  search list for node
			n = self.head
			while (n.next != node) and (n.next != None):
				n = n.next

			if n.next == node:
				n.next = node.next
				print('found node')
			else:
				print('not find node')

n1 = SingleLinkedListNode("test1", None)
n2 = SingleLinkedListNode("test2", None)
n3 = SingleLinkedListNode("test3", None)

c = SLLController(n1)

c.add(n2)
c.add(n3)

c.print()

c.remove(n3)
c.print()

c.remove(n2)
c.print()
