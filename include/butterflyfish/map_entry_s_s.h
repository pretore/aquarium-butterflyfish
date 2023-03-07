#ifndef _BUTTERFLYFISH_MAP_ENTRY_S_S_H_
#define _BUTTERFLYFISH_MAP_ENTRY_S_S_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>
#include <sea-urchin.h>

struct sea_turtle_string;
struct butterflyfish_map_s_s;

#define BUTTERFLYFISH_MAP_ENTRY_S_S_ERROR_OBJECT_IS_NULL \
    SEA_URCHIN_ERROR_OBJECT_IS_NULL
#define BUTTERFLYFISH_MAP_ENTRY_S_S_ERROR_ENTRY_IS_NULL \
    SEA_URCHIN_ERROR_ITEM_IS_NULL
#define BUTTERFLYFISH_MAP_ENTRY_S_S_ERROR_VALUE_IS_NULL \
    SEA_URCHIN_ERROR_VALUE_IS_NULL
#define BUTTERFLYFISH_MAP_ENTRY_S_S_ERROR_OUT_IS_NULL \
    SEA_URCHIN_ERROR_OUT_IS_NULL

struct butterflyfish_map_entry_s_s;

int butterflyfish_map_entry_s_s_key(
        const struct butterflyfish_map_s_s *object,
        const struct butterflyfish_map_entry_s_s *entry,
        const struct sea_turtle_string **out);

int butterflyfish_map_entry_s_s_get_value(
        const struct butterflyfish_map_s_s *object,
        const struct butterflyfish_map_entry_s_s *entry,
        const struct sea_turtle_string **out);

int butterflyfish_map_entry_s_s_set_value(
        struct butterflyfish_map_s_s *object,
        struct butterflyfish_map_entry_s_s *entry,
        const struct sea_turtle_string *value);

#endif /* _BUTTERFLYFISH_MAP_ENTRY_S_S_H_ */
