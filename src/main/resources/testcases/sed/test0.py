
import sys, os
sys.path.append(os.path.join(os.path.dirname(__file__), '..', '.'))
import listVerification


bp1 = gdb.Breakpoint("2220")
bp2 = gdb.Breakpoint("2226")
res = []
# Define handler routines
def stopHandler(stopEvent):
  for b in stopEvent.breakpoints:
    if b == bp1 or b == bp2:
      #print("myFunc() breakpoint")
      #res.append(gdb.execute("p info", False, True))
      top = gdb.newest_frame()
      #valOfVar = (top.read_var('*pp2'))
      py_ptrref = gdb.parse_and_eval("last_regex")
      valOfVar = (py_ptrref.referenced_value())
      print(valOfVar);
      res.append(valOfVar)
  gdb.execute("continue")


# Register event handlers
gdb.events.stop.connect (stopHandler)

gdb.execute("run")
print(listVerification.allDistinct(res))
