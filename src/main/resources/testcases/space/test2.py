      objects = gdb.lookup_symbol("fopen")
      if objects[0] != None:
       for obj in objects:
         print(obj)
         print("line no." + str(obj.line))
         #gdb.execute("info frame")
         #top = gdb.newest_frame()
         #valOfVar = float(top.read_var('info'))
         print("zzzzzzzzzzzzzzzzzzzzzzz");
         #res.append(valOfVar)






import sys, os
sys.path.append(os.path.join(os.path.dirname(__file__), '..', '.'))
import listVerification
import tp


# https://stackoverflow.com/questions/28163123/how-can-i-set-breakpoints-by-regular-expression-in-gdb-via-python
gdb.execute("rbreak space_single_original.c:.")
bp0 = gdb.breakpoints()
#bp1 = tp.SetTracepoint()
#gdb.execute("tp main")
res = []
# Define handler routines
def stopHandler(stopEvent):
  for b in stopEvent.breakpoints:
    if b in bp0:
      frame = gdb.newest_frame()
      block = frame.block()
      objects = gdb.lookup_symbol("f")[0]
      if objects != None:
       print("line num:" + str(objects.line))
       for s in block:
        if s.is_variable:
         typ = s.type
         name = s.name
         print(str(typ) + "  " + str(name))
         print("yyyy");
        if s.is_function:
         name = s.print_name
         print("  " + str(name))
         print("xxxx");
  gdb.execute("continue")


# Register event handlers
gdb.events.stop.connect (stopHandler)

gdb.execute("run")
#print(listVerification.strictly_increasing(res))
