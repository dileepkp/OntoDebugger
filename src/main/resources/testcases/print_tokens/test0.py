
import sys, os
sys.path.append(os.path.join(os.path.dirname(__file__), '..', '.'))
import listVerification


bp1 = gdb.Breakpoint("224")
bp2 = gdb.Breakpoint("233")
res1 = []
res2 = []
# Define handler routines
def stopHandler(stopEvent):
  for b in stopEvent.breakpoints:
    if b == bp1 or b == bp2:
      top = gdb.newest_frame()
      valOfVar = int(gdb.parse_and_eval("tstream_ptr->ch_stream->stream_ind"))
      if b == bp1:
       res1.append(valOfVar)
      if b == bp2:
       res2.append(valOfVar)
  gdb.execute("continue")


# Register event handlers
gdb.events.stop.connect (stopHandler)

gdb.execute("run < /home/aidb/SIRprograms/formatted/printtokens/inputs/newtst171.tst")
print(listVerification.equalSpanOf(res1,res2))
