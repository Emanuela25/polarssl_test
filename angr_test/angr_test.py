import argparse
import os
import sys
import angr
from angrutils import *
import monkeyhex
import claripy

def generate_cfg(proj):
  print("Flag --graph set: generating control-flow graph of the program")
  main = proj.loader.main_object.get_symbol("main")
  start_state = proj.factory.blank_state(addr=main.rebased_addr)
  cfg = proj.analyses.CFGEmulated(fail_fast=True, starts=[main.rebased_addr], initial_state=start_state)
  cfg_name = os.path.basename(proj.filename)+"_cfg"
  plot_cfg(cfg, cfg_name, asminst=True, remove_imports=True, remove_path_terminator=True)
  print("Control-flow graph generated in current directory: " + cfg_name + ".png")

def symbolic_execution(proj):
  argv1 = claripy.BVS('c{}'.format(8), 64, explicit_name=True)
  initial_state = proj.factory.entry_state(args=[proj.filename, argv1], add_options={angr.options.LAZY_SOLVES})

  initial_state.add_constraints(argv1.chop(8)[0] == 't')
  initial_state.add_constraints(argv1.chop(8)[1] == 'y')
  initial_state.add_constraints(argv1.chop(8)[2] == 'p')
  initial_state.add_constraints(argv1.chop(8)[3] == 'e')
  initial_state.add_constraints(argv1.chop(8)[4] == '=')

  sm = proj.factory.simulation_manager(initial_state)
  sm.explore(find=lambda s: b"Seeding the random number generator..." in s.posix.dumps(1))

  for f in sm.found:
    solution = f.solver.eval(argv1, cast_to=bytes)
    print("Constraint solved: " + str(solution))

if __name__ == '__main__':
  parser = argparse.ArgumentParser(description='angr script to analysis executable file')
  parser.add_argument("filename", help="filename of executable file to be analyzed")
  parser.add_argument("-g", "--graph", help="generate control-flow graph of executable file", action="store_true")
  parser.add_argument("-s", "--symbolic", help="set program argument symbolic", action="store_true")
  args = parser.parse_args()

  proj = angr.Project(args.filename, load_options={'auto_load_libs':False})
  print('Executable file: ' + proj.filename)
  print('Compiling architecture: ' + proj.arch.name)
  print('Address of entry point: 0x' + str(proj.entry))

  if args.graph:
    generate_cfg(proj)
  
  if args.symbolic:
    symbolic_execution(proj)
