template <typename, typename>
class Merge;

//Merging 2 sets of Chars
template <template <char...> class left, char... LeftChars,
          template <char...> class right, char... RightChars>
class Merge<left<LeftChars...>, right<RightChars...>>
{
    public:
        typedef Chars<LeftChars..., RightChars...> CP;
};