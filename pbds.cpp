#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, 
tree_order_statistics_node_update>;
//order_of_key (find index from val)
//find_by_order (find val from index)
//less // greater_equal // less_equal
// similar to set/ multiset
