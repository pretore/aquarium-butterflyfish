#ifndef _BUTTERFLYFISH_BUTTERFLYFISH_H_
#define _BUTTERFLYFISH_BUTTERFLYFISH_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

/* native integer (ni) */
#include <butterflyfish/stream_ni.h>

/* pointer (p) */

/* integer (i) */
#include <butterflyfish/addable_i.h>
#include <butterflyfish/addable_i_i.h>
#include <butterflyfish/collection_i.h>
#include <butterflyfish/collection_i_i.h>
#include <butterflyfish/incremental_list_i.h>
#include <butterflyfish/incremental_list_i_i.h>
#include <butterflyfish/incremental_map_i_i.h>
#include <butterflyfish/incremental_set_i.h>
#include <butterflyfish/incremental_set_i_i.h>
#include <butterflyfish/insertable_i.h>
#include <butterflyfish/insertable_i_i.h>
#include <butterflyfish/list_i.h>
#include <butterflyfish/list_i_i.h>
#include <butterflyfish/map_i_i.h>
#include <butterflyfish/map_i_i_entry.h>
#include <butterflyfish/mutable_list_i.h>
#include <butterflyfish/mutable_list_i_i.h>
#include <butterflyfish/mutable_map_i_i.h>
#include <butterflyfish/mutable_set_i.h>
#include <butterflyfish/mutable_set_i_i.h>
#include <butterflyfish/ordered_i.h>
#include <butterflyfish/ordered_i_i.h>
#include <butterflyfish/ordered_incremental_list_i.h>
#include <butterflyfish/ordered_incremental_list_i_i.h>
#include <butterflyfish/ordered_incremental_map_i_i.h>
#include <butterflyfish/ordered_incremental_set_i.h>
#include <butterflyfish/ordered_incremental_set_i_i.h>
#include <butterflyfish/ordered_list_i.h>
#include <butterflyfish/ordered_list_i_i.h>
#include <butterflyfish/ordered_map_i_i.h>
//#include <butterflyfish/ordered_mutable_list_i.h>
//#include <butterflyfish/ordered_mutable_list_i_i.h>
//#include <butterflyfish/ordered_mutable_map_i_i.h>
//#include <butterflyfish/ordered_mutable_set_i.h>
//#include <butterflyfish/ordered_mutable_set_i_i.h>
//#include <butterflyfish/ordered_reducible_list_i.h>
//#include <butterflyfish/ordered_reducible_list_i_i.h>
//#include <butterflyfish/ordered_reducible_map_i_i.h>
//#include <butterflyfish/ordered_reducible_set_i.h>
//#include <butterflyfish/ordered_reducible_set_i_i.h>
#include <butterflyfish/ordered_set_i.h>
#include <butterflyfish/ordered_set_i_i.h>
//#include <butterflyfish/ordered_settable_incremental_list_i.h>
//#include <butterflyfish/ordered_settable_incremental_list_i_i.h>
//#include <butterflyfish/ordered_settable_incremental_map_i_i.h>
//#include <butterflyfish/ordered_settable_incremental_set_i.h>
//#include <butterflyfish/ordered_settable_incremental_set_i_i.h>
//#include <butterflyfish/ordered_settable_list_i.h>
//#include <butterflyfish/ordered_settable_list_i_i.h>
//#include <butterflyfish/ordered_settable_map_i_i.h>
//#include <butterflyfish/ordered_settable_reducible_list_i.h>
//#include <butterflyfish/ordered_settable_reducible_list_i_i.h>
//#include <butterflyfish/ordered_settable_reducible_map_i_i.h>
//#include <butterflyfish/ordered_settable_reducible_set_i.h>
//#include <butterflyfish/ordered_settable_reducible_set_i_i.h>
//#include <butterflyfish/ordered_settable_set_i.h>
//#include <butterflyfish/ordered_settable_set_i_i.h>
#include <butterflyfish/reducible_list_i.h>
#include <butterflyfish/reducible_list_i_i.h>
#include <butterflyfish/reducible_map_i_i.h>
#include <butterflyfish/reducible_set_i.h>
#include <butterflyfish/reducible_set_i_i.h>
#include <butterflyfish/removable_i.h>
#include <butterflyfish/removable_i_i.h>
#include <butterflyfish/set_i.h>
#include <butterflyfish/set_i_i.h>
#include <butterflyfish/settable_i.h>
#include <butterflyfish/settable_i_i.h>
#include <butterflyfish/settable_incremental_list_i.h>
#include <butterflyfish/settable_incremental_list_i_i.h>
#include <butterflyfish/settable_incremental_map_i_i.h>
#include <butterflyfish/settable_incremental_set_i.h>
#include <butterflyfish/settable_incremental_set_i_i.h>
#include <butterflyfish/settable_list_i.h>
#include <butterflyfish/settable_list_i_i.h>
#include <butterflyfish/settable_map_i_i.h>
#include <butterflyfish/settable_reducible_list_i.h>
#include <butterflyfish/settable_reducible_list_i_i.h>
#include <butterflyfish/settable_reducible_map_i_i.h>
#include <butterflyfish/settable_reducible_set_i.h>
#include <butterflyfish/settable_reducible_set_i_i.h>
#include <butterflyfish/settable_set_i.h>
#include <butterflyfish/settable_set_i_i.h>
#include <butterflyfish/sorted_i.h>
#include <butterflyfish/sorted_i_i.h>
//#include <butterflyfish/sorted_incremental_list_i.h>
//#include <butterflyfish/sorted_incremental_list_i_i.h>
//#include <butterflyfish/sorted_incremental_map_i_i.h>
//#include <butterflyfish/sorted_incremental_set_i.h>
//#include <butterflyfish/sorted_incremental_set_i_i.h>
//#include <butterflyfish/sorted_list_i.h>
//#include <butterflyfish/sorted_list_i_i.h>
//#include <butterflyfish/sorted_map_i_i.h>
//#include <butterflyfish/sorted_mutable_list_i.h>
//#include <butterflyfish/sorted_mutable_map_i_i.h>
//#include <butterflyfish/sorted_mutable_set_i.h>
//#include <butterflyfish/sorted_reducible_list_i.h>
//#include <butterflyfish/sorted_reducible_list_i_i.h>
//#include <butterflyfish/sorted_reducible_map_i_i.h>
//#include <butterflyfish/sorted_reducible_set_i.h>
//#include <butterflyfish/sorted_reducible_set_i_i.h>
//#include <butterflyfish/sorted_set_i.h>
//#include <butterflyfish/sorted_set_i_i.h>
//#include <butterflyfish/sorted_settable_incremental_list_i.h>
//#include <butterflyfish/sorted_settable_incremental_list_i_i.h>
//#include <butterflyfish/sorted_settable_incremental_map_i_i.h>
//#include <butterflyfish/sorted_settable_incremental_set_i.h>
//#include <butterflyfish/sorted_settable_incremental_set_i_i.h>
//#include <butterflyfish/sorted_settable_list_i.h>
//#include <butterflyfish/sorted_settable_list_i_i.h>
//#include <butterflyfish/sorted_settable_map_i_i.h>
//#include <butterflyfish/sorted_settable_reducible_list_i.h>
//#include <butterflyfish/sorted_settable_reducible_map_i_i.h>
//#include <butterflyfish/sorted_settable_reducible_set_i.h>
//#include <butterflyfish/sorted_settable_set_i.h>
//#include <butterflyfish/sorted_settable_set_i_i.h>
#include <butterflyfish/stream_i.h>
#include <butterflyfish/stream_i_i.h>
#include <butterflyfish/unordered_i.h>
#include <butterflyfish/unordered_i_i.h>

/* string (s) */

/* strong reference (sr) */

/* weak reference (wr) */

#endif /* _BUTTERFLYFISH_BUTTERFLYFISH_H_ */
