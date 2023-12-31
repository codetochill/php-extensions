srcdir = /Users/hello/Projects/php-extensions/utils/ext
builddir = /Users/hello/Projects/php-extensions/utils/ext
top_srcdir = /Users/hello/Projects/php-extensions/utils/ext
top_builddir = /Users/hello/Projects/php-extensions/utils/ext
EGREP = /usr/bin/grep -E
SED = /usr/bin/sed
CONFIGURE_COMMAND = './configure' '--enable-utils'
CONFIGURE_OPTIONS = '--enable-utils'
SHLIB_SUFFIX_NAME = dylib
SHLIB_DL_SUFFIX_NAME = so
AWK = awk
shared_objects_utils = utils.lo kernel/main.lo kernel/memory.lo kernel/exception.lo kernel/debug.lo kernel/backtrace.lo kernel/object.lo kernel/array.lo kernel/string.lo kernel/fcall.lo kernel/require.lo kernel/file.lo kernel/operators.lo kernel/math.lo kernel/concat.lo kernel/variables.lo kernel/filter.lo kernel/iterator.lo kernel/time.lo kernel/exit.lo utils/encoder.lo utils/greeting.lo
PHP_PECL_EXTENSION = utils
UTILS_SHARED_LIBADD =
PHP_MODULES = $(phplibdir)/utils.la
PHP_ZEND_EX =
all_targets = $(PHP_MODULES) $(PHP_ZEND_EX)
install_targets = install-modules install-headers
prefix = /opt/homebrew/Cellar/php/8.2.10
exec_prefix = $(prefix)
libdir = ${exec_prefix}/lib
prefix = /opt/homebrew/Cellar/php/8.2.10
phplibdir = /Users/hello/Projects/php-extensions/utils/ext/modules
phpincludedir = /opt/homebrew/Cellar/php/8.2.10/include/php
CC = gcc
CFLAGS = -O2 -fvisibility=hidden -Wparentheses -flto -DZEPHIR_RELEASE=1
CFLAGS_CLEAN = $(CFLAGS) -D_GNU_SOURCE
CPP = gcc -E
CPPFLAGS = -DHAVE_CONFIG_H
CXX =
CXXFLAGS =
CXXFLAGS_CLEAN = $(CXXFLAGS)
EXTENSION_DIR = /opt/homebrew/Cellar/php/8.2.10/pecl/20220829
PHP_EXECUTABLE = /opt/homebrew/Cellar/php/8.2.10/bin/php
EXTRA_LDFLAGS =
EXTRA_LIBS =
INCLUDES = -I/opt/homebrew/Cellar/php/8.2.10/include/php -I/opt/homebrew/Cellar/php/8.2.10/include/php/main -I/opt/homebrew/Cellar/php/8.2.10/include/php/TSRM -I/opt/homebrew/Cellar/php/8.2.10/include/php/Zend -I/opt/homebrew/Cellar/php/8.2.10/include/php/ext -I/opt/homebrew/Cellar/php/8.2.10/include/php/ext/date/lib
LFLAGS =
LDFLAGS =
SHARED_LIBTOOL =
LIBTOOL = $(SHELL) $(top_builddir)/libtool
SHELL = /bin/sh
INSTALL_HEADERS = ext/utils/php_UTILS.h
BUILD_CC = gcc
mkinstalldirs = $(top_srcdir)/build/shtool mkdir -p
INSTALL = $(top_srcdir)/build/shtool install -c
INSTALL_DATA = $(INSTALL) -m 644

DEFS = -I$(top_builddir)/include -I$(top_builddir)/main -I$(top_srcdir)
COMMON_FLAGS = $(DEFS) $(INCLUDES) $(EXTRA_INCLUDES) $(CPPFLAGS) $(PHP_FRAMEWORKPATH)

all: $(all_targets)
	@echo
	@echo "Build complete."
	@echo "Don't forget to run 'make test'."
	@echo

