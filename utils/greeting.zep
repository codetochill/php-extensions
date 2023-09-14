namespace Utils;

class Greeting
{

    public static function say()
    {
        echo "hello world!";
    }

    public static function binaryToHex(string! s) -> string
    {
        var o = "", n; char ch;

        for ch in range(0, s->length()) {
            let n = ch->toHex();
            if n->length() < 2 {
                let o .= "0" . n;
            } else {
                let o .= n;
            }
        }
        return o;
    }

}