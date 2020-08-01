%% #!/usr/bin/swipl
%% swipl --nosignals --quiet run.pl is.c.ttl is.c.txt

:- set_prolog_flag(verbose, silent).

:- use_module(library(semweb/rdf_db)).
:- use_module(library(semweb/turtle)).

:- use_module('../csem/basic.pl').
:- use_module('../csem/canonical_loop.pl').

:- initialization main.

:- rdf_register_prefix(c, 'http://www.semanticweb.org/yzhao30/ontologies/2015/7/c#').

%% get the root folder of openk project
openk_root(OPENK) :-
	working_directory(W, W), 
	atom_concat(W, '../..', OPENKR),
	absolute_file_name(OPENKR, OPENK).


c_onto(Cowl) :-
	openk_root(R), atom_concat(R, '/projects/csem/c.owl', Cowl).

eval :-
	current_prolog_flag(argv, Argv),
% write(Argv),
	% append(_, [-- | Allargs], Argv),
append(_, Allargs, Argv),
% write('hi2'),
	[Inputfile, Outputfile|_] = Allargs,
 write(Inputfile), tab(1), writeln(Outputfile),
	c_onto(Conto),
	rdf_load(Conto, [register_namespaces(ture)]),
	writeln('c.owl is loaded!'),

	analysis(Inputfile, Outputfile),
	writeln(done).

 %% printList([A,B,C,D,E,F|_]) :- write(A), write(B), write(C), write(D), write(E), writeln(F).
%% test comments	
main :- 
%	writeln('hi'),
	catch(eval, E, (print_message(error, E), fail)), 
	halt(0).
	
main :-
	halt(0).

%% analysis(InTurtle, Outputfile) :-
%% 	write(InTurtle), nl, write(Outputfile), nl, !.

analysis(InTurtle, OutReport) :-
	%% open output report file
	atom(OutReport), open(OutReport, write, Out), !,
	rdf_load(InTurtle, [format(turtle), register_namespaces(true)]),
%% writeln('input is loaded!'), 
	 write(InTurtle), tab(1), writeln('is loaded'),
%	statistics(cputime, T1),
%	forall( (canonicalLoop(Loop), get_id(Loop, L)), fwriteln(Out, L)),
%	statistics(cputime, T2),
%	Tdiff is (T2 - T1) * 1000000,

 statistics(walltime, [TimeSinceStart | [TimeSinceLastCall]]),
  forall( (canonicalLoop(Loop), get_id(Loop, L)), fwriteln(Out, L)),
   statistics(walltime, [NewTimeSinceStart | [Tdiff]]),

	fwriteln(Out, '-----------------'),
	write(Out, '#'), fwriteln(Out, Tdiff), 
	fwriteln(Out, '-----------------'),
	close(Out).

fwriteln(Out, Text) :-
	write(Out, Text), nl(Out).