build-modules: $(PHP_MODULES) $(PHP_ZEND_EX)

build-binaries: $(PHP_BINARIES)

libphp.la: $(PHP_GLOBAL_OBJS) $(PHP_SAPI_OBJS)
	$(LIBTOOL) --mode=link $(CC) $(LIBPHP_CFLAGS) $(CFLAGS) $(EXTRA_CFLAGS) -rpath $(phptempdir) $(EXTRA_LDFLAGS) $(LDFLAGS) $(PHP_RPATHS) $(PHP_GLOBAL_OBJS) $(PHP_SAPI_OBJS) $(EXTRA_LIBS) $(ZEND_EXTRA_LIBS) -o $@
	-@$(LIBTOOL) --silent --mode=install cp $@ $(phptempdir)/$@ >/dev/null 2>&1

libs/libphp.bundle: $(PHP_GLOBAL_OBJS) $(PHP_SAPI_OBJS)
	$(CC) $(MH_BUNDLE_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) $(LDFLAGS) $(EXTRA_LDFLAGS) $(PHP_GLOBAL_OBJS:.lo=.o) $(PHP_SAPI_OBJS:.lo=.o) $(PHP_FRAMEWORKS) $(EXTRA_LIBS) $(ZEND_EXTRA_LIBS) -o $@ && cp $@ libs/libphp.so

install: $(all_targets) $(install_targets)

install-sapi: $(OVERALL_TARGET)
	@echo "Installing PHP SAPI module:       $(PHP_SAPI)"
	-@$(mkinstalldirs) $(INSTALL_ROOT)$(bindir)
	-@if test ! -r $(phptempdir)/libphp.$(SHLIB_DL_SUFFIX_NAME); then \
		for i in 0.0.0 0.0 0; do \
			if test -r $(phptempdir)/libphp.$(SHLIB_DL_SUFFIX_NAME).$$i; then \
				$(LN_S) $(phptempdir)/libphp.$(SHLIB_DL_SUFFIX_NAME).$$i $(phptempdir)/libphp.$(SHLIB_DL_SUFFIX_NAME); \
				break; \
			fi; \
		done; \
	fi
	@$(INSTALL_IT)

install-binaries: build-binaries $(install_binary_targets)

