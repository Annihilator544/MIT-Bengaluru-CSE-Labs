class Pro:
	def __init__(self, id):
		self.id = id
		self.act = True

class RING:
	def __init__(self):
		self.TotalProcess = 0
		self.process = []
	
	def initialiseRING(self):
		print("No of processes 7")
		self.TotalProcess = 7
		self.process = [Pro(i) for i in range(self.TotalProcess)]
	
	def Election(self):
		print("Process no " + str(self.process[self.FetchMaximum()].id) + " fails")
		self.process[self.FetchMaximum()].act = False
		print("Election Initiated by 2")
		initializedProcess = 2

		old = initializedProcess
		newer = old + 1

		while (True):
			if (self.process[newer].act):
				print("Process " + str(self.process[old].id) + " pass Election(" + str(self.process[old].id) + ") to" + str(self.process[newer].id))
				old = newer
			newer = (newer + 1) % self.TotalProcess
			if (newer == initializedProcess):
				break

		print("Process " + str(self.process[self.FetchMaximum()].id) + " becomes coordinator")
		coord = self.process[self.FetchMaximum()].id

		old = coord
		newer = (old + 1) % self.TotalProcess
		while (True):
			if (self.process[newer].act):
				print("Process " + str(self.process[old].id) + " pass Coordinator(" + str(coord) + ") message to process " + str(self.process[newer].id))
				old = newer
			newer = (newer + 1) % self.TotalProcess
			if (newer == coord):
				print("End Of Election ")
				break
	
	def FetchMaximum(self):
		maxId = -9999
		ind = 0
		for i in range(self.TotalProcess):
			if (self.process[i].act and self.process[i].id > maxId):
				maxId = self.process[i].id
				ind = i
		return ind

def main():
	object = RING()
	object.initialiseRING()
	object.Election()

if __name__ == "__main__":
	main()