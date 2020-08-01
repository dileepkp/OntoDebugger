import sys, os, re
sys.path.append(os.path.join(os.path.dirname(__file__), '.', '.'))
import a1, a2, a3, a4, a5, a6, a7, a8

n = 8
## https://stackoverflow.com/questions/6158602/does-python-classes-support-events-like-other-languages
class Event:
    def __init__(self):
        self.listeners = []

    def __iadd__(self, listener):
        """Shortcut for using += to add a listener."""
        self.listeners.append(listener)
        return self

    def notify(self, *args, **kwargs):
        for listener in self.listeners:
            listener(*args, **kwargs)

### File library related code
fopenBPs = []
fcloseBPs = [] 
freadBPs = [] 
fopenVars = []
fcloseVars = []
freadVars = []
recentFopenBP = 0

with open("space_single_original.c") as myFile:
    for num, line in enumerate(myFile, 1):
       fopenMatch = re.search('(\w+)\s*=\s*fopen\s*\(', line)
       if fopenMatch:
        fopenBPs.append(gdb.Breakpoint(str(num)))
        fopenVars.append(fopenMatch.group(1))
#        print("fopen var:", fopenMatch.group(1), str(num+6))
       freadMatch = re.search('getc\s*\((\w+)\)', line)
       if n>=3 and freadMatch:
        freadBPs.append(gdb.Breakpoint(str(num)))
        freadVars.append(freadMatch.group(1))
       fcloseMatch = re.search('fclose\s*\((\w+)\)', line)
       if fcloseMatch:
        fcloseBPs.append(gdb.Breakpoint(str(num)))
        fcloseVars.append(fcloseMatch.group(1))
#        print("fclose var:", fcloseMatch.group(1))
#    print("The length of list is: ", len(fopenBPs)) 

def stopHandler(stopEvent):
  global recentFopenBP
  for b in stopEvent.breakpoints:
#    print("breakpoint-stop:", b)
    if b in fopenBPs:
      recentFopenBP = b
      gdb.execute("next")
    if b in fcloseBPs:
#      print("Execution in fclose bp")
      ind = fcloseBPs.index(b)
      var = fcloseVars[ind]
      top = gdb.newest_frame()
      valOfVar = (top.read_var(var))
      line = top.find_sal().line  
      funcCallEvent.notify('fclose', ind, var, top, valOfVar, line)
    if recentFopenBP != 0:
      ind = fopenBPs.index(recentFopenBP)
      recentFopenBP = 0
      var = fopenVars[ind]
      top = gdb.newest_frame()
      valOfVar = (top.read_var(var))
      line = top.find_sal().line  
      funcCallEvent.notify('fopen', ind, var, top, valOfVar, line)
    if b in freadBPs:
      ind = freadBPs.index(b)
      var = freadVars[ind]
      top = gdb.newest_frame()
      valOfVar = (top.read_var(var))
      line = top.find_sal().line  
      funcCallEvent.notify('fread', ind, var, top, valOfVar, line)
  gdb.execute("continue")

### Registration handler
def funcCallRegistrations(funcCallEvent):
   if n >= 1:
       funcCallEvent += a1.process
   if n >= 2:
       funcCallEvent += a2.process
   if n >= 3:
       funcCallEvent += a3.process
   if n >= 4:
       funcCallEvent += a4.process
   if n >= 5:
       funcCallEvent += a5.process
   if n >= 6:
       funcCallEvent += a6.process
   if n >= 7:
       funcCallEvent += a7.process
   if n >= 8:
       funcCallEvent += a8.process

def postExecutionRegistrations(funcCallEvent):
   if n >= 1:
       funcCallEvent += a1.completeProcessing
   if n >= 2:
       funcCallEvent += a2.completeProcessing
   if n >= 3:
       funcCallEvent += a3.completeProcessing
   if n >= 4:
       funcCallEvent += a4.completeProcessing
   if n >= 5:
       funcCallEvent += a5.completeProcessing
   if n >= 6:
       funcCallEvent += a6.completeProcessing
   if n >= 7:
       funcCallEvent += a7.completeProcessing
   if n >= 8:
       funcCallEvent += a8.completeProcessing


funcCallEvent = Event()
funcCallRegistrations(funcCallEvent)
finishExecutionEvent = Event()
postExecutionRegistrations(finishExecutionEvent)

gdb.events.stop.connect (stopHandler)
gdb.execute("run")
finishExecutionEvent.notify()
