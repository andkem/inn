#!/usr/local/bin/perl

# Keep track of which groups are currently being read.  Takes logfile input
# on stdin.
require '/var/netnews/lib/innshellvars.pl';
$readfile="$inn'newsetc/readgroups";

$curtime = time;
$oldtime = $curtime - 30 * 86400; # 30 days in the past

if (open(RDF, $readfile)) {
    while (<RDF>) {
	chop;
	@foo=split(/ /); # foo[0] should be group, foo[1] lastreadtime
	if ($foo[1] < $oldtime) {
	    next; # skip entries that are too old.
	}
	$groups{$foo[0]} = $foo[1];
    }
    close(RDF);
}

# read input logs.
while (<>) {
    next unless /nnrpd/;
    next unless / group /;
    chop;
    @foo = split(/ +/);
    # group name is in the 8th field.
    $groups{$foo[7]} = $curtime;
}

open(WRF, ">$readfile") || die "cannot open $readfile for write.\n";
foreach $i (keys %groups) {
    print WRF $i, " ", $groups{$i}, "\n";
}

exit(0);
    
