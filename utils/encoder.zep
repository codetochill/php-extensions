namespace Utils;

class Encoder
{
    public static function encode(var text)
    {
        if strlen(text) != 0
        {
            if function_exists("my_custom_encoder") {
                return my_custom_encoder(text);
            } else {
                return base64_encode(text);
            }
        }

        return false;
    }
}