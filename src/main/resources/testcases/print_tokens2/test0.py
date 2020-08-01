
import sys, os
sys.path.append(os.path.join(os.path.dirname(__file__), '..', '.'))
import listVerification


bp1 = gdb.Breakpoint("165")
bp2 = gdb.Breakpoint("173")
res = []
# Define handler routines
def stopHandler(stopEvent):
  for b in stopEvent.breakpoints:
    if b == bp1 or b == bp2:
      #print("myFunc() breakpoint")
      #res.append(gdb.execute("p info", False, True))
      top = gdb.newest_frame()
      valOfVar = int(top.read_var('ch'))
      print(valOfVar);
      res.append(valOfVar)
  gdb.execute("continue")


# Register event handlers
gdb.events.stop.connect (stopHandler)

gdb.execute("run < /home/aidb/SIRprograms/formatted/printtokens2/inputs/ts527")
print(listVerification.allSame(res))
