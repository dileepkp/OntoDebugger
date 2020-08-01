
import sys, os
sys.path.append(os.path.join(os.path.dirname(__file__), '..', '.'))
import listVerification


bp1 = gdb.Breakpoint("505")
res = []
# Define handler routines
def stopHandler(stopEvent):
  for b in stopEvent.breakpoints:
    if b == bp1:
      #print("myFunc() breakpoint")
      #res.append(gdb.execute("p info", False, True))
      top = gdb.newest_frame()
      valOfVar = int(top.read_var('bytesread'))
      #print(valOfVar);
      res.append(valOfVar)
  gdb.execute("continue")


# Register event handlers
gdb.events.stop.connect (stopHandler)

gdb.execute("run -n I /home/aidb/SIRprograms/formatted/grep/inputs/grep1.dat")
print(listVerification.allNonNegative(res))
