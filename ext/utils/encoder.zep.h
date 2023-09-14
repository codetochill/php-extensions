
extern zend_class_entry *utils_encoder_ce;

ZEPHIR_INIT_CLASS(Utils_Encoder);

PHP_METHOD(Utils_Encoder, encode);
PHP_METHOD(Utils_Encoder, my_custom_encoder);

ZEND_BEGIN_ARG_INFO_EX(arginfo_utils_encoder_encode, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_utils_encoder_my_custom_encoder, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(utils_encoder_method_entry) {
	PHP_ME(Utils_Encoder, encode, arginfo_utils_encoder_encode, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Utils_Encoder, my_custom_encoder, arginfo_utils_encoder_my_custom_encoder, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
