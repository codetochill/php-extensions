
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(Utils_Greeting)
{
	ZEPHIR_REGISTER_CLASS(Utils, Greeting, utils, greeting, utils_greeting_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Utils_Greeting, say)
{
	zval *this_ptr = getThis();



	php_printf("%s", "hello world!");
}

PHP_METHOD(Utils_Greeting, binaryToHex)
{
	zend_bool _1;
	char ch = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, _2, _3;
	zval *s_param = NULL, o, n, _0, _4$$3, _5$$3, _6$$3, _7$$4;
	zval s;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&s);
	ZVAL_UNDEF(&o);
	ZVAL_UNDEF(&n);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(s)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &s_param);
	if (UNEXPECTED(Z_TYPE_P(s_param) != IS_STRING && Z_TYPE_P(s_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 's' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(s_param) == IS_STRING)) {
		zephir_get_strval(&s, s_param);
	} else {
		ZEPHIR_INIT_VAR(&s);
	}


	ZEPHIR_INIT_VAR(&o);
	ZVAL_STRING(&o, "");
	_3 = zephir_fast_strlen_ev(&s);
	_2 = 0;
	_1 = 0;
	if (_2 <= _3) {
		while (1) {
			if (_1) {
				_2++;
				if (!(_2 <= _3)) {
					break;
				}
			} else {
				_1 = 1;
			}
			ch = _2;
			ZEPHIR_INIT_NVAR(&_4$$3);
			ZEPHIR_INIT_NVAR(&_5$$3);
			ZVAL_STRINGL(&_5$$3, &ch, 1);
			zephir_string_to_hex(&_4$$3, &_5$$3);
			ZEPHIR_CPY_WRT(&n, &_4$$3);
			ZEPHIR_CALL_METHOD(&_6$$3, &n, "length", NULL, 0);
			zephir_check_call_status();
			if (ZEPHIR_LT_LONG(&_6$$3, 2)) {
				ZEPHIR_INIT_NVAR(&_7$$4);
				ZEPHIR_CONCAT_SV(&_7$$4, "0", &n);
				zephir_concat_self(&o, &_7$$4);
			} else {
				zephir_concat_self(&o, &n);
			}
		}
	}
	RETURN_CCTOR(&o);
}

