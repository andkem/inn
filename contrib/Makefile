##  There are no installation rules or other top-level rules for this
##  directory as it's not properly part of INN.  Installation should be
##  done by the user by hand for those files that they're interested in.

include ../Makefile.global

top           = ..
CFLAGS        = $(GCFLAGS)

ALL	      = analyze-traffic archivegz authmysql auth_pass backlogstat \
		cleannewsgroups count_overview delayer expirectl \
		findreadgroups fixhist innconfcheck makeexpctl makestorconf \
		mkbuf mlockfile newsresp \
		nnrp.access2readers.conf pullart reset-cnfs respool \
		stathist thdexpire \
		tunefeed

all: $(ALL)

warnings:
	$(MAKE) COPT='$(WARNINGS)' all

clean clobber distclean maintclean:
	rm -f *.o $(ALL)
	rm -rf .libs

$(FIXSCRIPT):
	@echo Run configure before running make.  See INSTALL for details.
	@exit 1


##  Compilation rules.

LINK 		= $(LIBLD) $(LDFLAGS) -o $@
FIX		= $(FIXSCRIPT)

STORELIBS	= $(LIBSTORAGE) $(LIBHIST) $(LIBINN) $(STORAGE_LIBS) $(LIBS)

auth_pass:	auth_pass.o	; $(LINK) auth_pass.o $(LIBINN) $(CRYPT_LIBS)
expirectl:	expirectl.o	; $(LINK) expirectl.o
mlockfile:	mlockfile.o	; $(LINK) mlockfile.o
newsresp:	newsresp.o	; $(LINK) newsresp.o $(LIBS)
pullart:	pullart.o	; $(LINK) pullart.o $(LIBINN)
reset-cnfs:	reset-cnfs.o	; $(LINK) reset-cnfs.o
respool:	respool.o	; $(LINK) respool.o $(STORELIBS)

analyze-traffic: analyze-traffic.in $(FIX) ; $(FIX) -i analyze-traffic.in
archivegz:       archivegz.in       $(FIX) ; $(FIX) -i archivegz.in
authmysql:       authmysql.in       $(FIX) ; $(FIX) -i authmysql.in
backlogstat:     backlogstat.in     $(FIX) ; $(FIX) backlogstat.in
cleannewsgroups: cleannewsgroups.in $(FIX) ; $(FIX) cleannewsgroups.in
count_overview:  count_overview.in  $(FIX) ; $(FIX) -i count_overview.in
delayer:         delayer.in         $(FIX) ; $(FIX) -i delayer.in
findreadgroups:  findreadgroups.in  $(FIX) ; $(FIX) findreadgroups.in
fixhist:         fixhist.in         $(FIX) ; $(FIX) -i fixhist.in
innconfcheck:    innconfcheck.in    $(FIX) ; $(FIX) -i innconfcheck.in
makeexpctl:      makeexpctl.in      $(FIX) ; $(FIX) makeexpctl.in
makestorconf:    makestorconf.in    $(FIX) ; $(FIX) makestorconf.in
mkbuf:           mkbuf.in           $(FIX) ; $(FIX) -i mkbuf.in
nnrp.access2readers.conf: nnrp.access2readers.conf.in $(FIX) ; $(FIX) -i nnrp.access2readers.conf.in
stathist:        stathist.in        $(FIX) ; $(FIX) -i stathist.in
thdexpire:       thdexpire.in       $(FIX) ; $(FIX) thdexpire.in
tunefeed:        tunefeed.in        $(FIX) ; $(FIX) -i tunefeed.in
