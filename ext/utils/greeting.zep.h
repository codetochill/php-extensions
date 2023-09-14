
extern zend_class_entry *utils_greeting_ce;

ZEPHIR_INIT_CLASS(Utils_Greeting);

PHP_METHOD(Utils_Greeting, say);
PHP_METHOD(Utils_Greeting, binaryToHex);

ZEND_BEGIN_ARG_INFO_EX(arginfo_utils_greeting_say, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_utils_greeting_binarytohex, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, s, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(utils_greeting_method_entry) {
#if PHP_VERSION_ID >= 80000
	PHP_ME(Utils_Greeting, say, arginfo_utils_greeting_say, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
#else
	PHP_ME(Utils_Greeting, say, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
#endif
	PHP_ME(Utils_Greeting, binaryToHex, arginfo_utils_greeting_binarytohex, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
