#define MM 2305842993ll // MM = 2^61/mod
inline int rem(long long a){return a-mod*((a>>29)*MM>>32);}