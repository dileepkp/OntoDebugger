import gdb

class MyBreakpoint(gdb.Breakpoint):
 res = []
 def stop (self):
  #gdb.write('MyBreakpoint\n')
  # res.append(gdb.execute("p info", False, True))
  # Continue automatically.
  #print(res)
  return False
  # Actually stop.
  # return True


MyBreakpoint('228')
gdb.execute("run < /home/aidb/SIRprograms/formatted/totinfo/inputs/test5")



#def main():
# gdb.execute("break 228")
# gdb.execute("run")
# gdb.execute("p info", False, True)
 #print(res)
  #gdb.execute("c")main()

#main()


