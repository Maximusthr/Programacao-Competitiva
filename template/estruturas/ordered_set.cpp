#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template<class T> using ordered_set = 
tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

// less or less_equal (multi valores)
// order_of_key()
// find_by_order()

// erase em multiset: order.erase(order.find_by_order(order.order_of_key(sal[idx])));
