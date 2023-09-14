
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
#include "kernel/string.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Utils_Encoder)
{
	ZEPHIR_REGISTER_CLASS(Utils, Encoder, utils, encoder, utils_encoder_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Utils_Encoder, encode)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *text, text_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(text)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &text);


	if (zephir_fast_strlen_ev(text) != 0) {
		if ((zephir_function_exists_ex(ZEND_STRL("my_custom_encoder")) == SUCCESS)) {
			ZEPHIR_RETURN_CALL_FUNCTION("my_custom_encoder", NULL, 0, text);
			zephir_check_call_status();
			RETURN_MM();
		} else {
			ZEPHIR_RETURN_CALL_FUNCTION("base64_encode", NULL, 1, text);
			zephir_check_call_status();
			RETURN_MM();
		}
	}
	RETURN_MM_BOOL(0);
}

PHP_METHOD(Utils_Encoder, my_custom_encoder)
{
	zval *text, text_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(text)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &text);


	RETURN_STRING("base64_encode(text)");
}

