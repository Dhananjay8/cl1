import sys
import numpy as np
from xml.dom import minidom
xmldoc=minidom.parse('b1.xml')
itemlist=xmldoc.getElementsByTagName('Item')
sys.setrecursionlimit(1000000000)
firstQueen=0
class NQueens:
	def __init__(self,size_of_board):
		self.size=size_of_board
		self.columns =[] * self.size
		self.num_of_places = 0
		self.num_of_backtracks = 0
	def placeFirst(self):
		self.columns.append(firstQueen)
	def place(self,startRow=0):
		if len(self.columns)==self.size:
			print str(self.size)
			print str(self.num_of_places)
			print str(self.columns)
			print str(self.num_of_backtracks)
			return self.columns
		else:
			for row in range(startRow,self.size):
				if self.isSafe(len(self.columns),row) is True:
					self.columns.append(row)
					self.num_of_places+=1
					return self.place()
			else:	
				lastRow=self.columns.pop()
				self.num_of_backtracks+=1
				return self.place(startRow=lastRow+1)
	def isSafe(self,col,row):
		for threatRow in self.columns:
			threatCol = self.columns.index(threatRow)
			if row == threatRow or col == self.columns.index(threatRow):
				return False
			elif threatRow + threatCol == row + col or threatRow - threatCol == row - col:
				return False
		return True

n=8
datalist=[]
for s in itemlist:
	datalist.append(s.getAttribute("index").encode("utf-8"))
print datalist
for s in datalist:
	if(s!=' '):
		firstQueen=int(s)
		break
        
print "First queen placed in first row at: ",firstQueen
queens = NQueens(8)
queens.placeFirst()
queens.place(0)

# convert board to numpy array for pretty printing
board = np.array([['*'] * n] * n)
for queen in queens.columns:
	board[queens.columns.index(queen), queen] = 'Q'
print board

