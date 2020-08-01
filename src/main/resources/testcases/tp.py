# tp.py
#https://www.pythonsheets.com/appendix/python-gdb.html
import gdb

tp = {}

class Tracepoint(gdb.Breakpoint):
    def __init__(self, *args):
        super().__init__(*args)
        self.silent = True
        self.count = 0

    def stop(self):
        self.count += 1
        frame = gdb.newest_frame()
        block = frame.block()
        sym_and_line = frame.find_sal()
        framename = frame.name()
        filename = sym_and_line.symtab.filename
        line = sym_and_line.line
        # show tracepoint info
        print(filename+ " " + str(line))
        print("{framename} @ {filename}:{line}")
        # show args and vars
        for s in block:
            if not s.is_argument and not s.is_variable:
                continue
            typ = s.type
            val = s.value(frame)
            size = typ.sizeof
            name = s.name
            print("\t{name}({typ}: {val}) [{size}]")
        # do not stop at tracepoint
        return False

class SetTracepoint(gdb.Command):
    def __init__(self):
        super().__init__("tp", gdb.COMMAND_USER)

    def invoke(self, args, tty):
        try:
            global tp
            tp[args] = Tracepoint(args)
        except Exception as e:
            print(e)

def finish(event):
    for t, p in tp.items():
        c = p.count
        print("Tracepoint '{t}' Count: {c}")

gdb.events.exited.connect(finish)
SetTracepoint()