install-modules: build-modules
	@test -d modules && \
	$(mkinstalldirs) $(INSTALL_ROOT)$(EXTENSION_DIR)
	@echo "Installing shared extensions:     $(INSTALL_ROOT)$(EXTENSION_DIR)/"
	@rm -f modules/*.la >/dev/null 2>&1
	@$(INSTALL) modules/* $(INSTALL_ROOT)$(EXTENSION_DIR)

install-headers:
	-@if test "$(INSTALL_HEADERS)"; then \
		for i in `echo $(INSTALL_HEADERS)`; do \
			i=`$(top_srcdir)/build/shtool path -d $$i`; \
			paths="$$paths $(INSTALL_ROOT)$(phpincludedir)/$$i"; \
		done; \
		$(mkinstalldirs) $$paths && \
		echo "Installing header files:          $(INSTALL_ROOT)$(phpincludedir)/" && \
		for i in `echo $(INSTALL_HEADERS)`; do \
			if test "$(PHP_PECL_EXTENSION)"; then \
				src=`echo $$i | $(SED) -e "s#ext/$(PHP_PECL_EXTENSION)/##g"`; \
			else \
				src=$$i; \
			fi; \
			if test -f "$(top_srcdir)/$$src"; then \
				$(INSTALL_DATA) $(top_srcdir)/$$src $(INSTALL_ROOT)$(phpincludedir)/$$i; \
			elif test -f "$(top_builddir)/$$src"; then \
				$(INSTALL_DATA) $(top_builddir)/$$src $(INSTALL_ROOT)$(phpincludedir)/$$i; \
			else \
				(cd $(top_srcdir)/$$src && $(INSTALL_DATA) *.h $(INSTALL_ROOT)$(phpincludedir)/$$i; \
				cd $(top_builddir)/$$src && $(INSTALL_DATA) *.h $(INSTALL_ROOT)$(phpincludedir)/$$i) 2>/dev/null || true; \
			fi \
		done; \
	fi

PHP_TEST_SETTINGS = -d 'open_basedir=' -d 'output_buffering=0' -d 'memory_limit=-1'
PHP_TEST_SHARED_EXTENSIONS =  ` \
	if test "x$(PHP_MODULES)" != "x"; then \
		for i in $(PHP_MODULES)""; do \
			. $$i; \
			if test "x$$dlname" != "xdl_test.so"; then \
				$(top_srcdir)/build/shtool echo -n -- " -d extension=$$dlname"; \
			fi; \
		done; \
	fi; \
	if test "x$(PHP_ZEND_EX)" != "x"; then \
		for i in $(PHP_ZEND_EX)""; do \
			. $$i; $(top_srcdir)/build/shtool echo -n -- " -d zend_extension=$(top_builddir)/modules/$$dlname"; \
		done; \
	fi`
PHP_DEPRECATED_DIRECTIVES_REGEX = '^(magic_quotes_(gpc|runtime|sybase)?|(zend_)?extension(_debug)?(_ts)?)[\t\ ]*='

test: all
	@if test ! -z "$(PHP_EXECUTABLE)" && test -x "$(PHP_EXECUTABLE)"; then \
		INI_FILE=`$(PHP_EXECUTABLE) -d 'display_errors=stderr' -r 'echo php_ini_loaded_file();' 2> /dev/null`; \
		if test "$$INI_FILE"; then \
			$(EGREP) -h -v $(PHP_DEPRECATED_DIRECTIVES_REGEX) "$$INI_FILE" > $(top_builddir)/tmp-php.ini; \
		else \
			echo > $(top_builddir)/tmp-php.ini; \
		fi; \
		INI_SCANNED_PATH=`$(PHP_EXECUTABLE) -d 'display_errors=stderr' -r '$$a = explode(",\n", trim(php_ini_scanned_files())); echo $$a[0];' 2> /dev/null`; \
		if test "$$INI_SCANNED_PATH"; then \
			INI_SCANNED_PATH=`$(top_srcdir)/build/shtool path -d $$INI_SCANNED_PATH`; \
			$(EGREP) -h -v $(PHP_DEPRECATED_DIRECTIVES_REGEX) "$$INI_SCANNED_PATH"/*.ini >> $(top_builddir)/tmp-php.ini; \
		fi; \
		TEST_PHP_EXECUTABLE=$(PHP_EXECUTABLE) \
		TEST_PHP_SRCDIR=$(top_srcdir) \
		CC="$(CC)" \
			$(PHP_EXECUTABLE) -n -c $(top_builddir)/tmp-php.ini $(PHP_TEST_SETTINGS) $(top_srcdir)/run-tests.php -n -c $(top_builddir)/tmp-php.ini -d extension_dir=$(top_builddir)/modules/ $(PHP_TEST_SHARED_EXTENSIONS) $(TESTS); \
		TEST_RESULT_EXIT_CODE=$$?; \
		rm $(top_builddir)/tmp-php.ini; \
		exit $$TEST_RESULT_EXIT_CODE; \
	else \
		echo "ERROR: Cannot run tests without CLI sapi."; \
	fi

clean:
	find . -name \*.gcno -o -name \*.gcda | xargs rm -f
	find . -name \*.lo -o -name \*.o -o -name \*.dep | xargs rm -f
	find . -name \*.la -o -name \*.a | xargs rm -f
	find . -name \*.so | xargs rm -f
	find . -name .libs -a -type d|xargs rm -rf
	rm -f libphp.la $(SAPI_CLI_PATH) $(SAPI_CGI_PATH) $(SAPI_LITESPEED_PATH) $(SAPI_FPM_PATH) $(OVERALL_TARGET) modules/* libs/*
	rm -f ext/opcache/jit/zend_jit_x86.c
	rm -f ext/opcache/jit/zend_jit_arm64.c
	rm -f ext/opcache/minilua

distclean: clean
	rm -f Makefile config.cache config.log config.status Makefile.objects Makefile.fragments libtool main/php_config.h main/internal_functions_cli.c main/internal_functions.c Zend/zend_dtrace_gen.h Zend/zend_dtrace_gen.h.bak Zend/zend_config.h
	rm -f main/build-defs.h scripts/phpize
	rm -f ext/date/lib/timelib_config.h ext/mbstring/libmbfl/config.h ext/oci8/oci8_dtrace_gen.h ext/oci8/oci8_dtrace_gen.h.bak
	rm -f scripts/man1/phpize.1 scripts/php-config scripts/man1/php-config.1 sapi/cli/php.1 sapi/cgi/php-cgi.1 sapi/phpdbg/phpdbg.1 ext/phar/phar.1 ext/phar/phar.phar.1
	rm -f sapi/fpm/php-fpm.conf sapi/fpm/init.d.php-fpm sapi/fpm/php-fpm.service sapi/fpm/php-fpm.8 sapi/fpm/status.html
	rm -f ext/phar/phar.phar ext/phar/phar.php
	if test "$(srcdir)" != "$(builddir)"; then \
	  rm -f ext/phar/phar/phar.inc; \
	fi
	$(EGREP) define'.*include/php' $(top_srcdir)/configure | $(SED) 's/.*>//'|xargs rm -f

prof-gen:
	CCACHE_DISABLE=1 $(MAKE) PROF_FLAGS=-fprofile-generate all
	find . -name \*.gcda | xargs rm -f

prof-clean:
	find . -name \*.lo -o -name \*.o | xargs rm -f
	find . -name \*.la -o -name \*.a | xargs rm -f
	find . -name \*.so | xargs rm -f
	rm -f libphp.la $(SAPI_CLI_PATH) $(SAPI_CGI_PATH) $(SAPI_LITESPEED_PATH) $(SAPI_FPM_PATH) $(OVERALL_TARGET) modules/* libs/*

prof-use:
	CCACHE_DISABLE=1 $(MAKE) PROF_FLAGS=-fprofile-use all

%_arginfo.h: %.stub.php
	@if test -e "$(top_srcdir)/build/gen_stub.php"; then \
		if test ! -z "$(PHP)"; then \
			echo Parse $< to generate $@;\
			$(PHP) $(top_srcdir)/build/gen_stub.php $<; \
		elif test ! -z "$(PHP_EXECUTABLE)" && test -x "$(PHP_EXECUTABLE)"; then \
			echo Parse $< to generate $@;\
			$(PHP_EXECUTABLE) $(top_srcdir)/build/gen_stub.php $<; \
		fi; \
	fi;

.PHONY: all clean install distclean test prof-gen prof-clean prof-use
.NOEXPORT:
-include utils.dep
utils.lo: /Users/hello/Projects/php-extensions/utils/ext/utils.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/Users/hello/Projects/php-extensions/utils/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /Users/hello/Projects/php-extensions/utils/ext/utils.c -o utils.lo  -MMD -MF utils.dep -MT utils.lo
-include kernel/main.dep
kernel/main.lo: /Users/hello/Projects/php-extensions/utils/ext/kernel/main.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/Users/hello/Projects/php-extensions/utils/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /Users/hello/Projects/php-extensions/utils/ext/kernel/main.c -o kernel/main.lo  -MMD -MF kernel/main.dep -MT kernel/main.lo
-include kernel/memory.dep
kernel/memory.lo: /Users/hello/Projects/php-extensions/utils/ext/kernel/memory.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/Users/hello/Projects/php-extensions/utils/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /Users/hello/Projects/php-extensions/utils/ext/kernel/memory.c -o kernel/memory.lo  -MMD -MF kernel/memory.dep -MT kernel/memory.lo
-include kernel/exception.dep
kernel/exception.lo: /Users/hello/Projects/php-extensions/utils/ext/kernel/exception.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/Users/hello/Projects/php-extensions/utils/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /Users/hello/Projects/php-extensions/utils/ext/kernel/exception.c -o kernel/exception.lo  -MMD -MF kernel/exception.dep -MT kernel/exception.lo
-include kernel/debug.dep
kernel/debug.lo: /Users/hello/Projects/php-extensions/utils/ext/kernel/debug.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/Users/hello/Projects/php-extensions/utils/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /Users/hello/Projects/php-extensions/utils/ext/kernel/debug.c -o kernel/debug.lo  -MMD -MF kernel/debug.dep -MT kernel/debug.lo
-include kernel/backtrace.dep
kernel/backtrace.lo: /Users/hello/Projects/php-extensions/utils/ext/kernel/backtrace.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/Users/hello/Projects/php-extensions/utils/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /Users/hello/Projects/php-extensions/utils/ext/kernel/backtrace.c -o kernel/backtrace.lo  -MMD -MF kernel/backtrace.dep -MT kernel/backtrace.lo
-include kernel/object.dep
kernel/object.lo: /Users/hello/Projects/php-extensions/utils/ext/kernel/object.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/Users/hello/Projects/php-extensions/utils/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /Users/hello/Projects/php-extensions/utils/ext/kernel/object.c -o kernel/object.lo  -MMD -MF kernel/object.dep -MT kernel/object.lo
-include kernel/array.dep
kernel/array.lo: /Users/hello/Projects/php-extensions/utils/ext/kernel/array.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/Users/hello/Projects/php-extensions/utils/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /Users/hello/Projects/php-extensions/utils/ext/kernel/array.c -o kernel/array.lo  -MMD -MF kernel/array.dep -MT kernel/array.lo
-include kernel/string.dep
kernel/string.lo: /Users/hello/Projects/php-extensions/utils/ext/kernel/string.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/Users/hello/Projects/php-extensions/utils/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /Users/hello/Projects/php-extensions/utils/ext/kernel/string.c -o kernel/string.lo  -MMD -MF kernel/string.dep -MT kernel/string.lo
-include kernel/fcall.dep
kernel/fcall.lo: /Users/hello/Projects/php-extensions/utils/ext/kernel/fcall.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/Users/hello/Projects/php-extensions/utils/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /Users/hello/Projects/php-extensions/utils/ext/kernel/fcall.c -o kernel/fcall.lo  -MMD -MF kernel/fcall.dep -MT kernel/fcall.lo
-include kernel/require.dep
kernel/require.lo: /Users/hello/Projects/php-extensions/utils/ext/kernel/require.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/Users/hello/Projects/php-extensions/utils/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /Users/hello/Projects/php-extensions/utils/ext/kernel/require.c -o kernel/require.lo  -MMD -MF kernel/require.dep -MT kernel/require.lo
-include kernel/file.dep
kernel/file.lo: /Users/hello/Projects/php-extensions/utils/ext/kernel/file.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/Users/hello/Projects/php-extensions/utils/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /Users/hello/Projects/php-extensions/utils/ext/kernel/file.c -o kernel/file.lo  -MMD -MF kernel/file.dep -MT kernel/file.lo
-include kernel/operators.dep
kernel/operators.lo: /Users/hello/Projects/php-extensions/utils/ext/kernel/operators.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/Users/hello/Projects/php-extensions/utils/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /Users/hello/Projects/php-extensions/utils/ext/kernel/operators.c -o kernel/operators.lo  -MMD -MF kernel/operators.dep -MT kernel/operators.lo
-include kernel/math.dep
kernel/math.lo: /Users/hello/Projects/php-extensions/utils/ext/kernel/math.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/Users/hello/Projects/php-extensions/utils/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /Users/hello/Projects/php-extensions/utils/ext/kernel/math.c -o kernel/math.lo  -MMD -MF kernel/math.dep -MT kernel/math.lo
-include kernel/concat.dep
kernel/concat.lo: /Users/hello/Projects/php-extensions/utils/ext/kernel/concat.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/Users/hello/Projects/php-extensions/utils/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /Users/hello/Projects/php-extensions/utils/ext/kernel/concat.c -o kernel/concat.lo  -MMD -MF kernel/concat.dep -MT kernel/concat.lo
-include kernel/variables.dep
kernel/variables.lo: /Users/hello/Projects/php-extensions/utils/ext/kernel/variables.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/Users/hello/Projects/php-extensions/utils/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /Users/hello/Projects/php-extensions/utils/ext/kernel/variables.c -o kernel/variables.lo  -MMD -MF kernel/variables.dep -MT kernel/variables.lo
-include kernel/filter.dep
kernel/filter.lo: /Users/hello/Projects/php-extensions/utils/ext/kernel/filter.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/Users/hello/Projects/php-extensions/utils/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /Users/hello/Projects/php-extensions/utils/ext/kernel/filter.c -o kernel/filter.lo  -MMD -MF kernel/filter.dep -MT kernel/filter.lo
-include kernel/iterator.dep
kernel/iterator.lo: /Users/hello/Projects/php-extensions/utils/ext/kernel/iterator.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/Users/hello/Projects/php-extensions/utils/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /Users/hello/Projects/php-extensions/utils/ext/kernel/iterator.c -o kernel/iterator.lo  -MMD -MF kernel/iterator.dep -MT kernel/iterator.lo
-include kernel/time.dep
kernel/time.lo: /Users/hello/Projects/php-extensions/utils/ext/kernel/time.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/Users/hello/Projects/php-extensions/utils/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /Users/hello/Projects/php-extensions/utils/ext/kernel/time.c -o kernel/time.lo  -MMD -MF kernel/time.dep -MT kernel/time.lo
-include kernel/exit.dep
kernel/exit.lo: /Users/hello/Projects/php-extensions/utils/ext/kernel/exit.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/Users/hello/Projects/php-extensions/utils/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /Users/hello/Projects/php-extensions/utils/ext/kernel/exit.c -o kernel/exit.lo  -MMD -MF kernel/exit.dep -MT kernel/exit.lo
-include utils/encoder.dep
utils/encoder.lo: /Users/hello/Projects/php-extensions/utils/ext/utils/encoder.zep.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/Users/hello/Projects/php-extensions/utils/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /Users/hello/Projects/php-extensions/utils/ext/utils/encoder.zep.c -o utils/encoder.lo  -MMD -MF utils/encoder.dep -MT utils/encoder.lo
-include utils/greeting.dep
utils/greeting.lo: /Users/hello/Projects/php-extensions/utils/ext/utils/greeting.zep.c
	$(LIBTOOL) --mode=compile $(CC) -I. -I/Users/hello/Projects/php-extensions/utils/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)   -DZEND_COMPILE_DL_EXT=1 -c /Users/hello/Projects/php-extensions/utils/ext/utils/greeting.zep.c -o utils/greeting.lo  -MMD -MF utils/greeting.dep -MT utils/greeting.lo
$(phplibdir)/utils.la: ./utils.la
	$(LIBTOOL) --mode=install cp ./utils.la $(phplibdir)

./utils.la: $(shared_objects_utils) $(UTILS_SHARED_DEPENDENCIES)
	$(LIBTOOL) --mode=link $(CC) -shared $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) $(LDFLAGS)  -o $@ -export-dynamic -avoid-version -prefer-pic -module -rpath $(phplibdir) $(EXTRA_LDFLAGS) $(shared_objects_utils) $(UTILS_SHARED_LIBADD)

